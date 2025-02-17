# NOSQL(Not Only SQL)

### NOSQL
- `특정 데이터 모델`과 `특정 목적`에 맞추어 DB를 설계하여 현대적인 프로그램 구축에 용이함
- 개발의 용이성, 기능성, 확장성 측면에서 이점이 있음
- SQL VS NO SQL
    1. 데이터 모델
        - 모든 요소들이 정확하게 규정되어있는 sql과는 달리 no sql은 성능과 규모 확장에 최적화된 `다양한 모델`을 제공
    2. ACID 속성
        - SQL의 ACID 속성과 달리 NO SQL은 `수평 확장`을 위한 유연한 데이터모델을 위해 ACID속성을 완화시킴
- NO SQL의 종류
    - Document DB
    - Key Value DB
    - Graph DB
---
### document DB
- 데이터를 `json document` 형태로 저장
- 어떤 종류의 어떤 모양의 데이터든 저장 가능
- 개발자들이 자신의 어플리케이션에서 사용하는 것과 동일한 형식을 사용하여 `손쉽게 데이터를 저장하고 처리` 할 수 있음.
    ``` 
    [
        {
            "이름" : "홍길동",
            "사진" : "{이미지 주소}",
            "수강과목" : ["db","os"],
            "정보" : {
                "학번" : 12345678,
                "학년" : 3,
                "주소" : "~~"
            }
        }
    ]
    ```
- 대표적으로 몽고DB가 이에 해당됨
---
### key value DB
- 정의 : `키-값 메소드`를 사용하여 데이터를 저장, 단순한 객체에서 복잡한 집합체까지 모든것이 키가 될수 있음
- 특징
    - 단순 데이터 모델 : 모든 데이터가 키-값 쌍으로 되어있는 단순한 데이터 모델로 사용하거나 유지하는것이 편함
    - 빠른 읽기, 쓰기 : 읽고 쓰는것이 `매우 빠른`것이 특징
    - 확장성 : 수평확장이 가장 용이한 형태의 DB
    - DB의 타입에 제한적 `미리 어떤 데이터를 얻을지 고민하고 설계`
- 대표적인 DB : Dynamo DB, Cassandra DB
    |key|value|
    |---|---|
    |k1|v1|
    |k2|v2|
    |k3|v3|
    |k4|v4|
    
---
### graph DB
- 정의 
    - 노드와 엣지로 구성된 데이터베이스
    - 노드에는 데이터의 개체를 저장하고 엣지에는 각 개체들간의 관계를 저장
- 특징
    - 유연성 : 개발자가 json이나 xml등 다양한 형식으로 데이터를 추가 할 수 있음
    - 관계 중심 : 각 개체 간의 관계를 기반으로 데이터를 저장하여 복잡한 관계를 잘 표현
    - 빠른 쿼리 : 빠른 쿼리 및 검색에 최적화 되어있음
    - 확장성 : 수평적으로 확장되도록 설계되어 높은 수준의 동시 읽기,쓰기 작업을 처리할 수 있음
- 대표적인 DB : Neo4j, arangoDB
<img src=graphDB.png width="60%">


