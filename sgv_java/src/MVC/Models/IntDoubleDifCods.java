package MVC.Models;

import java.util.Set;
import java.util.TreeSet;

public class IntDoubleDifCods {
    private int compra;
    private double gastos;
    private Set<String> cods;

    public IntDoubleDifCods(){
        this.compra = 0;
        this.gastos = 0;
        this.cods = new TreeSet<>();
    }

    public void addCamps(int c, double g, String s){
        this.compra+=c;
        this.gastos+=g;
        this.cods.add(s);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Compras: ").append(this.compra).append(" , Gastos: ").append(String.format("%.2f",this.gastos)).append(" , codigos distintos: ").append(this.cods.size());
        return sb.toString();
    }
}
