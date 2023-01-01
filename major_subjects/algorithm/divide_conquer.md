# 분할 정복 (Divide and Conquer)

### 정의

- 문제를 작게 나누어 푼 후 합쳐서 전체 문제의 답을 찾는 기법
- 하향식 접근법
- 보통 순환 호출을 이용하여 구현

## 합병 정렬(Merge Sort)

### 정의

- 하나의 리스트를 두 개의 균등한 크기로 분할, 분할된 부분 리스트를 정렬한 다음
    
    두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 기법
    

### 특징

- 분할(Divide) : 입력 배열을 같은 크기의 2개의 부분 배열로 분할
- 정복(Conquer) : 부분 배열을 정렬.
    - 부분 배열의 크기가 충분히 작지 않으면 **순환 호출**을 이용하여 다시 분할 정복 방법 적용
- 결합(Combine) : 정렬된 부분 배열들을 하나의 배열에 합병

### 원리

<img src = "https://user-images.githubusercontent.com/88774925/209679151-ab536252-8705-4abf-a730-297318cad95a.png" width = "700" height = "500" />


1. 주어진 배열을 길이가 1이 될 때까지 계속 반으로 나눈다.
2. 나눈 배열들의 길이가 전부 1이 되면, 역순으로 배열 내 원소들의 크기를 비교하며 다시 합친다.
3. 2번 과정을 원래 크기의 배열이 될 때까지 반복한다.

### 코드(오름차순 정렬)

```python
def divide(list):

    if len(list) <= 1:
        return list

    mid = len(list)//2
    left = list[:mid]
    right = list[mid:]

    left_completed = divide(left)
    right_completed = divide(right)
    return merge(left_completed,right_completed)
```

- 반으로 계속 나누는 함수
- 순환 호출을 이용하여 길이가 1이 될 때까지 나눈다.
- 전부 1이 되면, merge 함수를 호출하여 합친다.

```python
def merge(left,right):

    result = []         # 결과를 담을 리스트

    while len(left) > 0 or len(right) > 0:  # 분할한 리스트(왼쪽/오른쪽) 길이가 0보다 크다면 반복
        if len(left) > 0 and len(right) > 0:
            if left[0] <= right[0]:    # 왼쪽 리스트의 처음 값이 더 작으면
                result.append(left[0])
                left = left[1:]       # 결과 리스트에 넣은 값은 삭제
            else:
                result.append(right[0])
                right = right[1:]
        elif len(left) > 0:
            result.append(left[0])
            left = left[1:]
        elif len(right) > 0:
            result.append(right[0])
            right = right[1:]
    return result
```

### 장점

- 매우 빠르다. (효율적)

### 단점

- 구현의 복잡성

### 시간복잡도

- O(nlog₂n)

#

## 피보나치 수열 (Fibonacci)

### 정의

- 첫째 및 둘째 항이 1이며 그 뒤의 모든 항은 바로 앞 두 항의 합인 수열
- F(n) = F(n-1) + F(n-2)

### 원리

</br>

- n번째 피보나치 수를 Fn이라 하는 2 x 2 행렬

<p align="center"><img src="https://user-images.githubusercontent.com/113777043/210164058-574a1555-a266-4eb3-9f80-d46a7cf779c7.png"></p>

<p align="center"><img src="https://user-images.githubusercontent.com/113777043/210164101-919afcf8-8faa-4ed0-9295-44637dc5ab00.png"></p>

- n이 1이 될 때까지 반으로 계속 분할하고 계산하면 Fn을 구할 수 있다.

**n = 짝수**
<p align="center"><img src="https://user-images.githubusercontent.com/113777043/210164140-01b1cd36-e015-4667-9fec-88321cd6786e.png"></p>

**n = 홀수**
<p align="center"><img src="https://user-images.githubusercontent.com/113777043/210164171-84640964-cd66-4bd2-ba89-05191660ae6a.png"></p>

</br>

### 코드

```java
public static matrix pow (matrix A, int n) {

        if (n > 1) {

            A = pow (A, n/2);
            //짝수일 경우 반으로 나누기
            A = multi (A, A);

            if (n % 2 == 1) {
                //홀수일 경우

                matrix B = new matrix(); // {1, 1}
                                         // {1, 0}
                A = multi (A, B);

            }
        }

        return A;

    }

```

### 장점

- 재귀함수를 사용하지 않고 행렬과 분할정복을 사용하여 메모리, 시간 측면에서 효율적이다.

### 단점

- 분할한 데이터들을 스택에 담기에 스택 오버플로우가 발생할 

### 시간복잡도

- 재귀 => O(2^n)
- 행렬과 분할정복 => O(log2n)
