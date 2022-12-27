# 데이터 압축 (Data Compression)


## 데이터 압축

- 데이터를 더 적은 저장 공간에 효율적으로 기록하기 위한 기술

**손실 압축** : 중복되고 필요하지 않은 정보가 손실되는 것을 허용

**무손실 압축** : 자료의 손실이 없으며 입출력 영상이 완전히 동일하도록 압축

- 반복 길이 부호화
- 허프만 부호화
- 산술 부호화


</br>

## RLE(Run-Length encoding)

### 정의

- **동일한 패턴이 반복**되는 문자열을 압축하는 알고리즘
- **무손실 압축** 방법 중의 하나

### 예시

- aaabbcccc → 3a2b4c

### 코드(simple)

```python
def rle(st):
    n = len(st)
    i = 0
    while i < n - 1:
				
        count = 1
        while (i < n - 1 and st[i] == st[i + 1]): # 반복 비교하면서 count 체크
            count += 1
            i += 1
			
        print(st[i] +str(count),end="") # count 완료되면 바로 출력

        i += 1
```
