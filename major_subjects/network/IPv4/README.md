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

