# Kubernetes 간단 이론
## Kubernetes
- 컨테이너화된 애플리케이션의 자동 디플로이, 스케일링 등의 다양한 기능을 제공하는 오케스트레이션(orchestration) 시스템
- 로드 밸런싱, 스토리지 관리, 자동 rollout과 rollback, 자가 치유, 인증 키 및 설정 관리 그리고 자원 활용 등의 기능을 지원함
- 오픈소스이며 Go 언어로 작성되어있음
- 줄여서 K8s 라고도 불림

## Terms
Kubernetes에는 매우 많은 용어들이 존재하는데, 이 중 자주 사용하는 용어들에 대해서 정리하였다. 모든 용어의 목록은 [여기](https://kubernetes.io/docs/reference/glossary/)에서 확인할 수 있다. 

### Tool
Kubernetes에서 사용되는 도구 관련된 용어
> 명령어는 다음에 다시 언급하도록 하겠습니다

- **cgroup**: Linux 커널 기능 중 특정 프로세스에서 사용할 수 있는 자원을 관리하는 기능. Kubernetes의 경우 cgroup을 통해서 리소스를 설정함
- **Helm Chart**: 사전에 설정된 Kubernetes 리소스 패키지를 의미
- **kubeadm**: Kubernetes를 설치하고, 클러스터를 구축할 때 사용하는 도구
- **kubectl**: Kubernetes의 CLI 도구 (이후 가장 많이 사용할 도구)
- **kubelet**: 클러스터의 각 node에서 동작하는 agent. 각 Pod에서 모든 container들이 잘 동작하는지에 대해서 확인함
- **kube-proxy**: Kubernetes 클러스터에 있는 node에서 동작하는 네트워크 프록시

### Fundamental
- **Container**: 소프트웨어와 모든 의존 프로그램들을 다 가지고 있는 실행 가능한 이미지. Kubernetes에서는 Docker, containerd 등의 컨테이너를 사용할 수 있음.
- **Node**: Kubernetes 클러스터에서 있는 worker 컴퓨터들을 의미
- **Pod**: Kubernetes의 가장 간단하고 작은 개체. 한개의 Pod에서는 하나 또는 그 이상의 container를 가질 수 있음
- **Service**: 한개 또는 그 이상의 Pod를 하나의 네트워크 서비스로 노출 시키는 추상적인 방법
- **Ingress**: 클러스터의 service에 외부 접근을 허용할 수 있도록 관리하는 API를 의미. 주로 HTTP를 많이 사용
- **Deployment**: 복제된 application을 관리하는 API 
- **ReplicaSet**: Pod만 단독으로 만들 시, Pod에 문제가 생기는 경우 자동으로 복구되지 않음. ReplicaSet은 설정된 갯수의 Pod가 클러스터에서 실행중이도록 "보장" 하는 역할을 함
- **Volume**: 하나의 Pod 에서 접근 가능한 데이터를 포함하는 디렉토리. Persistent Volume, Storage Class 등의 다양한 volume들이 존재함
- **ConfigMap**: non-credential한 데이터를 key-value 쌍으로 저장할 때 사용하는 API 객체. Pod에서는 ConfigMap을 환경 변수 등으로 받아서 사용할 수 있음
- **Secret**: 민감한 정보들을 저장하는 객체 (예를 들면 OAuth 토큰, SSH Key, 비밀번호 등)
- **Resource Quotas**: 하나의 Namespace에서 사용할 수 있는 자원의 양을 설정함. Pod, Deployment, Service, Node 단위로 자원의 제한을 걸 수 있음. 
