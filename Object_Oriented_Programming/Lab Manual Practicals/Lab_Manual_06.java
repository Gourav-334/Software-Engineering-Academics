import java.util.*;
class Lab_Manual_06 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        final double g=0.38;
        System.out.println("Enter the weight in pounds");
        double pounds=sc.nextInt();
        double weight=g*pounds;
        System.out.println("Weight in Earth"+" "+pounds);
        System.out.println("Weight in Mars"+" "+weight);
    }
}
