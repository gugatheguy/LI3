package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IFact;

import java.io.Serializable;
import java.util.*;

/**
 * Write a description of class FactTotal here.
 *
 * @author 89510-89561-89501
 * @version 12/05/2020
 */
public class FactTotal implements IFactTotal, Serializable {

    private Map<String, List<IFact>> fact;

    public FactTotal(){
        this.fact = new HashMap<>();
    }

    public FactTotal(Map<String, List<IFact>> map) {
        this.setFact(map);
    }

    public FactTotal(FactTotal ft){
        this.setFact(ft.fact);
    }

    public FactTotal(Set<String> s){
        this.setFactTotal(s);
    }

    public void setFactTotal(Set<String> s){
        this.fact = new HashMap<>();
        for(String str : s)
            this.fact.put(str, new ArrayList<>());
    }

    public void addFact(String s, IFact f){
        List<IFact> l = this.fact.get(s);
        l.add(f);
    }

    public Map<String,List<IFact>> getFact(){
        Map<String,List<IFact>> r = new HashMap<>();
        for (Map.Entry<String,List<IFact>> e : this.fact.entrySet()) {
            String s = e.getKey();
            List<IFact> lvf = new ArrayList<>();
            r.put(s, lvf);
            List<IFact> l = e.getValue();
            for (IFact v : l)
                lvf.add(v.clone());
        }
        return  r;
    }

    public void setFact(Map<String,List<IFact>> m){
        this.fact = new HashMap<>();
        for (Map.Entry<String,List<IFact>> e : m.entrySet()) {
            String s = e.getKey();
            this.fact.put(s, new ArrayList<>());
            List<IFact> l = e.getValue();
            for (IFact v : l)
                this.addFact(s,v.clone());
        }
    }

    public List<IFact> getFactProd(String cod){
        List<IFact> r = new ArrayList<>();
        List<IFact> aux = this.fact.get(cod);
        for (IFact v : aux)
            r.add(v.clone());
        return r;
    }

    public int getSize(){
        int size =0;
        for (Map.Entry<String,List<IFact>> e : this.fact.entrySet()) {
            size += e.getValue().size();
        }
        return size;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[\n");
        for(Map.Entry<String,List<IFact>> e : this.fact.entrySet()){
            sb.append(e.getKey()).append("\n{\n");
            List<IFact> l = e.getValue();
            for (IFact v : l)
                sb.append(v).append("\n");
            sb.append("}\n");
        }
        sb.append("]");
        return sb.toString();
    }

    public int nFiliais(){
        int res = 0;
        for (Map.Entry<String,List<IFact>> e : this.fact.entrySet()) {
            for ( IFact f : e.getValue()){
                if(res < f.getFilial()){
                    res++;
                }
            }
        }
        return res;
    }

    public boolean existeProd(String s){
        return this.fact.containsKey(s);
    }
}