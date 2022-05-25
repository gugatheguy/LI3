package MVC;

import MVC.Models.*;

import java.io.IOException;
import java.util.List;
import java.util.Map;

public interface IGereVendasModel {

     /**
      * Query 1
      * @return Lista dos produtos não comprados.
      */
     List<String> produtosNaoComprados();

     /**
      * Query 2 Filial a Filial
      * @param mes mês
      * @return Lista das vendas mês Filial a Filial
      * @throws InvalidMonth Verifica se o mês é válido.
      */
     List<VendasMesFilial> vendasClientesMesFilialaFilial(int mes) throws InvalidMonth;

     /**
      * Query 2 Global
      * @param mes mês
      * @return Lista das vendas mês global.
      * @throws InvalidMonth Verifica se o mês é válido.
      */
     VendasMesFilial vendasClientesMesFilialGlobal(int mes) throws InvalidMonth;

     /**
      * Query 3
      * @param client Cliente
      * @return Compras, produtos distintos comprados e gastos por um dado cliente por mês.
      * @throws DoesNotExistCode Verifica se o Cliente existe.
      */
     List<IntDoubleDifCods> vendasClientesMes(String client) throws DoesNotExistCode;

     /**
      * Query 4
      * @param produto Produto
      * @return Compras, clientes distintos e total faturado por um dado produto por mês.
      * @throws DoesNotExistCode Verfica se o Produto existe.
      */
     List<IntDoubleDifCods> vendasProdutosMes(String produto) throws DoesNotExistCode;

     /**
      * Query 5
      * @param client Cliente
      * @return Produtos mais comprados por um cliente
      * @throws DoesNotExistCode Verifica se o Cliente existe.
      */
     List<ClienteQuantidade> produtosMaisCompradosCliente(String client) throws DoesNotExistCode;

     /**
      * Query 6
      * @return Lista com os X produtos mais vendidos.
      */
     List<ProdutosVendas> produtosMaisVendidos();

     /**
      * Query 7
      * @return Top 3 Clientes e os seus gastos.
      */
     Map<Integer, List<ClienteDinheiro>> top3Compradores();

     /**
      * Query 8
      * @return Lista com os X clientes que compraram mais produtos diferentes.
      */
     List<ClienteQuantidade> clientesComMaisProdutos();

     /**
      * Query 9
      * @param prod Produto
      * @return Lista com os X clientes que mais compraram um dado produto.
      * @throws DoesNotExistCode Verfica se o Produto existe.
      */
     List<ClienteQuantidadeValor> xClientesQueMaisCompraramXProd(String prod) throws DoesNotExistCode;

     /**
      * Query 10
      * @return Lista com a Faturacao total para cada produto mês a mês.
      */
     List<ProdFact> factPorProd();

     /**
      * Query Estatística 1
      * @return Dados da ultima leitura
      */
     Dados getDados();

     /**
      * Query Estatística 2
      * @return Lista com as vendas, faturacao total e clientes distintos por mês
      */
     List<VendasFactNClientes> factPorMes();

     void loadDefault();

     void gravaEstado() throws IOException;

     void gravaEstado(String filename) throws IOException;

     void carregaEstado() throws IOException, ClassNotFoundException;

     void carregaEstado(String filename) throws IOException, ClassNotFoundException;

     void loadProdutos();

     void loadProdutos(String path);

     void loadClientes();

     void loadClientes(String path);

     void loadVendas();

     void loadVendas(String path);

}
