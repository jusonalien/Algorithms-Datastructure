import java.util.Scanner;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        	Scanner scan=new Scanner(System.in);
		while(scan.hasNextInt())
		{
			int a=scan.nextInt();
			int b=scan.nextInt();
			System.out.println(a+b);
		}
    }

}

