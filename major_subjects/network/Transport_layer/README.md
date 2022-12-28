
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
  
  

## TCP/UDP
- 
  
  
