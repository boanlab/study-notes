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

- [C언어 문법](grammar/README.md)
