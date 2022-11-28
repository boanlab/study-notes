# 큐(Queue)


### 정의

- 스택과 마찬가지로 데이터를 일시적으로 쌓아 두기 위한 자료구조

### 특징

- 선입선출 구조 ( 먼저 넣은 데이터를 먼저 꺼낸다.)
  - ex) 대기열

### 용어

- 인큐(enqueue) 
  - 큐에 데이터를 넣는 작업
 
- 디큐(dequeue)
  - 큐에서 데이터를 꺼내는 작업

- 프론트(front) 
  - 데이터를 꺼내는 쪽
  - 큐의 맨 앞의 위치(인덱스)
    - ex) 대기열의 가장 앞 손님
 
- 리어(rear)
  - 데이터를 넣는 쪽
  - 큐의 맨 뒤에 위치(인덱스)
    - ex) 대기열 마지막 손님


### 구현
#
- 선형 큐 (Linear Queue)
  - 밑의 그림은 삭제 시 front 만 옮기는 구조
    - enqueue : rear = rear + 1
    - dequeue : front = front + 1
    - is_full : rear = size -1
    - is_empty : front == rear
![QueueArray](https://user-images.githubusercontent.com/88774925/204083365-1360ffc3-020e-4d35-91d8-ce9616375e72.jpg)

  - 단점
    - 삭제(dequeue)시 모든 값들을 하나하나 앞으로 옮겨주어야 하는 연산 발생
    - 위의 단점을 보완하여 front만 옮기는 경우에, 큐(배열)가 full 상태가 아님에도 삽입이 불가능해지는 문제 발생 가능성
    - 위의 단점은 순환 큐로 구현 시 해결 가능  
    
    
  #    
- 원형 큐 (Circular Queue)
  - 위의 단점을 해결한 구조
  - 선형 큐와 유사하나, 모듈러 연산 등이 추가된다. (원형 처럼 이루어져있다고 가정하기 위함)
    - enqueue : rear = (rear + 1) % size
    - dequeue : front = (front + 1) % size 
    - is_full : ((rear + 1) % size) == front
    - is_empty : front == rear
    - 큐의 한 부분은 사용 불가 (rear + 1 자리에 front 가 있음을 판단하기 위함)
![CircularQueue](https://user-images.githubusercontent.com/88774925/204096370-8ca1d47b-f261-4469-8b5d-0ce514da4659.jpg)


  - 장점
    - 선형 큐에 비해 상대적으로 메모리 낭비가 발생하지 않는다.
  
  - 단점
    - 배열로 구현하였기 때문에, 크기가 정적이다.

