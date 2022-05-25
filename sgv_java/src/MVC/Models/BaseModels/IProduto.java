package MVC.Models.BaseModels;

public interface IProduto{

    /**
     * Devolve o Código de um Produto.
     * @return Código do Produto.
     */
    String getCodigo();

    /**
     * Verifica se o Código do Produto é Válido.
     * @return True caso seja Válido, False caso contrário.
     */
    boolean valido();

    /**
     * Cria um clone de Produto.
     * @return Produto clonado.
     */
    IProduto clone();

}