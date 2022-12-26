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
