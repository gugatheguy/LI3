package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IProduto;

import java.util.Set;

public interface IProdutos {

    /**
     * Devolve uma cópia do Catálogo de Produtos.
     *
     * @return Catálogo de Produtos Clonado.
     */
    Set<String> getCatalogo();

    /**
     * Devolve o número total de produtos no Catálogo.
     *
     * @return Número de Produtos.
     */
    int getSize();

    /**
     * Verifica se um Código de Produto existe no Catálogo.
     *
     * @param s Código de Produto.
     * @return True caso exista, False caso contrário.
     */
    boolean existe(String s);

    /**
     * Verifica se um Produto existe no Catálogo.
     *
     * @param p Produto.
     * @return True caso exista, False caso contrário.
     */
    boolean existe(IProduto p);

    /**
     * Adiciona um Produto ao Catálogo de Produtos.
     * @param p Produto
     */
    void adicionaProduto(IProduto p);
}