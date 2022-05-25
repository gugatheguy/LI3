package MVC.Models;

public class ClearScreen {

    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        /*final String ANSI_CLS = "\u001b[2J";
        final String ANSI_HOME = "\u001b[H";
        System.out.println(ANSI_CLS + ANSI_HOME);*/
    }

}
