package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IProduto;
import MVC.Models.BaseModels.Produto;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Produtos2 implements IProdutos, Serializable {
    private Set<IProduto> cat;

    public Produtos2(){
        this.cat = new HashSet<>();
    }

    public Produtos2(Set<IProduto> s){
        this.cat = new HashSet<>();
        for(IProduto c: s)
            this.cat.add(c.clone());
    }

    public Set<String> getCatalogo() {
        return this.cat.stream().map(IProduto::getCodigo).collect(Collectors.toSet());
    }

    public int getSize(){
        return this.cat.size();
    }

    public void adicionaProduto(IProduto p){
        this.cat.add(p.clone());
    }

    public boolean existe(String s){
        return this.cat.contains(new Produto(s));
    }

    public boolean existe(IProduto p) {
        return this.cat.contains(p);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        for (IProduto c: this.cat) {
            sb.append("\t").append(c).append("\n");
        }
        sb.append("}");
        return sb.toString();
    }
}