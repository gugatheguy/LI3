package MVC.Models.BaseModels;

import java.io.Serializable;

/**
 * Write a description of class VendaFilial here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class VendaFilial implements IVendaFilial, Serializable {

    private String produto;
    private double preco;
    private int quantidade;
    private char promocao;
    private int mes;

    public VendaFilial(){
        this.produto = "";
        this.preco = 0;
        this.quantidade = 0;
        this.promocao = ' ';
        this.mes = 0;
    }

    public VendaFilial(String prod, double prec, int quant, char promo, int mes){
        this.produto = prod;
        this.preco = prec;
        this.quantidade = quant;
        this.promocao = promo;
        this.mes = mes;
    }

    public VendaFilial(VendaFilial v){
        this.produto = v.getProduto();
        this.preco = v.getPreco();
        this.quantidade = v.getQuantidade();
        this.promocao = v.getPromocao();
        this.mes = v.getMes();
    }

    public String getProduto(){
        return this.produto;
    }

    public double getPreco(){
        return this.preco;
    }

    public int getQuantidade(){
        return this.quantidade;
    }

    public char getPromocao(){
        return this.promocao;
    }

    public int getMes(){
        return this.mes;
    }

    public IVendaFilial clone(){
        return new VendaFilial(this);
    }

    public boolean equals(Object o){
        if (o == this) return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        IVendaFilial v = (IVendaFilial) o;
        return this.produto.equals(v.getProduto()) &&
                this.preco == v.getPreco() &&
                this.quantidade == v.getQuantidade() &&
                this.promocao == v.getPromocao() &&
                this.mes == v.getMes();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append(" Produto: ").append(this.produto);
        sb.append(", Preco: ").append(this.preco);
        sb.append(", Quantidade: ").append(this.quantidade);
        sb.append(", Tipo de Compra: ").append(this.promocao);
        sb.append(", Mes: ").append(this.mes).append("\n");

        return sb.toString();
    }
}