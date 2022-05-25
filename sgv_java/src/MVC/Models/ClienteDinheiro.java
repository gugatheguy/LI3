package MVC.Models;

public class ClienteDinheiro {

    private String cliente;
    private double gastos;

    public ClienteDinheiro(String cl, double gast){

        this.cliente = cl;
        this.gastos = gast;

    }

    public String getCliente(){

        return this.cliente;
    }

    public double getGastos(){

        return this.gastos;
    }

    public void addGastos(double g){
        this.gastos += g;
    }

    public boolean equals(Object o){
        if (o == this) return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        ClienteDinheiro cd = (ClienteDinheiro) o;
        return this.cliente.equals(cd.getCliente()) &&
                this.gastos == cd.getGastos();
    }

    static int comparaClientes(ClienteDinheiro cd1, ClienteDinheiro cd2){
        double size_cd1 = cd1.getGastos();
        double size_cd2 = cd2.getGastos();
        int r = 0;

        if(size_cd1 < size_cd2)
            r = 1;

        if(size_cd1 > size_cd2)
            r = -1;

        return r;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Cliente: ").append(this.cliente);
        sb.append(", Gastos: ").append(String.format("%.2f",this.gastos)).append("\n");

        return sb.toString();
    }

}
