
### 1.1.3 운영체제의 목표
- 운영체제의 목표
    - 사용자에게 편리성 제공
    - 컴퓨터 시스템의 효율적 운영
- 운영체제의 목적
    - 사용자에게 컴퓨터에서 프로그램을 효율적이고 편리하게 실행할 수 있는 환경을 제공
    - 컴퓨터 자원의 할당, 이 할당은 공정해야 하며 효율적으로 이루어져야 함.
    - 제어 프로그램으로 사용자 프로그램의 실행을 감독하여 오류와 컴퓨터 오용을 방지하고 입출력 장치의 제어와 동작을 관리한다.

------------
## 1.2 메인프레임 시스템
- 한 사용자가 하나의 프로그램만을 수행하면 운영체제의 일은 그만큼 쉽다. 반면에 한 사용자가 여러 프로그램을 동시에 수행하거나 여러 사용자가 동시에 사용하는 시스템에서는 운영체제의 일은 간단하지 않다.

    ### 1.2.1 일괄처리 시스템
    - 초창기 시스템은 사용자가 직접 시스템을 사용하지 않고, 전문 컴퓨터 운영자에게 프로그램과 데이터를 펀치 카드를 통해 제공하여 사용하였다.
    - 한번의 하나의 프로그램만이 수행되므로 다음 작업으로 제어를 자동적으로 옮기는 것이었다.
    - 운영체제는 항상 메모리에 상주하였다.
    - 처리속도를 향상하기 위해 유사한 요구를 필요로 하는 작업을 함께 모아서 일괄처리(batch processing)하였다.
    - 문제점
        - 기계적 입출력 장치가 전자적 장치의 속도보다 상대적으로 느려 CPU가 종종 쉬는 경우가 많았다.
    - 직접 접근(direct access)이 가능한 디스크의 도입
        - `작업 스케줄링(job scheduling)`과 `다중프로그래밍(multiprogramming)`이 가능하게 됨.

    ### 1.2.2 다중프로그램 시스템
    - 다중 프로그래밍이란 여러 개의 프로그램을 동시에 메모리에 적재하여 하나의 프로그램이 대기 상태가 되면 그 동안 다른 프로그램을 실행하는 방식을 말한다.
    - 장점
        - 입출력과 프로그램의 실행을 병행으로 수행할 수 있어 `CPU의 사용 효율(CPU utilization)이 증가`함
    - 다중 프로그래밍에서 운영체제는 사용자를 대신하여 의사결정을 하여야 한다.
        - 디스크에 있는 작업저장소(job pool)에서 작업을 선택하여 메모리로 옮기는 것을 `작업 스케줄링`이라 한다.
        - 실행중인 작업이 대기 상태가 되었을 때 메모리에 있는 작업 중 하나를 선택하여 CPU에 할당하는 것은 `CPU 스케쥴링`이라 한다.
    - 여러 프로그램이 동시에 메모리에 상주하므로 메모리 관리가 복잡하다.

    ### 1.2.3 시분할 시스템
    - 다중 프로그래밍을 제공하는 일괄처리 시스템은 CPU의 사용 효율은 높였지만 사용자와 컴퓨터간 상호작용을 제공하지 못하였다.
    - `시분할(time sharing)`또는 멀티태스킹(multitasking)은 다중 프로그래밍과 달리 정해진 시간이 되면 무조건 다음 순서의 작업을 실행하는 방식으로, 교대하는 시간이 매우 짧아 프로그램이 실행되는 동안 사용자는 컴퓨터와 상호작용이 가능하다.
    - 이처럼 사용자와 시스템 간에 직접 상호작용이 가능한 시스템을 대화식 컴퓨터(interactive computer system)이라 한다. 이런 시스템에서는 응답시간(response time)이 짧아야 한다.
    - 시분할 시스템은 여러 사용자가 동시에 컴퓨터를 사용할 수 있게 해준다.
    - 메모리에 적재되어 실행중인 프로그램을 `프로세스(process)`라 한다.
    - 많은 사용자의 프로그램을 동시에 수행하기 위해서는 주기억장치의 용량으로는 부족하다. 이 문제를 해결하기 위해 디스크를 주기억장치의 보조 저장장치로 활용하며, 현재 가장 널리 사용되는 기법은 가상 메모리(virtual memory)이다.
---------------------
## 1.3 데스크탑 시스템
- 초창기 개인용 컴퓨터의 CPU의 한계 때문에 개인용 컴퓨터의 운영체제는 단순한 기능만 제공하였다.
- 기술의 발전에 따라 개인용 컴퓨터의 운영체제도 멀티태스킹, 가상 메모리 등과 같은 고급 기능을 제공하게 되었다. 하지만 이들 운영체제는 CPU의 사용 효율보다는 사용의 편리성에 치중하였다.
- 통신의 발달에 따라 원격에서 파일을 접근할 수 있게 되어, 기존 개인용 컴퓨터에 필요없던 파일보호가 필요해졌다.
---------
## 1.4 다중프로세서 시스템
- 다중프로세서 시스템(multiprocessor system): 컴퓨터 버스, 클럭, 메모리 등을 공유하는 둘 이상의 프로세서를 사용하는 시스템
    - 다른 말로 병렬 시스템(parallel system) 또는 밀결합 시스템(tightly coupled system)이라 한다.
    - 프로세서 : 프로세스를 동작되게끔 해주는 하드웨어
- 다중프로세서 시스템의 장점
    - 처리율(throughput) 증가: N개의 프로세서를 사용한다고 하여 처리율이 N배 증가하는 것은 아니다.
    - 경제적 측면에서 다중프로세서 시스템을 사용하는 것이 여러 개의 단일프로세서 시스템을 사용하는 것보다 저렴하다.
    - 신뢰성 증가: 결함 허용(fault tolerance)에 유리하다. 계속 수행되는 하드웨어의 수에 비례하여 서비스를 계속 제공할 수 있는 능력을 우아한 성능 저하(graceful degradation)라 한다.
- 다중 프로세서 시스템의 분류
    - 대칭형 다중처리(SMP, Symmetric MultiProcessing): 가장 많이 사용하고 있는 방식으로 이 방식에서 각 프로세서느 대등하며, 같은 수준의 일을 한다.
    - 비대칭형 다중처리(asymmetric MultiProcessing): 이 방식에서 각 프로세서는 서로 다른 업무를 분담한다. 보통 프로세서 간에 주/종 관계(master/slave relationship)를 형성하며, 주 프로세서는 작업의 스케줄을 결정하여 종속 프로세서에 작업을 할당한다.
---------------
## 1.5 분산시스템
- 이 시스템은 네트워크를 통해 통신하여 그 기능을 제공한다.
- 분산시스템은 다중프로세서 시스템과 마찬가지로 여러 프로세서를 사용하지만 밀결합 형태가 아니고 소결합(loosely coupled)형태이며, 컴퓨터 버스나 클럭을 공유하지 않고, 네트워크를 이용하여 통신한다.
- 네트워크는 사용하는 프로토콜, 망의 크기, 전송매체에 따라 분류할 수 있다. 망의 크기에 따라서는 LAN(Local Area Network), MAN(Metropolitan Area Network), WAN(Wida Area Network)으로 분류한다.

    ### 1.5.1 클라이언트-서버 시스템
    - 서버 시스템은 크게 계산 서버 시스템(compute-server system)과 파일 서버(file-server system)으로 분류할 수 있다.
        - 계산 서버 시스템: 클라이언트로 부터 요청을 받아 그것을 대신 수행해 준 다음에 클라이언트에게 결과를 되돌려 준다.
        - 파일 서버 시스템: 클라이언트에게 파일 시스템 인터페이스를 제공하여 주며, 클라이언트는 이 인터페이스를 통해 파일을 생성, 갱신, 삭제 등을 할 수 있다.

--------------
## 1.6 집단 시스템
-`집단 시스템(clusterd system)`은 병렬 시스템, 분산시스템과 마찬가지로 다중 CPU를 사용하지만 여러 개의 시스템을 밀결합하여 사용한다는 측면에서 다르다.
- 집단화(clustering)의 목적은 높은 가용성이다.
- 집단 시스템도 다중프로세서 시스템과 마찬가지로 대칭형 방식과 비대칭형 방식으로 분류할 수 있다.
    - 비대칭형 방식: 하나의 컴퓨터는 대기상태로 있고 나머지는 활성화되어 응용 프로그램을 수행한다. 대기상태의 컴퓨터는 나머지 활성화 컴퓨터를 감시한다. 만약 하나의 컴퓨터가 실패하면 대기상태의 컴퓨터가 활성화되어 실패한 서버를 대신한다.
    - 대칭형 방식: 각 컴퓨터는 모두 응용 프로그램을 수행하는 동시에 다른 컴퓨터의 상태를 감시한다.

-----------------
## 1.7 실시간 시스템
- `실시간 시스템(real-time system)`은 프로세서 작동이나 데이터 흐름에 엄격한 시간 제약이 있을때 사용된다.
- 실시간 시스템의 운영체제는 보통 특수 목적용이다.
- 실시간과 빠르다는 것은 다른 개념이다.
- 실시간 시스템의 분류
    - `엄격한 실시간 시스템(hard real-time system)`: 중요한 작업이 정해진 시간 내에 완료됨을 보장한다. 이를 위해 시스템 내에 있는 모든 지연은 엄격한 시간 제한을 가진다.
    - `완화된 실시간 시스템(soft real-time system)`: 중요한 실시간 작업은 다른 작업보다 우선순위를 가지고 실행되지만 엄격하게 정해진 시간 내에 완료됨을 보장하지는 않는다.

----------------------------
## 1.8 휴대용 시스템
- `휴대용 시스템(handlheld system)`: 네트워크 통신이 가능한 PDA(Personal Digital Assistant) 또는 휴대 전화와 같은 시스템
- 특징
    - 적은 메모리
    - 프로세스의 성능이 일반 PC에 비해 상대적으로 떨어진다. 이것은 휴대용 시스템의 크기와 전력 사용 문제 때문이다.
    - 작은 화면
- 최근에 bluetooth와 같은 무선 통신 기술을 이용하여 인터넷 접근을 제공한다.

----------------------
## 1.9 컴퓨팅 환경
- 초창기 컴퓨팅 환경은 중앙집중 컴퓨팅 환경이었다. 네트워크 기술, 특히 유선통신 기술의 발달로 분산컴퓨팅(distibuted computing) 환경이 등장하였다. 최근에는 무선통신 기술과 소형, 휴대용 컴퓨터 하드웨어 기술의 발달로 이동컴퓨팅(mobile computing) 환경이 등장하였다.
- 인터넷의 발달로 현재의 컴퓨팅 환경을 웹 기반컴퓨팅 이라고도 한다.
- 최근에는 실시간 운영체제를 각종 기계와 장치에 내장하여 사용하고 있다. 이런 컴퓨팅 환경을 임베디드 컴퓨팅(embedded computing)환경이라 한다. 이런 환경에 사용되는 운영체제는 가상 메모리와 같은 고급 기능은 제공하지 않는다.
