package MVC.Models;

import java.io.Serializable;

public class Dados implements Serializable {
    private String nome;
    private int vendasErradas;
    private int produtos;
    private int produtosComprados;
    private int clientes;
    private int clientesQueCompram;
    private int comprasGratis;
    private double faturacao;

    public Dados(){
        this.nome = "";
        this.vendasErradas = 0;
        this.produtos = 0;
        this.produtosComprados = 0;
        this.clientes = 0;
        this.clientesQueCompram = 0;
        this.comprasGratis = 0;
        this.faturacao = 0;
    }

    public Dados(Dados d){
        this.nome = d.nome;
        this.vendasErradas = d.vendasErradas;
        this.produtos = d.produtos;
        this.produtosComprados = d.produtosComprados;
        this.clientes = d.clientes;
        this.clientesQueCompram = d.clientesQueCompram;
        this.comprasGratis = d.comprasGratis;
        this.faturacao = d.faturacao;
    }

    public int getClientes() {
        return clientes;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setVendasErradas(int vendasErradas) {
        this.vendasErradas = vendasErradas;
    }

    public void setProdutos(int produtos) {
        this.produtos = produtos;
    }

    public void setProdutosComprados(int produtosComprados) {
        this.produtosComprados = produtosComprados;
    }

    public void setClientes(int clientes) {
        this.clientes = clientes;
    }

    public void setClientesQueCompram(int clientesQueCompram) {
        this.clientesQueCompram = clientesQueCompram;
    }

    public void setComprasGratis(int comprasGratis) {
        this.comprasGratis = comprasGratis;
    }

    public void setFaturacao(double faturacao) {
        this.faturacao = faturacao;
    }

    public Dados clone(){
        return new Dados(this);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Nome do Ficheiro: ").append(this.nome).append("\nNumero Vendas Erradas: ").append(this.vendasErradas).append("\nNumero Produtos: ").append(this.produtos)
          .append("\nNumero Produtos comprados: ").append(this.produtosComprados).append("\nNumero Produtos nao comprados: ").append(this.produtos-this.produtosComprados)
          .append("\nNumero Clientes: ").append(this.clientes).append("\nNumero Clientes que compraram: ").append(this.clientesQueCompram).append("\nNumero Clientes que nao compraram: ")
          .append(this.clientes-this.clientesQueCompram).append("\nCompras Gratis: ").append(this.comprasGratis).append("\nFaturacao: ").append(String.format("%.2f",this.faturacao));
        return sb.toString();
    }
}