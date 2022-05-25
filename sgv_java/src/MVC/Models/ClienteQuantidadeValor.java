package MVC.Models;

import java.util.Objects;

public class ClienteQuantidadeValor implements Comparable<ClienteQuantidadeValor>{
    private String cliente;
    private int quant;
    private double valor;

    ClienteQuantidadeValor(String c, int q, double v){
        this.cliente = c;
        this.quant = q;
        this.valor = v;
    }

    public String getCliente() {
        return this.cliente;
    }

    public int getQuant() {
        return this.quant;
    }

    public void setQuant(int quant) {
        this.quant = quant;
    }

    public double getValor() {
        return this.valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ClienteQuantidadeValor)) return false;
        ClienteQuantidadeValor that = (ClienteQuantidadeValor) o;
        return getQuant() == that.getQuant() &&
                Double.compare(that.getValor(), getValor()) == 0 &&
                Objects.equals(getCliente(), that.getCliente());
    }

    public int compareTo(ClienteQuantidadeValor o) {
        if (this.quant > o.getQuant()) return -1;
        if (this.quant < o.getQuant()) return 1;
        return this.cliente.compareTo(o.getCliente());
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Cliente: ").append(this.cliente).append(" , Quantidade:").append(this.quant).append(" , Pagou: ").append(String.format("%.2f",this.valor)).append("\n");
        return sb.toString();
    }
}
