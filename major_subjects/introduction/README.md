# Introduction

## Contents

### [1. 컴퓨터와 데이터](1_introduction.md)

- 컴퓨터 및 컴퓨터 과학
- 컴퓨터 시스템
- 데이터

### [2. 자료구조](2_data_structure.md)

- 선형 자료구조
    - 배열
    - 희소행렬
    - 리스트
    - 스택과 큐

- 비선형 자료구조
    - 트리
        - 이진트리
        - 경사 이진트리
        - 포화 이진트리
        - 완전 이진트리
    - 그래프
        - DFS
        - BFS

### [3. 알고리즘](3_algorithm.md)

- 정의

- 점근 성능

- 설계 기법
    - 분할 정복(Divide and Conquer)
    - 동적 프로그래밍
    - 탐욕(Greedy)

- 알고리즘 분석

- 정렬 알고리즘
    - 선택(Selection)
    - 버블(Bubble)
    - 삽입(Insertion)

- 탐색 알고리즘
    - 순차(Sequential)
    - 이진 탐색 트리(Binary Search Tree)

### [4. 운영체제](4_operating_system.md)

- 작업처리 방식
    - 일괄처리 시스템 (batch processing system)
    - 다중 프로그래밍 시스템 (multi-programming system)
    - 시분할처리 시스템 (time-sharing processing system)

- 기억장치 계층구조

- 주기억장치 할당 방법
    - 고정 분할 다중 프로그래밍
    - 동적 분할 다중 프로그래밍

- 가상기억장치 관리 기법
    - 페이징 (paging)
    - 세그먼테이션 (sagmentation)

- 프로세스

- 중앙처리장치 스케줄링 기법
    - 선점 방식
    - 비선점 방식
        - 우선순위 스케줄링
        - FCFS(First-Come First Served)
        - SJF(Short Job First)
        - RR(Round Robin)

- 교착상태(Deadlock)

- 파일 관리 시스템

- 디스크 공간 할당 기법
    - 연속 할당
    - 불연속 할당
        - 섹터 단위
        - 블록 단위

### 5. [컴퓨터 구조](5_computer_architecture.md)

- 컴퓨터 시스템의 하드웨어 기본 구성요소

- 불대수

- 논리회로
    - 조합회로
        - 전가산기
        - 디코더
        - 멀티플렉서
    - 순서회로
        - 카운터
        - 플립플롭

- 기억장치
    - RAM
    - ROM

- 기억장치 계층구조

- 명령어
    - 종류
        - 데이터 전송
        - 데이터 처리
        - 프로그램 제어
        - 입출력
    - 형식

- 주소지정방식

- CPU 레지스터

- 처리장치에서의 연산 처리

- 제어장치

- 입출력 시스템
    - 구성요소
    - 제어 방식
        - 중앙처리장치에 의한 제어방식
        - DMA(Direct Memory Access)에 의한 제어방식
        - 채널에 의한 방식

- 병렬 처리

### [6. 프로그래밍언어](6_programming_language.md)

- 프로그래밍 언어 유형
    - 기계어
    - 어셈블리어
    - 함수형 프로그래밍 언어
    - 구조적 프로그래밍 언어
    - 논리형 프로그래밍 언어
    - 객체지향 프로그래밍 언어
    - 스크립트 언어

- 파스 트리

- 컴파일 과정

- 프로그래밍 언어의 공통 개념

- 블록과 변수의 유효범위

- 부프로그램

- 함수의 매개변수

- 변수의 수명

- 객체지향 프로그래밍
    - 추상화(Abstraction)
    - 캡슐화(Encapsulation)

### [7. 데이터베이스](7_database.md)

- 데이터베이스 특징
- 데이터베이스 시스템
    - 스키마
    - 3단계 데이터베이스 구조
    - 데이터베이스 관리 시스템 (DBMS)
    - 데이터 언어
        - 데이터 정의어 (DDL)
        - 데이터 조작어 (DML)
        - 데이터 제어어 (DCL)
- 데이터 모델링
    - 논리적 모델
    - 개체-관계 (E-R) 모델
    - 관계형 모델
    - 키
    - 릴레이션
- 데이터베이스 설계
    - 사용자 요구사항 분석
    - 개념적 설계
    - 논리적 설계
    - 물리적 설계
    - 구현
- SQL
    - SQL 데이터 정의어
    - SQL 데이터 조작어
    - 뷰

### [8. 컴퓨터 네트워크](8_network.md)

- 네트워크 구성요소
    - 채널
    - 주파수
    - 대역폭
    - 노드
    - 네트워크 인터페이스
    - 프로토콜

- 네트워크 크기
    - LAN (Local Area Network)
    - MAN (Metropolitan Area Network)
    - WAN (Wide Area Network)

- 연결 형태
    - 버스(bus)형
    - 성(star)형
    - 원(ring)형

- 데이터 교환 방식
    - 회선 교환 방식
    - 데이터 교환 방식
    - 패킷 교환 방식

- 네트워크 연결 요소
    - 리피터 (repeater)
    - 브릿지 (bridge)
    - 스위치 (switch)

- OSI 참조 모델 (7계층)
    - 물리 계층 (physical layer)
    - 데이터링크 계층 (datalink layer)
    - 네트워크 계층 (network layer)
    - 전송 계층 (transport layer)
    - 셰션 계층 (session layer)
    - 표현 계층 (representation layer)
    - 응용 계층 (application layer)

- 인터넷

- IP

- TCP

- 응용 계층 프로토콜
    - ICMP (Internet Control Message Protocol)
    - FTP (File Transfer Protocol)
    - HTTPS (HyperText Transfer Protocol over Secure skcket layer)
    - SMTP (Simple Mail Transfer Protocol)
    - DHCP
    - DNS (Domain Name System)
