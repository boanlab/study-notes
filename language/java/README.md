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



## Comment

```
// comment
```

```
/*
    comment
*/
```
