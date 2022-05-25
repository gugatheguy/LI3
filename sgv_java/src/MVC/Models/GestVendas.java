package MVC.Models;

import MVC.IGereVendasModel;
import MVC.Models.BaseModels.IFact;
import MVC.Models.BaseModels.IVendaFilial;
import MVC.Models.Catalogs.*;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class GestVendas implements IGereVendasModel,Serializable{
    private IProdutos prods;
    private IFiliais fils;
    private IClientes clients;
    private IFactTotal ft;
    private Dados d;

    public GestVendas(){
        this.prods = new Produtos();
        this.fils = new Filiais();
        this.clients = new Clientes();
        this.ft = new FactTotal();
        this.d = new Dados();
    }

    public void loadDefault(){
        Parse p = new Parse();
        p.parseTotal(this.clients,this.prods,this.ft,this.fils, this.d);
    }

    public void gravaEstado() throws IOException {
        gravaEstado("dados/gestVendas.dat");
    }

    public void gravaEstado(String filename) throws IOException {
        ObjectOutputStream o = new ObjectOutputStream(new FileOutputStream(filename));
        o.writeObject(this);
        o.flush();
        o.close();
    }

    private void cloneToSelf(GestVendas g){
        this.ft = g.ft;
        this.clients = g.clients;
        this.fils = g.fils;
        this.prods = g.prods;
    }

    public void carregaEstado() throws IOException, ClassNotFoundException {
        carregaEstado("dados/gestVendas.dat");
    }

    public void carregaEstado(String filename) throws IOException, ClassNotFoundException {
        ObjectInputStream o = new ObjectInputStream(new FileInputStream(filename));
        this.cloneToSelf((GestVendas) o.readObject());
        o.close();
    }

    //Query 1
    public List<String> produtosNaoComprados(){
        List<String> r = new ArrayList<>();
        for (Map.Entry<String, List<IFact>> e : this.ft.getFact().entrySet()){
            if (e.getValue().size() == 0)
                r.add(e.getKey());
        }
        r.sort(String::compareTo);
        return r;
    }

    //Query 2
    private VendasMesFilial vendasClientesMesFilialaux(IFilial f,int mes){
        int nvendas = 0;
        int nclientes = 0;
        boolean teste = false;

        for (Map.Entry<String,List<IVendaFilial>> e : f.getVendas().entrySet()){
            for (IVendaFilial v : e.getValue()){
                if(v.getMes()==mes) {
                    nvendas++;
                    teste = true;
                }
            }
            if(teste) {
                nclientes++;
                teste = false;
            }
        }
        return new VendasMesFilial(nclientes, nvendas);
    }

    public List<VendasMesFilial> vendasClientesMesFilialaFilial(int mes) throws InvalidMonth{
        if(mes>=1 & mes<=12){
            List<VendasMesFilial> res = new ArrayList<>();
            for (int i = 1; i <= this.fils.getSize(); i++)
                res.add(vendasClientesMesFilialaux(this.fils.getFilial(i), mes));
            return res;
        }
        else
            throw new InvalidMonth(String.valueOf(mes));
    }

    public VendasMesFilial vendasClientesMesFilialGlobal(int mes) throws InvalidMonth{
        if(mes>=1 & mes<=12){
            int nvendas = 0;
            Set<String> nclientes = new TreeSet<>();
            boolean teste = false;
            for (int i = 1; i <= this.fils.getSize(); i++) {
                IFilial f = this.fils.getFilial(i);
                for (Map.Entry<String, List<IVendaFilial>> e : f.getVendas().entrySet()) {
                    for (IVendaFilial v : e.getValue()) {
                        if (v.getMes() == mes) {
                            nvendas++;
                            teste = true;
                        }
                    }
                    if (teste) {
                        nclientes.add(e.getKey());
                        teste = false;
                    }
                }
            }
            return new VendasMesFilial(nclientes.size(), nvendas);
        }
        else
            throw new InvalidMonth(String.valueOf(mes));
    }

    //Query 3
    public List<IntDoubleDifCods> vendasClientesMes(String client) throws DoesNotExistCode{
        if(this.fils.existeCliente(client)){
            List<IntDoubleDifCods> list = new ArrayList<>() ;
            for (int i=0; i<12;i++){
                list.add(new IntDoubleDifCods());
            }
            for(int i=1; i<=this.fils.getSize();i++) {
                for (IVendaFilial v : this.fils.getVendasClienteFilial(client, i)){
                    IntDoubleDifCods aux = list.get(v.getMes()-1);
                    aux.addCamps(1, v.getQuantidade()*v.getPreco(), v.getProduto());
                }
            }
            return list;
        }
        else
            throw new DoesNotExistCode(client);
    }

    //Query 4
    public List<IntDoubleDifCods> vendasProdutosMes(String produto) throws DoesNotExistCode{
        if(this.ft.existeProd(produto)){
            List<IntDoubleDifCods> list = new ArrayList<>() ;
            for(int i=0;i<12;i++)
                list.add(new IntDoubleDifCods());


            for(int i=1; i<=this.fils.getSize();i++) {
                for (Map.Entry<String, List<IVendaFilial>> e : this.fils.getFilial(i).getVendas().entrySet())
                    for (IVendaFilial v : e.getValue()) {
                        if (produto.equals(v.getProduto())) {
                            IntDoubleDifCods aux = list.get(v.getMes()-1);
                            aux.addCamps(1, v.getQuantidade()*v.getPreco(), e.getKey());
                        }
                    }
            }
            return list;
        }
        else
            throw new DoesNotExistCode(produto);
    }

    //Query 5
    public List<ClienteQuantidade> produtosMaisCompradosCliente(String client) throws DoesNotExistCode{
        if(this.fils.existeCliente(client)){
            Map<String, ClienteQuantidade> res = new HashMap<>();
            ClienteQuantidade aux;
            int quant;
            for(int i=1; i<=this.fils.getSize();i++) {
                for (IVendaFilial v : this.fils.getVendasClienteFilial(client, i)){
                    if(res.containsKey(v.getProduto())){
                        aux = res.get(v.getProduto());
                        quant = aux.getQuant();
                        quant += v.getQuantidade();
                        aux.setQuant(quant);
                    }
                    else{
                        aux = new ClienteQuantidade(v.getProduto(), v.getQuantidade());
                        res.put(v.getProduto(), aux);
                    }
                }
            }
            Set<ClienteQuantidade> r =  new TreeSet<>(res.values());
            return new ArrayList<>(r);
        }
        else
            throw new DoesNotExistCode(client);

    }

    //Query 6
    private void addProduto(Map<String,ProdutosVendas> res, ProdutosVendas p){
        String codProduto = p.getProduto();
        if(res.containsKey(codProduto))
            res.get(codProduto).adicionaProduto(p);
        else
            res.put(codProduto,p);
    }

    public List<ProdutosVendas> produtosMaisVendidos(){
        Map<String,ProdutosVendas> res = new HashMap<>();
        for (int i=1;i<=this.fils.getSize();i++){
            for (Map.Entry<String, List<IVendaFilial>> e : this.fils.getFilial(i).getVendas().entrySet()){
                for (IVendaFilial v : e.getValue()){
                    addProduto(res,new ProdutosVendas(v.getProduto(),v.getQuantidade(),e.getKey()));
                }
            }
        }
        return res.values().stream().sorted(ProdutosVendas::compareTo).collect(Collectors.toList());
    }

    //Query 7
    public Map<Integer, List<ClienteDinheiro>> top3Compradores(){
        Map<Integer, List<ClienteDinheiro>> res = new HashMap<>();
        Comparator<ClienteDinheiro> comparador = ClienteDinheiro::comparaClientes;

        for(int i = 1 ; i <= this.fils.getSize(); i++){
            List<ClienteDinheiro> aux = new ArrayList<>();
            for (Map.Entry<String, List<IVendaFilial>> e : this.fils.getFilial(i).getVendas().entrySet()) {

                ClienteDinheiro cd = new ClienteDinheiro(e.getKey(), 0);
                for (IVendaFilial v : e.getValue()) {
                    cd.addGastos(v.getQuantidade() * v.getPreco());
                }
                aux.add(cd);
            }
            aux.sort(comparador);
            List<ClienteDinheiro> aux2 = aux.subList(0, 3);
            res.put(i, aux2);
        }
        return res;
    }

    //Query 8
    public List<ClienteQuantidade> clientesComMaisProdutos() {
        Map<String, ClienteQuantidade> res = new HashMap<>();
        ClienteQuantidade aux;
        int quant;
        for (int i = 1; i <= this.fils.getSize(); i++) {
            for (Map.Entry<String, List<IVendaFilial>> e : this.fils.getFilial(i).getVendas().entrySet()) {
                quant = 0;
                if (res.containsKey(e.getKey())) {
                    aux = res.get(e.getKey());
                    quant = aux.getQuant();
                    for (IVendaFilial v : e.getValue())
                        quant++;
                    aux.setQuant(quant);
                } else {
                    for (IVendaFilial v : e.getValue())
                        quant++;
                    aux = new ClienteQuantidade(e.getKey(), quant);
                    res.put(e.getKey(), aux);
                }
            }
        }
        return res.values().stream().sorted().collect(Collectors.toList());
    }

    //Query 9
    public List<ClienteQuantidadeValor> xClientesQueMaisCompraramXProd(String prod) throws DoesNotExistCode{
        if(this.ft.existeProd(prod)){
            Map<String, ClienteQuantidadeValor> res = new HashMap<>();

            for (int i = 1; i <= this.fils.getSize(); i++) {
                IFilial fil = this.fils.getFilial(i);
                for (Map.Entry<String, List<IVendaFilial>> e : fil.getVendas().entrySet()) {
                    ClienteQuantidadeValor aux;
                    int qt = 0;
                    double val = 0;
                    IVendaFilial vf;
                    if (res.containsKey(e.getKey())) {
                        if(fil.clienteContainsProd(e.getKey(), prod)){
                            vf = fil.getProdVendaFilial(e.getKey(), prod);
                            aux = res.get(e.getKey());
                            qt = aux.getQuant();
                            val = aux.getValor();
                            qt += vf.getQuantidade();
                            val += vf.getQuantidade() * vf.getPreco();
                            aux.setQuant(qt);
                            aux.setValor(val);
                        }
                    } else {
                        if(fil.clienteContainsProd(e.getKey(), prod)){
                            vf = fil.getProdVendaFilial(e.getKey(), prod);
                            qt += vf.getQuantidade();
                            val += vf.getQuantidade() * vf.getPreco();
                            aux = new ClienteQuantidadeValor(e.getKey(), qt, val);
                            res.put(e.getKey(), aux);
                        }
                    }
                }
            }
            Set<ClienteQuantidadeValor> ansaux = new TreeSet<>(res.values());

            return new ArrayList<>(ansaux);
        }
        else
            throw new DoesNotExistCode(prod);
    }

    //Query 10
    public List<ProdFact> factPorProd(){
        Map<String, ProdFact> res = new HashMap<>();
        ProdFact aux;
        double totalmes;
        int nfiliais = this.ft.nFiliais();

        for (Map.Entry<String, List<IFact>> e : this.ft.getFact().entrySet()){
            String s = e.getKey();
            aux = new ProdFact(s, nfiliais);
            for (IFact f : e.getValue()){
                totalmes = f.getPreco() * f.getQuantidade();
                aux.addCat(f.getMes(), f.getFilial(), totalmes);
            }
            res.put(e.getKey(), aux);
        }
        Set<ProdFact> ansaux = new TreeSet<>(res.values());
        return new ArrayList<>(ansaux);
    }

    //QueryE 1
    public Dados getDados(){
        this.d.setClientes(this.clients.getSize());
        this.d.setProdutos(this.prods.getSize());
        int pc = 0;
        for (Map.Entry<String, List<IFact>> e : this.ft.getFact().entrySet()){
            if(!e.getValue().isEmpty())
                pc++;
        }
        this.d.setProdutosComprados(pc);

        Set<String> aux = new TreeSet<>();
        for (int i = 1; i <= this.fils.getSize(); i++) {
            IFilial fil = this.fils.getFilial(i);
            for (Map.Entry<String, List<IVendaFilial>> e : fil.getVendas().entrySet()) {
                String s = e.getKey();
                if (!e.getValue().isEmpty())
                    aux.add(s);

            }
        }
        this.d.setClientesQueCompram(aux.size());
        return d.clone();
    }

    //QueryE 2
    public List<VendasFactNClientes> factPorMes(){
        List<VendasFactNClientes> l = new ArrayList<>();
        for (int i=0;i<12;i++)
            l.add(new VendasFactNClientes(this.fils.getSize()));
        for (int i = 1; i <= this.fils.getSize(); i++) {
            IFilial fil = this.fils.getFilial(i);
            for (Map.Entry<String, List<IVendaFilial>> e : fil.getVendas().entrySet()) {
                String client = e.getKey();
                for (IVendaFilial v : e.getValue()) {
                    l.get(v.getMes()-1).addVenda(1,v.getPreco()*v.getQuantidade(),client,i);
                }
            }
        }
        return l;
    }

    public void loadProdutos(){
        this.prods = new Produtos();
        Parse.parseProdutos(this.prods);
    }

    public void loadProdutos(String path){
        this.prods = new Produtos();
        Parse.parseProdutos(this.prods, path);
    }

    public void loadClientes(){
        this.clients = new Clientes();
        Parse.parseClientes(this.clients);
    }

    public void loadClientes(String path){
        this.clients = new Clientes();
        Parse.parseClientes(this.clients, path);
    }

    public void loadVendas(){
        this.ft= new FactTotal();
        this.fils = new Filiais();
        this.d = new Dados();
        Parse.parseVendas(this.prods,this.clients,this.fils,this.ft,this.d);
    }

    public void loadVendas(String path){
        this.ft= new FactTotal();
        this.fils = new Filiais();
        this.d = new Dados();
        Parse.parseVendas(this.prods,this.clients,this.fils,this.ft,this.d,path);
    }

}