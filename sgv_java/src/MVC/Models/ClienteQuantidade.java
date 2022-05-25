package MVC.Models;

import java.util.Objects;

public class ClienteQuantidade implements Comparable<ClienteQuantidade>{
    private String cod;
    private int quant;

    ClienteQuantidade(String st, int q){
        this.cod = st;
        this.quant = q;
    }

    public String getCod() {
        return this.cod;
    }

    public int getQuant() {
        return this.quant;
    }

    public void setQuant(int quant) {
        this.quant = quant;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ClienteQuantidade)) return false;
        ClienteQuantidade that = (ClienteQuantidade) o;
        return getQuant() == that.getQuant() &&
                Objects.equals(getCod(), that.getCod());
    }

    public int compareTo(ClienteQuantidade o) {
        if (this.quant > o.getQuant()) return -1;
        if (this.quant < o.getQuant()) return 1;
        return this.cod.compareTo(o.getCod());
    }


    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Codigo: ").append(this.cod).append(" , Quantidade:").append(this.quant);
        return sb.toString();
    }
}
