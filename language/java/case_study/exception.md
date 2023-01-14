# 예외 처리

## 종류
    - Exception: 모든 예외 출력
    - ArithmeticException: 연산에서 발생하는 예외 처리

```java
public class ExceptionProcess {
    public static void main(String[] args) {
        String str = "H";

        try {
            int temp = Integer.parseInt(str);
            System.out.println(temp);
        } catch (Exception e) {
            System.out.println("예외"); // NumberFormatException을 제외한 모든 예외 처리
            System.out.println(e);
            // e.printStackTrace();

        } finally {
            System.out.println("반드시 수행"); // 어떠한 경우에서든지 수행
        }


    }
}
```

- 결과
```
예외
java.lang.NumberFormatException: For input string: "H"
반드시 수행
```