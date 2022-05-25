package MVC.Views;

import MVC.IGereVendasView;

public class QueriesEView implements IGereVendasView {
    public void show(){
        System.out.println("########## Menu ##########");
        System.out.println("##########################");
        System.out.println("1 - Dados da ultima leitura\n");
        System.out.println("2 - Vendas, faturacao total e clientes distintos por mes\n");
        System.out.println("0 - Exit\n");
        System.out.println("##########################");
        System.out.println("Insert Option: ");
    }

    public void show(Object o){
        show();
    }
}
