package MVC;

import MVC.Views.*;
import MVC.Controller.*;
import MVC.Models.*;


public class GestVendasAppMVC {

    private static IGereVendasModel createData(){
        IGereVendasModel r = new GestVendas();
        //IGereVendasModel r = new GestVendas2(); //For Benchmarking purposes
        r.loadDefault();
        return r;
    }

    public static void main(String[] args){
        IGereVendasView view;
        IGereVendasModel model = createData();
        if(model==null){
            view = new ErrorView();
            view.show("Error loading default model");
            System.exit(-1);
        }
        view = new MainMenuView();
        IGereVendasController cont = new GestVendasController();
        cont.setModel(model);
        cont.setView(view);
        cont.start();
        System.exit(0);
    }
}
