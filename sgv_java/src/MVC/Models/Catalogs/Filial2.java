package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;
import MVC.Models.BaseModels.VendaFilial;

import java.io.Serializable;
import java.util.*;

public class Filial2 implements IFilial, Serializable {

    private Map<String, List<IVendaFilial>> vendas;

    public Filial2(){
        this.vendas = new TreeMap<>();
    }

    public Filial2(Map<String, List<IVendaFilial>> map) {
        this.setVendas(map);
    }

    public Filial2(Set<String> s){
        this.vendas = new TreeMap<>();
        for(String str : s)
            this.vendas.put(str,new Vector<>());
    }

    public Filial2(Filial2 f){
        this.setVendas(f.getVendas());
    }

    public void addVenda(String s, IVendaFilial v){
        List<IVendaFilial> l = this.vendas.get(s);
        l.add(v);
    }

    public Map<String,List<IVendaFilial>> getVendas(){
        Map<String,List<IVendaFilial>> r = new TreeMap<>();
        for (Map.Entry<String,List<IVendaFilial>> e : this.vendas.entrySet()) {
            String s = e.getKey();
            List<IVendaFilial> lvf = new Vector<>();
            r.put(s, lvf);
            List<IVendaFilial> l = e.getValue();
            for (IVendaFilial v : l)
                lvf.add(v.clone());
        }
        return  r;
    }

    public void setVendas(Map<String,List<IVendaFilial>> m){
        this.vendas = new TreeMap<>();
        for (Map.Entry<String,List<IVendaFilial>> e : m.entrySet()) {
            String s = e.getKey();
            this.vendas.put(s, new Vector<>());
            List<IVendaFilial> l = e.getValue();
            for (IVendaFilial v : l)
                this.addVenda(s,v.clone());
        }
    }

    public List<IVendaFilial> getVendasCliente(String cod){
        List<IVendaFilial> r = new Vector<>();
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
        return new Filial2(this);
    }

}