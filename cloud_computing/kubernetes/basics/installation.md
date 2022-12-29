# Kubernetes 설치
Kubernetes를 설치하는 방법에 대해서 알아보도록 한다.
### 환경
- Ubuntu 22.04
- Kubernetes 1.23.1 + Docker

### 1. Installation
> Docker를 container로 사용하는 Kubernetes의 경우, 반드시 Kubernetes 설치 이전 Docker가 설치되어있어야 합니다. 또한 설치 절차는 모든 node에서 진행해야 합니다.

```bash
$ curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add
$ sudo apt-add-repository "deb http://apt.kubernetes.io/ kubernetes-xenial main"
```
를 통해 GPG 키를 등록하고 Kubernetes 레포지토리를 저장합니다.
```bash
$ sudo apt-get install kubeadm kubelet kubectl
```
를 통해 `kubeadm`, `kubelet`, `kubectl`을 설치합니다.

```bash
$ kubectl version --client
Client Version: version.Info{Major:"1", Minor:"23", GitVersion:"v1.23.1", GitCommit:"86ec240af8cbd1b60bcc4c03c20da9b98005b92e", GitTreeState:"clean", BuildDate:"2021-12-16T11:41:01Z", GoVersion:"go1.17.5", Compiler:"gc", Platform:"linux/amd64"}
```
위의 명령어를 통해 `kubectl`이 정상적으로 설치되었는지 확인합니다.

### 2. Network Settings
Kubernetes는 다음의 포트들을 내부 통신을 위해 사용합니다. Kubernetes에서는 원활한 통신을 위해 다음의 포트를 열어놓으라고 권장합니다 (자세한 내용은 [여기](https://kubernetes.io/docs/reference/networking/ports-and-protocols/) 확인).
> 만일 Calico 등의 다른 추가 포트를 개방해야하는 경우, 적절하게 개방해야 합니다.

#### A) Master Node로 inbound
- 6443 : Kubernetes API Server
- 2379-2380 : etcd server client API
- 10250 : Kubelet API
- 10259 : kube-scheduler
- 10257 : kube-controller-manager

위의 목록에 적힌 포트를 열어야 합니다.

```bash
$ sudo iptables -I INPUT 1 -p tcp --dport 6443 -j ACCEPT
$ sudo iptables -I INPUT 1 -p tcp --dport 2370 -j ACCEPT
$ sudo iptables -I INPUT 1 -p tcp --dport 2380 -j ACCEPT
$ sudo iptables -I INPUT 1 -p tcp --dport 10250 -j ACCEPT
$ sudo iptables -I INPUT 1 -p tcp --dport 10259 -j ACCEPT
```

#### B) Worker Node로 inbound
- 10250 : Kubelet API
- 30000-32767 : NodePort Services
- 179: Calico

```bash
$ sudo iptables -I INPUT 1 -p tcp --dport 10250 -j ACCEPT
$ sudo iptables -A INPUT -p tcp --match multiport --dports 30000:32767 -j ACCEPT
$ sudo iptables -I INPUT 1 -p tcp --dport 179 -j ACCEPT
```

### 3. Cluster Setup
각각의 Node에 해당하는 설정을 마친 이후 Kubernetes 클러스터에 각 worker node를 추가해야합니다. 이는 다음의 방법을 통해서 설정할 수 있습니다.
> Master Node 설정을 먼저 마친 이후, Worker Node의 설정을 진행해야합니다.

#### A) Master Node
우선 기존에 `kubeadm`에 관련된 설정이 존재할 수 있기 때문에, 이를 먼저 초기화하는 것이 권장됩니다.

```bash
$ sudo kubeadm reset
$ sudo rm -rf $HOME/.kube/config
```
이후 초기화가 완료되었다면 다음의 명령어를 통해 `kubelet`을 초기화해줍니다.
```bash
$ sudo kubeadm init
...
Your Kubernetes control-plane has initialized successfully!
 
To start using your cluster, you need to run the following as a regular user:

mkdir -p $HOME/.kube
sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
sudo chown $(id -u):$(id -g) $HOME/.kube/config
 
Alternatively, if you are the root user, you can run: 

export KUBECONFIG=/etc/kubernetes/admin.conf

You should now deploy a pod network to the cluster.
Run "kubectl apply -f [podnetwork].yaml" with one of the options listed at:

https://kubernetes.io/docs/concepts/cluster-administration/addons/

Then you can join any number of worker nodes by running the following on each as root:

kubeadm join 172.25.244.51:6443 --token a0h4ai.5vla7kst6hh1rd0p \

--discovery-token-ca-cert-hash sha256:df6b8e6b697bde67ff717527d09dfed836fb7cd0106124d2dd6e1a30ba5141a4
```
조금 시간이 지나면 다음과 같은 출력이 나옵니다. (위와 같지 않은 출력의 경우 나오는 에러를 파악하여 적절하게 조치해야합니다) 
```bash
$ mkdir -p $HOME/.kube
$ sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
$ sudo chown $(id -u):$(id -g) $HOME/.kube/config
```
이전 출력에서 위 3개의 명령어를 입력하라고 했습니다. 만일 입력하지 않은 경우, `kubectl` 명령어를 무저곤 `sudo kubectl`로 실행해야하는 번거로움이 있으니 선택적으로 진행하면 됩니다.
```bash
$ sudo kubeadm token create --print-join-command
kubeadm join 172.25.244.51:6443 --token vpdrbu.exqmlpmb91774dyf --discovery-token-ca-cert-hash sha256:3370c2ef69c6ac1f46c09fb294aea3cfd41244eb3482c09e9f0df306298e73a1
```
위의 명령어를 통해 Kubernetes 클러스터에 새로운 worker node를 추가하는 명령어를 확인해야합니다. 위의 명령어에 대한 결과로 나온 명령어를 다른 worker node에서 실행시키면 Kubernetes 클러스터에 해당 worker node를 추가할 수 있습니다.


#### B) Worker Node
Master Node에서 `kubeadm init`이후 확인할 수 있는 token을 통해 Kubernetes 클러스터에 새로운 worker node를 추가할 수 있습니다. 먼저 Master node의 6443 포트에 접근이 가능한지 확인합니다.
```bash
$ sudo nc -zv 172.25.244.85 6443
Connection to 172.25.244.85 6443 port [tcp/*] succeeded!
```
위의 출력처럼 연결이 성공적이면 이후 단계를 진행해도 됩니다. 만일 연결이 되지 않은 경우, 6443 포트가 정상적으로 열려있는지, `kubelet`이 실행중인지 확인해야합니다. 

```bash
$ kubeadm join 172.25.244.51:6443 --token vpdrbu.exqmlpmb91774dyf --discovery-token-ca-cert-hash sha256:3370c2ef69c6ac1f46c09fb294aea3cfd41244eb3482c09e9f0df306298e73a1
[preflight] Running pre-flight checks

[WARNING SystemVerification]: missing optional cgroups: hugetlb blkio

[preflight] Reading configuration from the cluster...

[preflight] FYI: You can look at this config file with 'kubectl -n kube-system get cm kubeadm-config -o yaml'

[kubelet-start] Writing kubelet configuration to file "/var/lib/kubelet/config.yaml"

[kubelet-start] Writing kubelet environment file with flags to file "/var/lib/kubelet/kubeadm-flags.env"

[kubelet-start] Starting the kubelet

[kubelet-start] Waiting for the kubelet to perform the TLS Bootstrap...

This node has joined the cluster:
* Certificate signing request was sent to apiserver and a response was received.
* The Kubelet was informed of the new secure connection details.
Run 'kubectl get nodes' on the control-plane to see this node join the cluster.
```

`sudo kubeadm token create --print-join-command`를 Master node에서 입력했을 때 나온 join 명령어를 Worker node에서 실행합니다. 위의 명령어 처럼 `This node has joined the cluster:` 가 나오면 정상적으로 worker node를 Kubernetes 클러스터에 등록한 것을 확인할 수 있습니다.

### 4. Cluster Check
방금까지는 다음의 절차를 실행했습니다.
1. Master node에서 Kubernetes 클러스터 시작 및 join token 생성
2. 생성된 join token을 바탕으로 Worker node에서 클러스터에 참여

이제 worker node가 성공적으로 클러스터에 참여되었는지 확인하기 위해 다음의 명령어를 master node에서 입력합니다.
```bash
$ kubectl get nodes
NAME        STATUS   ROLES           AGE     VERSION
isulab321   NotReady    <none>          7m19s   v1.25.0
labisu123   NotReady    control-plane   12m     v1.25.0
```
위처럼 node는 성공적으로 보이나, `NotReady`가 나오는 경우 CNI 설정이 완료되지 않아서 node를 사용할 수 없는 경우입니다. (물론 다른 경우도 존재하긴 합니다)

### 5. Container Network Interface (CNI) 설정
Kubernetes에서 각 container끼리 네트워크가 연결되기 위해서는 CNI가 필요합니다. CNI의 종류는 매우 다양합니다:
- [Calico](https://github.com/projectcalico/calico)
- [Flannel](https://github.com/flannel-io/flannel)
- 이외 매우 많음
> 이 튜토리얼에서는 Calico(v3.24.0)를 통한 CNI를 사용합니다. 본인 필요에 따라 다른 CNI를 사용하는 것이 필요합니다. 

```bash
$ curl https://docs.projectcalico.org/manifests/calico.yaml -O
kubectl apply -f calico.yaml
```
위의 명령어를 통해 `calico.yaml`을 다운로드 받고, `kubectl apply`를 진행합니다. `calico.yaml`은 만약 필요하다면 수정해야할 수도 있습니다.

```bash
$ kubectl get pods -n kube-system
NAME                                       READY   STATUS    RESTARTS      AGE
calico-kube-controllers-7bdf4bf59d-jp7lr   1/1     Running   0             29m
calico-node-f9dz7                          1/1     Running   0             35m
calico-node-m6rdb                          1/1     Running   0             27m
coredns-565d847f94-trf57                   1/1     Running   0             29m
coredns-565d847f94-wnz6w                   1/1     Running   0             29m
...
```
위와 같이 `calico` 관련 pod들이 정상적으로 동작하는 것을 확인해야합니다. 이후 `kubectl`을 통해서 Calico의 CLI 도구를 활용할 수 있게 하기 위해 다음의 명령어가 필요합니다
```bash
$ curl -L https://github.com/projectcalico/calico/releases/download/v3.24.0/calicoctl-linux-amd64 -o kubectl-calico
$ chmod +x kubectl-calico
```
이후 `kubectl-calico` 실행 파일을 `$PATH` 디렉토리에 넣습니다. 
```bash
$ sudo kubectl calico node status
Calico process is running.

IPv4 BGP status
+---------------+-------------------+-------+----------+-------------+
| PEER ADDRESS  |     PEER TYPE     | STATE |  SINCE   |    INFO     |
+---------------+-------------------+-------+----------+-------------+
| 172.25.244.71 | node-to-node mesh | up    | 07:27:50 | Established |
+---------------+-------------------+-------+----------+-------------+

IPv6 BGP status
No IPv6 peers found.
```
위처럼 `calico node status`를 활용해서 연결이 잘 되었는지 확인하면 됩니다. 만일 각 node에 해당하는 `INFO` 값이 `Established`로 나타나면, 성공적으로 연결이 되었음을 확인할 수 있습니다.

## Summary
현재까지 진행한 내용입니다.
- Kubernetes 설치
- Kubernetes 클러스터 구축
- Worker node가 클러스터에 참여
- CNI 설치




