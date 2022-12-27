# Docker

## Index
1. Background
2. Installation
3. Commands

## Background
![](https://velog.velcdn.com/images/isukim/post/95362d5a-17ea-4430-9d34-63f9e99b0a2f/image.png)
사진 출처: https://www.docker.com/resources/what-container/ 

### Container
- 어떤 환경에서나 실행하기 위해서 필요한 모든 요소를 포함하는 소프트웨어 패키지
> "어떤 환경" 이라고 하긴 했지만, 사실 ARM, AMD64 등의 환경에서는 다르게 동작하고 다르게 컴파일 해줘야 하기 때문에 약간 다르긴 하지만 뭐...
- 여러개의 container들이 한개의 물리적 머신에서 동작할 수 있으며 OS Kernel을 공유함
> 개인 경험상, OS Kernel을 공유한다는 측면이 container의 장점이면서 동시에 단점이라고 생각한다... 이 얘기는 나중에 자세히 얘기하도록 하겠습니다.

- Virtual machine (VM)에 비해 가볍다는 장점이 있음
> 이것 또한 논란이 조금 될 수 있는 발언이긴 한게, 최근 VM의 경우 container처럼 가볍게 생기는 경우도 많다. 뿐만 아니라 최근 일부 Docker container의 경우 상당히 무거운 친구들도 많긴 하다.

- VM은 hardware의 virtualization을 제공하지만, container는 OS의 virtualization을 제공

### Docker
- Container 기술중에서 가장 많이 사용되는 De facto 중 하나
- 기타 친구들은 `containerd`, `lxc` 등이 있음 
- https://hub.docker.com/ 에서 다른 사람이 만든 Docker 이미지를 다운 받아서 사용하거나 또는 본인이 만든 Docker 이미지를 업로드 하여 다른 사람에게 공유하는 것도 가능
- 각 Docker container image들이 Docker Engine 위에서 돌아감
- Go 언어로 작성이 됨
- 자세한 이론적 내용들은 나도 모르기에 생략

## Installation
Docker Image를 다운받고 이를 돌리기 위해서는 Docker Engine이 필요하다. amd64 Ubuntu 22.04 기준으로 작성되었으며, 자세한 내용은 [공식 홈페이지](https://docs.docker.com/engine/install/ubuntu/)를 참고하면 좋을 것이다. 

### Warning
```bash
sudo apt-get install docker
```
라고 생각할 수 있는 사람 있는데, 이렇게 설치하는거 아니다...
### Docker Install
```bash
 sudo apt-get remove docker docker-engine docker.io containerd runc
```
혹시 남아있을지 모르는 기존 버전을 삭제하자.

```bash
sudo apt-get update
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
```
필요한 패키지들을 설치하자.
```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```
Docker의 공식 GPG 키를 등록하자.
```bash
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```
이후 `apt-get`으로 업데이트할 수 있도록 Docker 공식 레포지토리를 저장해놓도록 한다.
```bash
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```
`apt-get` 을 `update`한 이후, `docker`관련 프로그램들을 설치한다.
> 위의 GPG키 등록 및 레포지토리 등록 안하고 바로 실행시 정상 동작 하지 않는다. 

```bash
sudo docker run hello-world
```
`docker`가 정상적으로 사용 가능한지 테스트해보자.
```
Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/
```
처럼 Docker `hello-world`이미지가 정상 동작한다면 잘 설치된거라고 볼 수 있다.

### Docker Setup
여기까지 진행하면 한가지 거슬리는 문제가 생긴다.
```bash
sudo docker run hello-world
```
는 동작하지만
```
docker run hello-world
```
는 권한 관련 문제로 동작하지 않는다. [여기](https://stackoverflow.com/questions/48957195/how-to-fix-docker-got-permission-denied-issue)에 따르면 이를 해결하는 방안이 존재한다. 
```bash
sudo groupadd docker
sudo usermod -aG docker $USER
newgrp docker
```
이제 `sudo` 없이도 `docker` 명령어를 사용할 수 있다.


## Commands
기초적인 Docker 명령어들에 대해서 알아보자. `>`, `<<` 이런 redirection 또는 어려운 one-liner 명령어들은 다음시간에(?) 알아보도록 하자. 이번 시간에 알아볼 명령어는 다음과 같다.
- `pull`: DockerHub에서 Docker image 다운로드
- `run`: Docker image 실행
- `kill`: 실행중인 Docker container 중지
- `ps`: 실행중인 Docker container 목록 확인

### Pull
Docker image의 경우 타인과 공유할 수 있다. 이런 공유하는 파일들은 DockerHub에 올라가게 되며, `pull`이라는 명령어를 통해 DockerHub에 올라간 Docker image를 다운받아 사용할 수 있다. 예를 들어, `ubuntu` 이미지를 다운받아보도록 하자. 
```
$ docker pull ubuntu
Using default tag: latest
latest: Pulling from library/ubuntu
6e3729cf69e0: Pull complete
Digest: sha256:27cb6e6ccef575a4698b66f5de06c7ecd61589132d5a91d098f7f3f9285415a9
Status: Downloaded newer image for ubuntu:latest
docker.io/library/ubuntu:latest

```
이렇게 이미지 이름만 적는 경우, 자동으로 `latest` 버전의 Docker image를 `pull` 한다. 만약 특정 버전을 원하는 경우, `NAME:TAG`으로 설정을 할 수 있다. 만일 `ubuntu`이미지의 22.04 버전이 아닌, 16.04 버전을 원한다면, 다음처럼 해보자.
```
$ docker pull ubuntu:16.04
58690f9b18fc: Pull complete
b51569e7c507: Pull complete
da8ef40b9eca: Pull complete
fb15d46c38dc: Pull complete
Digest: sha256:1f1a2d56de1d604801a9671f301190704c25d604a416f59e03c04f5c6ffee0d6
Status: Downloaded newer image for ubuntu:16.04
docker.io/library/ubuntu:16.04
```
요약하자면, 
```
docker pull name:tag
```
를 통해, 특정 Docker image의 tag에 해당하는 Docker image를 `pull` 할 수 있다. 
> 현재 `pull`만 한 상태에서는 Docker container가 동작하지 않는다! 이를 실행하기 위해서는 `run`을 해주어야 한다. 약간 `.exe`파일 다운 받아놓고, 더블클릭 하기 직전의 느낌이라고 생각하면 된다.



