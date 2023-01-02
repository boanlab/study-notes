import java.util.Scanner;

class matrix {

    long[][] data = new long [2][2];

    matrix() {

        data[0][0] = 1; data[0][1] = 1;
        data[1][0] = 1; data[1][1] = 0;

    }
}

public class kp_Fibonacci {

    // ��� ��
    public static matrix multi (matrix A, matrix B) {

        matrix result = new matrix();

        result.data[0][0] = ( A.data[0][0] * B.data[0][0] )
                            +( A.data[0][1] * B.data[1][0] );
        
        result.data[0][1] = ( A.data[0][0] * B.data[1][0] )
                            +( A.data[0][1] * B.data[1][1] );

        result.data[1][0] = ( A.data[1][0] * B.data[0][0] )
                            +( A.data[1][1] * B.data[1][0] );

        result.data[1][1] = ( A.data[1][0] * B.data[1][0] )
                            +( A.data[1][1] * B.data[1][1] );
                 
                            
        return result;

    }

    //������������ �Ǻ���ġ ���ϴ� �޼ҵ�
    public static matrix pow (matrix A, int n) {

        if (n > 1) {

            A = pow (A, n/2);
            //¦���� ��� ������ ������
            A = multi (A, A);

            if (n % 2 == 1) {
                //Ȧ���� ���

                matrix B = new matrix(); // {1, 1}
                                         // {1, 0}
                A = multi (A, B);

            }
        }

        return A;

    }

    public static long fibonacci (int n) {

        if (n==0) 
            return 0;

        matrix A = new matrix();
        A = pow(A, n);
        
        return A.data[0][1];
        //A.data[0][1]�� Fn��

    }

    public static void main (String[] args) {

        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        
        System.out.println(fibonacci(n));

        sc.close();
    }

}

