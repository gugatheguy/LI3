package MVC.Views;

import MVC.IGereVendasView;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class LimitListView<T> implements IGereVendasView {
    private List<T> l;

    public LimitListView(){
        this.l = new ArrayList<T>();
    }

    public LimitListView(Collection<T> c){
        this.l = new ArrayList<T>(c);
    }

    public void setList(List<T> l) {
        this.l = l;
    }

    public void show(){
        System.out.println("S - Exit");
    }

    public void show(Object o){
        int size = l.size();
        System.out.println("##########################");
        if(o instanceof Integer && ((Integer) o>0)){
            int max = (Integer) o;
            int i;
            for (i = 0; i<max && i<size;i++) {
                System.out.println(l.get(i));
            }
        }
        else{
            System.out.println("erro");//Exception
        }
        System.out.println("##########################");
        show();
    }
}