package MVC.Controller;

import MVC.IGereVendasController;
import MVC.IGereVendasModel;
import MVC.IGereVendasView;
import MVC.Input;
import MVC.Models.*;
import MVC.Views.*;

import java.io.IOException;
import java.util.List;
import java.util.Map;

import static MVC.Models.ClearScreen.clearScreen;

public class GestVendasController implements IGereVendasController {
    private IGereVendasModel model;
    private IGereVendasView view;

    public void setModel(IGereVendasModel m){
        this.model = m;
    }

    public void setView(IGereVendasView v){
        this.view = v;
    }

    public void start(){
        Input input = new Input(new ErrorView());
        String op = "";
        clearScreen();
        do{
            view.show();
            op = input.lerString();
            op = op.toUpperCase();
            switch(op){
                case "1" :
                    lerFicheiro();
                    break;
                case "2" :
                    gravaCarregaEstado();
                    break;
                case "3" :
                    queriesI();
                    break;
                case "4" :
                    queriesE();
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!op.equals("0"));
    }

    private void queriesI(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new QueriesIView();
        clearScreen();
        do{
            view.show();
            op = input.lerString().toUpperCase();
            switch(op){
                case "1" :
                    clearScreen();
                    produtosNaoComprados();
                    break;
                case "2" :
                    clearScreen();
                    query2();
                    break;
                case "3" :
                    clearScreen();
                    vendasClienteMes();
                    break;
                case "4" :
                    clearScreen();
                    vendasProdutoMes();
                    break;
                case "5" :
                    clearScreen();
                    produtosMaisCompradosCliente();
                    break;
                case "6" :
                    clearScreen();
                    produtosMaisVendidos();
                    break;
                case "7" :
                    clearScreen();
                    top3Compradores();
                    break;
                case "8" :
                    clearScreen();
                    xClientesComMaisProdutosComprados();
                    break;
                case "9" :
                    clearScreen();
                    xClientesQueCompraramMaisProd();
                    break;
                case "10":
                    clearScreen();
                    factPorProd();
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!op.equals("0"));
        view = new MainMenuView();
    }

    private void queriesE(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new QueriesEView();
        clearScreen();
        do{
            view.show();
            op = input.lerString();
            op = op.toUpperCase();
            switch(op){
                case "1" :
                    dadosLeitura();
                    break;
                case "2" :
                    factPorMes();
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!op.equals("0"));
        view = new MainMenuView();
    }

    private void gravaCarregaEstado(){
            Input input = new Input(new ErrorView());
            String op = "";
            view = new GravaCarregaView();
            clearScreen();
            do{
                view.show();
                op = input.lerString();
                op = op.toUpperCase();
                switch(op){
                    case "1" :
                        gravaEstado();
                        break;
                    case "2" :
                        carregaEstado();
                        break;
                    case "0":
                        clearScreen();
                        break;
                    default:
                        clearScreen();
                        new ErrorView().show("Bad Input");
                        break;
                }
            }while(!op.equals("0"));
        view = new MainMenuView();
    }

    private void gravaEstado(){
        view = new FileView();
        String op = "";
        Input input = new Input(new ErrorView());
        Crono watch = new Crono();
        clearScreen();
        do{
            new MessageView().show("Como quer gravar o estado? ");
            view.show();
            op = input.lerString();
            switch(op){
                case "1" :
                    watch.start();
                    try {
                        model.gravaEstado();
                    }catch (IOException e){
                        clearScreen();
                        new ErrorView().show("Erro: " + e.getMessage());
                    }
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "2" :
                    clearScreen();
                    new MessageView().show("Insira o nome do ficheiro para gravar: ");
                    String file = input.lerString();
                    watch.start();
                    try {
                        model.gravaEstado(file);
                    }catch (IOException e){
                        clearScreen();
                        new ErrorView().show("Erro: " + e.getMessage());
                    }
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("0")||op.equals("1")||op.equals("2")));
        view = new GravaCarregaView();
    }

    private void carregaEstado(){
        view = new FileView();
        String op = "";
        Input input = new Input(new ErrorView());
        Crono watch = new Crono();
        clearScreen();
        do{
            new MessageView().show("Como quer carregar o estado? ");
            view.show();
            op = input.lerString();
            switch(op){
                case "1" :
                    watch.start();
                    try {
                        model.carregaEstado();
                    }catch (IOException | ClassNotFoundException e){
                        clearScreen();
                        new ErrorView().show("Erro: " + e.getMessage());
                    }
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "2" :
                    clearScreen();
                    new MessageView().show("Insira o nome do ficheiro para carregar: ");
                    String file = input.lerString();
                    watch.start();
                    try {
                        model.carregaEstado(file);
                    }catch (IOException | ClassNotFoundException e){
                        clearScreen();
                        new ErrorView().show("Erro: " + e.getMessage());
                    }
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("0")||op.equals("1")||op.equals("2")));
        view = new GravaCarregaView();
    }

    //Query 1
    private void produtosNaoComprados(){
        Input input = new Input(new ErrorView());
        String op = "";
        int idx = 0;
        view = new PageView<String>();
        Crono watch = new Crono();
        watch.start();
        List<String> l = model.produtosNaoComprados();
        watch.stop();
        new MessageView().show("Demorou: " + watch.getTime());
        ((PageView) view).setList(l);
        do{
            new MessageView().show("Numero de produtos que nao foram comprados: " + l.size());
            view.show(idx);
            op = input.lerString().toUpperCase();
            switch (op){
                case "A" :
                    idx--;
                    break;
                case "D" :
                    idx++;
                    break;
                case "J" :
                    new MessageView().show("Insira o numero da pagina: ");
                    idx = input.lerInt()-1;
                    break;
                case "S" :
                    break;
                default:
                    new ErrorView().show("Invalid Option");
                    break;
            }
            clearScreen();
        }while(!op.equals("S"));
        view = new QueriesIView();
    }

    //Query 2
    private void query2(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new GlobalOuFilialView();
        do{
            view.show("Como deseja o resultado?");
            op = input.lerString();
            op = op.toUpperCase();
            switch(op){
                case "1" :
                    vendasClienteMesFilial();
                    break;
                case "2" :
                    vendasClienteMesGlobal();
                    break;
                case "0":
                    break;
                default:
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("0")||op.equals("1")||op.equals("2")));
        view = new QueriesIView();
    }

    private void vendasClienteMesFilial(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new FilialView<VendasMesFilial>();
        clearScreen();
        new MessageView().show("Insira o mes desejado: ");
        int mes = input.lerInt();
        Crono watch = new Crono();
        try {
            watch.start();
            List<VendasMesFilial> l = model.vendasClientesMesFilialaFilial(mes);
            watch.stop();
            clearScreen();
            new MessageView().show("Demorou: " + watch.getTime());
            ((FilialView) view).setList(l);
            do{
                view.show();
                op = input.lerString().toUpperCase();
                if(!op.equals("S"))
                    new ErrorView().show("Invalid Option");
            }while(!op.equals("S"));
            clearScreen();
            view = new QueriesIView();
        } catch (InvalidMonth e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    private void vendasClienteMesGlobal(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new MessageView();
        clearScreen();
        view.show("Insira o mes desejado: ");
        int mes = input.lerInt();
        Crono watch = new Crono();
        try {
            watch.start();
            VendasMesFilial l = model.vendasClientesMesFilialGlobal(mes);
            watch.stop();
            clearScreen();
            view.show("Demorou: " + watch.getTime());
            do{
                view.show(l);
                view.show("S - Exit");
                op = input.lerString().toUpperCase();
                if(!op.equals("S"))
                    new ErrorView().show("Invalid Option");
            }while(!op.equals("S"));
            clearScreen();
            view = new QueriesIView();
        } catch (InvalidMonth e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    //Query 3
    private void vendasClienteMes(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new MesView<IntDoubleDifCods>();
        new MessageView().show("Insira o cliente desejado: ");
        String cliente = input.lerString().toUpperCase();
        Crono watch = new Crono();
        try {
            watch.start();
            List<IntDoubleDifCods> l = model.vendasClientesMes(cliente);
            watch.stop();
            clearScreen();
            new MessageView().show("Demorou: " + watch.getTime());
            ((MesView) view).setList(l);
            do{
                view.show();
                op = input.lerString().toUpperCase();
                if(!op.equals("S"))
                    new ErrorView().show("Invalid Option");
            }while(!op.equals("S"));
            clearScreen();
            view = new QueriesIView();
        } catch (DoesNotExistCode e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    //Query 4
    private void vendasProdutoMes(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new MesView<IntDoubleDifCods>();
        new MessageView().show("Insira o produto desejado: ");
        String produto = input.lerString().toUpperCase();
        clearScreen();
        try {
            Crono watch = new Crono();
            watch.start();
            List<IntDoubleDifCods> l = model.vendasProdutosMes(produto);
            watch.stop();
            new MessageView().show("Demorou: " + watch.getTime());
            ((MesView) view).setList(l);
            do{
                view.show();
                op = input.lerString().toUpperCase();
                if(!op.equals("S"))
                    new ErrorView().show("Invalid Option");
            }while(!op.equals("S"));
            clearScreen();
            view = new QueriesIView();
        } catch (DoesNotExistCode e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    //Query 5
    private void produtosMaisCompradosCliente(){
        Input input = new Input(new ErrorView());
        String op = "";
        int idx = 0;
        view = new PageView<String>();
        //Crono watch = new Crono();
        new MessageView().show("Insira o codigo do cliente: ");
        String cliente = input.lerString();
        clearScreen();
        cliente = cliente.toUpperCase();
        try {
            Crono.start();
            List<ClienteQuantidade> l = model.produtosMaisCompradosCliente(cliente);
            Crono.stop();
            new MessageView().show("Demorou: " + Crono.getTime());
            ((PageView) view).setList(l);
            do{
                new MessageView().show("Numero de produtos que nao foram comprados: " + l.size());
                view.show(idx);
                op = input.lerString().toUpperCase();
                switch (op){
                    case "A" :
                        idx--;
                        break;
                    case "D" :
                        idx++;
                        break;
                    case "J" :
                        new MessageView().show("Insira o numero da pagina: ");
                        idx = input.lerInt()-1;
                        break;
                    case "S" :
                        break;
                    default:
                        new ErrorView().show("Invalid Option");
                        break;
                }
                clearScreen();
            }while(!op.equals("S"));
            view = new QueriesIView();
        } catch (DoesNotExistCode e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    //Query 6
    private void produtosMaisVendidos(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new LimitListView<ProdutosVendas>();
        new MessageView().show("Insira o numero de produtos desejados: ");
        int max = input.lerInt();
        clearScreen();
        Crono watch = new Crono();
        watch.start();
        List<ProdutosVendas> l = model.produtosMaisVendidos();
        watch.stop();
        new MessageView().show("Demorou: " + watch.getTime());
        ((LimitListView) view).setList(l);
        do{
            view.show(max);
            op = input.lerString().toUpperCase();
            if(!op.equals("S"))
                new ErrorView().show("Invalid Option");
        }while(!op.equals("S"));
        clearScreen();
        view = new QueriesIView();
    }

    //Query 7
    private void top3Compradores(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new Query7View();
        Crono watch = new Crono();
        watch.start();
        Map<Integer,List<ClienteDinheiro>> l = model.top3Compradores();
        watch.stop();
        new MessageView().show("Demorou: " + watch.getTime());
        ((Query7View) view).setMap(l);
        do{
            view.show();
            op = input.lerString().toUpperCase();
            if(!op.equals("S"))
                new ErrorView().show("Invalid Option");
        }while(!op.equals("S"));
        clearScreen();
        view = new QueriesIView();
    }

    //Query 8
    private void xClientesComMaisProdutosComprados(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new LimitListView<ClienteQuantidade>();
        new MessageView().show("Insira o numero de clientes desejados: ");
        int max = input.lerInt();
        clearScreen();
        Crono watch = new Crono();
        watch.start();
        List<ClienteQuantidade> l = model.clientesComMaisProdutos();
        watch.stop();
        new MessageView().show("Demorou: " + watch.getTime());
        ((LimitListView) view).setList(l);
        do{
            view.show(max);
            op = input.lerString().toUpperCase();
            if(!op.equals("S"))
                new ErrorView().show("Invalid Option");
        }while(!op.equals("S"));
        clearScreen();
        view = new QueriesIView();
    }

    //Query 9
    private void xClientesQueCompraramMaisProd(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new LimitListView<ClienteQuantidadeValor>();
        Crono watch = new Crono();
        new MessageView().show("Insira o codigo do produto desejado: ");
        String produto = input.lerString().toUpperCase();
        clearScreen();
        new MessageView().show("Insira o numero de clientes desejados: ");
        int max = input.lerInt();
        clearScreen();
        try {
            watch.start();
            List<ClienteQuantidadeValor> l = model.xClientesQueMaisCompraramXProd(produto);
            watch.stop();
            new MessageView().show("Demorou: " + watch.getTime());
            ((LimitListView) view).setList(l);
            do{
                view.show(max);
                op = input.lerString().toUpperCase();
                if(!op.equals("S"))
                    new ErrorView().show("Invalid Option");
            }while(!op.equals("S"));
            view = new QueriesIView();
        } catch (DoesNotExistCode e){
            clearScreen();
            new ErrorView().show("Erro: " + e.getMessage());
            view = new QueriesIView();
        }
    }

    //Query 10
    private void factPorProd(){
        Input input = new Input(new ErrorView());
        String op = "";
        int idx = 0;
        view = new PageView<ProdFact>();
        Crono watch = new Crono();
        watch.start();
        List<ProdFact> l = model.factPorProd();
        watch.stop();
        new MessageView().show("Demorou: " + watch.getTime());
        ((PageView) view).setList(l);
        ((PageView) view).setLimit(1);
        do{
            view.show(idx);
            op = input.lerString().toUpperCase();
            switch (op){
                case "A" :
                    idx--;
                    break;
                case "D" :
                    idx++;
                    break;
                case "J" :
                    new MessageView().show("Insira o numero da pagina: ");
                    idx = input.lerInt()-1;
                    break;
                case "S" :
                    break;
                default:
                    new ErrorView().show("Invalid Option");
                    break;
            }
            clearScreen();
        }while(!op.equals("S"));
        view = new QueriesIView();
    }

    //QueryE 1
    private void dadosLeitura(){
        Input input = new Input(new ErrorView());
        String op = "";
        int idx = 0;
        view = new MessageView();
        Crono watch = new Crono();
        watch.start();
        Dados d = model.getDados();
        watch.stop();
        clearScreen();
        new MessageView().show("Demorou: " + watch.getTime());
        do{
            view.show(d);
            view.show("S - Exit");
            op = input.lerString().toUpperCase();
            if(!op.equals("S"))
                clearScreen();
            new ErrorView().show("Invalid Option");
        }while(!op.equals("S"));
        clearScreen();
        view = new QueriesEView();
    }

    //QueryE 2
    private void factPorMes(){
        Input input = new Input(new ErrorView());
        String op = "";
        view = new MesView<VendasFactNClientes>();
        Crono watch = new Crono();
        watch.start();
        List<VendasFactNClientes> l = model.factPorMes();
        watch.stop();
        clearScreen();
        new MessageView().show("Demorou: " + watch.getTime());
        ((MesView) view).setList(l);
        do{
            view.show();
            op = input.lerString().toUpperCase();
            if(!op.equals("S"))
                clearScreen();
            new ErrorView().show("Invalid Option");
        }while(!op.equals("S"));
        clearScreen();
        view = new QueriesEView();
    }

    private void lerFicheiro(){
        Input input = new Input(new ErrorView());
        String op = "";
        Crono watch = new Crono();
        view = new FileView();
        clearScreen();
        new MessageView().show("Insira como deseja ler o ficheiro de clientes: ");
        do{
            view.show();
            op = input.lerString();
            switch(op){
                case "1" :
                    watch.start();
                        model.loadClientes();
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "2" :
                    clearScreen();
                    new MessageView().show("Insira o path para ler o ficheiro: ");
                    String file = input.lerString();
                    watch.start();
                        model.loadClientes(file);
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("1")||op.equals("0")||op.equals("2")));
        new MessageView().show("Insira como deseja ler o ficheiro de produtos: ");
        do{
            view.show();
            op = input.lerString();
            switch(op){
                case "1" :
                    watch.start();
                    model.loadProdutos();
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "2" :
                    clearScreen();
                    new MessageView().show("Insira o path para ler o ficheiro: ");
                    String file = input.lerString();
                    watch.start();
                    model.loadProdutos(file);
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("1")||op.equals("0")||op.equals("2")));

        new MessageView().show("Insira como deseja ler o ficheiro de vendas: ");
        do{
            view.show();
            op = input.lerString();
            switch(op){
                case "1" :
                    watch.start();
                    model.loadVendas();
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "2" :
                    clearScreen();
                    new MessageView().show("Insira o path para ler o ficheiro: ");
                    String file = input.lerString();
                    watch.start();
                    model.loadVendas(file);
                    watch.stop();
                    clearScreen();
                    new MessageView().show("Demorou: " + watch.getTime());
                    break;
                case "0":
                    clearScreen();
                    break;
                default:
                    clearScreen();
                    new ErrorView().show("Bad Input");
                    break;
            }
        }while(!(op.equals("1")||op.equals("0")||op.equals("2")));
        view = new MainMenuView();
    }

}