class Main {

    static int a = 10;
    int b = 20;

    static void Run()
    {
        int d = 40;
        System.out.println(d + " " + a);
        ++a;
        ++d;
        System.out.println(d + " " + a);
        a++;
        d++;
    }

    static void AllNaturalNoAdd()
    {
        int n = 10;
        int sum = 0;
        for(int i = 0; i < 10; i++)
        {
            sum = sum + i;
        }
        System.out.println("Addition of All Natural no. is: " + sum);
    }

    static int Recursion(int m)
    {
        if(m == 0) //base condition
        {
            return 0;
        }
        return m + Recursion(m-1);
    }

    static void RecursionPrintNo(int m)
    {
        if(m == 0)
        {
            return ;
        }
        System.out.println("Reverse order ");
        System.out.println(m + " ");
        RecursionPrintNo(m-1);
        // System.out.println("Normal order");
        // System.out.println(m + " ");
    }

    static int Factorial(int m)
    {
        if(m == 0)
        {
            return 1;
        }
        else if(m == 1)
        {
            return 1;
        }
        return m * Factorial(m - 1);
    }

    // Note: The declaration/body of the Fibonacci method was cut off in the images,
    // but its call inside main is captured below exactly as shown.

    public static void main(String[] args) {
        System.out.println("Mrunali Jibhakate - 107");
        System.out.println("a value WITH STATIC:" + a);
        System.out.println(a);

        Main ab = new Main();
        System.out.println("a value WITH FUNCTION:" + ab.a);

        int c = 30;
        System.out.println("c value :" + c);

        System.out.println("Run function: ");
        Run();
        System.out.println("Run function: ");
        Run();

        AllNaturalNoAdd();

        System.out.println("Recursion : " + Recursion(5));

        System.out.println("Reverse order : ");
        RecursionPrintNo(6);

        System.out.println("Factorial is: " + Factorial(3));

        System.out.println("Fibonacci series: ");
        for(int i = 0; i < 10; i++)
        {
            System.out.println(Fibonacci(i));
        }
    }
}