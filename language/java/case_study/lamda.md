# Lamda 식

```java
public class MyLamda {
    public static void main(String[] args) {
        List<Integer> myList = Arrays.asList(1, 6, 16, 22, 23, 33);

        myList.forEach(
            /* m은 myList의 따라 Integer */
            m -> {
                System.out.printf(m+"\t");
            }
        );
        
        // 결과: 1 6 16 22 23 33

        System.out.println();

        Consumer<Integer> consume = (Integer m) -> {
            System.out.printf(m+"\t");
        };
        

        myList.forEach(consume);
        // 위와 결과 동일
    }
}
