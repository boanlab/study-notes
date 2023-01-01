# SQL
- 의미
    - 구조화 질의어
    - 종합 데이터베이스 언어
        - 검색 뿐만 아니라 여러 역할을 함
    - `DDL, DML, DCL`의 기능 모두 제공
- 특징 
    - 관계 대수 + 확장된 튜플 관계 해석 기초
    - `비 절차적 언어`(사용자 친화적)
    - 터미널을 통해 `대화식 질의어`
    - 응용 프로그램에 삽입된 형태로도 사용가능
    - 명령문에 `접근경로 명세 불필요`
---
### 데이터 정의문(DDL)
- 테이블 생성
    - 기본테이블
        - `CREATE TABLE`문으로 만들어짐
        - DBMS의 파일로 저장
    - 가상 테이블
        - CREATE VIEW로 만들어짐
        - 기본테이블에서 유도되어 만들어짐
        - 독자적으로는 존재 X
    - 임시 테이블
        - 질의문 처리 과정에서 임시로 만들어지는 테이블
    - ex) CREATE TABLE 학생({이름 VARCHAR(20),학번 INT,학년 INT})
    - 명령어
        - PRIMARY KEY : 기본키로 생성
        - UNIQUE : 후보키로 생성
        - NOT NULL : NULL값을 가질 수 없음
        - FOREIGN KEY : 외래키와 참조 무결성 제약조건 명세
        - SET NULL : 삭제되면 NULL로 설정
        - CASCADE : 참조하고 있는 다른테이블에 컬럼도 같이 UPDATE OR DELETE
        - CHECK : 제약조건 설정
- 테이블 제거
    - DROP TABLE {테이블 이름}
        - RESTRICT : 참조하는 테이블이나 제약조건 있으면 실행 실패
        - CASCADE : 참조하는 테이블이나 제약조건도 같이 삭제
    - EX) DROP TABLE 학생 CASCADE;
- 스키마 제거
    - DROP SCHEMA {스키마 이름}
- 테이블 변경
    - ALTER TABLE {테이블 이름} {ADD, DROP, ALTER} 열이름 조건
    - EX) ALTER TABLE 학생 DROP 성적 CASCADE;
---
### 데이터 조작문(DML)
- SELECT(검색)
    - DB안에 데이터를 조회할 때 사용
    - SELECT [ALL|DISTINCT] 속성 FROM 테이블 [WHERE] [GROUP BY] [ORDER BY]
        - ALL|DISTINCT : 중복되는 내용이 있을 시 어떻게 처리할지 정하는것 생략시 ALL
        - WHERE : 검색할 데이터에 조건을 설정, 생략시 모든 내용 검색
        - GROUP BY : HAVING과 함께 사용하여 집계함수를 사용할 수 있다.
        - ORDER BY : 검색된 내용을 정렬, ASC(오름차순) DESC(내림차순) 생략시 ASC
        - JOIN : 조인으로 두가지 이상의 테이블을 참조하여 검색 가능
    - LIKE : WHERE절에서 주로 사용하여 `포함되는 내용`을 찾을떄 사용됨
        - _ : 모든 문자 하나를 의미(EX 과목 LIKE '데이_베이스')
        - % : 글자수를 정해두지 않음(EX 과목 LIKE '데이터%')
- UPDATE(갱신)
    - 레코드를 수정할 때 사용
    - UPDATE 테이블 SET 튜플의속성=C WHRER 조건
- INSERT(삽입)
    - 테이블에 레코드를 새로 넣을 때 사용
    - INSERT INTO 테이블(속성1,속성2,..속성N) VALUES (값1,값2,...,값N)
- DELETE(삭제)
    - 테이블의 레코드를 삭제
    - DELETE FROM 테이블 WHERE 속성 = C
---
### 뷰(가상테이블)
- 하나 이상의 `기본 테이블로부터 유도`되어 만들어지는 `가상 테이블`
- 여러 테이블에서 필요한 정보를 조회하기 위해 만들어진 가상의 테이블 `일종의 함수`라고도 볼 수 있음
- 생성
    - CREATE VIEW 뷰이름(속성1,속성2,...) AS SELECT 참조속성1,참조속성2,... FROM 참조테이블 [WITH CHECK OPTION]
        - WITH CHEK OPTION : 뷰 정의 조건에 따라 검사
- 삭제
    - DROP VIEW 뷰이름 {RESTRICT | CASCADE}
- SELECT문은 모든 뷰에서 사용 가능하지만 변경은 제한적임
    - 뷰의 연산이 허용되지 않는 경우
        1. 뷰의 열이 상수나 산술식으로 이루어져있는 경우
        2. 집계 함수가 관련되어 정의된 경우
        3. DISTINCT, GROUP BY, HAVING절이 사용되어 정의된 경우
        4. 두 개 이상의 테이블이 관련되어 정의된 경우
        5. 변경할 수 없는 뷰로 만들어진 뷰의 경우
- 뷰의 장점
    - `독립성` : 테이블이 변해도 뷰에서 조회한 내용이 그대로 라면 응용프로그램 그대로 사용 가능
    - `보안성` : 사용자에 권한에 따라 열람 가능한 컬럼을 정의한 뷰를 생성하면 접근 제어 가능
    - `편리성` : 자주 사용되는 쿼리를 미리 뷰로 정의해두어 추후 간단한 조회 가능
---
### 삽입 SQL
- SQL문을 응용프로그램에서도 사용 가능
- 삽입 SQL 특징
    - 명령문 앞에 `EXEC SQL` 붙임
    - SQL문에서 사용되는 호스트 변수(DB에서 속성이나 필드명)앞에 : 를 붙임
    - 호스트 변수 SQLSTATE는 성공과 경고를 피드백함
- EX) EXEC SQL DELETE FROM 학생 WHERE 학번 = :학번;



