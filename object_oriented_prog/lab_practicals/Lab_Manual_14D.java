public class Lab_Manual_14D {
    public static void main(String[] args) {
    B obj=new B();
    obj.print();
    }
}
class A
{
	int x=87;
}
class B extends A
{
	int x=95;
	void print()
	{
		System.out.println(x);
		System.out.println(super.x);
	}
}