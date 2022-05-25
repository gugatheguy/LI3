/**
 * Classe que abstrai a utilização da classe Scanner, escondendo todos os
 * problemas relacionados com excepções, e que oferece métodos simples e
 * robustos para a leitura de valores de tipos simples e String.
 *
 * É uma classe de serviços, como Math e outras de Java, pelo que devem ser
 * usados os métodos de classe implementados.
 *
 * Utilizável em BlueJ, NetBeans, CodeBlocks ou Eclipse.
 * 
 * Utilização típica:  int x = Input.lerInt();
 *                     String nome = Input.lerString();
 * 
 * @author F. Mário Martins
 * @version 1.0 (6/2006)
 */

package MVC;

import static java.lang.System.out;
import static java.lang.System.in;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Input {

    private IGereVendasView view;

    public Input(IGereVendasView v){
        this.view = v;
    }

 public String lerString() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     String txt = "";
     while(!ok) {
         try {
             txt = input.nextLine();
             ok = true;
         }
         catch(InputMismatchException e) 
             { view.show("Texto Invalido");
               view.show("Novo valor: ");
               input.nextLine(); 
             }
     }
     //input.close();
     return txt;
  } 

 
 public int lerInt() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     int i = 0; 
     while(!ok) {
         try {
             i = input.nextInt();
             ok = true;
         }
         catch(InputMismatchException e) {
             view.show("Inteiro Invalido");
             view.show("Novo valor: ");
             input.nextLine();
             }
     }
     //input.close();
     return i;
  } 
  
  public double lerDouble() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     double d = 0.0; 
     while(!ok) {
         try {
             d = input.nextDouble();
             ok = true;
         }
         catch(InputMismatchException e) 
             { view.show("Valor real Invalido");
                 view.show("Novo valor: ");
               input.nextLine(); 
             }
     }
     //input.close();
     return d;
  }  
  
   public float lerFloat() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     float f = 0.0f; 
     while(!ok) {
         try {
             f = input.nextFloat();
             ok = true;
         }
         catch(InputMismatchException e) {
             view.show("Valor real Invalido");
             view.show("Novo valor: ");
             input.nextLine();
             }
     }
     //input.close();
     return f;
  }  
  
   public boolean lerBoolean() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     boolean b = false; 
     while(!ok) {
         try {
             b = input.nextBoolean();
             ok = true;
         }
         catch(InputMismatchException e) 
             { view.show("Booleano Invalido");
               view.show("Novo valor: ");
               input.nextLine(); 
             }
     }
     //input.close();
     return b;
  } 
  
  public short lerShort() {
     Scanner input = new Scanner(in);
     boolean ok = false; 
     short s = 0; 
     while(!ok) {
         try {
             s = input.nextShort();
             ok = true;
         }
         catch(InputMismatchException e) 
             { view.show("Short Invalido");
               view.show("Novo valor: ");
               input.nextLine(); 
             }
     }
     //input.close();
     return s;
  }  
}