import java.util.Scanner;
public class Lab_Manual_04 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int days=0,months=0,years=0;
        System.out.println("Enter the Birth Date in Days, Months & Year");
        int birth_day=sc.nextInt();
        int birth_month=sc.nextInt();
        int birth_year=sc.nextInt();
        System.out.println("Enter the Current Date in Days,Months & Year");
        int curr_day=sc.nextInt();
        int curr_month=sc.nextInt();
        int curr_year=sc.nextInt();
        int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (birth_day > curr_day) {
            curr_month = curr_month - 1;
            curr_day = curr_day + month[birth_month - 1];
        }
        if (birth_month > curr_month) {
            curr_year = curr_year - 1;
            curr_month = curr_month + 12;
        }
        days= curr_day - birth_day;
        months = curr_month - birth_month;
        years = curr_year - birth_year;
        System.out.println("You are"+" "+years+" "+"years old");
        System.out.println("You are"+" "+months+" "+"months old");
        System.out.println("You are"+" "+days+" "+"days old");
    }
}
