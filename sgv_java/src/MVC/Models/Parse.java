package MVC.Models;

import MVC.Models.Catalogs.*;
import MVC.Models.BaseModels.*;

import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.charset.StandardCharsets;
import java.util.Set;

/**
 * Write a description of class Parse here.
 *
 * @author 89510-89561-89501
 * @version 12/05/2020
 */
public class Parse {

    public void parseTotal(IClientes c,IProdutos p,IFactTotal ft, IFiliais f, Dados d){
        parseClientes(c);
        parseProdutos(p);
        parseVendas(p,c,f,ft,d);
    }

    static public void parseClientes(IClientes clients){
        parseClientes(clients, "dados/Clientes.txt");
    }

    static public void parseClientes(IClientes clients, String path){
        List<String> linhas = lerFicheiro(path);
        for (String linha : linhas) {
            if(Cliente.valido(linha)) {
                clients.adicionaCliente(new Cliente(linha));
            }
        }
    }

    static public void parseProdutos( IProdutos p){
        parseProdutos(p, "dados/Produtos.txt");
    }

    static public void parseProdutos(IProdutos p, String path){
        List<String> linhas = lerFicheiro(path);
        for (String linha : linhas) {
            if(Produto.valido(linha)) {
                p.adicionaProduto(new Produto(linha));
            }
        }
    }

    public static void parseVendas(IProdutos prods, IClientes clients,IFiliais f, IFactTotal ft, Dados d){
        parseVendas(prods,clients,f, ft,d,"dados/Vendas_1M.txt");
    }

    public static void parseVendas(IProdutos prods, IClientes clients,IFiliais f, IFactTotal ft,Dados d, String path){
        List<String> linhas = lerFicheiro(path);
        d.setNome(path);
        String[] campos;
        ft.setFactTotal(prods.getCatalogo());
        int nfilial = 0;
        Set<String> s = clients.getCatalogo();
        int vendasGratis = 0;
        int vendasErradas = 0;
        double faturacao = 0;
        for (String linha : linhas) {
            campos = linha.split(" ");
            String produto = campos[0];
            double preco = Double.parseDouble(campos[1]);
            int quant = Integer.parseInt(campos[2]);
            char promo = campos[3].charAt(0);
            String cliente = campos[4];
            int mes = Integer.parseInt(campos[5]);
            int filial = Integer.parseInt(campos[6]);
            if(nfilial < filial){
                for (int i = nfilial; i < filial; i++)
                    f.addNewFilial(s);
                nfilial = filial;
            }
            if(ft.existeProd(produto) && f.existeCliente(cliente) && (filial>=1) && 0.0<=preco && preco<=999.99 && 1<=quant && quant<=200 && 1<=mes && mes<=12 && (promo == 'N'||promo == 'P' )) {
                if(preco==0)
                    vendasGratis++;
                faturacao+=preco;
                f.addVenda(cliente, new VendaFilial(produto, preco, quant, promo, mes), filial);
                ft.addFact(produto, new Fact(preco, quant, promo, mes, filial));
            }
            else
                vendasErradas++;
            d.setFaturacao(faturacao);
            d.setComprasGratis(vendasGratis);
            d.setVendasErradas(vendasErradas);
        }

    }

    public static List<String> lerFicheiro(String nomeFich) {
        List<String> lines = new ArrayList<>();
        try { lines = Files.readAllLines(Paths.get(nomeFich), StandardCharsets.UTF_8); }
        catch(IOException exc) { System.out.println(exc.getMessage()); }
        return lines;
    }
}