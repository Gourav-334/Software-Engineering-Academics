public class Lab_Manual_14C {
    void sum(int a)
	{
	System.out.println("Sum "+a);
	}
	void sum(int a,int b)
	{
	System.out.println("Sum "+(a+b));
	}
	void sum(int a,int b,int c)
	{
	System.out.println("Sum "+(a+b+c));
	}
}
class Overloading{
	public static void main(String args[]){
	Lab_Manual_14C obj=new Lab_Manual_14C();
	obj.sum(5);
	obj.sum(7,3);
	obj.sum(3,3,4);
	}
}

