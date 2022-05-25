package MVC.Views;

import MVC.IGereVendasView;
import MVC.Models.Catalogs.Filial;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class FilialView<T> implements IGereVendasView {
    private List<T> l;

    public FilialView(){
        this.l = new ArrayList<T>();
    }

    public FilialView(Collection<T> c){
        this.l = new ArrayList<T>(c);
    }

    public void setList(List<T> l) {
        this.l = l;
    }

    public void show(){
        int size = l.size();
        System.out.println("##########################");
        for (int i=0;i<size;i++){
            System.out.println("Filial "+(i+1)+ ":");
            System.out.println(l.get(i) + "\n");
        }
        System.out.println("##########################");
        System.out.println("S - Exit");
    }

    public void show(Object o){
    }
}
