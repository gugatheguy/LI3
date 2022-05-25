package MVC.Views;

import MVC.IGereVendasView;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class PageView<T> implements IGereVendasView {
    private List<T> l;
    private Integer idx = 0;
    private static int limit = 10;

    public PageView(){
        this.l = new ArrayList<T>();
    }

    public PageView(Collection<T> c){
        this.l = new ArrayList<T>(c);
    }

    public int getIdx() {
        return idx;
    }

    public void setLimit(int l){
        limit = l;
    }

    public void setList(List<T> l) {
        this.l = l;
    }

    public void show(){
        System.out.println("Insira a Opcao: ");
    }

    public void show(Object o){
        int size = l.size();
        int num = (int) Math.ceil(size/((double) limit));
        System.out.println("##########################");
        if(o instanceof Integer && ((Integer) o>=0)){
            this.idx = (Integer) o;
            int i;
            for (i = this.idx * limit; (i <((idx + 1) * limit) && i<size);i++) {
                System.out.println(l.get(i));
            }
            idx++;

        }
        else{
            System.out.println("erro");//Exception
        }
        System.out.println("##########################");
        System.out.println("Pag " + idx + " of " + num + " Pages");
        System.out.println("A = <- | D= -> | J = jump to page n | S = Quit");
        show();
    }
}
