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
        } else if(texto1.length() == 0) retorno = 1;
        return retorno;
    }
    private static int comparar(String texto1, String texto2) { return comparar(texto1, texto2, 0); }
    private static boolean x1(String texto){
        boolean retorno = false;
        for(int i = 0; i < texto.length() && !retorno; i++){
            char c = texto.charAt(i);
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                retorno = true;
        }
        return retorno;
    }
    private static boolean x2(String texto){
        boolean retorno = false;
        for(int i = 0; i < texto.length() && !retorno; i++){
            char c = texto.charAt(i);
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) if(!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
                retorno = true;
        }
        return retorno;
    }
    private static boolean x3(String texto){
        boolean retorno = false;
        for(int i = 0; i < texto.length() && !retorno; i++){
            char c = texto.charAt(i);
            if(c >= '1' && c <= '9')
                retorno = true;
        }
        return retorno;
    }
    private static boolean x4(String texto){
        boolean retorno = false;
        for(int i = 0; i < texto.length() && !retorno; i++){
            char c = texto.charAt(i);
            if(c >= '1' && c <= '9')
                if(texto.charAt(i + 1) == ',')
                    {retorno = true;}
            else 
                if(c == ',')
                    if(texto.charAt(i + 1) >= 'a' && texto.charAt(i + 1) <= 'z')
                        retorno = true;
        }
        return retorno;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String texto = "";

        texto = sc.nextLine();
        while(comparar(texto,"FIM") != 0){
            System.out.println(
                (x1(texto) ? "SIM" : "NAO") + " " + 
                (x2(texto) ? "SIM" : "NAO") + " " + 
                (x3(texto) ? "SIM" : "NAO") + " " + 
                (x4(texto) ? "SIM" : "NAO")
            );
            texto = sc.nextLine();
        }

        sc.close();
    }
}
