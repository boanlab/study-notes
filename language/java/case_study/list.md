# List 사용

```java
import java.util.ArrayList;
import java.util.List;

public class MyList {
    public static void main(String[] args) {
        // 리스트 객체 생성
        List<Integer> myList = new ArrayList<>();

        for (int i=0; i<=11; i++) {
            myList.add(i);
        }
        
        System.out.println();

        for (int list: myList) {
            System.out.printf("%d\t", list);
        }
        // 1 ... 10

        /* 아래와 동일 */
        /* 
        for (int j = 0; j<myList.size(); j++){
            System.out.printf("%d\t", myList.get(j));
        }
        */
    }
}
```