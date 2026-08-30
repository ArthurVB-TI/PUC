import java.util.Scanner;

public class tp {
    private static int comparar(String texto1, String texto2, int i){
        int retorno = 0;
        if(i < texto1.length() && i < texto2.length()){
            if(texto1.charAt(i) != texto2.charAt(i)){
                retorno = 1;
            } else {
                retorno = retorno + comparar(texto1,texto2,i + 1);
            }
        } else if(texto1.length() != texto2.length()) retorno = 1;
        return retorno;
    }
    private static int comparar(String texto1, String texto2) { return comparar(texto1, texto2, 0); }
    private static String cifra(String texto,int n){
        String cifra = "";
        char c = '\0';
        for(int i = 0; i < n; i = i + 1){
            c = (char) (texto.charAt(i) + 3);
            cifra = cifra + c;
        }
        return cifra;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = "";

        texto = sc.nextLine();
        while(comparar(texto,"FIM") != 0){
            texto = cifra(texto,texto.length());
            System.out.println(texto);
            texto = sc.nextLine();
        }

        sc.close();
    }
}
