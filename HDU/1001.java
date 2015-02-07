////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-30 20:57:44
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:5012KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
import java.io.*;

public class Main 
{
    public static int sum(int n)
    {
        int ans = 0,i;
        for(i = 1;i <= n;++i)
            ans += i;
        return ans;
    }
    public static void main(String args[])
    {
        int a,ANS;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            a = cin.nextInt();
            //ANS = sum(a);
            System.out.println(sum(a));
            System.out.println();
        }
    }
}