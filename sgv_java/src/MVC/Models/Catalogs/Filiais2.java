package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;

import java.io.Serializable;
import java.util.List;
import java.util.Set;
import java.util.Vector;

public class Filiais2 implements IFiliais, Serializable {
    private List<IFilial> fils;

    public Filiais2(){
        this.fils = new Vector<>();
    }

    public Filiais2(int num){
        this.fils = new Vector<>();
        for (int i=0; i<num;i++){
            this.fils.add(new Filial2());
        }
    }

    public Filiais2(Set<String> s, int num){
        this.setFiliais(s,num);
    }

    public Filiais2(Filiais2 fs){
        this.fils = new Vector<>();
        for(IFilial f : fs.fils)
            this.fils.add(f.clone());
    }

    public void setFiliais(Set<String> s,int num){
        this.fils = new Vector<>();
        for (int i=0; i<num;i++){
            this.fils.add(new Filial2(s));
        }
    }

    public int getSize(){
        return this.fils.size();
    }

    public void addVenda(String s, IVendaFilial v, int n) {
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