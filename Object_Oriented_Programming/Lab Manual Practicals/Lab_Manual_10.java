class Lab_Manual_10 {
    public static void main(String[] args) {
        int arr[]={1,2,0,2,0,2,1,0,0,2};
        int count1=0,count2=0,count3=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0)
            count1++;
            else if(arr[i]==1)
            count2++;
            else
            count3++;
        }
        for(int i=0;i<count1;i++){
            System.out.print(0);
        }
        for(int i=0;i<count2;i++){
            System.out.print(1);
        }
        for(int i=0;i<count3;i++){
            System.out.print(2);
        }
    }
}
