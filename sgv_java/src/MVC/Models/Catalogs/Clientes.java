package MVC.Models.Catalogs;

import MVC.Models.BaseModels.Cliente;
import MVC.Models.BaseModels.ICliente;

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

/**
 * Write a description of class Clientes here.
 *
 * @author 89510-89561-89501
 * @version 12/05/2020
 */
public class Clientes implements Serializable, IClientes {

    private Set<ICliente> cat;

    public Clientes(){
        this.cat = new TreeSet<>();
    }

    public Clientes(Set<ICliente> s){
        this.cat = new TreeSet<>();
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