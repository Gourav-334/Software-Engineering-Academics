interface A
{
	int num=5;
	void show();
    default void display()
	{
		System.out.println("Bye");
	}
	static void message()
	{
		System.out.println("Message");
	}
}
interface C
{
	void print();
}
class B implements A,C
{
	public void show()
	{
		System.out.println("Hello");
	}
	public void print()
	{
		System.out.println("Hii");
	}
}
public class Lab_Manual_17 {
    public static void main(String args[]){
		System.out.println(A.num);
		B obj=new B();
		obj.show();
		obj.print();
		obj.display();
        A.message();
	}
}
