import java.util.Scanner;

class java{
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
    
    private static boolean is_senha(String texto){
        boolean retorno = false;
        boolean a = false, b = false, c = false, d = false;
        for(int i = 0; i < texto.length(); i++){
            if(texto.charAt(i) >= 'a' && texto.charAt(i) <= 'z') a = true;
            else if(texto.charAt(i) >= 'A' && texto.charAt(i) <= 'Z') b = true;
            else if(texto.charAt(i) >= '0' && texto.charAt(i) <= '9') c = true;
            else d = true;
        }
        retorno = (a && b && c && d && texto.length() >= 8);
        return retorno;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = "";

        texto = sc.nextLine();
        while(comparar(texto,"FIM") != 0){
            System.out.println((is_senha(texto) ? "SIM" : "NAO"));
            texto = sc.nextLine();
        }

        sc.close();
    }
}