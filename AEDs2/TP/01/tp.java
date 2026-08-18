import java.util.Scanner;

class java{
    private static String cifra(String texto,int n){
        String cifra = "";
        char c = '\0';
        for(int i = 0; i < n; i = i + 1){
            c = (char) (texto.charAt(i) + 3);
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
                cifra = cifra + c;
            } else {
                cifra = cifra + c;
            }
        }
        return cifra;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = "";
        
        texto = sc.nextLine();
        while(texto.compareTo("FIM") != 0){
            texto = cifra(texto,texto.length());
            System.out.println(texto);
            texto = sc.nextLine();
        }

        sc.close();
    }
}