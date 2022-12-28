# IPv6 Addressing

### Introduction

- IPv6 주소는 128bit이다 (IPv4의 4배)
- 콜론 hexadecimal notation을 사용한다.
- IPv6에서는 목적지 주소는 세가지 카테고리에 속할수 있다.
    - Unicast Address
        - Unicast address는 단일 인터페이스를 식별한다.
    - Multicast Address
        - Multicast Address는 같은 데이터를 특정 그룹에 보내주어야 할 때 사용되는 방식이다.
        - 송신자는 한 채널에 자신의 데이터를 보내고 수신자는 그 데이터중 자신이 조인한 채널만을 수신한다.
        - UDP방식을 사용
    - Anicast Address
        - Anicast Address는 가장 가까운 노드와 통신하는 방식이다.
        - 송신 노드가 네트워크에 연결된 수신 가능한 노드 중에서 한 노드에만 데이터를 전송한다.
        - Anicast Address의 이용 목적
            - 트래픽 부하 분산
            - 네트워크 이중화
            - DDos 공격에 대한 방지
            - 응답시간 감소

### Address Space Allocation

![Untitled](IPv6%20Addressing%2007328db4a8ec45b4b07a0ca931d8ad75/Untitled.png)

- 주소 공간의 일부만 글로벌 유니캐스트 통신에 사용될 수 있다.
- IPv4 호환 주소
    - 0000000을 사용하는 주소는 reserved 되어 있지만, 일부는 IPv4 주소를 호환하는데 사용한다.
    - CIDR 표기법에서 이 블록은 0000::/8로 정의 가능하다
    - 미지정 주소
        - 전체 주소가 0으로 구성됨
        - 부트스트랩 동안 호스트가 자신의 주소를 모를 때와 자신의 주소를 알기 위해 문의를 보낼 때  사용된다.
    - 루프백 주소
        - 호스트가 네트워크에 들어가지 않고 자신을 테스트 하기 위해 사용되는 주소
        - 끝에 1개의 비트가 1
    - 내장된 IPv4 주소
        - 호환 주소
            - 96비트의 0과 32비트의 IPv4주소로 이루어진다
        - 매핑된 주소
            - 80비트의 0과 16비트의 1, 32비트의 IPv4주소로 이루어진다.
- Global Unicast Block(001)
    - 인터넷에서 호스트의 유니캐스트를 위한 메인 블록
    - (2000:: ~ 3FFF:: /3)
- Unique Local Unicast Block(1111 110)
    - 사설 IP주소
    - (FC00::/7)
- Link Local Block(1111 1110 10)
    - 동일 네트워크 내부에서만 유일하게 사용하는 IP주소
    - (FE80::/64)
- Multicast Block (1111 1111)
    - 하나를 대신하여 호스트들의 그룹을 정의할 때 사용하는 주소

### Autoconfiguration

- IPv6에서 DHCP 는 여전히 호스트에 IPv6 주소를 할당할 때 사용하지만 , 호스트가 자체적으로 구성할 수 있다.

### Renumbering

- 사이트가 서비스 공급자를 변경할 수 있도록 하기 위해, address prefix의 renumbering이 IPv6 Addressing에 내장되었다.
- 사이트와 연결된 라우터는 새로운 prefix를 알릴 수 있고, 이전 prefix를 비활성화 하기전에 사이트가 사용하게 할 수 있다.