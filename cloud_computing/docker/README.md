# Docker
## Environment Setup
- Ubuntu (출처: [공식 홈페이지](https://docs.docker.com/engine/install/ubuntu/))
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
이후 `apt-get`으로 `update`를 수행할 수 있도록 Docker 공식 레포지토리를 저장해놓도록 한다.
```bash
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```
`apt-get` 을 `update`한 이후, `docker`관련 패키지들을 설치한다.

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
처럼 Docker `hello-world`이미지가 정상 동작한다면 잘 설치된거라고 볼 수 있다. 여기까지 진행하면 한가지 거슬리는 문제가 생긴다.
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
## Contents
1. 간단한 이론
2. Docker 명령어
3. DockerFile 작성
4. Docker Compose 작성