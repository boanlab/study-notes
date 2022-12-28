## Address Mapping
- 패킷을 호스트나 라우터로 전달하려면 논리적 주소와 물리적 주소의 두가지 주소 지정이 요구된다.
- 논리 주소를 해당 물리 주소에 매핑하거나 그 반대로 매핑할 수 있어야 한다.
- static mapping, dynamic mapping을 이용할 수 있다

### Static Mapping
- 논리적 주소와 물리적 주소를 연결하는 테이블을 생성하는 것
- 이 테이블은 네트워크 각각의 머신에 저장된다.
- 머신은 다른 머신의 논리적 주소를 알고 있지만, 물리적 주소는 알지 못하여 테이블에서 조회 가능하여야 한다.
- Static Mapping은 mapping이 주기적으로 업데이트를 필요로 한다.

### Dynamic Mapping
<img width="366" alt="image" src="https://user-images.githubusercontent.com/110087065/209656082-bd042671-2ea7-4814-ad82-d853f16aa4a6.png">
- 머신이 다른 머신의 논리적(또는 물리적 주소)를 알고 있을 때, 프로토콜을 사용하여 물리적(또는 논리적 주소)를 찾을 수 있다.


## the ARP Protocol
- ARP는 IP 프로토콜에서 논리 주소를 받아 해당하는 물리 주소에 매핑하고 Data link 계층으로 전달합니다.

### ARP 구조
<img width="671" alt="image" src="https://user-images.githubusercontent.com/110087065/209835380-6b018bdf-2b98-439d-a702-d2142f4cbb54.png">
- Hardware Type: 하드웨어 주소의 유형을 나타낸다.<br/>
- Protocol Type: 프로토콜 유형(버전)을 나타낸다.<br/>
- Hardware Address Length: 이더넷 통신일 경우 0x06<br/>
- Protocol Address Length: IPv4일 경우 0x04<br/>
- 그 외 IP주소와 MAC주소를 사용하는 곳들로 구성<br/>

### ARP Packet
<img width="684" alt="image" src="https://user-images.githubusercontent.com/110087065/209835738-44a52cdf-fdc6-43f1-8381-3746fd79de42.png">
- Data 부분에 ARP 구조가 존재한다.
- Destination address, Source address에는 MAC 주소로 존재한다.

### ARP Operation
<img width="691" alt="image" src="https://user-images.githubusercontent.com/110087065/209836108-1e1f8855-e159-4525-951f-e9274c1182a3.png">
- A가 B에게 데이터를 전송하고 싶은데 MAC 주소를 모르는 상황<br/>
- LAN의 모든 컴퓨터에 broadcast로 ARP request를 보낸다.<br/>
- B가 이 패킷을 받고 ARP reply를 보낸다. ARP reply에는 B의 MAC 주소가 존재한다.<br/>
- A는 B의 reply를 받고 ARP Table에 B의 MAC 주소를 저장한다. <br/>

## ARP Package
<img width="678" alt="image" src="https://user-images.githubusercontent.com/110087065/209832471-6a84d6f2-07b2-4a83-b64d-0d794fb8da10.png">
- ARP Package에는 Cache Table, Queues, Output Module, Input Module, Cache-Control Module 다섯 가지 구성요소가 포함되어 있다.

### Cache Table
- 캐시 테이블에 저장된 주소는 다음 몇 분 내에 동일한 수신자를 대상으로 하는 데이터그램에 사용할 수 있습니다.
- Fields in Cache Table
  - 상태: FREE, PENDING(보류), RESOLVED(해결)
  - Hardware type, Protocol type, Hardware length, Protocol length, Interface number, Queue number, Attempts, Time-out, Hardware address, Protocol address

### Queues
- Queue 세트는 ARP가 물리 주소를 확인하려고 시도하는 동안 IP 패킷을 보유합니다. 

### Output Module
- Output Module은 해결됮 않은 패킷을 해당 대기열로 보낸다.
- IP 주소가 들어오면 실행된다.
- 테이블을 보고 들어온 IP 주소가 있는지 확인한다.
  1. IP 주소가 이미 테이블에 있고 상태가 RESOLVED, 즉 이미 MAC 주소까지 알고 있다면 다음 작업 실행
  2. 상태가 PENDING, 즉 ARP request를 보냈지만 아직 응답을 받지 못해 들어온 IP주소의 MAC 주소를 모른다면 패킷을 큐에 넣는다. 
- 테이블에 IP 주소가 없는 상황이라면 상태가 PENDING인 행을 테이블에 하나 추가한다. 이 행에 IP 주소를 기록한 후 MAC 주소를 공란으로 둔다. 이후 큐를 만들어 큐에 패킷을 넣고 ARP 요청을 전송한다.

### Input Module
- Input Module은 대기열에서 패킷을 제거학 확인된 물리 주소와 함께 전송을 위해 데이터 링크 계층으로 보낸다.
- 주로 ARP 페킷이 들어오면 실행된다.
- ARP 테이블에 IP가 존재하면 다음 작업 실행
  1. 상태가 RESOLVED라도 MAC 주소를 갱신한다.
  2. 상태가 PENDING이면 MAC 주소를 갱신하고 상태를 RESOLVED로 바꾼다. 그리고 큐에 있는 패킷을 모두 꺼내 전송한다.
- IP가 존재하지 않으면 테이블에 행을 추가하고 완벽하게 기록한다.
- 패킷이 ARP request라면 ARP reply를 전송한다.

### Cache-Control Module
- Cache-Control Module은 ARP table을 확인하여 갱신하는 모듈이다.
- 주기적으로 실행된다.
- 어떤 행의 상태가 FREE라면 갱신하지 않는다.
- 어떤 행의 상태가 PENDING이라면 다음과 같이 진행한다.
  1. attempt 횟수를 1 늘린다. attempt 횟수가 일정 이상인 경우 상태를 FREE로 바꾸고 큐를 제거한다.
  2. attempt 횟수가 Max보다 적다면 ARP 요청을 다시 보낸다.
- 어떤 행의 상태가 Resolved라면 time-out으 감소시킨다. time-out이 0보다 작아지면 상태를 FREE로 바꾸고 큐를 제거한다.



