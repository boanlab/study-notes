# 시그널 핸들러

## 개요

- Signal은 비동기적 이벤트를 처리하기 위해 사용

- 자주 언급되는 Signal들은 다음과 같음

    - SIGINT (Signal Interrupt): Ctrl+C를 눌렀을 때 발생
    - SIGKILL (Signal Kill): 강제로 프로세스를 종료할 때 사용
    - SIGTERM (Signal Terminate): 프로세스로 종료하라는 신호를 전달
    - SIGHUP (Signal Hung): 기존 프로세스는 종료되고, 다시 프로세스가 실행됨 (PID는 바뀌지 않음)
    - SIGSEGV (Signal Segmentation Violation): SegFault가 생기면 발생
    - SIGSTOP (Signal Stop), SIGCONT (Signal Continue): 프로세스를 잠시 멈췄다 다시 시작할 때 사용

        ##

- 그 외에도 수십개의 Signal이 존재함

    ```
    $ kill -l
     1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
     6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
    11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
    16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
    21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
    26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
    31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
    38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
    43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
    48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
    53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
    58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
    63) SIGRTMAX-1  64) SIGRTMAX
    ```

## 프로그램 상에서의 Signal 활용 사례

- Ctrl+C

    - 프로그램 동작 중 Ctrl+C를 누르게 되면 별도의 후처리 없이 바로 프로그램이 종료됨
    - 이러한 경우, 프로그램에서 Signal을 받아봄으로 후처리 후 정상적으로 프로그램을 종료 시킬 수 있음

        ##

- Segmentation Fault

    - 기본적으로 Segmentation Fault가 발생하면 프로그램도 강제 종료됨
    - 이러한 경우, 프로그램에서 Signal을 받아봄으로 SegFault가 발생한 부분만 후처리하며, 프로그램을 계속 동작시킬 수 있음

        ##

## Signal 구현 예시 1

- 코드

    ```
    #include <stdio.h>
    #include <unistd.h>

    void sig_handler(int signo);

    int main()
    {
        int cnt = 1;

        // SIGINT에 대한 signal handler 정의
        signal(SIGINT, (void *)sig_handler);

        while (1) {
            printf("%d\n", cnt++);
            sleep(1);
        }

        return 0;
    }

    void sig_handler(int signo)
    {
        printf("Got an interrupt\n");
        exit(0);
    }
    ```

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main

    1
    2
    3
    ^CGot an interrupt
    ```

- 위와 같이 SIGINT에 대해서 sig_handler를 정의할 경우 원래의 동작 방식은 무시됨
- 즉, Ctrl+C로는 더 이상 프로그램이 종료되지 않음
- 그렇기 때문에, 위 경우 exit()를 통해서 프로그램을 명시적으로 종료시켰음

## Signal 구현 예시 2

- 코드

    ```
    #include <stdio.h>
    #include <unistd.h>

    void sig_handler(int signo);

    int main()
    {
        int cnt = 1;

        // SIGINT에 대한 signal handler 정의
        signal(SIGINT, (void *)sig_handler);

        while (1) {
            printf("%d\n", cnt++);
            sleep(1);
        }

        return 0;
    }

    void sig_handler(int signo)
    {
        printf("Got an interrupt\n");
        signal(SIGINT, SIG_DFL);
    }
    ```

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main

    1
    2
    3
    ^CGot an interrupt
    4
    5
    6
    ^C
    ```

- signal 핸들러 함수 대신 SIG_DFL을 적어주면 기존 방식이 복원됨
- 위의 경우 처음 Ctrl+C를 눌렀을 경우에는 sig_handler가 호출됨
- 하지만 sig_handler 내에서 SIG_DFL을 통해 기존 방식을 복원하였기 때문에, 다시 Ctrl+C를 누르면 기존 방식대로 프로그램 종료됨
