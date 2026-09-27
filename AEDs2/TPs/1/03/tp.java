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
    private static boolean vogal(char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    private static boolean consoante(char c){
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && !vogal(c);
    }
    private static boolean digito(char c){
        return (c >= '0' && c <= '9');
    }
    private static boolean x1(String texto){
        boolean retorno = (texto.length() > 0);
        for(int i = 0; i < texto.length() && retorno; i = i + 1){
            if(!vogal(texto.charAt(i))) retorno = false;
        }
        return retorno;
    }
    private static boolean x2(String texto){
        boolean retorno = (texto.length() > 0);
        for(int i = 0; i < texto.length() && retorno; i = i + 1){
            if(!consoante(texto.charAt(i))) retorno = false;
        }
        return retorno;
    }
    private static boolean x3(String texto){
        boolean retorno = (texto.length() > 0);
        for(int i = 0; i < texto.length() && retorno; i = i + 1){
            if(!digito(texto.charAt(i))) retorno = false;
        }
        return retorno;
    }
    private static boolean x4(String texto){
        boolean retorno = (texto.length() > 0);
        int separadores = 0;
        int digitos = 0;
        for(int i = 0; i < texto.length() && retorno; i = i + 1){
            char c = texto.charAt(i);
            if(digito(c)) digitos = digitos + 1;
            else if(c == '.' || c == ',') separadores = separadores + 1;
            else retorno = false;
        }
        if(separadores > 1 || digitos == 0) retorno = false;
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
