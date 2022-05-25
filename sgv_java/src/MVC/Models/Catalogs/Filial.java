package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;
import MVC.Models.BaseModels.VendaFilial;

import java.io.Serializable;
import java.util.*;

/**
 * Write a description of class Filial here.
 *
 * @author 89510-89561-89501
 * @version 12/05/2020
 */
public class Filial implements IFilial, Serializable {

    private Map<String, List<IVendaFilial>> vendas;

    public Filial(){
        this.vendas = new HashMap<>();
    }

    public Filial(Map<String, List<IVendaFilial>> map) {
        this.setVendas(map);
    }

    public Filial(Set<String> s){
        this.vendas = new HashMap<>();
        for(String str : s)
            this.vendas.put(str, new ArrayList<>());
    }

    public Filial(Filial f){
        this.setVendas(f.getVendas());
    }

    public void addVenda(String s, IVendaFilial v){
        List<IVendaFilial> l = this.vendas.get(s);
        l.add(v);
    }

    public Map<String,List<IVendaFilial>> getVendas(){
        Map<String,List<IVendaFilial>> r = new HashMap<>();
        for (Map.Entry<String,List<IVendaFilial>> e : this.vendas.entrySet()) {
            String s = e.getKey();
            List<IVendaFilial> lvf = new ArrayList<>();
            r.put(s, lvf);
            List<IVendaFilial> l = e.getValue();
            for (IVendaFilial v : l)
                lvf.add(v.clone());
        }
        return  r;
    }

    public void setVendas(Map<String,List<IVendaFilial>> m){
        this.vendas = new HashMap<>();
        for (Map.Entry<String,List<IVendaFilial>> e : m.entrySet()) {
            String s = e.getKey();
            this.vendas.put(s, new ArrayList<>());
            List<IVendaFilial> l = e.getValue();
            for (IVendaFilial v : l)
                this.addVenda(s,v.clone());
        }
    }

    public List<IVendaFilial> getVendasCliente(String cod){
        List<IVendaFilial> r = new ArrayList<>();
        List<IVendaFilial> aux = this.vendas.get(cod);
        for (IVendaFilial v : aux)
            r.add(v.clone());
        return r;
    }

    public int getSize(){
        int size =0;
        for (Map.Entry<String,List<IVendaFilial>> e : this.vendas.entrySet()) {
            size += e.getValue().size();
        }
        return size;
    }

    public boolean clienteContainsProd(String cl, String prod){
        boolean ans = false;
        List<IVendaFilial> aux = this.getVendasCliente(cl);
        for (IVendaFilial vf : aux){
            if (vf.getProduto().equals(prod)) {
                ans = true;
                break;
            }
        }
        return ans;
    }

    public IVendaFilial getProdVendaFilial(String cl, String prod){
        IVendaFilial ans = new VendaFilial();
        List<IVendaFilial> aux = this.getVendasCliente(cl);
        for (IVendaFilial vf : aux){
            if (vf.getProduto().equals(prod)) {
                ans = vf;
                break;
            }
        }
        return ans;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[\n");
        for(Map.Entry<String,List<IVendaFilial>> e : this.vendas.entrySet()){
            sb.append(e.getKey()).append("\n{\n");
            List<IVendaFilial> l = e.getValue();
            for (IVendaFilial v : l)
                sb.append(v).append("\n");
            sb.append("}\n");
        }
        sb.append("]\n");
        return sb.toString();
    }

    public boolean existeCliente(String s){
        return this.vendas.containsKey(s);
    }

    public IFilial clone(){
        return new Filial(this);
    }

}