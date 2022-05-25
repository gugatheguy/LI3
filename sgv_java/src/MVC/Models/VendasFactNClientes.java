package MVC.Models;

import java.util.*;

public class VendasFactNClientes {
    private int vendas;
    private double fact;
    private List<Set<String>> nclientes;

    public VendasFactNClientes(int n){
        vendas = 0;
        fact = 0;
        nclientes = new ArrayList<>();
        for (int i=0;i<n;i++)
            nclientes.add(new TreeSet<>());
    }

    public void addVenda(int n,double f, String s,int fil){
        vendas += n;
        fact += f;
        nclientes.get(fil-1).add(s);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Compras: ").append(vendas).append("\nFaturacao global: ").append(String.format("%.2f",fact)).append("\nClientes Distintos:{\n");
        for (int i=0;i<nclientes.size();i++) {
            sb.append("\tFilial").append(i + 1).append(": ").append(nclientes.get(i).size()).append("\n");
        }
        sb.append("}");
        return sb.toString();
    }
}
