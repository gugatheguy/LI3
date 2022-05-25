package MVC.Models.Catalogs;

import MVC.Models.BaseModels.IFact;

import java.util.List;
import java.util.Set;
import java.util.Map;

public interface IFactTotal {

    /**
     * Cria uma Lista de Faturação Total inicial.
     * @param s Set com todos os Produtos existentes.
     */
    void setFactTotal(Set<String> s);

    /**
     * Adiciona uma Fatura a um Cliente existente no Catálogo de Faturas Total.
     * @param s Código do Produto.
     * @param f Fatura a adicionar.
     */
    void addFact(String s, IFact f);

    /**
     * Devolve uma Fatura de um determinado Produto.
     * @return Fatura resultante.
     */
    Map<String, List<IFact>> getFact();

    /**
     * Cria uma Lista de Faturas Total através de outra.
     * @param m Lista de Faturas Total.
     */
    void setFact(Map<String, List<IFact>> m);

    /**
     * Devolve uma cópia da Lista de Todas as Faturas de um dado Produto.
     * @param cod Código do Produto.
     * @return Lista Clonada.
     */
    List<IFact> getFactProd(String cod);

    /**
     * Devolve o número total de Faturas existentes.
     * @return Número de Faturas.
     */
    int getSize();

    /**
     * Devolve o número de filiais existentes atráves das Faturas.
     * @return Número de Filiais.
     */
    int nFiliais();

    /**
     * Verifica se existe Produto.
     * @param s Código de Produto.
     * @return True caso existe, False caso contrário.
     */
    boolean existeProd(String s);

}