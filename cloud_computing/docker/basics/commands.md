# Docker 명령어
## Index
- `pull`: DockerHub에서 Docker image 다운로드
- `run`: Docker image 실행
- `exec`: 실행중인 Docker container에 특정 기능을 실행
- `ps`: 실행중인 Docker container 목록 확인
- `kill`: 실행중인 Docker container 중지
- `rm`: 저장된 Docker container를 삭제

## Commands
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

### Run
Docker image를 실제적으로 실행시켜 Docker container를 생성한다. `run`에서 지원하는 수많은 옵션들이 존재하지만, 몇가지만 알아보도록 한다:
- `--detach` , `-d`: Container를 background에서 `run`하며, container의 ID를 반환한다.
- `--env` , `-e`: 환경 변수를 설정한다.
- `--interactive` , `-i`: STDIN을 attach된 상태가 아니여도 계속 열어놓는다. (이 옵션과 후술할 `-t`옵션을 합쳐 `-it` 옵션을 많이 사용하곤 한다)
- `--name`: 컨테이너에 이름을 지어준다. 설정해주지 않으면, Docker에서 랜덤하게 이름을 부여한다.
- `--privileged`: Container를 privileged 모드로 실행한다. 일반 Docker container와는 다르게 호스트 머신의 커널 관련된 내용을 사용할 수 있다.
- `--publish` , `-p`: Container 내부의 특정 port를 호스트 머신의 특정 port와 연결한다.
- `--tty` , `-t`: pseudo-TTY를 할당한다. (이 옵션과 앞서 설명한 `-i`옵션을 합쳐 `-it` 옵션을 많이 사용하곤 한다)
- `--volume` , `-v`: Container에서 사용할 볼륨을 설정해준다. 예를 들어 로컬 머신의 특정 디렉토리를 container의 특정 디렉토리와 연결할 수 있다.

이 외에 많은 명령행 인자가 존재하니, [여기](https://docs.docker.com/engine/reference/commandline/run/)에서 확인할 수 있다.
> 주의: `docker run` 실행 시, Docker container 이름이 나오기 이전까지의 옵션들만 유효하다. 예를 들어 `docker run -it -p 8080:80 ubuntu -p 1234:321` 이라는 명령어를 실행한 경우, `-p 1234:321`은 무시된다.

#### Example 1
- `nginx` 이미지를 실행
- `nginx` 컨테이너의 80번 포트를 로컬 머신의 8080 포트로 연결
- `nginx` 컨테이너의 이름을 `web`으로 설정
- `nginx` 컨테이너의 `/usr/share/nginx/html`를 `~/site-content`로 volume mount
- `nginx` 컨테이너에게 STDIN과 pseudo-TTY 할당

```
docker run -it -d -p 8080:80 --name web -v ~/site-content:/usr/share/nginx/html nginx
```

#### Example 2
- `ubuntu` 이미지를 실행
- `ubuntu` 컨테이너의 22번 포트를 로컬 머신의 9999 포트로 연결
- `ubuntu` 컨테이너를 privileged 모드로 실행
- `ubuntu` 컨테이너에게 STDIN과 pseudo-TTY 할당
- `ubuntu` 컨테이너의 환경변수 중 `FOO`에 `bar` 저장
- `ubuntu` 컨테이너의 이름을 `test_ubuntu`로 설정

```
docker run -it --privileged -p 9999:22 --name test_ubuntu -e FOO=bar ubuntu
```

### Exec
실행중인 Docker container에 특정 명령어 실행.

- `--detach` , `-d`: 명령어를 background 에서 실행한다.
- `--env` , `-e`: 환경 변수를 설정하여 명령어를 실행한다.
- `--interactive` , `-i`: STDIN을 attach된 상태가 아니여도 계속 열어놓는다. (이 옵션과 후술할 `-t`옵션을 합쳐 `-it` 옵션을 많이 사용하곤 한다)
- `--tty` , `-t`: pseudo-TTY를 할당한다. (이 옵션과 앞서 설명한 `-i`옵션을 합쳐 `-it` 옵션을 많이 사용하곤 한다)

이 외에 많은 명령행 인자가 존재하니, [여기](https://docs.docker.com/engine/reference/commandline/exec/)에서 확인할 수 있다.

#### Example 1
`test_ubuntu` Docker container에서 `ls` 실행
```
$ docker exec -it test_ubuntu ls
bin   dev  home  lib32  libx32  mnt  proc  run   srv  tmp  var
boot  etc  lib   lib64  media   opt  root  sbin  sys  usr
```
#### Example 2
`test_ubuntu` Docker image에서 `/bin/bash` 실행
```
$ docker exec -it test_ubuntu /bin/bash
root@981a91f68ed3:/# whoami
root
root@981a91f68ed3:/#
```

### ps
실행중인 Docker container의 목록을 불러온다. Linux로 치면 `ps -ef`와 같은 기능이라고 볼 수 있다.

```
$ docker ps
CONTAINER ID   IMAGE         COMMAND          CREATED         STATUS                 PORTS                                       NAMES
981a91f68ed3   ubuntu        "bash"           5 minutes ago   Up 5 minutes           0.0.0.0:10101->22/tcp, :::10101->22/tcp     test_ubuntu
```
### kill
실행중인 Docker container를 중지한다. Linux로 치면 `kill -9`와 같은 기능이라고 볼 수 있다.

```
$ docker kill test_ubuntu
test_ubuntu
```
### rm
저장된 Docker container를 삭제한다. `kill`로 Docker container를 삭제시, 컨테이너가 동작하는 것은 멈추지만 이름과 같은 데이터는 남아있다. 이런 데이터를 삭제하기 위해 `rm`을 사용하면 된다. Linux로 치면 `rm`과 같은 기능이라고 볼 수 있다.

```
$ docker rm test_ubuntu
test_ubuntu
```