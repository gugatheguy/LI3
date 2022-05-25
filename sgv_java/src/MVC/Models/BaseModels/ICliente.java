package MVC.Models.BaseModels;

public interface ICliente {

    /**
     * Devolve o Código de um Cliente.
     * @return Código do Cliente.
     */
    String getCodigo();

    /**
     * Verifica se o Código do Cliente é Válido.
     * @return True caso seja Válido, False caso contrário.
     */
    boolean valido();

    /**
     * Cria um clone de Cliente.
     * @return Cliente clonado.
     */
    ICliente clone();

}