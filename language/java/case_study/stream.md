# Stream
    - 순차적으로 나열된 데이터
    - filter, map, reduce 기능 제공
        - filter: 조건에 맞는 수를 찾아내는 함수, 
        - map: map은 요소들을 특정조건에 해당하는 값으로 변환
        - reduce: Stream에 요소들을 하나의 데이터로 처리하는, 즉, 모두 합치는 기능을 하는 함수, 매개변수는 accumulator(합) 함수

**filter,reduce**
public class MyStream {
    public static void main(String[] args) {
        List<Integer> myList = new ArrayList<>();
        int s = 0;

        for (int i=0; i<=100; i++) {
            myList.add(i);
        }

        /* 1 ~ 100까지의 합 */
        s = myList.stream().reduce(0, Integer::sum);

        System.out.println("1에서 100까지의 합: "+s);

        /* 1 ~ 100까지의 홀수의 합 */
        /* filter : 조건에 맞는 수 골라냄 */
        /* ::를 사용하여 파라미터(i) 중복 없이 사용 가능 */
        s = myList.stream().filter(i -> i%2 == 1).reduce(0, Integer::sum); // filter: 조건에 맞는 수 골라냄
        System.out.println("1 ~ 100까지의 홀수의 합: "+s);

        /* 위와 동일 */
        /*
        s = myList.stream().filter(i -> i%2 == 1).reduce(0, (x, y) -> x+y); // 0 + 1 + 3 + 5 + ... + 99
        System.out.println("1 ~ 100까지의 홀수의 합: "+s);
        */

        /*
        s = myList.stream().filter(i -> i%2 == 1).reduce(0,
                new BinaryOperator<Integer>() {
                    @Override
                    public Integer apply(Integer x, Integer y) {
                        return x+y;
                    }
                });
        System.out.println("1 ~ 100까지의 홀수의 합: "+s);
        */

    }
}

**map**

```java
public class MyStream {
    public static void main(String[] args) {
       ArrayList<String> list = new ArrayList<>(Arrays.asList("Apple", "Banana", "Pineapple", "Strawberry"));

        // joining의 파라미터의 기호를 기준으로 요소를 구분함, 해당 코드에서는 /로 구분
        System.out.println(list.stream().map(s -> s.toUpperCase()).collect(Collectors.joining("/")));

        System.out.println(list.stream().map(String::toLowerCase).collect(Collectors.toList()));
    }
}
```
