////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-30 21:25:50
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:1000MS
////Run memory:5876KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
import java.io.*;

public class Main 
{
    public static BigInteger factorial(int n)
    {
        BigInteger ans =  BigInteger.valueOf(1);
        int i;
        for(i = 1;i <= n;++i)
        {
            ans = ans.multiply(BigInteger.valueOf(i));
        }
        return ans;
    }
    public static void main(String args[])
    {
        int N;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            N = cin.nextInt();
            //ANS = sum(a);
            System.out.println(factorial(N));
        }
    }
}