import java.util.*;
class Lab_Manual_09 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n=sc.nextInt();
        if(n%2==0){
        System.out.println("Invalid choice");
        System.exit(0);;
        }
        else
        {
        int flag=n/2+1;
        int spaces=n/2,stars=1;
        for(int i=1;i<=n;i++){
            
            for(int j=0;j<spaces;j++){
                System.out.print(" ");
            }
            for(int k=0;k<stars;k++){
                System.out.print("*");
            }
            System.out.println();
            if(i>=flag)
            {
                spaces++;
                stars-=2;
            }
            else
            {
            spaces--;
            stars+=2;
            }
        }
    }
}
}
