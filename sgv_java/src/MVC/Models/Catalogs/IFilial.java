package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;

import java.util.List;
import java.util.Map;

public interface IFilial {

    /**
     * Adiciona uma VendaFilial a um Cliente existente numa Filial.
     * @param s Código de Cliente.
     * @param v VendaFilial.
     */
    void addVenda(String s, IVendaFilial v);

    /**
     * Devolve uma cópia do Catálogo de uma Filial.
     * @return Cópia da Filial.
     */
    Map<String, List<IVendaFilial>> getVendas();

    /**
     * Cria um Catálogo de Filial a partir de outro.
     * @param m Catálogo de Filial.
     */
    void setVendas(Map<String, List<IVendaFilial>> m);

    /**
     * Devolve uma cópia da Lista de VendasFilial de um Cliente.
     * @param cod Código de Cliente.
     * @return Cópia da Lista de VendasFilial.
     */
    List<IVendaFilial> getVendasCliente(String cod);

    /**
     * Devolve o tamanho do Catálogo da Filial.
     * @return Tamanho total.
     */
    int getSize();

    /**
     * Verifica se um Cliente comprou um Produto na Filial.
     * @param cl Código do Cliente.
     * @param prod Código do Produto
     * @return true caso tenha, false caso contrário.
     */
    boolean clienteContainsProd(String cl, String prod);

    /**
     * Devolve a VendaFilial que contém o produto que o Cliente comprou.
     * @param cl Código de Cliente.
     * @param prod Código de Produto.
     * @return VendaFilial resultante.
     */
    IVendaFilial getProdVendaFilial(String cl, String prod);

    /**
     * Vê se um código de cliente numa Filial.
     * @param s Código de Cliente.
     * @return boolean.
     */
    public boolean existeCliente(String s);

    /**
     * Cria um Clone de uma Filial.
     * @return Filial clonada.
     */
    IFilial clone();
}