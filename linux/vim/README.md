# 5. VI 편집기
---
## contents
- [1. VI 편집기란?](#1-vi-편집기란)
- [2. VI 사용 모드](#2-vi-사용-모드)
- [3. 편집 명령](#3-편집-명령)
- [4. VI 에디터 설정 변경](#4-vi-에디터-설정-변경)
---

## 1. VI 편집기란?
- **VI**sual display editor의 약자
- VI는 터미널 환경에서 많이 사용되는 텍스트 에디터
- 리눅스 뿐 아니라 윈도우용 vim도 배포되어 있다
- VIM(VI Improved)은 VI를 개선하여 만들어진 프로그램
- VIM이 VI로 alias(별칭)가 등럭되어 있다면 VI를 입력하면 자동으로 VIM이 실행된다
- 쉘 상에서 `vi 파일명` 을 입력하여 새로운 문서를 편집할 수 있다

<br>

---

## 2. VI 사용 모드
### 1. 명령 모드(command mode)
 - 처음 vi를 시작하면 들어가지는 **기본 상태** <br>
 - 이 모드는 vi에게 **명령**을 내리는 모드고, 편집을 위한 모드가 **아니다**<br>
 - 키 입력으로 삭제, 복사, 붙이기 등의 작업을 하는 모드<br>
 - 명령 모드로 되돌아 오기 위해서는 <kbd>esc</kbd>를 누르면 된다<br>

   
### 2. 입력 모드(insert mode)
 - 실제로 문서를 편집하는 모드<br>
 - 명령모드에서 <kbd>i</kbd>나 <kbd>a</kbd>, <kbd>o</kbd>, <kbd>s</kbd>, <kbd>a</kbd> 키를 통해 들어올 수 있다 <br> 
 - 자유롭게 코드나 글을 작성할 수 있다 <br>
 - **복사, 붙이기** 와 같은 기능은 입력모드에서 할 수 없고, **명령 모드** 로 이동해야 한다<br>
    
### 3. EX 모드
 - vim은 ex에디터를 기반으로 만들어진 에디터이므로 ex에디터 기능을 그대로 사용할 수 있다<br>
 - ex라인 에디터의 기능을 기본적으로 사용할 수 있는 것이 EX모드이다<br>
 - 명령 모드에서 <kbd>:</kbd> 을 입력해 진입한다 <br>
 - Ex명령어를 실행한다<br>
<!-- - `syntax on` 명령: 문법 강조 기능 on/off<br>
 
### 3. 비주얼모드(visual mode):
 - 명령 모드에서 <kbd>v</kbd> 를 입력해 진입한다
-->

<br>

---
## 3. 편집 명령

- 더 많은 명령어: https://vim.rtorr.com/lang/ko/
- [1. vi 시작](#1-vi-시작)
- [2. 커서 이동](#2-커서-이동)
- [3. 입력 모드 변경](#3-입력-모드-변경)
- [4. 삭제](#4-삭제)
- [5. 되돌리기](#5-되돌리기)
- [6. 복사, 붙여넣기](#6-복사-붙여넣기)
- [7. 저장, 종료](#7-저장-종료)
- [8. 검색, 대체](#8-검색-대체)
- [9. 추가 EX 모드 명령어](#9-추가-ex-모드-명령어)

<br>

### 1. vi 시작
- vi에 진입하고 싶을 때 사용하는 명령어

| 명령어 | 설명 |
| :---: | --- |
| vi 파일명| 파일을 열고 작성<br> (만일 해당 파일이 없다면 생성한다) |
| view | 읽기 전용으로 파일 열기 |
<br>

### 2. 커서 이동
- **키보드 방향키** 로도 이동 가능
- 명령 모드에서 실행

| 명령어 | 방향키 | 설명 |
| :---: | :---: | --- |
| j | ⬇️ | 아래로 이동  |
| k | ⬆️ | 위로 이동 |
| l | ➡️ | 오른쪽으로 이동  |
| m | ⬅️ | 왼쪽으로 이동 |
<br>

### 3. 입력 모드 변경
- 명령 모드에서 **입력 모드로 진입**할 때, 다양한 키(i, o, ...)를 선택했다. <br>
이러한 키는 어느 위치에 **문자를 삽입**할지 결정한다<br>
- 입력 모드로 진입하기 위한 키는 다음과 같다<br>

| 명령어 | 모드 | 설명 |
| :---: | :---: | --- | 
| **i** | 명령모드 | 현재 커서 위치에서 문자 삽입( **insert** ) |
| **a** | 명령모드 | 현재 커서 위치의 다음 칸부터 문자 삽입 ( **append** ) |
| **o** | 명령모드 | 커서 바로 아래에 줄을 만들고 문자 삽입 ( **open line** ) |
| O | 명령모드 | 커서 바로 위에 줄을 만들고 문자 삽입|
| A | 명령모드 | 현재 커서가 위치한 줄의 마지막 위치에서 문자 삽입 |
| I | 명령모드 | 현재 커서가 위치한 줄의 맨 앞에서 문자 삽입 |
| gg | 명령모드 | 첫 라인으로 이동하여 문자 삽입|
| G | 명령모드 | 마지막 라인으로 이동하여 문자 삽입|
<br>


### 4. 삭제
- 입력 모드에서 문서를 편집하다가, 삭제하고 싶은 문자가 생길 때 사용<br>
- **명령 모드** 로 진입하여 사용
- EX모드에서 사용하는 꼴: **(줄 수1),(줄 수2)d** : 줄 수 1~ 줄 수 2 행 삭제 <br>
- 명령모드에서 사용하는 꼴: **[횟수] d 대상** 또는 **d [횟수] 대상** <br>
  - **(1) 횟수**는 기본 1 <br>
  - **(2) d**는 삭제한다는 명령을 나타낸다<br>
  - **(3) 대상**은 3 종류가 있다. <br>
    - **w** : 커서에서 단어 끝까지 삭제(공백 포함) <br>
          _횟수만큼 단어 삭제(단어 구분은 공백) + 마지막 단어 뒤에 나오는 공백도 삭제_ <br>
    - **e** : 커서에서 단어 끝까지(공백 포함 x) <br>
          _횟수만큼 단어 삭제(단어 구분은 공백) + 마지막 단어 뒤에 나오는 공백 삭제x_ <br>
    - **$** : 커서에서 그 줄의 끝까지 <br>
 <br>
 
| 명령어 | 모드 | 설명 |
| :---: | :---: | --- |
| **x**, dI | 명령모드| - 커서 위치의 **문자 삭제**<br>- x의 개수만큼 문자 삭제 _(xxx은 문자 3개 삭제)_ |
| **dd** | 명령모드| 커서가 있는 **행 전체 삭제** |
| X, dh | 명령모드| 커서 위치 바로 앞의 문자 삭제 |
| dw | 명령모드| 한 단어 삭제 | 
| d0 | 명령모드| 커서가 위치한 곳부터 그 행의 맨 앞 문자까지 삭제(왼쪽 삭제) |
| D, d$ | 명령모드| 커서가 위치한 곳부터 그 행의 마지막 문자까지 삭제(오른쪽 삭제) |
| dk | 명령모드| 커서가 위치한 행과 그 앞 행 삭제 |
| dj | 명령모드| 커서가 위치한 행과 그 다음 행 삭제 |
| dG | 명령모드| 커서가 위치한 행부터 마지막 행까지 삭제 |
| 2,3d | EX모드| 2번째~3번째 행 삭제 |

> 응용: **화면 전체 삭제**
> 1. 명령 모드에서 `gg`를 눌러 커서를 **첫 라인** 으로 이동 <br>
> 2. (그대로) 명령 모드에서 `dG`를 입력해 **맨 뒷줄까지 삭제** <br>
> -> **모든 화면 삭제 완료**

<br>


### 5. 되돌리기
- window의 ctrl + z, ctrl + y와 같은 기능<br>
- 입력 모드에서 문서를 편집하다가, 되돌리고 싶을 때 사용
- **명령모드** 에서 실행

| 명령어 | 모드 | 설명 |
| :---: | :---: | --- |
| u | 명령모드| 되돌리기(window의 ctrl + z) |
| <kbd>ctrl</bkd> + r | 명령모드| redo (widow의 ctrl + y) |

<br>

### 6. 복사, 붙여넣기
- window의 ctrl + c, ctrl + v와 같은 기능
- 입력 모드에서 문서를 편집하다가, 문자를 복사/붙여넣기하고 싶을 때 사용
- 기본적으로 **명령모드** 에서 실행

| 명령어 | 모드 | 설명 |
| :---: | :---: | --- |
| **yy** | 명령모드 | 커서가 위치한 **줄 복사** |
| **p** | 명령모드 | 커서 바로 **다음 위치에 붙여넣기** |
| **P** | 명령모드 | 커서가 있는 **위치에 붙여넣기** |
| y0 | 명령모드 | 커서 위치에서 해당 행의 맨 처음까지 복사(왼쪽 복사) |
| y$ | 명령모드 | 커서 위치에서 해당 행의 맨 끝까지 복사(오른쪽 복사) |
| yw | 명령모드 | 커서 위치에서 **단어**의 끝까지 복사 |
| y2w | 명령모드 | 커서 위치에서 단어 2개 복사 |
| 2yy | 명령모드 | 커서가 위치한 줄을 포함해 **아래로 2줄** 복사 |
| yj | 명령모드 | 커서가 위치한 줄과 그 다음줄 복사 |
| yk | 명령모드 | 커서가 위치한 줄과 그 앞줄 복사 |
| yG | 명령모드 | 커서가 위치에서 **파일 끝까지** 복사 |
| r 파일명 | **EX모드** | `파일명` 파일을 현재 **문서에 삽입** |

> 응용: **원하는 블록만 복사**
> 1. 명령 모드에서 v키를 누르고 커서를 이동해 블록 설정
> 2. y키를 눌러 (캐시에) 복사한다
> 3. p를 눌러 붙여넣기한다

<br>

### 7. 저장, 종료
- 명령모드에서 **ex모드**로 들어와(: 입력) 작업
- 만일 입력 모드에서 문서를 작성한다면 <kbd>esc</kbd> -> <kbd>:</kbd> 를 눌러 진입

| 명령어 | 모드 | 설명 |
| :---: | :---: | --- |
| **wq** | EX모드 | **저장 후 종료** |
| wq! | EX모드 | 강제 저장 후 종료 |
| q! | EX모드 | vi 강제 종료 |
| W | EX모드 | 파일 저장 |
| W 파일명 | EX모드 | 파일명으로 파일 저장 |
| q | EX모드 | vi 종료(파일 저장 x) |

<br>

### 8. 검색, 대체
- 기본적으로 명령모드에서 **ex모드** 로 들어와(<kbd>:</kbd> 입력) 작업
- 대체 명령어 꼴은 다음과 같다: _[범위]/[매칭 문자열]/[치환 문자열]/[라인 범위]_
- 만일 라인 범위로 **g** 를 사용하지 않는다면, <br>한 라인에 해당 매칭 문자열이 **2개 이상** 존재할 때 2번째 이상부터의 문자열은 **치환이 이뤄지지 않는다**
- 라인 범위에 **c** 를 사용하면 매칭되는 문자열에 대해 치환할 것인지 사용자에게 묻는다
- 정규표현식(**패턴** 부분에 사용)을 이용해 치환 가능하다: _g/패턴/범위/문자열1/문자열2/라인범위_

| 명령어 | 모드 | 설명 |
| :---: | :---: | --- |
| ?문자열 | EX모드 | 커서 위치에서 왼쪽, 위로 파일 첫번째까지 탐색 |
| /문자열 | EX모드 | 커서 위치에서 오른쪽, 아래로 파일 마지막까지 탐색 |
| $s/문자열1/문자열2/g | EX모드 | **모든** 문자열1을 문자열 2로 대체 |
| s/문자열1/문자열2/g | EX모드 | 현재 커서가 있는 **행**의 모든 문자열1을 문자열 2로 대체 |
| s/문자열1/문자열2| EX모드 | 현재 커서가 있는 **행**의 **첫번째** 문자열1을 문자열 2로 대체 |
| 1,3s/문자열1/문자열2/g | EX모드 | **1~3행**에서 문자열 1을 문자열 2로 대체 |
| -1,+3s/문자열1/문자열2/g | EX모드 | 현재 커서에서 **위로 1개, 아래로 3개 행**에서<br> 문자열 1을 문자열 2로 대체(현재 커서 행도 포함) |
| g/**\\(^[^#].\*TEST\\\)**/범위<br>/문자열1/문자열2/라인범위 | EX모드 | 범위에 대해  **_#문자로 시작하지 않는 TEST문자열_** 이 있는 <br>모든or라인당 하나의(라인 범위에 따라 상이) 문자열 1을 문자열 2로 수정 |
| % | **명령모드** | (커서를 괄호에 위치하게 할 것) **짝이 맞는 괄호**로 이동 |

<br>

### 9. 추가 EX 모드 명령어
- !command를 이용해 외부 명령 실행 가능 

| 명령어 | 모드 | 설명 |
| :---: | :--: | --- |
| !dir | EX모드 | **디렉토리 리스트** 불러옴(파일명 출력) |
| !rm 파일명 | EX모드 | 파일명 삭제 |
| set nu | EX모드 | 작성한 파일의 **라인 번호** 출력 |
| set nonu | EX모드 | 작성한 파일의 라인 번호 출력 취소 |
| help | EX모드 | 도움말 제공 |
| help 명령어 | EX모드 | 명령어에 대한 도움말 |

<br>

--- 

## 4. VI 에디터 설정 변경
- `.vimrc` 파일을 통해 vim 에디터 설정 변경
- shift 간격, tab 간격 등 설정 가능
- 언어, 인코딩 방식, 색 테마 등 설정 가능
- .vimrc파일을 직접 수정하기도 하지만, `jellybeans`와 같은 colorscheme을 적용하기도 한다


- 홈 디렉토리 최상위에 .vimrc파일 작성
```console
$ vi ~/.vimrc
```

### - 문법 강조
```console
if has(“syntax”)
    syntax on
endif
```
### - 자동 들여쓰기
```console
set autoindent #자동 들여쓰기
set cindent #c 프로그램 작성 시 자동 들여쓰기
```
### - 줄 번호
```console
set nu 
```



