## 1. Delivery
- 최종 목적지로의 패킷 전달은 Direct Delivery, Indirect Delivery 두 가지 전달 방법을 사용하여 수행됩니다.

### Direct Delivery
<img width="442" alt="image" src="https://user-images.githubusercontent.com/110087065/209628019-5845fb7c-23b4-42e6-a944-841e94eb58a4.png">
- 같은 네트워크 <br/>
- 물리적 연결 <br/>
- Network 주소가 같으면 같은 block안에 존재한다.<br/>

### Indirect Delivery
<img width="511" alt="image" src="https://user-images.githubusercontent.com/110087065/209628214-c359404e-be9c-4de9-a3e0-7ee8d58e5250.png">
- 위의 그림에서 A에서 목적지 B로 가기 위해 2번의 간접 전달과 1번의 직접 전달이 이루어진다.


## 2. Forwarding
- Forwarding은 packet을 목적지까지의 경로에 배치하는 것을 의미한다.
- Forwarding은 packet을 next hop(목적지 또는 중간 장치)으로 전달하는 것을 의미합니다.

- Routing table
  - Routing table은 IP Network르 통하여 이동하는 packet이 어디로 향하게 될지 결정하는데 사용되는 일련의 규칙으로, 보통 Table 형태로 표현된다.
  - Routing table에는 패킷이 대상을 향한 최상의 경로를 따라 전달하는데 필요한 정보가 포함되어 있다.

### Next-Hop Routing
- Next-Hop Routing에서 Routing table은 next hop의 주소만 보유합니다.
- Routing table의 크기를 줄일 수 있다.

### Network-Specific Routing
- Destination Network의 모든 host 정보 대신, 네트워크 주소를 정의하는 정보만 존재한다.
- Routing table은 1개의 네트워크 정보만 저장하면 되므로 Routing table의 크기를 줄일 수 있다.

### Host-Specific Routing
- 목적지에 대한 host 정보를 저장한다.
- 경로 점검의 경우 사용

### Default Routing
- Routing table에 명시되어 있지 않은 주소에 대한 사용
- Routing table에 모든 정보를 저장할 수 없기 때문에 사용

