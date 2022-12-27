
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
  
  
