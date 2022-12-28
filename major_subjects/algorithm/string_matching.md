# 문자열 탐색 (String Matching)

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



