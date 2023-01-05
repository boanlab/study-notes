# C 언어

## Environment Setup

- Ubuntu

    - build-essentials를 설치하면 gcc, g++, make 등 개발에 필요한 기본적인 패키지들이 설치된다

        ```
        sudo apt-get -y install build-essentials
        ```

- CentOS

    - gcc, g++, make를 개별적으로 설치한다

        ```
        sudo dnf -y install gcc gcc-g++ make
        ```

    - 또는 Ubuntu의 build-essentials처럼 Development Tools를 설치하여 개발에 필요한 기본적인 패키지들을 한 번에 설치할 수도 있다

        ```
        sudo yum groupinstall 'Development Tools'
        ```

## Contents

- [C언어 기본문법](basics/grammar.md)
- [포인터](basics/pointer.md)
- [문자열 처리](basics/string.md)
- [파일 입출력](basics/file_input_output.md)
- [동적 메모리 할당](basics/dynamic_memory.md)

## Case Study

- [명령 행 인자](case_study/command-line_argument.md)
- [환경 변수](case_study/env_variable.md)
- [시그널 핸들러](case_study/signal.md)
- [명령어 실행](case_study/execution.md)
- [병렬 처리](case_study/parallel.md)
    - 멀티 프로세싱
    - 멀티 스레딩

- [동기화](case_study/sync.md)
    - Mutex
    - Condition variable
    - Spinlock
    - Read-write Lock

- [소켓 프로그래밍](case_study/socket.md)
    - TCP 소켓
    - UDP 소켓
    - Raw 소켓
    - Unix 도메인 소켓

- [메시지 큐](case_study/message_queue.md)
- [비트 필드](case_study/bit_field.md)
- [문자열 매칭](case_study/string_match.md)
- [정규 표현식](case_study/regex.md)
- [랜덤 함수](case_study/random.md)
- [해시 테이블](case_study/hash.md)
- [암호화](case_study/crypto.md)
- [데몬 프로세스](case_study/daemon.md)
- [메모리 풀](case_study/memory_pool.md)
- [스레드 풀](case_study/thread_pool.md)
- [파일/디렉토리 모니터링](case_study/file_dir_monitor.md)
- [메모리 덤프](case_study/memory_dump.md)
