package MVC.Models.BaseModels;

import java.io.Serializable;

/**
 * Write a description of class Fact here.
 *
 * @author 89510-89561-89501
 * @version 12/05/2020
 */


public class Fact implements IFact, Serializable {
    private double preco;
    private int quantidade;
    private char promo;
    private int mes;
    private int filial;

    public Fact(){
        this.preco = 0;
        this.quantidade = 0;
        this.promo = ' ';
        this.mes = 0;
        this.filial = 0;
    }

    public Fact(double preco, int quantidade, char promo, int mes, int filial) {
        this.preco = preco;
        this.quantidade = quantidade;
        this.promo = promo;
        this.mes = mes;
        this.filial = filial;
    }

    public Fact(Fact f){
        this.preco = f.getPreco();
        this.quantidade = f.getQuantidade();
        this.promo = f.getPromo();
        this.mes = f.getMes();
        this.filial = f.getFilial();
    }

    public double getPreco() {
        return this.preco;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

    public char getPromo() {
        return this.promo;
    }

    public int getMes() {
        return this.mes;
    }

    public int getFilial() {
        return this.filial;
    }

    public IFact clone(){
        return new Fact(this);
    }

    public boolean equals(Object o) {
        if (o == this) return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        IFact f = (IFact) o;
        return  this.preco == f.getPreco() &&
                this.quantidade == f.getQuantidade() &&
                this.promo == f.getPromo() &&
                this.mes == f.getMes() &&
                this.filial == f.getFilial();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append(" Preco: ").append(this.preco);
        sb.append(", Quantidade: ").append(this.quantidade);
        sb.append(", Tipo de Compra: ").append(this.promo);
        sb.append(", Mes: ").append(this.mes);
        sb.append(", Filial: ").append(this.filial).append("\n");

        return sb.toString();
    }
}