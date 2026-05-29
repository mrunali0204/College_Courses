class Main
{
    public static void main(String[] args)
    {
        System.out.println("Mrunali Jibhakate - 107");

        int arr[] = {10, 20, 30, 40};
        
        System.out.println("Array is");
        for(int i = 0; i < arr.length; i++)
        {
            System.out.println(arr[i]);
        }
        
        arr[2] = 100;
        System.out.println("New element is " + arr[2]);
        for(int i = 0; i < arr.length; i++)
        {
            System.out.println(arr[i]);
        }

        System.out.println("Highest element is ");
        int max = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
        System.out.println(max);

        System.out.println();
        System.out.println("2nd Highest element is ");
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[0] < arr[i] && max < arr[i])
            {
                System.out.println(arr[i]);
            }
        }

        System.out.println();
        int arr1[] = {132, 20, 303, 40};
        int temp = 0;
        System.out.println("Sorting array");
        for(int i = 0; i < arr1.length + 1; i++)
        {
            if(arr1[i] > arr1[i+1])
            {
                temp = arr1[i];
                arr1[i] = arr1[i+1];
                arr1[i+1] = temp;
            }
            System.out.println(arr1[i]);
        }
    }
}