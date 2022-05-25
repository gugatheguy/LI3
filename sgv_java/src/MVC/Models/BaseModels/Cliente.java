package MVC.Models.BaseModels;

import java.io.Serializable;
import java.util.Objects;

public class Cliente implements Comparable<ICliente>, ICliente, Serializable {
    public String codigo;

    public Cliente(){
        this.codigo = "";
    }

    public Cliente(String s){
        this.codigo = s;
    }

    public String getCodigo() {
        return codigo;
    }

    public Cliente(Cliente c){
        this.codigo = c.getCodigo();
    }

    public boolean valido(){
        return Cliente.valido(this.codigo);
    }

    public static boolean valido(String s){
        boolean r = (s.length()==5);
        if(r){
            String aux = s.substring(1);
            r = ((s.charAt(0)>='A' && s.charAt(0)<='Z') &&
                    (aux.equals("5000") ||
                        ((s.charAt(1)>='1' && s.charAt(1)<='4')
                        && (s.charAt(2)>='0' && s.charAt(2)<='9')
                        && (s.charAt(3)>='0' && s.charAt(3)<='9')
                        && (s.charAt(4)>='0' && s.charAt(4)<='9'))));
        }
        return r;
    }

    public int compareTo(ICliente cliente) {
        return this.codigo.compareTo(cliente.getCodigo());
    }

    public String toString() {
        return this.codigo;
    }

    /*public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ICliente cliente = (ICliente) o;
        return this.codigo.equals(cliente.getCodigo());
    }*/

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Cliente)) return false;
        Cliente cliente = (Cliente) o;
        return Objects.equals(getCodigo(), cliente.getCodigo());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getCodigo());
    }

    public ICliente clone(){
        return new Cliente(this);
    }
}