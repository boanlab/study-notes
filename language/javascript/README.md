# Javascript

## Operators


```
+, -, *, /, %                  // 산술 연산자
=, +=, -=, *=, /=, %=          // 대입 연산자
++, --                         // 증감 연산자
==, ===, !=, !==, >, >=, <, <= // 비교 연산자
&&, ||, !                      // 논리 연산자
&, !, ^, ~, <<, >>, >>>        // 비트 연산자
```

```
expr1 ? expr2 : expr3        // 삼항 연산자
delete exp[idx]              // delete 연산자
typeof operand               // typeof 연산자
expr1 instanceof (Data type) // instanceof 연산자 
```

## Data type

### Primitive type

```
typeof 3             // "number" -> Number(숫자)
typeof 1.24          // "number" -> Number(숫자)
typeof "Hello world" // "string" -> String(문자열)
typeof true          // "boolean" -> Boolean(불리언)
typeof null          // "object" -> null
typeof undefined     // "undefined" -> undefined
typeof Symbol()      // "symbol" -> Symbol(ES6에 추가)
```

### Reference type

```
typeof {boanLab:0}        // "object" -> Object(객체)
typeof [522, 502, 2]      // "object" -> Array
typeof function(){}       // "function" -> Function
typeof new Date()         // "object" -> Date
// RegExp
typeof /s/ === "function" // Chrome 1-12 Nonconform to ES5
typeof /s/ === "object"   // Firefox 5+ Conform to ES5
typeof new Map()          // "object" -> Map
typeof new WeakMap()      // "undefined" -> WeakMap
typeof new Set()          // "object" -> Set
typeof new WeakSet()      // "object" -> WeakSet
```

## Declarations & Initialization

```
var   -> 함수 스코프(scope)를 가짐
const -> 블록 스코프를 가짐, 변수에 값을 한 번만 대입 가능
let   -> 블록 스코프를 가짐, 변수에 값을 다시 대입 가능
```

### var
```
var x = 1;          // 변수 선인 및 초기화

if (x === 1) {
    var x = 2;      // var는 변수를 선택적 초기화 가능

    console.log(x); // expected output: 2
}

console.log(x);     // expected output: 2
```

### let

```
let x = 1;          // 변수 선언 및 초기화

if (x === 1) {
    let x = 2;      // 변수 재선언

    console.log(x); // expected output: 2
}

console.log(x);     // expected output: 1
```

```
let x = 1;

if (x === 1) {
    x = 2;          // let는 변수에 값을 다시 대입 가능

    console.log(x); // expected output: 2
}

console.log(x);     // expected output: 2
```

### const

```
const boanLab = 522;     // 변수 선언 및 초기화

try {
    const boanLab = 99;  // 변수 재선언
    
    console.log(boanLab) // expected output: 99
} catch (err) {
    console.log(err); 
}

console.log(boanLab);    // expected output: 522
```

```
const boanLab = 522;  // 변수 선언 및 초기화

try {
    boanLab = 99;     // const는 변수에 재할당 불가능
} catch (err) {
    console.log(err); // TypeError: invalid assignment to const `boanLab`
}

console.log(boanLab); // expected output: 522
```

## Condition

```
if (condition) {
    // true 
}

if (condition) // true -> 구문이 하나일 때
```

```
if (condition) {
    // true
} else {
    // false
}

// if-else 구문의 중첩
if (condition1) {
    // true
} else if (condition2) {
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
}
```

## Iteration

```
for (let i = 0; i<LAST; i++) {
    // statement
}
```

```
// 배열의 순회 방법
const arr = [1, 2, 3, 4, 5]

for (let i=0; i<arr.length; i++) {
    console.log(i);
}

arr.forEach((item, index) => {
    console.log(i);
})

for (let item of arr) {
    console.log(i);
}
```

```
while (flag) {
    // statement
}
```

```
do {
    // statement
} while (flag);
```

```
break;    // 루프를 종료하고 다음 코드로 넘어감
continue; // 루프의 나머지 코드를 건너뜀
```

```
return; // 함수의 나머지 코드를 건너뛰고 함수를 즉시 종료함
throw;  // 코드의 실행을 중단시키고 에러를 발생시킴
```

## Comment

```
// comment
```

```
/*
    comment1
    comment2
    ...
*/
```

## Function

```
function functionName(parameter1, parameter2, ...) {
    // 
    
    return value;
}
```

### function*

```
function* generator(i) {
  yield i;
  yield i + 10;
}

const gen = generator(10);

console.log(gen.next().value); // expected output: 10

console.log(gen.next().value); // expected output: 20
```

## Object

```
// Create object using literal notation
const obj = {
    property name1 : property value1,
    property name2 : property value2,
    ...
};
```

```
// Create object using constructor
const day = new Date()      // new 연산자를 통해 Date 객체 생성
```

```
// Create object using Object.create() method
const obj = Object.create(prototype, {
    property name1 : property value1,
    property name2 : property value2,
    ...
});

obj.name1;                  // expected output: value1
obj.name2;                  // expected output: value2
Object.getPrototypeOf(obj); // expected output: prototype
```

## Array

```
// Create array using literal notation
var arr = [1, true, "BoanLab",...];

// Create array using constructor
var arrObj = Array(1, true, "BoanLab", ...);

// Create array using array object's new operator
var arrNewObj = new Array(1, true, "BoanLab", ...);
```
