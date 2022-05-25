package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IFact;

import java.io.Serializable;
import java.util.*;

public class FactTotal2 implements IFactTotal, Serializable {

    private Map<String, List<IFact>> fact;

    public FactTotal2(){
        this.fact = new TreeMap<>();
    }

    public FactTotal2(Map<String, List<IFact>> map) {
        this.setFact(map);
    }

    public FactTotal2(FactTotal2 ft){
        this.setFact(ft.fact);
    }

    public FactTotal2(Set<String> s){
        this.setFactTotal(s);
    }

    public void setFactTotal(Set<String> s){
        this.fact = new TreeMap<>();
        for(String str : s)
            this.fact.put(str, new Vector<>());
    }

    public void addFact(String s, IFact f){
        List<IFact> l = this.fact.get(s);
        l.add(f);
    }

    public Map<String,List<IFact>> getFact(){
        Map<String,List<IFact>> r = new TreeMap<>();
        for (Map.Entry<String,List<IFact>> e : this.fact.entrySet()) {
            String s = e.getKey();
            List<IFact> lvf = new Vector<>();
            r.put(s, lvf);
            List<IFact> l = e.getValue();
            for (IFact v : l)
                lvf.add(v.clone());
        }
        return  r;
    }

    public void setFact(Map<String,List<IFact>> m){
        this.fact = new TreeMap<>();
        for (Map.Entry<String,List<IFact>> e : m.entrySet()) {
            String s = e.getKey();
            this.fact.put(s, new Vector<>());
            List<IFact> l = e.getValue();
            for (IFact v : l)
                this.addFact(s,v.clone());
        }
    }

    public List<IFact> getFactProd(String cod){
        List<IFact> r = new Vector<>();
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