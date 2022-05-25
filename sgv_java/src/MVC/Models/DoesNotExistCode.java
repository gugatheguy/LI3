package MVC.Models;

public class DoesNotExistCode extends Exception{
    public DoesNotExistCode(){
        super();
    }

    public DoesNotExistCode(String s){
        super(s);
    }
}