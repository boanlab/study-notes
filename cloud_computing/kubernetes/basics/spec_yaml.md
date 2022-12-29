# Kubernetes Spec 작성
Kubernetes의 리소스를 정의하는 `.yaml`로 적힌 spec 파일을 작성하는 법에 대해서 간단하게 알아봅니다. 모든 리소스에 대한 정의 및 자세한 내용은 [여기](https://kubernetes.io/docs/reference/kubernetes-api/workload-resources/)를 확인하면 됩니다.

## 규칙
- `.yaml` 형식의 파일로 작성해야 합니다.

다음의 내용들은 필수적으로 작성해야합니다.
- `apiVersion`: 이 Object를 생성하기 위해 어떤 버전의 Kubernetes API를 사용했는지
- `kind`: 이 Object가 어떤 종류인지
- `metadata`: 이 Object를 명시하는 내용들, 예를 들어 `name`, `uuid`, `namespace` 등
- `spec`: 이 Object가 어떤 state를 필요로 하는지

## Examples
### Pod 
간단한 Pod를 위한 spec에 대한 예시입니다. `nginx:1.14.2`를 실행하는 Pod를 생성하는 `.yaml` 파일입니다. (원본은 [여기](https://kubernetes.io/docs/concepts/workloads/pods/)에서 찾을 수 있습니다)

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx
spec:
  containers:
  - name: nginx
    image: nginx:1.14.2
    ports:
    - containerPort: 80
```
이후
```
$ kubectl apply -f pod.yaml
```
을 통해서 정의한 spec을 적용하여 `nginx` pod를 생성할 수 있습니다.

### Deployment
간단한 Deployment를 위한 spec에 대한 예시입니다. 3개의 `nginx` Pod를 생성하는 Deployment를 실행하는 `.yaml` 파일입니다. (원본은 [여기](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)에서 찾을 수 있습니다)

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deployment
  labels:
    app: nginx
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:1.14.2
        ports:
        - containerPort: 80
```
이후 
```
$ kubectl apply -f deployment.yaml
```
을 통해서 정의한 spec을 적용하여 `nginx` pod를 3개 생성할 수 있습니다.

### Service
간단한 Service를 위한 spec에 대한 예시입니다. `nginx-service`라는 service에 `nginx`라는 이름의 pod를 연결합니다.(원본은 [여기](https://kubernetes.io/docs/concepts/services-networking/service/)에서 찾을 수 있습니다)

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx
  labels:
    app.kubernetes.io/name: proxy
spec:
  containers:
  - name: nginx
    image: nginx:stable
    ports:
      - containerPort: 80
        name: http-web-svc

---
apiVersion: v1
kind: Service
metadata:
  name: nginx-service
spec:
  selector:
    app.kubernetes.io/name: proxy
  ports:
  - name: name-of-service-port
    protocol: TCP
    port: 80
    targetPort: http-web-svc
```
이후
```
$ kubectl apply nginx-svc.yaml
```
을 통해서 service를 적용할 수 있습니다. 위의 service를 적용하면 다음의 절차가 실행됩니다:
1. `nginx`라는 이름의 Pod를 생성하고, `http-web-svc`라는 port에 내부 컨테이너의 80번 포트를 연결합니다.
2. `nginx-service`라는 이름의 service를 생성하고, `http-web-svc`라는 port에 외부 80/tcp 포트를 연결합니다. 이를 통해 외부에서 `nginx` pod에 접근할 수 있게 됩니다.

### Persistent Volume (PV)
간단한 Persistent Volume을 위한 spec에 대한 예시입니다. `task-pv-volume`라는 이름을 가진 Persistent Volume을 생성합니다. 해당 PV의 경우 host의 `/mnt/data`에 연결되게 설정하며, 사용 공간은 10Gi로 제한합니다. (원본은 [여기](https://kubernetes.io/docs/tasks/configure-pod-container/configure-persistent-volume-storage/)에서 찾을 수 있습니다)

```yaml
apiVersion: v1
kind: PersistentVolume
metadata:
  name: task-pv-volume
  labels:
    type: local
spec:
  storageClassName: manual
  capacity:
    storage: 10Gi
  accessModes:
    - ReadWriteOnce
  hostPath:
    path: "/mnt/data"
```
이후
```
$ kubectl apply pv-test.yaml
```
을 통해서 `task-pv-volume`을 생성할 수 있습니다. 생성된 PV의 경우, 이후 Persistent Volume Claim을 통해 사용할 수 있습니다.

## Summary
이 외에도 다양한 spec을 통해 `.yaml` 파일을 작성할 수 있습니다. 작성한 `.yaml`파일을 `kubectl apply -f`를 통하여 Kubernetes에 적용하면 이후에 사용이 가능합니다.