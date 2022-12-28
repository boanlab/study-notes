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

### Packet Format
### Encapsulation
### Operation
### Proxy ARP


## ARP Package
- ARP Package에는 Cache Table, Queues, Output Module, Input Module, Cache-Control Module 다섯 가지 구성요소가 포함되어 있다.

### Cache Table
- 캐시 테이블에 저장된 주소는 다음 몇 분 내에 동일한 수신자를 대상으로 하는 데이터그램에 사용할 수 있습니다.
- Fields in Cache Table
  - 상태: FREE, PENDING(보류), RESOLVED(해결)
  - 하드웨어 유형
### Queues
### Output Module
### Input Module
### Cache-Control Module
