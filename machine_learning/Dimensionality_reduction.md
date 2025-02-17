# Dimensionality reduction

## 차원축소란?

- 매우 많은 피처로 구성된 다차원 데이터 세트의 차원을 축소해 새로운 차원의 데이터 세트를 생성하는 것
- 단순히 데이터를 압축X, 데이터를 잘 설명할 수 있는 잠재적인 요소 추출과적합을 방지

## 차원축소의 목적

- Curse of Dimensionality 차원의 저주 해결
    - 많은 차원의 데이터를 다루는 것은 효율성과 정확도가 감소함
- 실제 데이터에 영향을 미치는 고유차원은 작기 때문에 실제 영향을 미치는 차원만 추출하기 위해 사용
- 과적합을 방지하기 위해

## 차원축소의 장단점

### 차원축소의 장점

- 학습 데이터 크기를 줄여서 학습 시간 절약
- 불필요한 Feature 제거로 모델 성능 향상 기여 (주로 이미지 데이터)
    - 과적합을 방지
- 다차원 데이터를 3차원 이하의 데이터로 줄이면 시각화에 유용
- 추천 엔진, 이미지 분류 및 변환, 문서 토픽 모델링에서 유용
    - 텍스트 문서의 숨겨진 의미 추출 가능

### 차원축소의 단점

- 정보 손실 발생
- 차원 축소 후 데이터를 해석하는데 어려움
- 데이터가 변환되어 데이터 파이프 라인 복잡

## 차원축소의 종류

### 변수 선택

- 분석 목적에 부합하는 소수의 예측 변수만을 선택하는 것
    - 특정 변수에 종속성이 강한 불필요한 변수는 아예 제거
- 장점
    - 선택한 변수들의 해석이 용이
- 단점
    - 변수간 상관관계를 고려하기 어려움

### 변수 추출

- 예측변수의 변환을 통해 새로운 변수 추출
    - 기존 변수를 저차원의 중요 변수로 압축해서 추출
- 장점
    - 변수간 상관관계 고려
    - 변수의 개수를 많이 줄일 수 O
- 단점
    - 추출된 변수의 해석이 어려움
