import java.util.Scanner;

public class lab01{
    public static void main(String[] args) {
	   Scanner sc = new Scanner(System.in);
	   String linha = sc.nextLine();
	   while(linha.compareTo("FIM") != 0){
		    System.out.println(count_letraMaiuscula(linha,linha.length(),0));
		    linha = sc.nextLine();
	   }
	   sc.close();
    }
    public static int count_letraMaiuscula(String texto,int length,int index){
	    int retorno = 0;
	    int letra = 0;
	    if(index < length){
		    letra = (int) texto.charAt(index);
		    if(letra >= 65 && letra <= 90){
			    retorno = 1;
		    }
		    retorno = retorno + count_letraMaiuscula(texto,length,index + 1);
	    }
	    return retorno;
    }
}
