package MVC.Views;

import MVC.IGereVendasView;

public class MessageView implements IGereVendasView {
    public void show(){
    }

    public void show(Object o){
        System.out.println(o.toString());
    }
}
