package MVC.Models;

public class VendasMesFilial {
    private int nvendas;
    private int nclientes;

    public VendasMesFilial( int nclientes, int nvendas){
        this.nclientes = nclientes;
        this.nvendas = nvendas;
    }

    public VendasMesFilial(VendasMesFilial vm){
        this.nclientes = vm.getNclientes();
        this.nvendas = vm.getNvendas();
    }

    public int getNvendas() {
        return this.nvendas;
    }

    public int getNclientes() {
        return this.nclientes;
    }

    public VendasMesFilial clone() {
        return new VendasMesFilial(this);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Numero de clientes: ").append(this.nclientes).append("\nNumero de vendas: ").append(this.nvendas);
        return sb.toString();
    }
}
