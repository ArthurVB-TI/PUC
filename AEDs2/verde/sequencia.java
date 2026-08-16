import java.util.Scanner;

public class sequencia{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean v = true;
        while(v){
            try{
                int a = sc.nextInt();
                int b = sc.nextInt();
                mostrar(a, b);
            } catch(Exception e){
                v = false;
            }
        }
        sc.close();
    }

    public static void mostrar(int a, int b){
        StringBuilder sb = new StringBuilder();
        for(int i = a; i <= b; i = i + 1) sb.append(i);
        String parte1 = sb.toString();
        String parte2 = new StringBuilder(parte1).reverse().toString();
        System.out.println(parte1 + parte2);
    }
}