package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IProduto;
import MVC.Models.BaseModels.Produto;

import java.io.IOException;
import java.io.Serializable;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Produtos implements IProdutos, Serializable {
    private Set<IProduto> cat;

    public Produtos(){
        this.cat = new TreeSet<>();
    }

    public Produtos(Set<IProduto> s){
        this.cat = new TreeSet<>();
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