package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class Filiais implements IFiliais, Serializable {
    private List<IFilial> fils;

    public Filiais(){
        this.fils = new ArrayList<>();
    }

    public Filiais(int num){
        this.fils = new ArrayList<>();
        for (int i=0; i<num;i++){
            this.fils.add(new Filial());
        }
    }

    public Filiais(Set<String> s,int num){
        this.setFiliais(s,num);
    }

    public Filiais(Filiais fs){
        this.fils = new ArrayList<>();
        for(IFilial f : fs.fils)
            this.fils.add(f.clone());
    }

    public void setFiliais(Set<String> s,int num){
        this.fils = new ArrayList<>();
        for (int i=0; i<num;i++){
            this.fils.add(new Filial(s));
        }
    }

    public int getSize(){
        return this.fils.size();
    }

    public void addVenda(String s, IVendaFilial v,int n) {
        this.fils.get(n-1).addVenda(s,v);
    }

    public IFilial getFilial(int n){
        return this.fils.get(n-1).clone();
    }

    public List<IVendaFilial> getVendasClienteFilial(String cod, int n){
        return this.fils.get(n-1).getVendasCliente(cod);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.fils);
        return sb.toString();
    }

    public void addNewFilial(Set<String> s){
        this.fils.add(new Filial(s));
    }

    public boolean existeCliente(String s){
        return this.fils.get(0).existeCliente(s);
    }

}