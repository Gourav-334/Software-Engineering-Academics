public class Lab_Manual_14A {
    public static void main(String args[]){
           A obj=new A();
           obj.setter();
           System.out.println(obj.getName());
           System.out.println(obj.getAge());
        }
    }
    class A{
        private String name;
        private int age;
        public void setter()
        {
            name="Arnaw";
            age=18;
        }
        public String getName()
        {
            return name;
        }
        public int getAge()
        {
            return age;
        }
    }
    

