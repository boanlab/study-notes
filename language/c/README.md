# C

## Main function

```
void main(void)
{
    //
}
```

```
int main(int argc, char *argv[])
{
    //
}
```

## Operators

```
++, --
+, -, *, /, %
==, !=, >, >=, <, <=
&, |, ^
&&, ||
```

```
+=, -=, *=, /=, &=, |=, ...
```

```
expr1 ? expr2 : expr3
```

```
TYPE1 x;
(TYPE2) x; // type cast
```

## Preprocessor

```
#include <filename> // include library file
#include "filename" // include user file
```

```
#define name text
#define name(param, ...) text
```

```
#if
#elif
#else
#endif
```

```
#ifdef
#ifndef
```

```
#if defined(name)
```

## Data type

```
char      -> character (1 byte)
short     -> 16-bit integer
int       -> 32-bit integer
long      -> 32-bit integer (Win) / 64-bit integer (Linux)
long long -> 64-bit integer
```

```
float     -> 32-bit real number
double    -> 64-bit real number
```

```
unsigned TYPE
```

## Declarations

```
signed -> positive / negative
unsigned -> non-negative (no sign bit)
TYPE* -> pointer of TYPE
```

```
const TYPE x
TYPE const x
```

```
int main()
{
    const int MAX=10;
    MAX = 15; // error

    int a=1, b=2;
    const int *p1 = &a;
    int* const p2 = &a;

    p1 = &b;
    *p1 = 3; // error

    p2 = &b; // error
    *p2 = 3;

    p3 = &b; // error
    *p3 = 3; // error
}
```

```
static TYPE func() {...} // only allow calling in the same file
static TYPE x; // keep x persistently
extern TYPE func() // allow other files to call func()
extern TYPE x; // allow other files to use x
```

```
typedef type name; // allow using name instead of type
```

```
sizeof(TYPE) -> size of data type
sizeof(object) -> size of object
```

## Initialization

```
type name = value;
type name1 = value1, name2 = value2;
type name[] = {value1, value2, ...};
```

```
char str[] = "string";
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

## Iteration

```
for (i=0; i<LAST; i++) {
    //
}
```

```
while (flag) {
    //
}
```

```
do {
    //
} while (flag);
```


```
break;
continue;
```

```
label:
    statement
```

```
goto label;
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

## Function

```
type func1(type1 param1, ..., typeN paramN);
```

```
type func1(type1 param1, ..., typeN paramN)
{
    //

    return value;
}
```

## Pointer

```
TYPE *name;
TYPE *func();
TYPE (*pfunc)();
*pointer
&name
name[index]
name[index1][index2]
NULL
```

## Structure

```
struct name {
    TYPE x;
    declarations
};
```

```
name.x
name->x
```

## Scanf Format

```
%d : integer
%f : float
%lf : double
%s : string // char array
%c : single character 

```


## Union

Point : 공유를 통한 메모리 절약

```

union Student
{
    char name[20];
    char major[32];
    char number[8];
    float credit;
}; 

### example

int main() {

    // declare
    union Student Hwan;
    // Student Hwan  typedef 

    Hwan.major = "Computer Engineering // error (Pointer)
    strcpy(Hwan.major, "Computer Engineering); 
    Hwan.credit = 4.3; // Hwan에는 4.3만 저장됨

    printf("%ld \n",sizeof(Hwan)); // 32bit (major)
    

    return 0;
}

```
