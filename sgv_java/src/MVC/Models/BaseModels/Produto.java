package MVC.Models.BaseModels;

import java.io.Serializable;
import java.util.Objects;

public class Produto implements Comparable<IProduto>, Serializable, IProduto {
    public String codigo;

    public Produto(){
        this.codigo = "";
    }

    public Produto(String s){
        this.codigo = s;
    }

    public String getCodigo() {
        return codigo;
    }

    public Produto(Produto c){
        this.codigo = c.getCodigo();
    }

    public boolean valido(){
        return Produto.valido(this.codigo);
    }

    public static boolean valido(String s){
        boolean r = (s.length()==6);
        if(r){
            r = ((s.charAt(0)>='A' && s.charAt(0)<='Z')
                    && (s.charAt(1)>='A' && s.charAt(1)<='Z')
                    && (s.charAt(2)>='1' && s.charAt(2)<='9')
                    && (s.charAt(3)>='0' && s.charAt(3)<='9')
                    && (s.charAt(4)>='0' && s.charAt(4)<='9')
                    && (s.charAt(5)>='0' && s.charAt(5)<='9'));
        }
        return r;
    }

    public int compareTo(IProduto produto) {
        return this.codigo.compareTo(produto.getCodigo());
    }

    public String toString() {
        return this.codigo;
    }

    /*public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        IProduto produto = (IProduto) o;
        return this.codigo.equals(produto.getCodigo());
    }*/

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Produto)) return false;
        Produto produto = (Produto) o;
        return Objects.equals(getCodigo(), produto.getCodigo());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getCodigo());
    }

    public IProduto clone(){
        return new Produto(this);
    }
}