package MVC.Views;

import MVC.IGereVendasView;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class MesView <T> implements IGereVendasView {
    private List<T> l;

    public MesView(){
        this.l = new ArrayList<T>();
    }

    public MesView(Collection<T> c){
        this.l = new ArrayList<T>(c);
    }

    public void setList(List<T> l) {
        this.l = l;
    }

    public void show(){
        System.out.println("##########################");
        Integer i;
        for (i=0;i<12;i++){
            show(i+1);
            System.out.println(l.get(i) + "\n");
        }
        System.out.println("##########################");
        System.out.println("S - Exit");
    }

    public void show(Object o){
        if(o instanceof Integer){
            int n = (int) o;
            switch (n){
                case 1:
                    System.out.println("Janeiro:");
                    break;
                case 2:
                    System.out.println("Fevereiro:");
                    break;
                case 3:
                    System.out.println("Marco:");
                    break;
                case 4:
                    System.out.println("Abril:");
                    break;
                case 5:
                    System.out.println("Maio:");
                    break;
                case 6:
                    System.out.println("Junho:");
                    break;
                case 7:
                    System.out.println("Julho:");
                    break;
                case 8:
                    System.out.println("Agosto:");
                    break;
                case 9:
                    System.out.println("Setembro:");
                    break;
                case 10:
                    System.out.println("Outubro:");
                    break;
                case 11:
                    System.out.println("Novembro:");
                    break;
                case 12:
                    System.out.println("Dezembro:");
                    break;
            }
        }
    }
}
