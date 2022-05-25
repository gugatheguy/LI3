package MVC.Models;

import java.util.Arrays;
import java.util.Objects;

public class ProdFact implements Comparable<ProdFact>{
    private String prod;
    private double[][] cat;

    ProdFact(String prod, int nf){
        this.prod = prod;
        this.cat = new double[12][nf];
    }

    public String getProd() {
        return this.prod;
    }

    public double[][] getCat() {
        return this.cat;
    }


    public void addCat(int i, int j, double x){
        this.cat[i - 1 ][j - 1] += x;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ProdFact)) return false;
        ProdFact prodFact = (ProdFact) o;
        return Objects.equals(getProd(), prodFact.getProd()) &&
                Arrays.equals(getCat(), prodFact.getCat());
    }

    public int compareTo(ProdFact o) {
        return this.prod.compareTo(o.getProd());
    }

    private String getMes(int n){
        String s = "";
        switch (n){
            case 1:
                s = "Janeiro:";
                break;
            case 2:
                s = "Fevereiro:";
                break;
            case 3:
                s = "Marco:";
                break;
            case 4:
                s = "Abril:";
                break;
            case 5:
                s = "Maio:";
                break;
            case 6:
                s = "Junho:";
                break;
            case 7:
                s = "Julho:";
                break;
            case 8:
                s = "Agosto:";
                break;
            case 9:
                s = "Setembro:";
                break;
            case 10:
                s = "Outubro:";
                break;
            case 11:
                s = "Novembro:";
                break;
            case 12:
                s = "Dezembro:";
                break;
        }
        return s;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        int size = this.cat[0].length;
        sb.append("Produto: ").append(this.prod).append("\n");
        for (int z = 0; z < 12; z++){
            sb.append(getMes(z + 1)).append(":");
            for(int i = 0; i < size; i++) {
                sb.append("\n").append("\tFilial ").append(i + 1).append(": ").append(String.format("%.2f",this.cat[z][i]));
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
