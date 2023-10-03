import java.util.*;
class Lab_Manual_03 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number");
        int num=sc.nextInt();
        if(num>0){
        if(num%2==0)
        System.out.println("Even Number");
        else
        System.out.println("Odd Number");
       }
       else
       System.out.println("Neither even nor odd");

    }
}
