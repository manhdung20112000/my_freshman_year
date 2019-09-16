import java.util.Scanner;
public class week3 {
    public static int gcd (int x, int y){
        if (y==0) return x;
        return gcd (y, x%y);
    }
    public static int fibonacci (int n){
        if (n <= 1) return n;
        return fibonaci(n-2) + fibonaci(n-1);
    }
    public static boolean primes (int n){
        if (n<2) return false;
        if (n==2) return true;
        if (n%2 == 0) return false;
        for (int i=3; i<=(n-1); i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    //fibonacci
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        System.out.print(fibonacci(n));
    }
    
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     int x = sc.nextInt();
    //     int y = sc.nextInt();
    //     sc.close();
    //     System.out.println(gcd (x, y));
    // }

    //primes
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     int n = sc.nextInt();
    //     sc.close();
    //     for (int i=1; i<n; i++){
    //         if(primes(i)) System.out.print(i + " ");
    //     }
    // }

    

}