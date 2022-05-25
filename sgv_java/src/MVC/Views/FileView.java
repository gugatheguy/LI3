package MVC.Views;

import MVC.IGereVendasView;

public class FileView implements IGereVendasView {
    public void show(){
        System.out.println("########## Menu ##########");
        System.out.println("##########################");
        System.out.println("1 - Default File\n");
        System.out.println("2 - Custom File\n");
        System.out.println("0 - Exit\n");
        System.out.println("##########################");
        System.out.println("Insert Option: ");
    }

    public void show(Object o){
        show();
    }
}
