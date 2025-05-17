import java.util.*;
class Lab_Manual_13 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int max=100,min=1;
        int range=100;
        int random=(int)(Math.random()*100);
        while(true){
        System.out.println("Guess the number");
        int num=sc.nextInt();
        if(num==random){
        System.out.println("Congratulations !");
        System.exit(0);
        }
        else if(num<=random)
        System.out.println("Hint: Number you entered is less than the actual number");
        else
        System.out.println("Hint: Number you entered is more than the actual number");
    }}
}
