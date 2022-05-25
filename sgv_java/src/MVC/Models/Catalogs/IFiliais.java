package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IVendaFilial;

import java.util.List;
import java.util.Set;

public interface IFiliais {


    /**
     * Cria uma Lista de Filiais Inicial.
     * @param s Set com todos os Códigos de Clientes.
     * @param num Número de Filiais total.
     */
    void setFiliais(Set<String> s, int num);

    /**
     * Devolve o número total de Filiais existentes.
     * @return Número de Filiais.
     */
    int getSize();

    /**
     * Adiciona uma Venda (VendaFilial) de um determinado Cliente numa Filial.
     * @param s Código do Cliente.
     * @param v Venda.
     * @param n Filial onde foi realizada a venda.
     */
    void addVenda(String s, IVendaFilial v, int n);

    /**
     * Devolve uma Cópia de uma Filial.
     * @param n Número da Filial.
     * @return Cópia da Filial resultante.
     */
    IFilial getFilial(int n);

    /**
     * Devolve uma cópia da Lista de Todas as Vendas que um Cliente realizou numa determinada Filial.
     * @param cod Código do Cliente.
     * @param n Número da Filial.
     * @return Cópia da Lista de Vendas.
     */
    List<IVendaFilial> getVendasClienteFilial(String cod, int n);

    /**
     * Cria uma nova Filial com todos os códigos de cliente
     * @param s Set com todos os Códigos de Clientes.
     */
    void addNewFilial(Set<String> s);

    /**
     * Vê se um código de cliente numa Filial.
     * @param s Código de Cliente.
     * @return boolean.
     */
    public boolean existeCliente(String s);

}