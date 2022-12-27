## 1. Introduction

1.1 분산시스템이란 무엇인가?

분산 시스템은 사용자에게 단일 일관된 시스템으로 나타나는 자율 컴퓨팅 요소의 모음

“A collection of autonomous computing elements (nodes), which appears to its users as a single coherent system”

두가지 측면 

1. 독립적인 컴퓨팅 요소 

2. 단일시스템 → 미들웨어

분산시스템의 목표

1. 리소스를 사용 가능하게 만들기 
2. 유통 투명성
3. 개방상태
4. 확장성

→ 특징 1 : Collection of Autonomous Nodes 자율 컴퓨팅 요소의 집합

특징 : 

1. Independent Behavior 독립적인 행동 - 시간개념으로 자율적 → 동기화, 조정문제 발생
2. 노드 컬렉션으로 그룹 관리 - 열린그룹 / 폐쇄 그룹
3. 조직 - 오버레이 네트워크로 구성됨
    1. Structured Overlay 구조화 된 오버레이
    2. Unstructured Overlay 구조화 되지 않은 오버레이

→ 특징 2 : Single Coherent System 단일 코히어런트 시스템  

분산시스템은 하나의 일관된 시스템으로 나타나야 한다는 의미

즉 노드의 집합 전체는 사용자와 시스템간의 상호작용이 어디서, 언제, 어떻게 발생하는지에 관계없이 동일하게 작동하여야 함

→ Keyword : Distribution transparency (유동투명성)

분산 시스템의 속성 (분리 라는 기본 속성에 따른 파생 속성들)

1. Heterogeneity 이기종성 
2. Explicit communications 명시적 통신
3. Isolation 격리
4. Concurrency 동시성
5. Extensibility 확장성
6. Mobility 이동성
7. Partial Failure 부분실패
8. Multiple Authorities 여러권한

미들웨어 및 분산시스템

네트워크 환경에서 제공됨

네트워크를 통해 해당 리소스를 효율적으로 공유하고 배포하기

 → 어플리케이션 간 통신을 위한 시설, 보안서비스, 회계 서비스, 장애 마스킹 및 복구

미들웨어 서비스의 몇가지 예시들

1. 통신 서비스 : RPC(원격 프로토콜 호출) 서비스이다. 응용프로그램이 마치 로컬에서 사용 가능한 것처럼 원격 컴퓨터에서 구현되고 실행되는 기능을 호출 할 수 있음
2. 트랜잭션 : 응용프로그램 개발자는 관련된 원격 서비스만 지정하면 되며, 미들웨어는 표준화된 프로토콜에 따라 모든 서비스가 호출되거나 전혀 호출되지 않도록 한다
3. 서비스 구성 : 기존 프로그램을 결합하여 새로운 어플리케이션을 개발하는것을 도움
4. 신뢰성 : 안정적인 분산 응용 프로그램을 구축하기 위한 향상된 기능을 제공

1.2 분산 시스템의 과제

1. Heterogeneity 이기종성 지원
    
    네트워크, 하드웨어, 운영체제, 프로그래밍 언어 의 이기종성을 지원하여야 함
    
    → Middleware 미들웨어와 Mobile Code 모바일 코드를 이용
    
    미들웨어 : 분산 메커니즘에 덜 관심을 둔 분산 앱에 공통 레이어를 제공함
    
    모바일 코드 : 한 컴퓨터에서 다른 컴퓨터로 전송되어도 실행할 수 있는 코드(JVM-자바 가상머신) 이 있는 자바 코드
    
2. Openness 개방성
    
    시스템의 extensibility 확장성 또는 reconfigurability 재구성 가능성을 결정하는 기준
    
    기본 환경의 이질성에 관계없이 다른 구성 요소의 서비스와 상호 작용 허용
    
    → Key factor : Coherence - 일관성
    
    개방형 분산 시스템의 목표 :
    
    1. Interperability 상호 운용성 : 다른 두가지 시스템이 공존하고 함께 작동할 수 있음
    2. Composability 조합성 : 단일 분산 시스템을 위해 컴포넌트가 개발될수도 있지만 컴포넌트 들이 re-use되는 경우가 많다.
    3. Extensibility 확장성 : 원래의 구성요소에 영향을 주지않고 새 구성요소를 추가하거나 기존 구성요소를 교체할 수 있다.
3. Scalability 확장성
    
    사용자 및 리소스를 추가하여도 눈에 띄는 성능저하나 관리 복잡성이 증가하지 않아야 함
    
    확장성을 위한 고려사항 : 
    
    1. 물리적 자원 비용
    2. 성능 손실
    3. 소프트웨어 리소스 부족
    4. 성능 병목 현상
    
     확장성 구성 요소 : 
    
    1. Size scalability 크기 확장성 - 성능이나 리소스 부족을 해결하기 위해 확장 (사용자 및 프로세스 수)
    2. Geographic scalability 지리적 확장성 - 사용자와 어플리케이션이 멀리 떨어져 생기는 통신 지연을 줄이기 위해 (노드 간 최대거리)
    3. Administrative scalability 관리 확장성 - 많은 독립된 관리 조직에 걸쳐 있는 경우에도 시스템을 관리하기 위해 (관리 도메인 수)
    
    확장성을 해결할 수 있는 기술 : Scaling techniques 스케일링 기술
    
    스케일링 기술 : 분포(분할) , 복제/캐싱 
    
    통신 대기 시간 숨기기 : 요청에 대한 응답을 길게 기다리지 않음. 기다리는 대신 요청자 측에서 다른 작업을 수행할 수 있음 (비동기 통신만 사용)
    
    → 분할 및 배포를 사용한다. 예시) 인터넷 DNS, WWW
    
    → 복제 및 캐싱을 사용한다
    
4. Partial Failure 부분 실패 
    
    노드 중 하나가 실패하더라도 문제가 없어야 함
    
    장애 처리 기술 : 
    
    1. Fault detection 오류감지
    2. Fault masking 문제 마스킹
    3. Fault tolerance 문제 허용
    4. Recovery from failures 장애 복구
    5. Redundancy 중복성
5. Concurrency 동시성
    
    공유 리소스에 대한 동시 엑세스로 인해 리소스 불일치가 발생할 수도 있음
    
    → 업데이트가 손실, 일관되지 않은 검색이 초래할 수 있음.
    
    해결 방안 : 트랜잭션의 작업을 직렬화(한번에 하나씩) 해야 한다.
    
6. Security 보안
    
    Authentication 입증(누가)
    
    Authorization 권한부여(무엇을)
    
    Encryption and Decryption 암호화 및 암호 해독
    
7. Distribution Transparency 배포 투명성
    
    분리에서 파생된 속성을 은폐하여 분산시스템을 단일 통합 시스템처럼 보이게 하는 추상화 개념/매커니즘
    
    유동 투명성의 유형 :
    
    1. Access 접근
    2. Location 위치
    3. Relocation 재배치
    4. Migration 이동
    5. Replication복제
    6. Concurrency 동시성
    7. Failure 실패
    
    때로는 배포를 숨기는 것보다 노출하는 것이 더 좋을 때가 있음.
    

1.2.1 분산시스템 개발 시 함정에 빠질 수 있는 가정들

1. 네트워크는 신뢰할 수 있다
2. 네트워크는 안전하다
3. 네트워크가 균질하다
4. 토폴로지가 변경되지 않음
5. 지연시간은 0이다
6. 대역폭은 무한하다
7. 운송비가 제로이다
8. 한명의 관리자만 있다

1.3 분산 시스템의 유형

1. High Performance Distributed Computing 고성능 분산 컴퓨팅 시스템
    
    → 많은 분산 시스템이 고성능 컴퓨팅을 위해 구성됨.
    
    ex ) Parallel Computing 병렬 컴퓨팅, Cluster Computing 클러스터 컴퓨팅, Grid Computing 그리드 컴퓨팅, Cloud Computing 클라우드 컴퓨팅
    
    클러스터 컴퓨팅 : 기본적으로 LAN을 통해 연결된 고급 시스템 그룹, 동종 : 동일한 os, 거의 동일한 하드웨어, 단일 관리 노드
    
    그리드 컴퓨팅 : 이기종, 여러 조직에 분산, 광역 네트워크에 쉽게 확장 가능
    
2. Distributed Information Systems 분산 정보 시스템
    
    트랜잭션 : ACID(원자성, 일관성, 격리, 지속성)을 충족하는 개체의 상태에 대한 작업 모음입니다
    
    Transaction processing system 거래(트렌젝션) 처리 시스템
    
    → 많은 경우 트랜잭션과 관련된 데이터는 여러 서버에 분산됩니다. tp모니터는 트랜잭션 실행을 조정할 책임이 있음.
    
3. Distributed Systems for Pervasive Computing 분산 페베이시브 시스템
    
    → 노드가 작고 이동성이 있으며 종종 더 큰 시스템에 내장되는 차세대 분산 시스템. 시스템이 사용자 환경에 자연스럽게 혼합된다는 사실을 특징으로 함.
    
    세가지 하위 유형 : Ubiquitous system 유비쿼터스 시스템, Mobile computing 모바일 컴퓨팅, senser network 센서 네트워크
