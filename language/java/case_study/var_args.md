# 가변 인자

```java
public class VarArgs {
    /* 가변인자 표현: "..." */
    public static void print(int ... args) {
        for (int arg: args)
            System.out.printf(m+"\t");
        System.out.println();
    }

    public static void main(String[] args) {
        int[] mm = {1, 6, 16, 22, 23, 33};
        int a = 1, b = 6, c = 124;

        print(mm);
        // 1  6  16  22  23  33

        print(a, b, c);
        // 1  6  124
    }
}
```