# 명령행 전달인자 (Command-line Arguments)

- 프로그램을 실행할 때 전달하는 인자

- C언어에서는 아래와 같이 인자값을 전달 받음

    ```
    int main(int argc, char **argv) {
        //
    }
    ```

    - argc: 명령행 인자 개수
    - argv: 명령행 인자 벡터

        ##

- 모든 프로그램은 기본적으로 1개 이상의 인자를 가짐

    - 첫번째 인자는 프로그램 자기 자신의 경로

# 명령행 전달 인자 출력

- 예제

    ```
    #include <stdio.h>

    int main(int argc, char **argv)
    {
        int i;

        printf("The number of arguments: %d\n", argc);

        for (i=0; i<argc; i++) {
            printf("[%d]: %s\n", i, argv[i]);
        }

        return 0;
    }
    ```

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main abc 123

    The number of arguments: 3
    [0]: ./main
    [1]: abc
    [2]: 123
    ```

# 명령행 전달 인자 파싱

- 옵션

    - -i, --interface [Interface Name]
    - -m, --match [Matching Engine Name]
    - -v, --verbose

        ##

- 예제

    ```
    #include <stdio.h>
    #include <string.h>

    #define MAX_STRING 1024

    int main(int argc, char **argv)
    {
        int i;

        char interface[MAX_STRING] = {0};
        char match[MAX_STRING] = {0};
        int verbose = 0;

        for (i=0; i<argc; i++) {
            printf("[%d]: %s\n", i, argv[i]);

            if (strcmp(argv[i], "-i") == 0) {
                if (i+1 < argc) {
                    strcpy(interface, argv[i+1]);
                    i++;
                } else {
                    printf("out-of-boundary\n");
                }
            } else if (strcmp(argv[i], "--interface") == 0) {
                if (i+1 < argc) {
                    strcpy(interface, argv[i+1]);
                    i++;
                } else {
                    printf("out-of-boundary\n");
                }
            } else if (strcmp(argv[i], "-m") == 0) {
                if (i+1 < argc) {
                    strcpy(match, argv[i+1]);
                    i++;
                } else {
                    printf("out-of-boundary\n");
                }
            } else if (strcmp(argv[i], "--match") == 0) {
                if (i+1 < argc) {
                    strcpy(match, argv[i+1]);
                    i++;
                } else {
                    printf("out-of-boundary\n");
                }
            } else if (strcmp(argv[i], "-v") == 0) {
                verbose = 1;
            } else if (strcmp(argv[i], "--verbose") == 0) {
                verbose = 1;
            }
        }

        printf("Interface: %s\n", interface);
        printf("Match: %s\n", match);
        printf("Verbose: %s\n", (verbose == 0) ? "False" : "True");

        return 0;
    }
    ```

    - 옵션이 많아지면 코드가 복잡해질 수 밖에 없다
    - 사용자가 옵션을 제대로 입력하지 않을 경우 수많은 예외가 발생할 수 있다
    - 문자열 비교나 처리 과정에서 많은 에러가 발생할 수 있다

        ##

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main -i eth0 --match string -v

    [0]: ./main
    [1]: -i
    [3]: -m
    [5]: -v
    Interface: eth0
    Match: string
    Verbose: True
    ```

- (코너 케이스) 실행 결과

    ```
    ./main -i eth0 -m -v

    [0]: ./main
    [1]: -i
    [3]: -m
    Interface: eth0
    Match: -v
    Verbose: False
    ```

    - -m 뒤 인자값이 들어와야 하나, 사용자의 실수로 만약 인자값이 정의되지 않았다면 위와 같은 결과를 얻게 됨
    - -v가 또 다른 옵션임에도 불구하고 -m의 인자값으로 인식되어 프로그램이 제대로 동작하지 않게 됨

        ##

# getopt() 함수

- 함수 정의

    ```
    #include <unistd.h>
    int getopt(int argc, char * const argv[], const char *optstring);
    ```

    - argc와 argv는 main함수가 받은 파마미터를 그대로 전달
    - optstring은 파싱해야 할 파라미터를 의미
    - 옵션이 별도의 파라미터를 받는 경우 콜론을 함께 씀

        ##

- 전역 변수

    ```
    extern char *optarg;
    extern int optind, opterr, optopt;
    ```

    - optarg: 옵션 뒤 별도의 파라미터 값이 오는 경우, 해당 문자열이 저장됨
    - optind: 다음 번 처리될 옵션의 인덱스 값
    - opterr: 옵션에 문제가 있을 경우, 이 값이 0이 아닌 값이 되며, getopt() 함수가 에러 메시지를 표시
    - optopt: 알 수 없는 옵션을 만났을 때 해당 옵션이 저장됨 (이 때, getopt()의 리턴값은 '?'가 됨)

        ##

- 예제

    - 옵션: -i [Interface Name], -m [Match Engine Name], -v

        ```
        #include <stdio.h>
        #include <string.h>
        #include <unistd.h>

        #define MAX_STRING 1024

        int main(int argc, char **argv)
        {
            char interface[MAX_STRING] = {0};
            char match[MAX_STRING] = {0};
            int verbose = 0;

            int opt;
            while ( (opt = getopt(argc, argv, "i:m:v")) != -1) {
                switch (opt) {
                case 'i':
                    strcpy(interface, optarg);
                    break;
                case 'm':
                    strcpy(match, optarg);
                    break;
                case 'v':
                    verbose = 1;
                    break;
                case '?':
                    printf("Unknown option: %c\n", optopt);
                    break;
                }
            }

            printf("Interface: %s\n", interface);
            printf("Match: %s\n", match);
            printf("Verbose: %s\n", (verbose == 0) ? "False" : "True");

            return 0;
        }
        ```

    - 추가 파라미터가 있는 옵션이 파라미터가 없는 채 실행되면 인식할 수 없는 옵션으로 처리됨

        - getopt() 리턴값이 '?'가 되고 optopt에 해당 옵션이 저장됨

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main -i eth0 -m string -v -e

    ./main: invalid option -- 'e'
    Unknown option: e
    Interface: eth0
    Match: string
    Verbose: True
    ```

- (코너 케이스) 실행 결과

    ```
    ./main -i eth0 -m -v

    Interface: eth0
    Match: -v
    Verbose: False
    ```

    - getopt()와 같은 함수를 쓴다고 해도, 예외는 발생한다!
    - 외부 라이브러리를 가져다 쓴다고 해서 해당 라이브러리가 완벽하다고 말할 수 없다!
    - 항상 다양한 예외상황을 고려하여 기능과 결과값을 검증해야 한다!

# getopt_long() 함수

- 함수 정의

    ```
    #include <getopt.h>
    int getopt_long(int argc, char * const argv[], const char *optstring,
                    const struct option *longopts, int *longindex);
    ```

    - argc, argv, optstring까지는 getopt()와 동일
    - longopts는 <getopt.h>에 선언된 struct option 배열의 첫번째 요소에 대한 포인터

        ```
        struct option {
            const char *name;
            int         has_arg;
            int        *flag;
            int         val;
        };
        ```

        - name: 옵션 이름
        - has_arg: 옵션이 추가적인 파라미터를 갖는지 여부 / no_argument (=0), required_argument(=1), optional_argument(=2)
        - flag: 옵션 값이 저장될 위치
        - val: 옵션 값

        ##

    - longindex는 구조체 배열 중 매칭된 옵션의 위치

- 예제

    - 필요한 옵션: -i|--interface [Interface Name], -m|--match [Match Engine Name], -v|--verbose, --brief, --level [Logging Level]

        ```
        #include <stdio.h>
        #include <string.h>
        #include <getopt.h>

        #define MAX_STRING 1024

        static int brief_flag;

        int main(int argc, char **argv)
        {
            char interface[MAX_STRING] = {0};
            char match[MAX_STRING] = {0};
            int verbose = 0;

            static struct option long_options[] = {
                {"interface", required_argument, 0, 'i'}, // --interface를 만나면 -i로 변환
                {"match", required_argument, 0, 'm'},
                {"verbose", no_argument, 0, 'v'},
                {"brief", no_argument, &brief_flag, 1},   // --brief를 만나면 brief_flag에 1을 세팅
                {"level", required_argument, 0, 0},       // 짧은 옵션 없이 긴 옵션 (--level)만 존재
                {0, 0, 0, 0}
            };
            int option_index = 0;

            int opt;
            while ( (opt = getopt_long(argc, argv, "i:m:v", long_options, &option_index)) != -1) {
                switch (opt) {
                // 긴 옵션만 존재하는 경우
                case 0:
                    if (strcmp(long_options[option_index].name, "level") == 0) {
                        printf("Level: %s\n", optarg);
                    }
                    break;
                // 짧은 옵션만 또는 둘 다 존재하는 경우
                case 'i':
                    strcpy(interface, optarg);
                    break;
                case 'm':
                    strcpy(match, optarg);
                    break;
                case 'v':
                    verbose = 1;
                    break;
                case '?':
                    printf("Unknown option: %c\n", optopt);
                    break;
                }
            }

            printf("Interface: %s\n", interface);
            printf("Match: %s\n", match);
            printf("Verbose: %s\n", (verbose == 0) ? "False" : "True");
            printf("Brief: %s\n", (brief_flag == 0) ? "False" : "True");

            return 0;
        }
        ```

- 컴파일

    ```
    gcc -o main main.c
    ```

- 실행 결과

    ```
    ./main --interface eth0 -m string -v

    Interface: eth0
    Match: string
    Verbose: True
    ```
