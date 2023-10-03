public class Lab_Manual_14B {
    public static void main(String[] args) {
            Apple obj1=new Apple();
            obj1.print();
            Banana obj=new Banana();
            obj.print();
            obj.display();
            }
        }
        class Apple
        {
            void print()
            {
                System.out.println("Apple");
            }
        }
        class Banana extends Apple //Single Level Inheritance
        {
            void display()
            {
                System.out.println("Banana");
            }
            void print()
            {
                System.out.println("Not Banana");
            }
        }
        
    

