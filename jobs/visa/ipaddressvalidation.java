import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



public class Solution {
    static String patternipv4 = "(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)";
    static String patternipv6 = "([\\da-f]+):([\\da-f]+):([\\da-f]+):([\\da-f]+):([\\da-f]+):([\\da-f]+):([\\da-f]+):([\\da-f]+)";
    static boolean checkIPV(String line)
        {
        String arr[]=line.split("\\.");
        for(int i=0;i<arr.length;i++)
            {
            if(Integer.parseInt(arr[i])<0 || Integer.parseInt(arr[i])>255)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n;
        n=Integer.parseInt(sc.nextLine());
        Pattern p1 = Pattern.compile(patternipv4);
        Pattern p2 = Pattern.compile(patternipv6);

        for(int i=0;i<n;i++)
            {
            String line = sc.nextLine();
            Matcher r = p1.matcher(line);
            if(r.matches())
                {
                if(checkIPV(line))
                    System.out.println("IPv4");
                else
                    System.out.println("Neither");
            }
            else
                {
                Matcher r1 = p2.matcher(line);
                if(r1.matches())
                    {
                    System.out.println("IPv6");
                }
                else
                    {
                    System.out.println("Neither");
                }
            }
        }
        
    }
}
