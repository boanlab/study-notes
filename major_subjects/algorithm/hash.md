# 해시 (Hash)









---

## 해시 함수

### 나눗셈법(Division Method)

**정의**

- 해시 함수를 적용하고자 하는 값을 테이블 크기(N)으로 나눈 나머지 해시값으로 사용하는 방법
- **h(k) = k mod N**
    - 이때 N은 소수를 사용하는 것이 좋음
- 가장 기본적이고 많이 쓰이는 방법

**코드**

```python
def hash_func(self,key):
	return key % self.size
```
