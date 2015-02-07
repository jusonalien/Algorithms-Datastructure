////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-10 00:40:54
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:5740KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        // TODO code application logic here
        	Scanner scan=new Scanner(System.in);
            BigInteger a,b,c;
            int cas,i;
            cas = scan.nextInt();
		for(i = 1;i <= cas;++i)
		{
			 a = scan.nextBigInteger();
			 b = scan.nextBigInteger();
             c = a.add(b);
            System.out.println("Case "+i+":");
            System.out.println(a+" + "+b+" = "+c);
            if(i < cas){
                System.out.println("");
            }
		}
    }

}