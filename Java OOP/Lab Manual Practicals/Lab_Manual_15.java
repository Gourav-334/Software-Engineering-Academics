public class Lab_Manual_15 {
    public static void main(String[] args) {
        B obj=new B();
		obj.print();
		obj.display();
	}
}
class A
{
	int x=87;
    void print()
	{
		System.out.println(x);
	}
}
class B extends A
{
	int x=95;
	void print()
	{
		System.out.println(x);
		System.out.println(super.x);
	}
	void display()
	{
		print();
		super.print();
	}
}
    

