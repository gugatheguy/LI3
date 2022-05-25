package MVC.Models.BaseModels;

public interface IFact {

    /**
     * Devolve o Preço da Compra presente na Fatura.
     * @return Preço do Produto.
     */
    double getPreco();

    /**
     * Devolve a Quantidade total comprada presente na Fatura.
     * @return Quantidade Total de Produto comprada.
     */
    int getQuantidade();

    /**
     * Devolve o modo de Compra presente na Fatura.
     * @return Modo de Compra.
     */
    char getPromo();

    /**
     * Devolve o mês em que foi realizada a compra presente na Fatura.
     * @return Mês da Compra.
     */
    int getMes();

    /**
     * Devolve em que Filial foi realizada a compra presente na Fatura.
     * @return Filial onde foi realizada a Compra.
     */
    int getFilial();

    /**
     * Cria um clone da Fatura.
     * @return Fatura clonada.
     */
    IFact clone();

}