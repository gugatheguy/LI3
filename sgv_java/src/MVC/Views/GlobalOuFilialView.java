package MVC.Views;

import MVC.IGereVendasView;

public class GlobalOuFilialView implements IGereVendasView {
    public void show(){
        System.out.println("########## Menu ##########");
        System.out.println("##########################");
        System.out.println("1 - Filial a filial\n");
        System.out.println("2 - Global\n");
        System.out.println("0 - Exit\n");
        System.out.println("##########################");
        System.out.println("Insert Option: ");
    }

    public void show(Object o){
        System.out.println(o);
        show();
    }
}
