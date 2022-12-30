# Kubernetes 명령어
Kubernetes에서 자주 사용하는 `kubectl` 기반의 명령어에 대해서 알아보자

- `get`: 리소스에 대한 목록 확인
- `delete`: 리소스 삭제
- `apply`: 새로운 리소스 적용
- `edit`: 리소스 설정 변경
- `exec`: 리소스에 명령어 실행
- `top`: 리소스에 따른 자원 사용량 출력
- `describe`: 리소스 자세한 설명
- `cordon`: 특정 노드를 더이상 스케쥴링 불가능하게 설정
- `uncordon`: 특정 노드를 스케쥴링 가능하게 설정
- `drain`: `cordon` + 생성된 pod들 자동 이사

### get
특정 리소스에 대한 목록을 확인한다. 자세한 내용은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#get)에서 확인할 수 있으며, 이 중 자주 사용하는 내용을 추려보았다. 사용할 수 있는 리소스는 다음과 같다:
- `nodes`: 연결된 모든 node들에 대한 출력을 함
- `pods`: 실행중인 모든 pod들에 대한 출력을 함
- `deployments`: 실행중인 모든 deployment들에 대한 출력을 함
- `svc`: 실행중인 모든 service에 대한 출력을 함
- `pvs`: 생성된 모든 Persistent Volume들에 대한 출력을 함
- `pvcs`: 생성된 모든 Persistent Volume Claime들에 대한 출력을 함
- 기타

명령행 인자로 다음을 사용할 수 있다:
- `-n` 또는 `--namespace`: 특정 Namespace에 해당하는 내용을 조회
- `-o` 또는 `--output`: 출력 포멧을 변경한다. `wide`, `yaml`, `json`으로 출력할 수 있다.
- 기타

#### Examples
```
$ kubectl get nodes
```
연결된 모든 node들을 확인한다.
```
$ kubectl get svc -o wide -n kube-system
```
Namespace가 `kube-system`으로 정의된 모든 service에 대한 내용을 자세하게 출력한다.

### delete
특정 리소스를 삭제한다. 자세한 내용은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#delete)에서 확인할 수 있으며, 이중 자주 사용하는 내용들을 추려보았다. 사용 가능한 리소스는 다음과 같다:
- `pod`: 실행중인 pod를 삭제. 만일 Deployment로 pod를 생성한 경우, deployment의 특성상 새로 pod를 생성한다.
- `deployment`: 실행중인 deployment를 삭제. Deployment가 삭제되는 경우, 해당 deployment가 생성한 pod도 자동으로 삭제가 된다.
- `svc`: 실행중인 service를 삭제
- `pv`: 생성된 Persistent Volume를 삭제
- `pvc`: 생성된 Persistent Volume Claime를 삭제
- 기타

명령행 인자로 다음을 사용할 수 있다:
- `-n` 또는 `--namespace`: 특정 Namespace에 해당하는 내용을 조회
- 기타

#### Examples
```
$ kubectl delete pod test-pod
```
`test-pod`라는 이름을 가진 pod를 삭제한다.
### apply
파일 또는 stdin으로 정의된 설정을 적용한다. 사용 가능한 명령행 인자는 다음과 같다:
- `-f`: 특정 file을 적용한다. 예를 들어, 작성한 `.yaml` 파일을 적용하는 경우 사용
- 기타

#### Examples
```bash
$ kubectl apply -f calico.yaml
```
`calico.yaml`로 정의된 Calico CNI의 내용을 적용한다
```bash
$ cat <<EOF | kubectl apply -f -
apiVersion: v1
kind: Pod
metadata:
  name: busybox-sleep
spec:
  containers:
  - name: busybox
    image: busybox:1.28
    args:
    - sleep
    - "1000000"
---
apiVersion: v1
kind: Pod
metadata:
  name: busybox-sleep-less
spec:
  containers:
  - name: busybox
    image: busybox:1.28
    args:
    - sleep
    - "1000"
EOF
```
stdin으로 정의한 `.yaml` 내용을 바로 `apply` 한다.
### edit
실행중인 리소스에 대한 설정을 변경한다. 최초 기본값으로 설정된 텍스트 에디터로 설정할 수 있게 된다. (`vim` 또는 `nano` 텍스트 에디터가 열리면서 수정할 내용이 나타난다)
#### Examples
```
$ kubectl edit test-pod 
```
`test-pod`라는 이름을 가진 pod에 대한 설정을 변경한다.
```
$ kubectl edit test-svc
```
`test-svc`라는 이름을 가진 service에 대한 설정을 변경한다.
> 만일 옳지 못한 설정을 변경하거나, 실행중일 때 설정을 변경하지 못하는 내용을 변경한 경우, `edit`이 정상적으로 수행되지 않는다.

### exec
실행중인 Pod에 특정 명령어를 실행한다. Docker의 `exec` 명령어와 비슷한 역할을 한다. 명령행 인자 `-it` 등의 기능이 Docker의 명령어와 비슷하게 동작한다. 자세한 명령행 인자에 대한 설명은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#exec)를 확인하면 된다.


#### Examples
예를 들어 `test-ubuntu`에서 `ubuntu` 이미지를 실행하는 경우
```
$ kubectl exec -it test-ubuntu /bin/bash
```
`test-ubuntu`의 `/bin/bash` 명령어를 실행하고, TTY와 stdin을 사용한다.

```
$ kubectl exec -it test-ubuntu ls
```
`test-ubuntu`의 `ls` 명령어를 실행하고, TTY와 stdin을 사용한다.

### top
실행중인 리소스에 대한 자원 사용량을 출력한다. Linux의 `top` 명령어와 비슷한 내용이다. 사용할 수 있는 리소스는 다음과 같다:
- `nodes`: 연결된 모든 node들에 대한 출력을 함
- `pods`: 실행중인 모든 pod들에 대한 출력을 함
- `deployments`: 실행중인 모든 deployment들에 대한 출력을 함
- `svc`: 실행중인 모든 service에 대한 출력을 함
- `pvs`: 생성된 모든 Persistent Volume들에 대한 출력을 함
- `pvcs`: 생성된 모든 Persistent Volume Claime들에 대한 출력을 함
- 기타


#### Examples
```
$ kubectl top nodes
```
모든 node 들에 대한 자원 사용량을 출력한다
```
$ kubectl top pods
```
모든 pod 들에 대한 자원 사용량을 출력한다.

### describe
실행중인 리소스에 대한 자세한 내용을 출력한다. `get -o wide`로 나타나지 않는 자세한 정보를 조회할 수 있다 (자원 사용, 사용하는 pv 등에 대한 자세한 내용 포함). 자세한 명령행 인자에 대한 설명은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#describe)에서 확인할 수 있다.

#### Examples
```
$ kubectl describe test-ubuntu
```
`test-ubuntu`라는 pod에 대한 자세한 설명을 조회한다.
```
$ kubectl describe test-svc
```
`test-svc`라는 service에 대한 자세한 내용을 조회한다.

### cordon
특정 노드에 대해 앞으로 추가적인 pod 스케쥴링을 불가능하게 설정한다. 명령행 인자에 대한 설명은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#cordon)에서 확인할 수 있다.

#### Example
```
$ kubectl cordon node-1
```
`node-1`이라는 node를 더이상 스케쥴링 불가능하게 설정한다. 

### uncordon
특정 노드에 대해 앞으로 추가적인 pod 스케쥴링을 가능하게 설정한다. 명령행 인자에 대한 설명은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#uncordon)에서 확인할 수 있다.

#### Example
```
$ kubectl uncordon node-1
```
`node-1`이라는 node를 이제부터 스케쥴링 가능하게 설정한다


### drain
특정 노드에 대해 앞으로 추가적인 pod 스케쥴링을 진행하고, 해당 node에서 동작중인 모든 pod를 mirror한다. 이후 해당 node에서 동작중인 pod들을 삭제한다. 자세한 명령행 인자에 대한 설명은 [여기](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#drain)에서 확인할 수 있다.

#### Example
```
$ kubectl drain node-1
```
`node-1`이라는 node의 모든 pod를 빼고 그리고 앞으로 스케쥴링 불가능하게 설정한다.
