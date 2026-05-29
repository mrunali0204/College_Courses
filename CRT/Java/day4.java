class Main 
{
    public static void main(String[] args) 
    {
        System.out.println("Mrunali Jibhakate - 107");   
        System.out.println();       
        
        System.out.println("String is: ");   
        String str = "Hello";
        for(int i = 0; i <= str.length()-1 ; i++)
        {
            str.charAt(i);
            System.out.println("Character at " + i +  " is: " + str.charAt(i));    
        }
        System.out.println();
        
        System.out.println("Reverse String is: ");   
        for(int i = str.length()-1; i >= 0 ; i--)
        {
            str.charAt(i);
            System.out.println("Character at " + i +  " is: " + str.charAt(i));      
        }
        System.out.println();
        
        str = "naman";
        System.out.println("Palindrom or not: "); 
        String original = str;
        String rev = "";
        for(int i = 0; i <= str.length()-1 ; i++)
        {
            rev = rev + str.charAt(i);
        }
        if(rev.equals(original))
        {
            System.out.println("Palindrom"); 
        }
        System.out.println();
        
        System.out.println("Vowels: "); 
        str = "hello how are u";
        char ch;
        int vowels = 0;
        System.out.println("String is: " + str);  
        for(int i = 0; i <= str.length()-1; i++)
        {
            ch = str.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels = vowels + 1;
            }
        }
        System.out.println("No. of vowels are: " + vowels); 
        System.out.println();
        
        System.out.println("No. of words: ");
        int count = 1;
        for(int i = 0; i <= str.length()-1; i++)
        {
            if(str.charAt(i) == ' ')
                count++;
        }
        System.out.println("Count is : " + count);
        System.out.println();
        
        System.out.println("String without spaces: ");
        //METHOD - 1 
        String new_str = "";
        for(int i = 0; i <= str.length()-1; i++)
        {
            new_str = str.replace(" ", "");
        }
        System.out.println("String without spaces: " + new_str);
        System.out.println();
        
        //METHOD - 2 (string builder)
        // StringBuilder new_str = "";
        // for(int i = 0; i <= str.length()-1; i++)
        // {
        //     if(str.charAt(i) != ' ')
        //     {
        //         new_str.append(str.charAt(i));
        //     }
        // }
        // System.out.println("String without spaces: " + new_str);
        
        System.out.println("Frequency of word in string: ");
        int count1 = 0;
        String str2 = "";
        for(int i = 0; i < str.length(); i++)
        {
            for(int j = 0; j < str.length() ; j++)
            {
                if(str.charAt(i) == str.charAt(j))
                {
                    count1 = count1 + 1;
                }
                str2 = str2 + str.charAt(i);
            }
            System.out.println("Frequency of " + str.charAt(i) +  " is : " + count1);
        }
        System.out.println();
        
        
        
     
     
     
     
      
        
    }
}
