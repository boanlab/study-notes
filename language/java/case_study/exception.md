# 예외 처리

```java
public class ExceptionProcess {
    public static void main(String[] args) {
        String str = "H";

        /* 예외 처리 */
        try {
            int temp = Integer.parseInt(str);
            System.out.println(temp);
        } 
        catch (NumberFormatException e) {
            System.out.println("타입 확인"); // 타입 변환 오류 발생 시 예외 처리
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println("예외"); // NumberFormatException을 제외한 모든 예외 처리
        } finally {
            System.out.println("반드시 수행"); // 어떠한 경우에서든지 수행
        }
    }
}
```