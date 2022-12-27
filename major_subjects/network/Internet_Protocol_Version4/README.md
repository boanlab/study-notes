
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
  
