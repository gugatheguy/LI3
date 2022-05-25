package MVC;

public interface IGereVendasController {

    /**
     * Modifica o GereVendasModel.
     * @param m IGereVendasModel
     */
    void setModel(IGereVendasModel m);

    /**
     * Modifica o GereVendasView
     * @param v IGereVendasView
     */
    void setView(IGereVendasView v);

    /**
     * Inicializa o controller.
     */
    void start();
}
