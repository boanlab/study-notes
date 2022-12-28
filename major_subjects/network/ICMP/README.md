
## ICMP(Internet Control Message Protocol)
- ICMP란 네트워크 내 장치가 데이터 전송과 관련된 오류를 전달하기 위해 사용하는 프로토콜이다.
- ICMP의 가장 주요 책임은 오류 보고이다. 어떤 이유로 인해 패킷을 전달하지 못하면 송신자에게 보고한다.
- ICMP 주요방법은 데이터가 대상에 도달하는지와 도달 시간이 적절한지 확인한다.

### ICMP Packet
<img width="678" alt="image" src="https://user-images.githubusercontent.com/110087065/209844867-dadae7f3-0d45-47ab-9135-429edf07bd52.png">
- 다른 packet들과 다르게 데이터에 ICMP Message가 추가되었다.
- ICMP는 network layer protocol이다.
- 메시지는 하위 계층으로 이동하기 전에 IP 데이터그램 내부에 캡슐화된다.

##ICMP Message
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
  
  
