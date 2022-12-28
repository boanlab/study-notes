
## Transport-Layer Services
- Transport-Layer는 애플리케이션 계층에 서비스를 제공하는 역할을 수행한다.
- 네트워크 계층으로부터 서비스를 받는다.

### Process to Process Communication
<img width="537" alt="image" src="https://user-images.githubusercontent.com/110087065/209857074-d2a290df-d716-403a-bfcb-b9c1dd77fecc.png">
- 전송 계층 프로토콜은 프로세스 대 프로세스 통신 제공
- 메시지를 적절한 프로세스로 전달


### Addressing : Port Numbers

- 프로세스를 정의하기 위하 방법
  - 상위계층에서 제공하는 주소지정방식 - 포트번호 3가지
 - 포트 번호 범위는 0 ~ 65535 사이의 정수
 - 특정 호스트 내 하나의 프로세스를 정의하는 식별자
 
 - ICANN 범위
  - well-known ports: 0 ~ 1023, ICANN에 의해 배정되고 제어
  - registered ports: 1024 ~ 49151, ICANN에 의해 배정되고 제어되지 않음.
  - dynamic ports: 49152 ~ 65535, 제어되거나 등록되지 않음


### Encapsulation and Decapsulation
<img width="708" alt="image" src="https://user-images.githubusercontent.com/110087065/209858285-e2d3535f-0028-44d4-b1f9-2a4823c32709.png">

- Encapsulation<br/>
  - 헤더에 전송 정보를 붙여나가는 것
  
- Decapsulation
  - 수신측에서 최초로 보낸 데이터 형탤 데이터를 풀어내는 것

- trailer
  - 데이터를 전달할 때 데이터의 꼬리에 추가하는 정보
  

### Multiplexing and Demultiplexing

- 소켓
  - 네트워크에서 프로세스로 데이터를 전달하고 프로세스로부터 네트워크로 데이터를 전달하는 출입구
  - 데이터 송수신에 사용
  
- 다중화
  - 여러 소켓으로부터 데이터를 모아 캡슐화
  - 송신측 전송계층에서 수행
  
- 역다중화
  - 수신된 패킷을 해당된 소켓을 전달
  - 수신측 전송계층에 수행
  
### Flow Control
- 흐름 제어
  - 송신과 수신 측의 데이터 처리속도의 차이를 해소하기 위해 사용
  - 하나의 엔티티가 정보를 생성하고 다른 엔티티가 정보를 소비할 때 생성율과 소비율 간에 균형이 이루어져야 함
  
- Pushing
  - 소비자의 요구 없이 정보가 생성될 때마다 전송측에서 정보를 전달
  
- Pulling
  - 소비자가 요구하 경우에만 정보를 전달
  
- Buffer
  - 패킷을 저장할 수 있는 일련의 메모리 영역
  - 수신 전송 계층의 버퍼가 가득 차면 수신 전송 계층으 패킷의 전송을 멈추도록 송신 전송 계층에 알림
  - 버퍼에 빈 공간이 생기면 확인응답을 보내 메시지를 다시 전송해도 된다고 알림
  
  

## TCP/UDP (Transmission Control Protocol / User Datagram Protocol)
- TCP와 UDP는 TCP/IP의 Transport layer에서 사용되는 프로토콜이다.

### TCP
- TCP는 전송 계층에서 사용하는 프로토콜로 장치들 간에 논리적인 접속을 성립하기 위하여 연결을 설정하여 신뢰성을 보장하는 연결형 서비스이다.
- TCP는 네트워크에 연결된 컴퓨터에서 실행되는 프로그램 간에 데이터, 메시지, 세그먼트 등을 안정적, 순차적, 결함 없이 교환 가능하게 한다.

### TCP 특징
- 연결형 서비스
  - 연결형 서비스로 가상 회선 방식을 제공한다.
  - 3-way handshaking 과정으로 연결 설정
  - 4-way handshaking 과정으로 연결 해제

- 흐름 제어
  - 데이터 처리 속도를 조절하여 수신자의 버퍼 오버플로우를 방지
  
- 신뢰성이 높은 전송
  - Dupack-based retransmission
    - 정상적인 상황에서는 ACK 값이 연속적으로 전송되어야 한다.
    - ACK 값이 중복을 올 경우 패킷 이상을 감지하고 재전송을 요청한다.
  - Timeout-based retransmission
    - 일정시간동안 ACK 값 수신을 못할 경우 재전송을 요청한다.

- Full-Duplex, Point to Point
  - 전이중(Full-Duplex)
    - 전송이 양방향으로 동시에 발생 가능하다.
  - 점대점(Point to Point)
    - 각 연결이 정확히 2개의 종단점을 가지고 있다.
  - 따라서 multicasting, broadcasting을 지원하지 않는다.

### UDP
<img width="279" alt="image" src="https://user-images.githubusercontent.com/110087065/209864120-400211b1-e0d5-489a-8b61-2f52d79f5322.png">
- UDP는 packet이 목적지에 제대로 도착한다는 보장이 없다.<br/>
- UDP는 한번만 전송하고 재전송을 하지 않는다.<br/>
- in-order한 특성을 갖는 TCP와 다르게, UDP는 un-ordered한 특성을 가져 패킷을 보내는 순서를 신경쓰지 않는다.<br/>
- 따라서 신뢰성이 부족한 UDP는 손실이 나도 허용 가능하고 속독 중요한 서비스에 사용된다.<br/>
  - EX) DNS, SNMP, Video Streaming
  
### UDP segment
<img width="206" alt="image" src="https://user-images.githubusercontent.com/110087065/209865060-9247b994-98cd-4d2a-a1f9-9ad71836696f.png">
- 전송 계층의 목적인 프로세스간의 통신을 지원하기 위해 포트번호와 최소한의 정보만 가진다.
- source port: 보내는 곳의 포트번호
- dest port: 받는 곳의 포트번호
- length: UDP segment의 길이
- checksum: UDP segment가 목적지까지 도달하는 과정에서 정보의 변화가 있는 체크하는 항목

### TCP/UDP 정리
<img width="450" alt="image" src="https://user-images.githubusercontent.com/110087065/209862424-91c3871e-547d-41fc-a123-0c1a86ffc976.png">
<img width="600" alt="image" src="https://user-images.githubusercontent.com/110087065/209862792-41ccc551-51aa-419c-b632-9567f062f85b.png">

  
