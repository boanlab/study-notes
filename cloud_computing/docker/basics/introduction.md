# Docker Background
## Container
- 어떤 환경에서나 실행하기 위해서 필요한 모든 요소를 포함하는 소프트웨어 패키지
- 여러개의 container들이 한개의 물리적 머신에서 동작할 수 있으며 OS Kernel을 공유함
- Virtual machine (VM)에 비해 가볍다는 장점이 있음
- VM은 hardware의 virtualization을 제공하지만, container는 OS의 virtualization을 제공

## Docker
- Container 기술중에서 가장 많이 사용되는 De facto 중 하나
- 기타 친구들은 `containerd`, `lxc` 등이 있음 
- https://hub.docker.com/ 에서 다른 사람이 만든 Docker 이미지를 다운 받아서 사용하거나 또는 본인이 만든 Docker 이미지를 업로드 하여 다른 사람에게 공유하는 것도 가능
- 각 Docker container image들이 Docker Engine 위에서 돌아감
- Go 언어로 작성이 됨

## Terms
[Docker Docs](https://docs.docker.com/glossary/)에서 나온 자주 쓰이는 용어들의 일부
- **Base Image**: `Dockerfile`에 작성된 부모 이미지가 없는 이미지
- **Build**: 작성한 `Dockerfile`의 내용을 바탕으로, Docker 이미지를 생성하는 것
- **Compose**: 여러개의 Docker 이미지 등을 사용하여 복잡한 Docker 응용 프로그램을 만드는 도구 (Docker Compose라고도 알려짐)
- **Container Image**: 한 Docker container의 기저(basis)
- **Comtainer**: 한 Docker image의 실행 단위
- **Docker Hub**: Docker image를 업로드 또는 다운로드 및 타인들과 공유할 수 있는 온라인 서비스
- **Dockerfile**: Docker image를 build 하기 위해 실행해야하는 명령어를 모아놓은 텍스트 파일
- **Swarm**: 하나 또는 그 이상의 Docker Engine들이 묶여있는 클러스터. Swarm mode를 통해서 클러스터의 관리 및 오케스트레이션 기능을 사용할 수 있음
