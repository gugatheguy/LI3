package MVC.Views;

import MVC.IGereVendasView;
import MVC.Models.ClienteDinheiro;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Query7View implements IGereVendasView {
    private Map<Integer, List<ClienteDinheiro>> m;

    public Query7View(){
        this.m = new HashMap<>();
    }

    public void setMap(Map<Integer, List<ClienteDinheiro>> l) {
        this.m = l;
    }

    public void show(){
        System.out.println("##########################");
        for(Map.Entry<Integer, List<ClienteDinheiro>> e : this.m.entrySet()){
            System.out.print("Top 3 Compradores na Filial ");
            System.out.print(e.getKey() + ":\n");
            List<ClienteDinheiro> aux = e.getValue();
            for (ClienteDinheiro c : aux) {
                System.out.println(c);
            }
        }
        System.out.println("##########################");
        System.out.println("S - Exit");
    }

    public void show(Object o){
        show();
    }
}