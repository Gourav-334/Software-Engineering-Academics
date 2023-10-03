import java.util.*;
class Lab_Manual_08 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Principal,Rate & Time");
        double principal=sc.nextDouble();
        double rate=sc.nextDouble();
        double time=sc.nextDouble();
        double simple=(principal*rate*time)/100;
        System.out.println("Simple Interest"+" "+simple);
        double compound=principal*(Math.pow((1+rate/100),time))-principal;
        System.out.println("Compound Interest"+" "+compound);
    }
}
