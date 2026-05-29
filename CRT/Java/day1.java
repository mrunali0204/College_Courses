class Main
{
    float in_degree;
    static int salary = 50000;
    static int final_amount = 5000;
    static int km = 40;
    static int time = 25;

    static int add(int a, int b)
    {
        return a + b;
    }

    static float multiply(float a, float b)
    {
        return a * b;
    }

    static void print_name()
    {
        System.out.println("Mrunali Jibhakate - 107");
    }

    static float Temperature(float in_degree)
    {
        return in_degree + 32.2f;
    }

    static float Final_Amount(int final_amount)
    {
        if(final_amount >= 5000)
        {
            return 0.30f;
        }
        else if(final_amount >= 3000 || final_amount < 5000)
        {
            return 0.20f;
        }
        else
        {
            return 0.00f;
        }
    }

    static String Salary_Bonus(int salary)
    {
        if(salary >= 50000)
        {
            return "20 % bonus";
        }
        else if(salary >= 30000 || salary < 50000)
        {
            return "10 % bonus";
        }
        else
        {
            return "5 % bonus";
        }
    }

    static int Delivery_Time(int km)
    {
        if(km == 5)
        {
            System.out.println("20 min will take to deliver");
            return 1;
        }
        else if(km > 5)
        {
            for(int i = 5; i > 100; i++ )
            {
                time = time + 5;
            }
            return time;
        }
        else
        {
            System.out.println("None");
            return 0;
        }
    }

    public static void main(String[] args)
    {
        print_name();
        System.out.println(add(10,20));
        System.out.println(multiply(10.2f,20.3f));
        System.out.println(Temperature(47.7f));
        System.out.println(Final_Amount(final_amount));
        System.out.println(Salary_Bonus(salary));
    }
}