package MVC.Models.Catalogs;

import MVC.Models.BaseModels.Cliente;
import MVC.Models.BaseModels.ICliente;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Clientes2 implements Serializable, IClientes {

    private Set<ICliente> cat;

    public Clientes2(){
        this.cat = new HashSet<>();
    }

    public Clientes2(Set<ICliente> s){
        this.cat = new HashSet<>();
        for(ICliente c: s)
            this.cat.add(c.clone());
    }

    public Set<String> getCatalogo() {
        return this.cat.stream().map(ICliente::getCodigo).collect(Collectors.toSet());
    }

    public int getSize(){
        return this.cat.size();
    }

    public void adicionaCliente(ICliente c){
        this.cat.add(c.clone());
    }

    public boolean existe(String s){
        return this.cat.contains(new Cliente(s));
    }

    public boolean existe(ICliente c) {
        return this.cat.contains(c);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        for (ICliente c: this.cat) {
            sb.append("\t").append(c).append("\n");
        }
        sb.append("}");
        return sb.toString();
    }

}