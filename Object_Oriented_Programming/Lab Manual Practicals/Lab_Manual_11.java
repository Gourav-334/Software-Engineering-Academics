import java.util.*;
class Lab_Manual_11 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int arr[]=new int[5];
        System.out.println("Enter the elements");
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        int sum=0;
        for(int i=0;i<arr.length;i++){
        sum+=arr[i];
        }
        System.out.println("Sum Of elements of the array"+sum);
    }
}
