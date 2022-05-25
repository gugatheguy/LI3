package MVC.Models.Catalogs;

import MVC.Models.BaseModels.ICliente;

import java.util.Set;

public interface IClientes {

    /**
     * Devolve uma cópia do Catálogo de Clientes.
     *
     * @return Catálogo de Clientes Clonado.
     */
    Set<String> getCatalogo();

    /**
     * Devolve o número total de Clientes no Catálogo.
     *
     * @return Número de Clientse.
     */
    int getSize();

    /**
     * Verifica se um Código de Cliente existe no Catálogo.
     *
     * @param s Código de Cliente.
     * @return True caso exista, False caso contrário.
     */
    boolean existe(String s);

    /**
     * Verifica se um Cliente existe no Catálogo.
     *
     * @param c Cliente.
     * @return True caso exista, False caso contrário.
     */
    boolean existe(ICliente c);

    /**
     * Adiciona um Cliente ao Catálogo de Clientes.
     * @param c Cliente
     */
    void adicionaCliente(ICliente c);
}