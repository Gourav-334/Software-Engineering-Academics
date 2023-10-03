import java.util.*;
public class Lab_Manual_07 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter latitude & longitude of both cities");
        double lat1=sc.nextDouble();
        double long1=sc.nextDouble();
        double lat2=sc.nextDouble();
        double long2=sc.nextDouble();
        double x1=Math.toRadians(lat1);
        double x2=Math.toRadians(long1); 
        double x3=Math.toRadians(lat2);
        double x4=Math.toRadians(long2);
        double long_gap=long2-long1;
        double lat_gap=lat2-lat1;
        double x=Math.pow(Math.sin(lat_gap/2),2)+Math.cos(lat1)*Math.cos(lat2)*Math.pow(Math.sin(long_gap/2),2);
        double y=2*Math.asin(Math.sqrt(x));
        double z=6371*y;
        System.out.println(y);
    }
    
}
