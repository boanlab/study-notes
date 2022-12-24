# Intro   
  
## Contents

- 컴퓨터구조란
- 컴퓨터 구조의 큰 그림


## 컴퓨터구조란

- 사전적 정의 : 컴퓨터 구조(Computer Architecture)는 컴퓨터 과학에서 컴퓨터 시스템의 기능, 조직, 구현에 대한 법칙과 방법을 통칭한다. 또 다른 정의로는 컴퓨터 구조는 명령어 집합 구조(Instrcution Set Architecture), 마이크로아키텍처(Microarchitecture) 설계, 논리 설계 및 구현을 의미한다.

- 컴퓨터 구조를 배우는 이유
    - Enable better systems : make computers faster, cheaper, smaller, more reliable, ...
    - Enable new applications
    - Enable better solutions to problems
    - Understand why computers work the way they do now (현대 컴퓨터의 작동 방식 이해)

- 주요 테마
    - ISA (Instruction Set Architecture)
        - Data
        - Instruction
    - CPU
        - Single-cycle computer
        - Pipelined computer
        - Dependency handling
    - Cache : memory hierarchy for better performance
        - Memory/cache structure
        - Associative cache


## 컴퓨터 구조의 큰 그림

- 컴퓨터 구조

    - 컴퓨터가 이해하는 정보
        - 데이터 : 컴퓨터가 이해하는 정적인 정보 (숫자, 문자, 이미지, 동영상)
        - 명령어 : 데이터를 움직이고 작동시키는 정보

    - 컴퓨터의 네 가지 핵심 부품
        - CPU (Central Processing Unit)
        - Memory (RAM)
        - 보조기억장치 (SSD, Hard Disk, ...)
        - 입출력장치 (마우스, 키보드, ...)
    
    - 큰 그림   
        <img src="../src/bigpicture.jpg" width="500px" height="350px" title="bigpicture" alt="bigpicture"></img>


## 메모리

- 메모리는 현재 실행되는 프로그램의 명령어와 데이터를 저장하는 부품이다.   

    1. 프로그램이 실행되기 위해서는 반드시 메모리에 저장되어 있어야 한다.
    2. 메모리는 현재 실행되는 프로그램의 명령어와 데이터를 저장한다.
    3. 메모리에 저장된 값의 위치는 주소로 알 수 있다.

## CPU 

- CPU는 메모리에 저장된 명령어를 읽어 들이고, 읽어 들인 명령어를 해석하고, 실행하는 부품이다.

- CPU의 내부 구성 요소
    - 산술논리연산장치(ALU)
        - 계산기의 역할을 수행하는 부품.
    - 레지스터(Register)
        - CPU 내부의 작은 임시 저장 장치. 프로그램을 실행하는 데 필요한 값들을 임시로 저장한다.
    - 제어장치(Control Unit)
        - 제어 신호(Contrl Signal)라고 하는 전기 신호를 내보내고 명령어를 해석하는 장치


## 보조기억장치

- 메모리는 용량 대비 비싸고, 전원이 꺼지면 저장된 데이터가 삭제된다. 따라서 메모리보다 크고 전원이 꺼져도 저장된 내용을 잃지 않는 저장 장치가 필요한데, 이를 보조기억장치 라고 한다.

- 하드 디스크, SSD, USB 메모리, DVD 등이 보조기억장치이다.

- 메모리가 현재 **실행되는** 프로그램을 저장한다면, 보조기억장치는 **보관할** 프로그램을 저장한다고 볼 수 있다.


## 입출력장치

- 입출력장치는 마이크, 키보드, 모니터 처럼 컴퓨터 외부에 연결되어 컴퓨터 내부와 정보를 교환하는 장치를 의미한다.


## 메인보드와 시스템 버스

- 지금까지 설명한 컴퓨터의 핵심 부품들은 모두 메인보드라는 판에 연결된다. 메인보드는 마더보드 라고도 불린다.
- 메인보드에 연결된 부품들은 서로 정보를 주고받을 수 있는데, 이는 메인보드 내부에 버스(bus)라는 통로가 있기 때문이다.
- 여러 버스 가운데 컴퓨터의 네 가지 핵심 부품을 연결하는 가장 중요한 버스는 **시스템 버스(System Bus)** 다.
- 시스템 버스의 종류
    - 주소 버스 : 주소를 주고받는 통로
    - 데이터 버스 : 명령어와 데이터를 주고받는 통로
    - 제어 버스 : 제어 신호를 주고받는 통로
