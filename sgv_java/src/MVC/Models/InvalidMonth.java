package MVC.Models;

public class InvalidMonth extends Exception {
    public InvalidMonth() {
        super();
    }

    public InvalidMonth(String s) {
        super(s);
    }
}