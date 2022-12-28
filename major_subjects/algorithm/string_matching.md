# 문자열 탐색 (String Matching)

### 정의
- 문자열에서 찾고자 하는 특정 문자열(pattern)의 위치를 찾는 알고리즘

### 종류
- 단순 비교
- 라빈-카프 알고리즘
- KMP 알고리즘
- 보이어-무어 알고리즘
- 아호-코라식 알고리즘

---

## 단순 비교 (Naive Pattern Searching)

**정의**

- 단순히 문자열을 처음부터 끝까지 하나하나 비교하며 패턴을 찾는 알고리즘

  - 작은 문자열에서 유용
  
**원리**

- 길이가 n인 텍스트 T안에서 길이가 m인 패턴 P의 존재 여부를 검토 (m<=n)

    - T[ 0.. n-1 ]
    - P[ 0.. m-1 ]
    
- 패턴 P는 텍스트 T의 처음부터 n-m+1까지 이동하며 매치가 되는지 검토

- 패턴이 발견되면 패턴의 위치를 출력하고 다음 일치 위치 탐색

**코드**

```c

void naivePatternSearch (char T[], char P[]) {

  int n = strlen(T);
  int m = strlen(P);

  for (int i = 0; i <= n-m; i++) {

    for (int j = 0; j < m; j++) { 

      if (T[i+j] != P[j])
        break;

      if (j == m-1) {

        printf("Pattern found at index %d \n", i);
        break;

      }
    }
  }
}

```


**장점**

- 추가 공간이 요구되지 않음

**단점**

- 하나하나 비교하기에 비효율적
- 이미 검사를 마친 위치를 기억하지 못함

**시간복잡도**
  
  - **Best Case**
  
      - 패턴의 첫문자가 텍스트에 없을 때
     
          - T [] = "AABBAAB"
          - P [] = "FAA"
          
      - 텍스트의 길이가 n 이면 **O(n)**
     
  - **Worst Case**

      - 텍스트와 패턴의 모든 문자가 같을 경우
   
          - T [] = "AAAAAAA"
          - P [] = "AA"
          
      - 패턴의 마지막 문자만 다른 경우
    
          - T [] = "AAAAAAA"
          - P [] = "AAB"
          
      - 패턴의 길이가 m 이면 **O(m * (n-m+1))**

#

## 아호-코라식 알고리즘 (Aho-Corasick)


**정의**

- 패턴 집단에 대해 수행하는 문자열 탐색 알고리즘들의 속도가 느려 고안된 문자열 탐색 알고리즘


**특징**

- KMP 👉 텍스트에서 패턴 하나를 찾아낼 때 사용 (1:1)
- 아호 코라식 👉 텍스트에서 패턴 여러개를 동시에 찾아낼 때 사용 (1:N)

    - KMP의 확장이라고 볼 수 있음
    - KMP는 문자열과 문자열 매칭
    - 아호-코라식은 문자열과 **트라이** 간 매칭
    
    - **트라이란?**
    
        - 트라이(Trie)는 문자열의 집합을 표현하는 '트리 자료구조'
        - S = 문자열
        - W = 패턴 문자열 집합
        
<p align="center"><img src="https://user-images.githubusercontent.com/113777043/209805630-bb7782f7-5204-4000-96e4-52e21070cd19.png" width = "80%"></p> 

- **실패 함수(Failure Function)**
    - 매칭이 중간에 실패하였을 때 지금까지 사용한 데이터를 그대로 활용하여 효율적으로 탐색하기 위한 함수


#


## 라빈-카프 알고리즘(Rabin-Karp)

 

### 정의

- 문자열에 **해싱 기법**을 사용하여 **해시 값**으로 비교하는 알고리즘

### 원리

- 각 문자의 **아스키 코드** 값에 **특정 제곱수**를 차례대로 곱하고 **모두 더하여** 해시 값을 만든다.
    - 차례대로 라는 의미는 자리마다(흔히 인덱스) 다른 수를 곱해주는 것

### 예시

- 특정 제곱수를 2로 설정 시, abacaaba의 해시 값 ( a : 97 , b : 98 )
    - 97 * 2^7 +
        
        98 * 2^6  +
        
        97 * 2^5 + … (생략)
        
    
- 문자열 AABDCDAB에서 패턴 ABD 가 발견되는 지 탐색하는 예제

| 문자열 | A | A | B | D | C | D | A | B |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 패턴 | A | B | D |  |  |  |  |  |
- 검색 대상 문자열 해시 값(AAB) : 846
- 문자열 패턴 해시 값(ABD) : 851
    - 탐색 실패

| 문자열 | A | A | B | D | C | D | A | B |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 패턴 | A | B | D |  |  |  |  |  |
- ABD 해시 값이 같아 탐색 성공

이후로도 있는 지 같은 방식으로 계속 탐색

### 코드

```python
def find_string(parent, pattern):
	  parent_len = len(parent)    # 검색 대상 문자열
    pattern_len = len(pattern)  # 찾으려는 패턴 문자열
    parent_hash = 0
    pattern_hash = 0
    power = 1
    for i in range(parent_len - pattern_len + 1):
        if i == 0:
            for j in range(pattern_len):
                parent_hash += ord(parent[pattern_len - 1 - j]) * power  # ord : 아스키코드 값 반환
                pattern_hash += ord(pattern[pattern_len - 1 - j]) * power
                if j < pattern_len - 1:
                    power *= 2
        else:
            parent_hash = 2 * (parent_hash - ord(parent[i - 1]) * power) + ord(parent[pattern_len - 1 + i])

        if parent_hash == pattern_hash:
            found = True
            for j in range(pattern_len):
                if parent[i + j] != pattern[j]:
                    found = False
                    break
            if found:
                print(f'{i + 1}번째에서 발견')
```

- 특정 제곱수를 2로 설정 시의 코드

### 장점

- 일반적인 경우 빠른 속도
- 비교적 간단한 구조

### 단점

- 패턴 등이 길어질 수록 연산이 증가
    - 호너의 법칙 등을 사용하여 보완
- 해시 충돌

### 시간복잡도

- O(n)
