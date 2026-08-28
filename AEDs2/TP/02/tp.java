import java.util.Scanner;
import java.util.Random;

public class tp {
    private static Random r = new Random();

    private static int comparar(String texto1, String texto2, int i){
        int retorno = 0;
        if(i < texto1.length() && i < texto2.length()){
            if(texto1.charAt(i) != texto2.charAt(i)){
                retorno = 1;
            } else {
                retorno = retorno + comparar(texto1, texto2, i + 1);
            }
        } else if(texto1.length() != texto2.length()) retorno = 1;
        return retorno;
    }

    private static int comparar(String texto1, String texto2) { return comparar(texto1, texto2, 0); }

    private static int aleatorio(int max){ return Math.abs(r.nextInt()) % max; }

    private static String alterar(String texto, int length, char c1, char c2){
        String retorno = "";
        for(int i = 0; i < length; i = i + 1){
            if(texto.charAt(i) == c1) retorno = retorno + c2;
            else retorno = retorno + texto.charAt(i);
        }
        return retorno;
    }

    public static void main(String[] args){
        r.setSeed(4);
        Scanner sc = new Scanner(System.in);
        String texto = sc.nextLine();

        while(comparar(texto, "FIM") != 0){
            int n = texto.length();
            System.out.println(alterar(texto, n, (char)('a' + aleatorio(26)), (char)('a' + aleatorio(26))));
            texto = sc.nextLine();
        }
        sc.close();
    }
}