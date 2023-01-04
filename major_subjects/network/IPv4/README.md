- ip address란
  -  인터넷에 연결된 각 장치를 식별하기 위해 TCP/IP 프로토콜 제품의 IP 계층에서 사용되는 식별자를 IP 주소라고 한다.

- 인터넷 프로토콜의 4번째 버전 IPv4의 특징
  - IPv4 주소는 32 bits 길이를 가진다.
  - IPv4 주소는 유일한 주소를 가진다.
  - IPv4 주소는 2^32개, 대략 42억개의 주소 공간을 가진다.

- IPv4 표기법
  - IPv4 주소는 0.0.0.0부터 255.255.255.255까지 총 2^32개의 주소로 표현할 수 있다.

## 1. Classful Addressing
  - Classful Addressing은 전체 IP주소를 첫 8bytes의 수에 따라 5개의 클래스로 구분하여 주소를 할당하는 방법이다.
<img width="722" alt="KakaoTalk_Photo_2022-12-26-21-13-31" src="https://user-images.githubusercontent.com/110087065/209547818-219e7d09-a27d-40d1-9582-5d244028a8a0.png">
- class A: 대규모 네트워크 환경에 사용됨.<br/>  
- class B: 중규모 네트워크 환경에 사용됨.<br/>
- class C: 소규모 네트워크 환경에 사용됨.<br/>
- class D: 소규모 네트워크 환경에 사용됨.<br/>
- class E: 향후 다른 목적을 위해 일반적으로 사용하지 않는 클래스.<br/>

### 1-2. Two-Level Addressing
- IP Address는 Netid와 Hostid, 두 영역으로 구분 가능한데, 해당하는 클래스에 따라 영역이 달라진다.
![KakaoTalk_Image_2022-12-26-21-28-23](https://user-images.githubusercontent.com/110087065/209549029-8b37da89-bed6-4f3a-ace3-1c696df52d6d.png)
- 위의 정보로 IP 주소가 주어진 경우 알 수 있는 정보는 주소의 '해당 클래스','주소의 수','시작 주소와 끝 주소'이다.
  - EX) IP 주소 10.100.100.100은 주소가 속한 클래스: A CLASS, 주소 수: 2^24개, 시작 주소:10.0.0.0, 끝 주소: 10.255.255.255
  - 예외 사항으로 시작 주소는 network address, 끝 주소는 broadcast address로 사용하여 할당하지 않는다.
  
### 1-3. Network mask
- network mask address는 network address(시작 주소)를 찾을 때 사용되고, 해당 클래스마다 mask가 다르다.
- mask와 주어진 IP주소를 AND연산하면 network address(시작 주소)를 도출할 수 있다.
<img width="519" alt="KakaoTalk_Image_2022-12-26-22-15-20" src="https://user-images.githubusercontent.com/110087065/209552929-17f32d3d-c7b4-42bc-8020-373d2eca3e04.png">
  - EX) IP 주소 10.100.100.100 주소가 주어진 경우 A class임을 알 수 있고, A class의 mask와 AND 연산하여 10.0.0.0 이라는 network address(시작 주소)를 도출할 수 있다. 
  
### 1-4. Three-Level Addressing
- Subnetting
  - Classful Addressing 방식에서 배정받은 네트워크를 자체적으로 분할하여 주소 체계를 내부적으로 개편하는 방법.
  - 배정받은 네트워크는 Class A, B, C 네트워크 중 하나를 의미한다. (Unicast 주소)
  - 하나의 네트워크에 포함된 호스트들을 여러 그룹으로 묶는 방식이기 때문에, 서브넷팅이 진행되면 본 주소에서 Net-id의 Bit 필드는 늘어나고, Host-id 필드는 줄어들게 된다.
  - Class A, B, C는 각각 X.X.X.X/8, X.X.X.X/16, X.X.X.X/24와 같은 주소 형태를 보이는데, 서브넷팅된 네트워크의 주소는 X.X.X.X/9, X.X.X.X/15, X.X.X.X/19, X.X.X.X/28과 같이 Net-id와 Host-id를 더 이상 Byte 단위로 해석할 수 없게 된다.
  
### 1-5. supernetting
- Subnet과는 반대로 여러 개의 주 네트워크를 축약하는 방법이다.
- Supernetting 방법
  - 각 네트워크의 비트열이 같은 부분까지를 네트워크 부분으로 보고 계산하여 적용한다.


## 2. Classless Addressing
  - IPv4의 약 42억개 주소 공간은 현재 주소 고갈 문제를 일으키고, Classful Addressing의 subnetting과 supernetting은 IPv4의 주소 고갈 문제를 해결할 수 없었고, IPv6라는 장기적인 해결법이 고안되었지만, 단기적인 해결법으로 IPv4의 Classless Addressing을 사용했다.
  
### 2-1. Variable-Length Blocks
- Classless Addressing에서 Prefix는 Network를 정의하고 Suffix는 host를 정의한다.
- Classless Addressing에서 Prefix length는 0에서 32까지 가능하다.
<img width="505" alt="image" src="https://user-images.githubusercontent.com/110087065/209616318-97b9c651-6d1d-4229-9165-b5abc49c6da0.png">
- Classless Addressing에서는 Slash 뒤에 Prefix length를 알 수 있고, block의 주소 중 하나를 알 수 있다.<br/>
- Classless Addressing에서 주소는 주소가 속한 block을 정의할 수 없다.<br/>
  - EX) 주소 230.8.24.56으 관련 prefix에 따라 아래에 표와 같이 많은 block에 속할 수 있다.
  <img width="527" alt="image" src="https://user-images.githubusercontent.com/110087065/209617175-a7abdf10-00ef-42a0-ba9f-ff548f6abaa3.png">

### 2-2. Two-Level Addressing
- 167.199.170.82/27 이란 주소가 있을 때, 주소의 개수, 시작 주소, 끝 주소 를 구하는 방법.
  - n = 27
  - 따라서 network mask는 11111111 11111111 11111111 11100000
  - 주소의 개수: 2^32 / 2^n = 32
  - 시작 주소  
  <img width="480" alt="image" src="https://user-images.githubusercontent.com/110087065/209618647-7619541a-0144-4507-be6e-bced602cf370.png">
  
  - 끝 주소
  <img width="481" alt="image" src="https://user-images.githubusercontent.com/110087065/209618783-d77d680f-ac81-432c-b7b2-ebbcd0232744.png">

### 2-3. Block Allocation
- 만약 1000개의 주소 block을 요구할 때, 2의 거듭제곱인 1024개의 주소를 부여함.
- block의 prefix length는 n = 32 - log2(1024) = 22
- 시작 주소는 

### 2-4. Subnetting
- IP주소 낭비를 방지하기 위한 원본 네트워크를 여러 개의 네트워크로 분리하는 과정(자신의 네트워크 주소를 더 작은 서브 네트워크로 2의 제곱으로 나누는 과정)

## 3. Special Address
- Special Address란 IP 주소 중에서 특별한 목적으로 쓰이는 주소들을 말한다.

- all-zero address
  - 내가 누군지 모를 때 사용하는 주소(발신지로만 사용 가능)
  
- directed broadcast address
  - 라우터가 브로드캐스트 할 일이 있을 때 이 주소를 사용한다. 이 때 목적지 주소는 해당 네트워크 의 마지막 주소가 된다.
  
- limited broadcast address
  - destination IP주소가 255.255.255.255 이면 그 네트워크의 모든 호스트가 패킷을 쳐다보게된다.
  
- loopback address
  - 127.x.y.z 형태의 주소를 목적지 IP로 가지면, loopback address라고 부른다. loopback address를 목적지로하는 패킷은 이름에서 알 수 있듯이 나갔다가 자신에게 다시 돌아오게된다. 주로 네트워크 서비스 어플리케이션의 점검에 사용되고 흔한 loopback 주소로는 localhost를 의미하는 127.0.0.1이 있다.

## 4. NAT
- NAT(Network Address Translation)는 제한된 수의 인터넷 IPv4 주소 문제를 해결하기 위해 개발되었습니다. 여러 디바이스에서 인터넷에 액세스해야 하지만 하나의 IPv4 인터넷 주소만 ISP(인터넷 서비스 공급자)에 의해 할당되는 경우 NAT를 사용합니다.

