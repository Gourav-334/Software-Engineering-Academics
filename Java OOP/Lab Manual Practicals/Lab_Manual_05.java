import java.util.*;
class Lab_Manual_05 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Temperature in Celsius");
        int celsius=sc.nextInt();
        double fahrenheit= celsius*(9/5)+32;
        double kelvin=celsius+273.15;
        System.out.println("Temperature in Fahrenheit"+" "+fahrenheit);
        System.out.println("Temperature in Kelvin"+" "+kelvin);
    }
}
