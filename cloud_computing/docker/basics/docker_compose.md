# Docker Compose
Docker Compose란 여러개의 컨테이너로 이루어진 서비스를 구축, 실행하는 순서를 자동화하고 그리고 모든 관리를 간단하게 하는 도구이다. `.yaml` 파일을 작성해서 사용할 수 있다.
## Docker Compose 문법 
### 기본 규칙
- `#`를 통해 주석처리를 할 수 있다.
- `INSTRUCTION arguments`의 형태를 지닌다.

### Keyword
공식 문서는 [여기](https://docs.docker.com/compose/compose-file/)를 확인하면 자세한 정보를 얻을 수 있다. 이 중 일부 많이 사용하는 목록을 추려서 작성하였다.
- `services`: 제공하는 서비스에 대한 목록을 나열한다.
- `image`: 해당 서비스에서 사용하는 Docker image를 지정한다.
- `command`: 해당 서비스에서 제공하는 `CMD`를 override 하여 기본 명령어를 설정한다.
- `volumes`: 해당 서비스에서 사용할 volume에 대해 정의를 한다. 서비스에서 사용하는 데이터를 특정 디렉토리에 마운트 시킬수도 있다.
- `environment`: 해당 서비스의 환경 변수에 대해서 정의한다.
- `expose`: Docker compose 서비스들 사이에서 expose 할 포트 번호를 정의한다. 공식 문서에 따르면 해당 포트들은 호스트 머신에서 공개되지 않는 것을 권장한다.
- `ports`: Docker container에서 호스트 머신에 노출시킬 포트를 지정한다.

### Example: Wordpress + MariaDB
- CMS 인 Wordpress의 Docker image
- Wordpress에서 데이터를 저장할 DBMS인 MariaDB의 Docker image

위 두가지를 Docker compose를 이용해 한번에 동작하게 한다. 공식 Docker compose 문서는 [여기](https://github.com/docker/awesome-compose/tree/master/official-documentation-samples/wordpress)에서 확인할 수 있다.

```
services:
  db:
    image: mariadb:10.6.4-focal
    # DB를 mariadb 이미지를 통해 사용
    command: '--default-authentication-plugin=mysql_native_password'
    # command 옵션으로 기본 실행할 명령어를 정의
    volumes:
      - db_data:/var/lib/mysql
    # volumes 옵션으로 데이터베이스 저장을 특정 볼륨에 하도록 설정
    restart: always
    # restart 옵션을 추가
    environment:
      - MYSQL_ROOT_PASSWORD=somewordpress
      - MYSQL_DATABASE=wordpress
      - MYSQL_USER=wordpress
      - MYSQL_PASSWORD=wordpress
    # 환경변수 설정
    expose:
      - 3306
      - 33060
    # Compose 내부에서 노출시킬 포트들을 정의 (모두 MySQL 등의 DBMS관련 포트)
  wordpress:
    image: wordpress:latest
    # Wordpress 이미지를 사용해서 웹사이트 운영
    volumes:
      - wp_data:/var/www/html
    # volumes 옵션으로 웹 사이트 데이터를 저장하도록 설정
    ports:
      - 80:80
    restart: always
    environment:
      - WORDPRESS_DB_HOST=db
      - WORDPRESS_DB_USER=wordpress
      - WORDPRESS_DB_PASSWORD=wordpress
      - WORDPRESS_DB_NAME=wordpress
    # 환경변수 설정
volumes:
  db_data:
  wp_data:
```

## Docker Compose Commands
Docker compose에서 사용하는 명령어에 대한 목록이다. 더 많은 명령어들은 [여기](https://docs.docker.com/engine/reference/commandline/)에서 확인할 수 있다.

- `docker compose up`: Docker compose를 통해 컨테이너들 실행 시작
- `docker compose start`: 정지된 컨테이너를 다시 시작
- `docker compose stop`: 실행중인 컨테이너 정지
- `docker compose down`: `stop` 그리고 삭제도 같이 진행
- `docker compose ps`: 실행중인 컨테이너 목록 조회
- `docker compose rm`: 정지된 컨테이너 삭제
- `docker compose exec`: 실행중인 컨테이너에서 명령어 실행


