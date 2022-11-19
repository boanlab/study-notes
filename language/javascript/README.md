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
