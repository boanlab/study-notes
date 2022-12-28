# IPv6 Protocol

## Introduction

- IPv4에서 IPv6로의 변경 이유
    - 가장 큰 이유는 IPv4의 주소 공간 부족 문제이다.
    - 다른 이유
        - 일부  불필요한 처리로 인한 프로세스 속도 저하 문제
        - 새로운 옵션의 필요성
        - 멀티미디어 지원
        - 보안에 대한 필요
- IPv6 주요 변경 사항
    - 거대한 주소 공간
    - 향상된 헤더 형식
    - 새로운 옵션들
    - 확장 허용
    - 자원 할당 지원
    - 보안 지원

## Packet Format

![Untitled](IPv6%20Protocol%208006606c603a4c57a00903de0be1bfac/Untitled.png)

- 각 패킷은 Base header와 Payload로 구성된다.
- payload는 선택적 확장 헤더와 상위 계층으로부터의 데이터로 구성된다
- base header는 40byte를 차지하지만 확장 헤더와 상위 계층 데이터는 최대 65535 바이트의 정보를 포함한다

![Untitled](IPv6%20Protocol%208006606c603a4c57a00903de0be1bfac/Untitled%201.png)

### Base Header

- Version
    - IP의 버전 번호를 정의한다 (IPv6 = 6)
- Traffic Class
    - 전달 요구사항이 다른 여러 Payload를 구분하는데 사용된다
- Flow label
    - IPv6를 연결 지향 프로토콜로 사용할 수 있도록 처리한다.
    - Flow label handling을 지원하는 라우터는 flow label table을 가지고 있다
    - 동일 흐름에 속하는 모든 IPv6 패킷들은 동일 자원,목적지,우선권,옵션을 갖게 된다.
- Payload length
    - base header를 제외한 IP 데이터그램의 길이를 정의한다
- Next header
    - base header 뒤에 오는 헤더를 정의한다.
    - IP에 의해 사용되는 선택적 확장 헤더 또는 UDP,TCP같은 캡슐화된 패킷의 헤더이다.
- Hop limit
    - TTL필드와 동일한 용도로 사용된다
- Source address
    - 데이터그램의 원래 소스를 식별하는 인터넷 주소이다
- destination address
    - 데이터그램의 최종 목적지를 식별하는 인터넷 주소이다
    - 그러나 소스 라우팅이 사용되었다면 이 필드는 다음 라우터의 주소를 포함한다
- Extension Headers
    - base header의 길이는 40바이트로 고정이지만, IP데이터그램에 기능적으로 더 필요할 때, base header는 6개까지 확장 헤더를 가질수 있다
    - 확장 헤더 종류
        - Hop by hop
            - 패킷이 이동하는 경로에 있는 라우터들이 검사해야 하는 옵션에 대한 정보를 전달할 때 사용한다
        - Destination
            - 패킷의 전송 대상에서 처리해야 할 옵션을 표시한다
        - Source routing
            - 패킷이 특정 노드를 거쳐 가도록 조정할 필요가 있을 때 사용한다
        - Fragmentation option
            - MTU보다 큰 패킷을 전송하기 위해 패킷을 분할하고 재조립할 때 사용한다
        - Authentication
            - 네트워크 보안에서 인가된 사용자에게만 접근 또는 변경을 허용해 패킷의 무결성을 보장하고 출처를 제공한다
        - ESP
            - 패킷의 데이터 기밀 유지와 인증 및 무결성 서비스를 제공한다

## Transition to IPv6

- IPv6로의 전환을 돕기 위한 3가지 전략
    - Dual Stack
        - 완전히 버전 6로 이주되기 전까지 모든 호스트들은 Dual Stack을 가지는 것이 권장된다
    - Tunneling
        - IPv6를 사용하는 두 컴퓨터가 서로 통신하고 패킷이 반드시 IPv4를 사용하는 지역을 통과해야 할 때 사용되는 전략이다
        - 이 지역을 통과할 때 패킷은 IPv4 주소를 가지고 있어야 한다
    
    ![Untitled](IPv6%20Protocol%208006606c603a4c57a00903de0be1bfac/Untitled%202.png)
    
    - Header translation
        - 송신자가 IPv6를 쓰길 원하지만, 수신자가 IPv6를 이해하지 못한다면, 패킷이 IPv4형식이어야 수신자가 이해할 수 있으므로 터널링이 작동하지 않는다.
        - 이 경우에 header format이 header translation에 의해 완전히 변경되어야 한다.
        
        ![Untitled](IPv6%20Protocol%208006606c603a4c57a00903de0be1bfac/Untitled%203.png)