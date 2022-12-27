
## Introduction
- Internet Protocol(IP)
  - Network layer에서 TCP/IP 프로토콜이 사용하는 전송 메커니즘.
  
  
## Datagrams
- Network layer의 packets.

- IP = Internet Protocol
  - unreliable, connectionless datagram protocol
  - best-effort delivery service를 제공한다.
  - best-effort란 IP packet이 손상, 손실, 순서 없이 도착 또는 지연될 수 있고, 네트워크 혼잡을 야기할 수 있다.
  
## Format of datagram packet

### IP datagram
<img width="222" alt="image" src="https://user-images.githubusercontent.com/110087065/209644775-0b7c6659-ff34-4da6-952d-fbf4a68e6161.png">

### Header format
<img width="447" alt="image" src="https://user-images.githubusercontent.com/110087065/209644847-15843b34-6877-4d02-a8e1-b6d7d8802223.png">

- Version(VER)
  - IP protocol의 버전을 정의한다.
  - IPv4 = 0100
  - IPv6 = 0110
  
- Header length(HLEN)
  - Datagram Header의 총 길이를 4바이트 단어로 정의합니다.
  - no option의 경우, header length는 20bytes이고 field 값은 5이다.
  - option field가 최대 사이즈인 경우, field 값은 15이다.
  
- Service type
  - packet이 요구하는 서비스들마다 차별화된 서비스를 제공
  
- Total Length
  - IP datagram의 total length(header + data)를 바이트 단위로 정의한다.
  - header length는 20 ~ 60 바이트까지 가능하다.
  - 최대 길이는 65535
  
- Identification
- Flag
- Fragmentation Offset

- Time to Live
  - TTL 값이 0이 되는 경우 Datagram을 삭제한다.
  - 이 값은 두 호스트 사이의 최대 라우터 수의 대략 두배이다.
  - TTL 값이 1인 경우 첫 라우터에 도착할 때 Datagram을 삭제한다.
  
- Protocol
  - IP datagram이 전달되어야 하는 최종 목적지 프로토콜을 정의한다.
  - IP 프로토콜은 서로 다른 상위 프로토콜의 데이터를 다중화 및 역다중화하므로 이 필드의 값은 역다중화 프로세스에 도움이 됩니다.
  
- Source Address
  - 발생지의 IP 주소 정의

- Destination Address
  - 목적지의 IP 주소 정의
  
  
## Fragmentation

### MTU(Maximum Transfer Unit)
- 각 data link 계층 프로토콜에는 고유하 프레임 형식이 있습니다.
- MTU는 데이터 필드의 최대 크기이다.
- datagram이 frame에 캡슐화되면 datagram의 총 크기는 MTU보다 작아야 한다.
- 만일 MTU 사이즈보다 큰 경우 데이터 조각화를 필요 함.

### Fragmentation 관련 Fields
- datagram이 조각화되면 헤더의 필요한 부분을 모든 조각을 복사해야 한다.
- datagram을 분할하는 호스트 또느 라우터에 의해 변경되어야하는 세가지 필드
  - Flag, Fragmentation Offset, Total Length
  
- Flag
<img width="167" alt="image" src="https://user-images.githubusercontent.com/110087065/209651686-7bbff688-46a2-402d-acad-529bdfc8323e.png">
  - D: 조각화 하지 말 것
  - M: 조각화 할 것
  
- Fragmentation Offset
  - 8바이트 단위로 측정된 원본 데이터그램의 데이터 오프셋입니다.
  
  
## IP Package
- Header-Adding Module
  - 목적지 IP 주소오 함께 상위 프로토콜에게 데이터를 받는다.
  - IP 헤더를 추가하여 IP 데이터그램의 데이터를 캡슐화한다.
  
- Processing Module
  - 인터페이스 또는 헤더 추가 모듈로부터 데이터그램을 받는다.
  - 데이터그램이 최종 목적지에 도착하면 패킷이 재조리 모듈로 전송된다.
  - 노드가 라우터인 경우 TTL 값을 1씩 감소한다.
  - TTL 값이 0이 되면 데이터그램을 버리고 ICMP에 알린다.
  - TTL 값이 상수이면 데이터그램을 Forwarding Module로 전송한다.
  
- Fragmentation Module
  - Forwarding Module에게 IP 데이터그램, 다음 목적지(또는 라우터)의 IP주소, 데이터그램이 전송되는 인터페이스 번호를 수신한다.
  - 데이터그램의 길이가 MTU보다 크면 Fragmentation Module은 데이터그램을 조각화한다.
  
- Reassembly Module
  - Processing Module에서 목적지에 도착한 데이터그램 조각을 수신한다.
  - 조각화되지 않은 데이터그램을 조각이 하나만 있는 데이터그램에 속하는 조각으로 간주한다.
  - 조각이 순서대로 도착한다는 보장이 없기 때문에 연관되 연결 목록이 있는 Reassembly Table을 사용한다.
  
- Reassembly Table
<img width="355" alt="image" src="https://user-images.githubusercontent.com/110087065/209653368-01356a35-fee1-404b-84e1-5cda35ff46ca.png">  
  - 정해지 시간 내에 도착하는 모든 조각을 유지 한다.
  

