# Java

## Class & Method

```
public class BoanLab{

  public static void main(String[] args){
  
    System.out.println("Hello BoanLab");
    
  }
  
}
```

## Operators

```
++, --
+, -, *, /, %
>, <, >=, <=, ==, !=
&&, ||, ?:
```
```
~, &, ^, |, <<, >>, >>>
```
```
+=, -=, *=, /=, %=, <<=, >>=, &=, ^=, ~=
```
```
(type) x; // type cast
```


##

## Data type

```
boolean -> 8-bits         //    Wrapper -> Boolean
```
```
char -> 16-bits           //    Wrapper -> Character
```
```
byte -> 8-bits            //    Wrapper -> Byte
short -> 16-bits          //    Wrapper -> Short
int -> 32-bits            //    Wrapper -> Integer
long -> 64-bits           //    Wrapper -> Long
```
```
float -> 32-bits          //    Wrapper -> Float
double -> 64-bits         //    Wrapper -> Double
```

## String

```
String s1 = "Hello"
String s2 = "World"
```
**length()**
```
s1.length() 
// 5
```

**concat()**
```
String s3 = s1.concat(s2) 
// s3 = "HelloWorld"
```

**equals()**
```
s1.equals(s2) 
// false
```

**indexOf()**
```
s1.indexOf('e')
// 1
s1.indexOf('ell')
// 1
```

**charAt()**
```
s1.charAt(0)
// 'H'
```

**toUpperCase()**
```
s1.toUpperCase() // or toLowerCase()
// "HELLO" // or 'hello'
```


## Scanner

```
Scanner sc = new Scanner(System.in);
```
```
sc.next() : String                // 공백 문자 만날 때까지
sc.nextLine() : String            // 줄바꿈 문자 만날 때까지
```
```
sc.nextByte() : byte              // byte형 정수로
sc.nextShort() : short            // short형 정수로
sc.nextInt() : int                // int형 정수로
sc.nextLong() : long              // long형 정수로
sc.nextFloat() : float            // float형 실수로
sc.nextDouble() : double          // double형 실수로
```

## Enum

```
public enum Phone {

    GALAXY, IPHONE, XIAOMI;
  
    }
  
```

**values()**
```
for ( Phone phones : Phone.values()){

    System.out.println(phones);
    
    }
    
//GALAXY
//IPHONE
//XIAOMI
```

**ordinal()**
```
Phone phone = Phone.IPHONE;

phone.ordinal()
// 1
```

**valueOf()**

```
Phone phone = Phone.IPHONE;

phone.valueOf()
// IPHONE

```



    



## Array & ArrayList

```
int[] myWishScore = {98, 99, 100};
```
```
//same above
int[] myWishScore = new int[3];

myWishScore[0] = 98;
myWishScore[1] = 99;
myWishScore[2] = 100;
```
```
ArrayList<String> students = new ArrayList<String>();

//add to the ArrayList
students.add("json");
students.add("gson");

//remove from the ArrayList
students.remove(0) or
students.remove("json");
```

## Condition

```
if (condition) {
    // true
}
```
```
if (condition) {
    // true
} else {
    // false
}
```
```
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

**for each**

```
int[] myWishScore = {98, 99, 100};

for ( int score : myWishScore) {

      System.out.println(score)
    
}

//98
//99
//100

```


## Object-Oriented

### Intstance

****p is an instance of the class Person****

```
Person p = new Person();
```

**Use dot(.) to access instance fields**

```
public class Person {
  int age;
  
  public static void main(String [] args) {
    Person p = new Person();

    p.age = 20;
  }
}
```

### Constructor

```
public class Person {
  int age;
  String name;
  
  //Constructor
  public Person(int age, String name) {
  
    this.age = age;
    this.name = name;
    
  }
  
  public static void main(String [] args) {
    
    Person p = new Person(50,"Jordan");
    
  }
}
```

## Inheritance

```
// Parent class
class Animal {

  public void feeding() {
  
    System.out.println("Animal Yummy!");
    
  }
}

// Child class
class Cat extends Animal {

  public void feeding() {
  
    System.out.println("Cat Yummy!");
    
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

## 2D Arrays ( Two Dimensional )

```
int[][] arr = {
                {1,2,3},
                {4,5,6}
              };
```
```
String[][] animals;

stringValues = new String[][] {
                                {"lion", "tiger"},
                                {"cat", "dog"},
                                {"fox", "wolf"}
                              };     
```

**Row-Major**

```
for(int i = 0; i < animals.length; i++) {
    for(int j = 0; j < animals[i].length; j++) {
        System.out.println(animals[i][j]);
    }
}
```
**Column-Major**

```
for(int i = 0; i < animals[0].length; i++) {
    for(int j = 0; j < animals.length; j++) {
        System.out.println(animals[j][i]);
    }
}
```

## Generic

  - 정의
    - 특정 데이터 타입을 클래스 내부에서 지정하는 것이 아닌 외부에서 사용자에 의해 지정되는 것을 의미
  
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
    - 사용자의 정의한 클래스나 Integer, Double 같은 Wrapper 타입
    
  - 왜 Generic을 쓰는가?
  
    - 정적(static) 메소드로 선언할 때 필요하기 때문이다.
    
    - 잘못된 예
    
    ```
    class Name <E> {
    
      // static method는 객체가 생성되기 이전에 메모리에 먼저 올라가기 때문에 
      // E 타입을 클래스로부터 얻어올 방법이 없다.
      
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
    
    - 제네릭이 사용되는 메소드를 정적메소드로 두고 싶은 경우
      제네릭 클래스와 별도로 독립적인 제네릭이 사용되어야 한다.
      
    ```
    class Name <E> {
    
      
     // [접근 제어자] <제네릭타입> [반환타입] [메소드명]([제네릭타입] [파라미터])
     
        static <E> E genericMethod (E e) {
      
        return e;
        
      }
    }
    ```
    
    - Main
    
    ```
    Name.genericMethod(3);                        // 3
    Name.genericMethod(3).getClass().getName();   //  java.lang.Integer
    ```
    
    
    





## Comment

```
// comment
```

```
/*
    comment
*/
```
