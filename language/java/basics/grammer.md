# Java

## 클래스와 메소드

### 클래스란? 
  > 변수(데이터, 속성)와 메서드(행위)를 가지고 있는 집합, 객체를 생성하기 위한 틀
  > new 키워드를 통해서 인스턴스를 생성 가능

### 메서드란? 
  > 특정 기능을 수행하기 위해 필요한 명령어의 집합

## 기본 구조

```java
public class BoanLab{
  public static void main(String[] args){

    System.out.println("Hello BoanLab");

  }
}
```

## 객체 지향(Object-Oriented)

### Intstance
  > 클래스에서 객체를 생성하는 과정, 생성된 인스턴스들은 각자 다른 멤버 변수 값을 가질 수 있으며, 메서드 출력 값을 가질 수 있음

  - 예시
    ```java
    Person p = new Person(); // 인스턴스 생성
    
    ```

**Use dot(.) to access instance fields**

```java
public class Person {
  int age;
  
  public static void main(String [] args) {
    Person p = new Person();

    p.age = 20; // 인스턴스 멤버 변수 접근
  }
}
```

### Constructor
> 인스턴스를 생성과 동시에 인스턴스 변수 초기값을 생성할 수 있는 메소드

```java
public class Person {
  int age;
  String name;
  
  /* Constructor */
  public Person(int age, String name) {
    this.age = age;
    this.name = name;
  }

  /* Default Constructor */
  public Person() {
    ···
  } 
  
  public static void main(String [] args) {
    Person p = new Person(50,"Jordan"); // 인스턴스 생성
  }
}
```


## Operators

```
++, --  // 증감 연산자
+, -, *, /, % // 산술 연산자
>, <, >=, <=, ==, != // 비교 연산자
&&, ||, ?: // 논리 연산자
```
```
~, &, ^, |, <<, >>, >>> // 비트 연산자
```
```
+=, -=, *=, /=, %=, <<=, >>=, &=, ^=, ~= // 대입 연산자
```
```
(type) x; // type cast
```


##

## Data type

```
boolean -> 8-bits         //    Wrapper -> Boolean(객체)
```
```
char -> 16-bits           //    Wrapper -> Character(객체)
```
```
byte -> 8-bits            //    Wrapper -> Byte(객체)
short -> 16-bits          //    Wrapper -> Short(객체)
int -> 32-bits            //    Wrapper -> Integer(객체)
long -> 64-bits           //    Wrapper -> Long(객체)
```
```
float -> 32-bits          //    Wrapper -> Float(객체)
double -> 64-bits         //    Wrapper -> Double(객체)
```

## String

```java
String s1 = "Hello"
String s2 = "World"
```
**length()**
```java
s1.length() // String 길이
// 5
```

**concat()**
```java
String s3 = s1.concat(s2) // 접합
// s3 = "HelloWorld"
```

**equals()**
```java
s1.equals(s2) // s1과 s2 일치 여부
// false
```

**indexOf()**
```java
s1.indexOf('e') // s1에서 e에 해당하는 index
// 1
s1.indexOf('ell') // s1에서 ell이 존재하는 첫 index
// 1
```

**charAt()**
```java
s1.charAt(0) // 0번 index에 해당하는 char
// 'H'
```

**toUpperCase()**
```java
s1.toUpperCase() // or toLowerCase() // 대문자 -> 소문자 or 소문자 -> 대문자
// "HELLO" // or 'hello'
```


## Scanner

```java
Scanner sc = new Scanner(System.in); 
```
```java
sc.next() : String                // 공백 문자 만날 때까지
sc.nextLine() : String            // 줄바꿈 문자 만날 때까지
```
```java
sc.nextByte() : byte              // byte형 정수로
sc.nextShort() : short            // short형 정수로
sc.nextInt() : int                // int형 정수로
sc.nextLong() : long              // long형 정수로
sc.nextFloat() : float            // float형 실수로
sc.nextDouble() : double          // double형 실수로
```

## Enum

```java
public enum Phone {
  GALAXY, IPHONE, XIAOMI;
}
  
```

**values()**
```java
/* for-each */
for ( Phone phones : Phone.values()){

  System.out.println(phones);
    
}
    
//GALAXY
//IPHONE
//XIAOMI
```

**ordinal()**
```java
Phone phone = Phone.IPHONE;

phone.ordinal() // 인덱스 출력
// 1
```

**valueOf()**

```java
Phone.valueOf("IPHONE")
// IPHONE
```


## Array & ArrayList

### Array
> 선형 자료구조로 동일한 자료구조름 가진 유사한 데이터의 모임
> 고정된 길이를 가짐

- 예시
```java
int[] myWishScore = {98, 99, 100};
```
```java
//same above
int[] myWishScore = new int[3];

myWishScore[0] = 98;
myWishScore[1] = 99;
myWishScore[2] = 100;
```
### 2D Arrays ( Two Dimensional )

```java
int[][] arr = {
  {1,2,3},
  {4,5,6}
};
```
```java
String[][] animals;

animals = new String[][] {
  {"lion", "tiger"},
  {"cat", "dog"},
  {"fox", "wolf"}
};     
```

**Row-Major**

```java
/* 행 우선 */
for(int i = 0; i < animals.length; i++) {
  for(int j = 0; j < animals[i].length; j++) {
    System.out.println(animals[i][j]);
  }
}
```
**Column-Major**

```java
/* 열 우선 */
for(int i = 0; i < animals[0].length; i++) {
  for(int j = 0; j < animals.length; j++) {
    System.out.println(animals[j][i]);
  }
}
```

### ArrayList
> Array와 유사하지만 동적 길이 배열이라는 차이점을 가짐

- 예시
```java
ArrayList<String> students = new ArrayList<String>();

//add to the ArrayList
students.add("json");
students.add("gson");

//remove from the ArrayList
students.remove(0) // index 기반 삭제
// students.remove("json"); // 내용 기반 삭제
```

## Condition

- if
```java
if (condition) {
  // true
}
```

- if-else
```java
if (condition) {
  // true
} else {
  // false
}
```

- switch
```java
switch (flag) {
  case 0:
    // statement
    break;
  case 'a':
    // statement
    break;
  default:
    // statement
    break;
}
```




## Loops

**for-each**

```java
int[] myWishScore = {98, 99, 100};

for ( int score : myWishScore) {
  System.out.println(score)
}

//98
//99
//100

```



## Inheritance
> 부모의 기능을 그대로 가져오며, 필요에 따라 기능 추가 및 재정의가 가능함

```java
// Parent class
class Animal {
  public void feeding() {
    System.out.println("Animal Yummy!");
  }
}

// Child class
class Cat extends Animal {
  public void feeding() {
    System.out.println("Cat Yummy!"); // 함수 내용 재정의
  }
}

class MainClass {
  public static void main(String[] args) {
    Animal animal = new Animal();           // Animal object
    Animal cat = new Cat();                 // Cat object
    
    animal.feeding();                       // prints "Animal Yummy!"
    cat.feeding();                          // prints "Cat Yummy!"
  }
}
```


## Generic
> 특정 데이터 타입을 클래스 내부에서 지정하는 것이 아닌 외부에서 사용자에 의해 지정되는 것을 의미

- 주로 쓰는 타입
  
```
  - <T>	      // Type
  - <E>	      // Element
  - <K>	      // Key
  - <V>	      // Value
  - <N>	      // Number
```
  
- 주의할 점
  - 타입 파라미터로 명시할 수 있는 것은 참조 타입(Reference Type) 뿐이다.
  
- 참조 타입이란?
  - 사용자의 정의한 클래스나 Integer, Double 같은 Wrapper(기본 자료형의 객체) 타입
  
- 왜 Generic을 쓰는가?

  - 정적(static) 메소드로 선언할 때 필요하기 때문
  
- 잘못된 예

  ```
  class Name <E> {
  
    /* static method는 객체가 생성되기 이전에 메모리에 먼저 올라가기 때문에 
    E 타입을 클래스로부터 얻어올 방법이 없음 */
    
    static E genericMethod (E e) {
    
      return e;
      
    }
  }
  ```
  
  - Main
  
  ```
  Name.genericMethod(3);    //error
  ```
  
  #
  
  
  - 좋은 예
    
  ```java
  class Name <E> {
    /* [접근 제어자] <제네릭타입> [반환타입] [메소드명]([제네릭타입] [파라미터]) */
    static <E> E genericMethod (E e) {
  
    return e;
    }
  }
  ```
  
  ```java
  /* 메인 함수 */
  Name.genericMethod(3);                        // 3
  Name.genericMethod(3).getClass().getName();   //  java.lang.Integer
  ```

## Comment

- 한 줄 주석
```java
// comment
```

- 여러 줄 주석
```java
/*
    comment
*/
```
