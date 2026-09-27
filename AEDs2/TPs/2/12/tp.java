import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Data{
    private int dia;
    private int mes;
    private int ano;

    public void Init(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
    public Data(){ Init(1,1,2000); }
    public Data(int dia, int mes, int ano){ Init(dia,mes,ano); }

    public int getDia(){ return this.dia; }
    public int getMes(){ return this.mes; }
    public int getAno(){ return this.ano; }
    public void setDia(int dia){ this.dia = dia; }
    public void setMes(int mes){ this.mes = mes; }
    public void setAno(int ano){ this.ano = ano; }

    public static Data parseData(String s){
        String[] partes = s.split("-");
        int ano = Integer.parseInt(partes[0]);
        int mes = Integer.parseInt(partes[1]);
        int dia = Integer.parseInt(partes[2]);
        return new Data(dia,mes,ano);
    }
    public String format(){
        return String.format(Locale.US, "%02d/%02d/%04d", this.dia, this.mes, this.ano);
    }
}

class Veiculo{
    private int id;
    private String marca;
    private String modelo;
    private int ano;
    private String categoria;
    private String[] combustivel;
    private int cilindros;
    private double cilindrada;
    private String transmissao;
    private String tracao;
    private double consumoCidade;
    private double consumoEstrada;
    private double co2;
    private boolean turbo;
    private Data dataRegistro;

    public void Init(int id, String marca, String modelo, int ano, String categoria, String[] combustivel, int cilindros, double cilindrada, String transmissao, String tracao, double consumoCidade, double consumoEstrada, double co2, boolean turbo, Data dataRegistro){
        this.id = id;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.categoria = categoria;
        this.combustivel = combustivel;
        this.cilindros = cilindros;
        this.cilindrada = cilindrada;
        this.transmissao = transmissao;
        this.tracao = tracao;
        this.consumoCidade = consumoCidade;
        this.consumoEstrada = consumoEstrada;
        this.co2 = co2;
        this.turbo = turbo;
        this.dataRegistro = dataRegistro;
    }
    public Veiculo(){ Init(0,"","",0,"",new String[0],0,0.0,"","",0.0,0.0,0.0,false,new Data()); }
    public Veiculo(int id, String marca, String modelo, int ano, String categoria, String[] combustivel, int cilindros, double cilindrada, String transmissao, String tracao, double consumoCidade, double consumoEstrada, double co2, boolean turbo, Data dataRegistro){
        Init(id,marca,modelo,ano,categoria,combustivel,cilindros,cilindrada,transmissao,tracao,consumoCidade,consumoEstrada,co2,turbo,dataRegistro);
    }

    public int getId(){ return this.id; }
    public String getMarca(){ return this.marca; }
    public String getModelo(){ return this.modelo; }
    public int getAno(){ return this.ano; }
    public String getCategoria(){ return this.categoria; }
    public String[] getCombustivel(){ return this.combustivel; }
    public int getCilindros(){ return this.cilindros; }
    public double getCilindrada(){ return this.cilindrada; }
    public String getTransmissao(){ return this.transmissao; }
    public String getTracao(){ return this.tracao; }
    public double getConsumoCidade(){ return this.consumoCidade; }
    public double getConsumoEstrada(){ return this.consumoEstrada; }
    public double getCo2(){ return this.co2; }
    public boolean isTurbo(){ return this.turbo; }
    public Data getDataRegistro(){ return this.dataRegistro; }
    public void setId(int id){ this.id = id; }
    public void setMarca(String marca){ this.marca = marca; }
    public void setModelo(String modelo){ this.modelo = modelo; }
    public void setAno(int ano){ this.ano = ano; }
    public void setCategoria(String categoria){ this.categoria = categoria; }
    public void setCombustivel(String[] combustivel){ this.combustivel = combustivel; }
    public void setCilindros(int cilindros){ this.cilindros = cilindros; }
    public void setCilindrada(double cilindrada){ this.cilindrada = cilindrada; }
    public void setTransmissao(String transmissao){ this.transmissao = transmissao; }
    public void setTracao(String tracao){ this.tracao = tracao; }
    public void setConsumoCidade(double consumoCidade){ this.consumoCidade = consumoCidade; }
    public void setConsumoEstrada(double consumoEstrada){ this.consumoEstrada = consumoEstrada; }
    public void setCo2(double co2){ this.co2 = co2; }
    public void setTurbo(boolean turbo){ this.turbo = turbo; }
    public void setDataRegistro(Data dataRegistro){ this.dataRegistro = dataRegistro; }

    public static Veiculo parseVeiculo(String s){
        String[] campos = s.split(",");
        int id = Integer.parseInt(campos[0]);
        String marca = campos[1];
        String modelo = campos[2];
        int ano = Integer.parseInt(campos[3]);
        String categoria = campos[4];
        String[] combustivel = campos[5].split(";");
        int cilindros = Integer.parseInt(campos[6]);
        double cilindrada = Double.parseDouble(campos[7]);
        String transmissao = campos[8];
        String tracao = campos[9];
        double consumoCidade = Double.parseDouble(campos[10]);
        double consumoEstrada = Double.parseDouble(campos[11]);
        double co2 = Double.parseDouble(campos[12]);
        boolean turbo = Boolean.parseBoolean(campos[13]);
        Data dataRegistro = Data.parseData(campos[14]);
        return new Veiculo(id,marca,modelo,ano,categoria,combustivel,cilindros,cilindrada,transmissao,tracao,consumoCidade,consumoEstrada,co2,turbo,dataRegistro);
    }

    private String formatCombustivel(){
        String retorno = "";
        for(int i = 0; i < this.combustivel.length; i = i + 1){
            if(i > 0) retorno = retorno + ",";
            retorno = retorno + this.combustivel[i];
        }
        return retorno;
    }

    public String format(){
        return "[" + this.id + " ## " + this.marca + " ## " + this.modelo + " ## " + this.ano + " ## " + this.categoria
                + " ## [" + formatCombustivel() + "] ## " + this.cilindros + " ## " + String.format(Locale.US, "%.1f", this.cilindrada)
                + " ## " + this.transmissao + " ## " + this.tracao + " ## " + String.format(Locale.US, "%.2f", this.consumoCidade)
                + " ## " + String.format(Locale.US, "%.2f", this.consumoEstrada) + " ## " + String.format(Locale.US, "%.1f", this.co2)
                + " ## " + this.turbo + " ## " + this.dataRegistro.format() + "]";
    }
}

class LeitorCsv{
    public static Veiculo[] ler(String caminhoArquivo){
        Veiculo[] retorno = new Veiculo[0];
        int n = 0;
        try(BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))){
            String linha;
            br.readLine();
            while((linha = br.readLine()) != null) n = n + 1;
        } catch(IOException e){
            System.err.println("Erro ao ler arquivo: " + e.getMessage());
        }
        retorno = new Veiculo[n];
        try(BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))){
            String linha;
            int i = 0;
            br.readLine();
            while((linha = br.readLine()) != null){
                retorno[i] = Veiculo.parseVeiculo(linha);
                i = i + 1;
            }
        } catch(IOException e){
            System.err.println("Erro ao ler arquivo: " + e.getMessage());
        }
        return retorno;
    }
}

class No{
    private Veiculo dado;
    private No proximo;

    public No(Veiculo dado, No proximo){
        this.dado = dado;
        this.proximo = proximo;
    }

    public Veiculo getDado(){ return this.dado; }
    public No getProximo(){ return this.proximo; }
}

class Pilha{
    private No topo;

    public Pilha(){ this.topo = null; }

    public void empilhar(Veiculo v){
        this.topo = new No(v, this.topo);
    }

    public Veiculo desempilhar(){
        Veiculo retorno = this.topo.getDado();
        this.topo = this.topo.getProximo();
        return retorno;
    }

    public No getTopo(){ return this.topo; }
}

public class tp{
    private static int pesquisarSequencial(Veiculo[] v, int id){
        int retorno = -1;
        for(int i = 0; i < v.length; i = i + 1){
            if(v[i].getId() == id) retorno = i;
        }
        return retorno;
    }

    public static void main(String[] args){
        Veiculo[] veiculos = LeitorCsv.ler("/tmp/veiculos.csv");
        Pilha pilha = new Pilha();
        Scanner sc = new Scanner(System.in);

        int id = sc.nextInt();
        while(id != -1){
            int pos = pesquisarSequencial(veiculos, id);
            if(pos != -1) pilha.empilhar(veiculos[pos]);
            id = sc.nextInt();
        }

        int n = sc.nextInt();
        for(int i = 0; i < n; i = i + 1){
            String comando = sc.next();
            if(comando.equals("I")){
                int idIns = sc.nextInt();
                pilha.empilhar(veiculos[pesquisarSequencial(veiculos, idIns)]);
            } else if(comando.equals("R")){
                Veiculo removido = pilha.desempilhar();
                System.out.println("(R)" + removido.getMarca() + " " + removido.getModelo());
            }
        }
        sc.close();

        for(No atual = pilha.getTopo(); atual != null; atual = atual.getProximo()){
            System.out.println(atual.getDado().format());
        }
    }
}
