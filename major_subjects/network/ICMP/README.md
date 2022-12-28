
## ICMPv4(Internet Control Message Protocol Version 4)
- ICMP란 네트워크 내 장치가 데이터 전송과 관련된 오류를 전달하기 위해 사용하는 프로토콜이다.
- ICMP의 가장 주요 책임은 오류 보고이다. 어떤 이유로 인해 패킷을 전달하지 못하면 송신자에게 보고한다.
- ICMP 주요방법은 데이터가 대상에 도달하는지와 도달 시간이 적절한지 확인한다.

### ICMP Packet
<img width="678" alt="image" src="https://user-images.githubusercontent.com/110087065/209844867-dadae7f3-0d45-47ab-9135-429edf07bd52.png">
- 다른 packet들과 다르게 데이터에 ICMP Message가 추가되었다.
- ICMP는 network layer protocol이다.
- 메시지는 하위 계층으로 이동하기 전에 IP 데이터그램 내부에 캡슐화된다.

### ICMP Message
<img width="689" alt="image" src="https://user-images.githubusercontent.com/110087065/209845026-0ebea31a-0bde-4a79-9183-fb39ed337864.png">
- ICMP Message는 크게 Error-reporting messages, query messages로 구분된다.

- Error-reporting messages
  - 오류 보고 메시지는 라우터나 호스트가 IP 패킷을 처리할 때 발생하는 문제를 Original Source에 보고합니다.
  - 오류 검사 및 제어는 ICMP의 역할이 아닌 상위 프로토콜의 역할이다. ICMP는 오류를 단순히 보고만 한다.
  
- query messages
  - 쿼리 메시지는 호스트나 네트워크 관리자가 라우터나 다른 호스트로부터 특정 정보를 얻을 수 있도록 도와줍니다.
  - 호스트는 네트워크에서 라우터를 검색하고 학습할 수 있으며 라우터는 노드가 메시지를 재전송하는데 도움을 준다.

- ICMP 오류 메시지에 대한 중요 사항
  - 첫 번째 조각이 아닌 조각화된 데이터그램에 대한 ICMP 오류 메시지를 생성하지 않는다.
  - 멀티캐스트 주소를 가진 데이터그램에 대한 ICMP 오류 메시지를 생성하지 않는다.
  - loopback address, broadcast address 같은 특수 주소를 가진 데이터그램에 대한 ICMP 오류 메시지를 생성하지 않는다.
  
### 5 types of Error Reporting Messages
1 Destination unreachable
  - 라우터가 데이터그램을 라우팅할 수 없거나 호스트가 데이터그램을 전달할 수 없는 경우
  - 데이터그램은 폐기되고 라우터 또는 호스트는 데이터그램을 시작한 Source host로 Destination unreachable message를 전송한다.
  
2 Source Quench Message
  - 라우터 또는 호스트가 혼잡으로 인해 데이터그램을 버리면 데이터그램을 보낸 사람에게 source quench message르 전송한다.
  - source에 데이터그램이 폐기되었음을 알린다.
  - 경로 어딘가 정체가 있고 소스가 전송 프로세스를 느리게 해야 한다고 알린다.
  - 따라서 source quench message를 받은 source는 정체가 해소될 때 까지 데이터그래 전송 속도르 늦춰야 한다.

3 Time Exceeded Message
  - 라우터가 TTL 값이 0인 데이터그램을 감소시킬 때, 데이터그램을 버리고 Time Exceeded Message를 전송한다.
  - 최종 목적지가 정해진 시간 안에 모든 조각을 받지 못하면 받은 조각을 버리고 Time Exceeded Message를 original source로 전송한다.
  - Time Exceeded Message에서 코드 0은 TTL 필드의 값이 0임을 나타내기 위하여 라우터에서만 사용된다.
  - 코드 1은 대상 호스트에서만 설정 시간 내에 일부 조각이 도착하지 않았음을 표시한다.
  
4 Parameter Problem Message
  - 라우터나 대상 호스트가 데이터그램의 필드에서 모호하거나 누락된 값을 발견하면 데이터그램을 버리고 이 메시지를 보냅니다.
  
5 Redirection Message
  - 호스트는 다른 네트워크로 향하는 데이터그램을 잘못된 라우터로 보낼 수 있다.
  - 이 경우 데이터그램을 수신한 라우터는 데이터그램을 올바른 라우터로 전달하고 Redirection Message를 호스트로 전송한다.


### Query Message
1 Echo request and reply
  - echo request message는 호스트나 라우터에서 전송한다.
  - echo request message를 수신한 호스트나 라우터는 echo reply message를 보낸다.
  - echo request and reply message는 네트워크 관리자가 IP 프로토콜의 작동을 확인하는데 사용할 수 있다.
  - echo request and reply message는 호스트의 도달 가능성을 테스트 할 수 있다. EX)PING
  
2 Timestamp request and reply
  - Timestamp request and reply message는 시간이 동기화되지 않은 경우에도 소스와 대상 시스템간의 왕복 시간을 계산하는데 사용할 수 있습니다.
  - Timestamp request and reply message는 정확한 단방향 시간을 알고 있는 경우, 두 시스템에서 두 시간을 동기화할 수 있습니다.

### Debugging Tools
- 호스트 라우터가 살아 있는지 실행 중 인지 확인할 수 있다.
- 패킷의 경로를 추적할 수 있다.
- ICMP에서 디버깅을 위해 사용하는 두 가지 도구로 Ping, traceroute가 존재한다.

### ICMP Package
- ICMP message의 송수신을 처리하는 방법에 대한 아이디어르 제공하기 위해 두 모듈로 구성된 ICMP Package가 존재한다.
- Input Modulem, Output Module
<img width="546" alt="image" src="https://user-images.githubusercontent.com/110087065/209854368-2c56756b-1c88-4022-a7bc-17a05e9f2fcc.png">


