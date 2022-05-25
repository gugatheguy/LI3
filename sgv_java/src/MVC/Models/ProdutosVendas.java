package MVC.Models;

import java.util.Set;
import java.util.TreeSet;

public class ProdutosVendas implements Comparable<ProdutosVendas> {
    private String produto;
    private int vendas;
    private Set<String> clientes;

    public ProdutosVendas(String prod, int unidades, String client){
        this.produto = prod;
        this.vendas = unidades;
        this.clientes = new TreeSet<>();
        this.clientes.add(client);
    }

    public String getProduto() {
        return this.produto;
    }

    public void adicionaProduto(ProdutosVendas p){
        this.vendas += p.vendas;
        this.clientes.addAll(p.clientes);
    }

    public int compareTo(ProdutosVendas p) {
        if(this.vendas>p.vendas)
            return -1;
        if(this.vendas<p.vendas)
            return  1;
        return this.produto.compareTo(p.produto);
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ProdutosVendas that = (ProdutosVendas) o;
        return produto.equals(that.produto);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Produto: ").append(this.getProduto()).append(" , Unidades vendidas: ")
                .append(this.vendas).append(" , Clientes distintos: ").append(this.clientes.size());
        return sb.toString();
    }
}
