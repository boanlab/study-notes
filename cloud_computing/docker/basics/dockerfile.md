# Dockerfile 작성
## Dockerfile 문법
Dockerfile은 스크립트처럼 실행된다. 따라서 간단한 문법이 존재한다. 자세한 내용은 [여기](https://docs.docker.com/engine/reference/builder/)를 참고하면 된다.
### 기본 규칙
- `#`를 통해 주석처리를 할 수 있다
- `INSTRUCTION arguments`의 형태를 지닌다.

### Keyword
많이 사용되는 키워드에 대해 작성하였다. 자세한 내용은 [여기](https://docs.docker.com/engine/reference/builder/)를 참고하면 된다.
- `FROM`: Base image를 설정한다.
- `RUN`: 특정 명령어를 실행한다. Linux 기반의 이미지라면 `/bin/sh -c`로 실행이 되고, 윈도우 기반의 이미지라면 `cmd /S /C`로 실행이 된다.
- `CMD`: "실행중인" 컨테이너의 기본 명령어를 설정할 때 사용한다. `RUN`과 비슷하게 명령어를 실행하지만, 목적이 다르다.
- `LABEL`: Docker image의 metadata를 설정한다. 예를 들어 버전, 설명 등을 포함할 수 있다. Key-value 쌍으로 표현해야한다.
- `MAINTAINER`: Docker image를 만든 저자의 이름을 적는다.
- `EXPOSE`: 컨테이너에서 특정 포트를 사용한다고 명시한다. 명시된 포트는 `run` 할 시 `-p` 옵션을 통해서 연결할 수 있다.
- `ENV`: 환경 변수를 Key-value 쌍으로 설정한다
- `ENTRYPOINT`: 컨테이너가 하나의 프로그램으로 동작할 수 있게 설정한다. 만일 `CMD` 옵션과 같이 사용될 시, `CMD` 옵션을 override한다.

### Example
- `ubuntu` 패키지를 기반으로
- `apache2` 를 80번 포트에서 동작
- 환경변수 `DEBIAN_FRONTEND=noninteractive`를 설정
- `index.html`의 내용을 `"Hello world from Docker"` 로 설정
- Entrypoint로 apache2를 시작하게 설정

위의 기능을 하는 간단한 Dockerfile을 만들어보면 다음과 같다:
```bash
FROM ubuntu
# Ubuntu를 base image로 사용
MAINTAINER isukim
# 저자 이름 설정
ENV DEBIAN_FRONTEND=noninteractive
# apt-get 등의 과정에서 요청할 수 있는 유저 상호작용을 비활성화
RUN apt-get update -y
# apt-get update 실행
RUN apt-get install -y apache2
#  apache2 설치
RUN echo "Hello world from Docker" > /var/www/html/index.html
# index.html 수정
EXPOSE 80
# 80번 포트를 노출시킨다
ENTRYPOINT service apache2 start && tail -f /dev/null
# Entrypoint로 apache2를 시작한다. tail -f /dev/null을 통해 container가 종료하지 않게 설정
```
## Dockerfile Build
생성한 Dockerfile을 실제적으로 `build` 하여 Docker image로 변환하는 과정이 필요하다. 이때 `docker build` 명령어를 사용하면 된다. `build`는 다양한 명령행 인자를 지원한다. 모든 목록은 [여기](https://docs.docker.com/engine/reference/commandline/build/)에서 확인할 수 있다.

- 현 예시에서는 `-t` 또는 `--tag` 옵션을 통해서 특정 태그를 가진 Docker image를 빌드하는 것을 목표로 한다.

```
$ docker build -t container_name:latest .
```
위의 명령어는 
- `.` 디렉토리의 `Dockerfile`을 읽어서 
- `container_name` 이라는 Docker image를 생성하고
- Tag를 `latest`로 설정한다.

### Example
예를 들어, 위의 예시 Dockerfile을 build 하려면
```
$ docker build -t isukim/test_apache2 .
Sending build context to Docker daemon   2.56kB
Step 1/8 : FROM ubuntu
 ---> 6b7dfa7e8fdb
Step 2/8 : MAINTAINER isu
 ---> Using cache
 ---> 0ee2bed48c6d
Step 3/8 : ENV DEBIAN_FRONTEND=noninteractive
 ---> Using cache
 ---> 2ffc29c3015a
Step 4/8 : RUN apt-get update -y
 ---> Using cache
 ---> f78ebd1bddf0
Step 5/8 : RUN apt-get install -y apache2
 ---> Using cache
 ---> 470b10850fd0
Step 6/8 : RUN echo "Hello world from Docker" > /var/www/html/index.html
 ---> Using cache
 ---> 7d5ddfc3e28f
Step 7/8 : EXPOSE 80
 ---> Using cache
 ---> 0fdf956d02f6
Step 8/8 : ENTRYPOINT service apache2 start && tail -f /dev/null
 ---> Using cache
 ---> 6f8d837dfa20
Successfully built 6f8d837dfa20
Successfully tagged isukim/test_apache2:latest
```
를 활용하면 된다.
> 위의 경우, 이미 한번 `build`가 된 상태라 캐싱이 이루어져서 중간 과정이 생략되어 나타난다. 만일 캐싱이 되지 않은 경우, `apt-get`과 같은 모든 명령어가 수행된다.

생성된 Docker image의 경우, `docker run`을 통해서 Docker container를 실행할 수 있다:
```
$ docker run -d -it -p 1010:80 isu/test_apache2
```
실행된 Docker container가 정상 실행되는지, 다음을 통해 확인할 수 있다:
```
$ curl 0.0.0.0:1010
Hello world from Docker
```
`index.html`에 `"Hello world from Docker"`을 적어놓았으니, 정상적으로 동작함을 확인할 수 있다.

## DockerHub
생성한 Docker image를 DockerHub에 `push` 할 수 있다. `push` 하게 되면, 다른 사람도 나의 Docker image를 `pull` 하여 본인의 환경에서 사용할 수 있게 된다.

### 1. DockerHub Login
DockerHub에 본인의 Docker image를 `push`하기 위해서는 우선 DockerHub에 로그인을 해야 한다. DockerHub에 회원 가입을 하고, 다음의 명령어를 입력하면 된다:
```
$ docker login
Login with your Docker ID to push and pull images from Docker Hub. If you don't have a Docker ID, head over to https://hub.docker.com to create one.
Username: isukim
Password:
WARNING! Your password will be stored unencrypted in /home/gooday2die/.docker/config.json.
Configure a credential helper to remove this warning. See
https://docs.docker.com/engine/reference/commandline/login/#credentials-store

Login Succeeded
```

### 2. DockerHub Push
로그인이 완료된 이후, DockerHub에 `push`할 수 있게 된다.
```
$ docker push isukim/test_apache2:latest
The push refers to repository [docker.io/isukim/test_apache2]
abdb7cd22c0b: Pushed
5f49bab5deeb: Pushed
53c8fd26b162: Pushed
6515074984c6: Mounted from library/ubuntu
latest: digest: sha256:8981df3f7d91cf79a2741a652bfdc4aa9c48191470a6eb9903cb1f80b496740a size: 1160
```

성공적으로 `push`가 완료되었으니, 이제 다른 사람도 해당 이미지를 `pull` 받아 사용할 수 있게 된다.
