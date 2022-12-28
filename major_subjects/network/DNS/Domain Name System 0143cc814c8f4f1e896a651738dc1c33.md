# Domain Name System

## Need for DNS

- 웹사이트에 접속 할 때 우리는 외우기 어려운 IP 주소 대신 도메인 이름을 사용한다.
- 도메인 이름을 사용했을 때 입력한 도메인을 실제 네트워크상에서 사용하는 IP 주소로 바꾸고 해당 IP 주소로 접속하는 과정이 필요하다.
- 이러한 과정, 전체 시스템을 DNS(도메인 네임 시스템)라고 한다.이러한 시스템은 전세계적으로 약속된 규칙을 공유한다.
- 상위 기관에서 인증된 기관에게 도메인을 생성하거나 IP 주소로 변경할 수 있는 ‘권한’을 부여한다.
- DNS는 이처럼 상위 기관과 하위 기관과 같은 ‘계층 구조’를 가지는 분산 데이터베이스 구조를 가진다.

![Untitled](Domain%20Name%20System%200143cc814c8f4f1e896a651738dc1c33/Untitled.png)

### Name Space

- 이름은 반드시 고유해야 한다.
- Name Space는 flat 또는 hierarchical로 구성할 수 있다.
- Hierarchical Name Space
    - 각 이름은 여러 부분으로 구성된다.
    - ex) Challenger.fhda.edu
- Domain Name Space
    - 루트가 맨 위에 있는 역트리 구조로 이름이 정의된다.

![Untitled](Domain%20Name%20System%200143cc814c8f4f1e896a651738dc1c33/Untitled%201.png)

- Label
    - 트리에 각 노드에는 label이 있다.
    - 노드의 하위 항목이 서로 다른 label을 가져야 한다.
- Domain Name
    - 전체 도메인 이름은 점(.)으로 구분된 일련의 레이블
    
    ![Untitled](Domain%20Name%20System%200143cc814c8f4f1e896a651738dc1c33/Untitled%202.png)
    
    - 노드 전체를 표시하는 것을 FQDN, 부분적으로 노드를 표시한 것을 PQDN이라고 한다.
- Domain
    - Domain은 Domain Name Space의 하위 트리이다.
- Distribution of Name Space
    - Zone
        - 상위 도메인으로부터 위임받은 도메인을 기준으로 하위노드를 생성 관리하는 것을 zone이라고 한다.
    - Root Server
        - 영역이 전체 트리로 구성된 서버
    - Primary Server
        - 권한이 있는 영역에 대한 파일을 저장하는 서버
    - Secondary Server
        - 다른 서버로부터 Zone에 대한 정보를 전송하고 파일을 로컬디스크에 저장하는 서버

### DNS in the Internet

- DNS는 다양한 플랫폼에서 사용할 수 있는 프로토콜이다.
- Generic Domain
    - 일반 동작에 따라 등록된 호스트를 정의한다.
- Country Domain
    - 두 문자 국가 약어를 사용한다.
- Inverse Domain
    - 주소를 이름에 매핑하는데 사용된다.

### Resolution

- 이름을 주소에 매핑하거나 주소를 이름에 매핑하는 것을 이름-주소 resolution이라고 한다.
- Resolver
    - DNS 클라이언트 요청을 네임서버로 전달하고 찾은 정보를 클라이언트에게 제공하는 기능을 수행한다.
- Recursive Resolution
    - 클라이언트는 네임 서버로부터 재귀적 응답을 요청할 수 있다.
- Iterative Resolution
    - 클라이언트가 재귀 응답을 요청하지 않으면 반복적으로 매핑이 수행되어질 수 있다.
- Caching
    - DNS 네임서버가 한번 요청된 DNS 요청을 TTL만큼 메모리에 저장하여 뒀다가, 똑같은 요청에 대해 신속히 처리할 수 있도록 한다