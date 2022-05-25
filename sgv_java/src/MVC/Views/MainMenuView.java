package MVC.Views;

import MVC.IGereVendasView;

public class MainMenuView implements IGereVendasView {

    public void show(){
        System.out.println("########## Menu ##########");
        System.out.println("##########################");
        System.out.println("1 - Ler ficheiro\n");
        System.out.println("2 - Gravar/Carregar Estado\n");
        System.out.println("3 - Consultas interativas\n");
        System.out.println("4 - Consultas estatisticas\n");
        System.out.println("0 - Exit\n");
        System.out.println("##########################");
        System.out.println("Insert Option: ");
    }

    public void show(Object o){
        show();
    }
}
