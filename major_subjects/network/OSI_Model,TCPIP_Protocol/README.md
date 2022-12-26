- protocol이란
  - 개체간의 데이터 통신을 원할하게 하기 위해 필요한 통신 규약


## 1.  OSI 7 Layer Model

<img width="104" alt="KakaoTalk_Photo_2022-12-26-20-39-05" src="https://user-images.githubusercontent.com/110087065/209544909-9f73237e-5200-4329-b705-9ff8296daa66.png">

- 일반 사용자는 application layer를 통해 데이터의 송수신을 요청하며, 이 요청은 순차적으로 하향 전달되어 physical layer를 통해 상대 호스트에 전송된다.
- 데이터를 수신한 호스트는 송신 호스트와 반대 과정으로 처리된다. Physical layer로 들어온 데이터는 순차적으로 상향 전달되어 application layer로 올라간다. 그리고 처리가 완료된 결과는 다시 순차적으로 하향 전달되어 송신 호스트로 전송된다.

- OSI 7계층 모델의 각 계층별 기능
  - Application layer: 네트워크 리소스에 대한 액세스를 허용하기 위해
  - Presentation layer: 데이터 번역, 암호화 및 압축하기 위해
  - Session layer: 세션을 설정, 관리 및 종료하기 위해
  - Transport layer: 신뢰할 수 있는 프로세스간 메시지 전달 및 오류 복구 제공
  - Network layer: 송신 호스트가 전송한 데이터(패킷)가 목적지 호스트까지 이동하는 internetworking 제공 
  - Datalink layer: hop-to-hop 전달을 제공하기 위해 비트를 프레임으로 구성
  - Physical layer: 기계적, 전기적 특성을 제공하기 위해 매체를 통해 비트를 전송하는 것
  
  
  
## 2.  TCP/IP Protocol Suite

<img width="123" alt="KakaoTalk_Photo_2022-12-26-21-51-45" src="https://user-images.githubusercontent.com/110087065/209551121-85f797d6-d122-4ffb-ba2d-2de5f8091318.png">


- 각 계층별 통신 단위
  - Physical layer에서 통신 단위로 bit를 사용.
  - Data Link layer에서 통신 단위로 frame을 사용.
  - Network layer에서 통신 단위로 datagram을 사용.
  - Transport layer에서 통신 단위는 사용하는 프로토콜에 따라 segment, user datagram, packet을 사용.
  - Application layer에서 통신 단위로 message를 사용.
  
  
  
## 3.  Addressing
  - Data link layer (Frame) -> Physical addresses
  - Network layer (Datagram) -> Logical addresses
  - Transport layer (Segment) -> Port addresses
  - Application layer (Message) -> Application-Specific addresses
