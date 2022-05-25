package MVC.Views;

import MVC.IGereVendasView;

public class ErrorView implements IGereVendasView {
    public void show(){
        System.out.println("Error");
    }

    public void show(Object o){
        System.out.println(o.toString());
    }
}
