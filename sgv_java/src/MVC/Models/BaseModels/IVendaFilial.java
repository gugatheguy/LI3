package MVC.Models.BaseModels;

public interface IVendaFilial {

    /**
     * Devolve o Código do Produto presente na Venda.
     * @return Código do Produto.
     */
    String getProduto();

    /**
     * Devolve o Preço da Venda.
     * @return Preço.
     */
    double getPreco();

    /**
     * Devolve a Quantidade do Produto vendido na compra.
     * @return Quantidade Total.
     */
    int getQuantidade();

    /**
     * Devolve o modo de Compra.
     * @return Modo de Compra.
     */
    char getPromocao();

    /**
     * Devolve o Mês em que foi realizada a compra.
     * @return Mês da Venda.
     */
    int getMes();

    /**
     * Cria um clone de uma VendaFilial.
     * @return VendaFilial clonado.
     */
    IVendaFilial clone();
}