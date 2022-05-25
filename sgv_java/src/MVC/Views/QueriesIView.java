package MVC.Views;

import MVC.IGereVendasView;

public class QueriesIView implements IGereVendasView {
    public void show(){
        System.out.println("########## Menu ##########");
        System.out.println("##########################");
        System.out.println("1 - Produtos nao comprados\n");
        System.out.println("2 - Numero de vendas realizadas e de clientes distintos que as fizeram num mes\n");
        System.out.println("3 - Compras, produtos distintos comprados e gastos por um dado cliente\n");
        System.out.println("4 - compras, clientes distintos e total faturado por um dado produto\n");
        System.out.println("5 - Produtos mais comprados por um cliente\n");
        System.out.println("6 - X produtos mais vendidos\n");
        System.out.println("7 - top 3 Compradores\n");
        System.out.println("8 - X clientes que compraram mais produtos diferentes\n");
        System.out.println("9 - X clientes que mais compraram um dado produto\n");
        System.out.println("10 - Faturacao total para cada produto mes a mes\n");
        System.out.println("0 - Exit\n");
        System.out.println("##########################");
        System.out.println("Insert Option: ");
    }

    public void show(Object o){
        show();
    }
}
