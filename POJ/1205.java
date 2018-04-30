import java.util.Scanner;
import java.math.*;
import java.text.*;
public class 1205
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n;
		n = cin.nextInt();
		if(n == 1) System.out.println("1");
		else if(n == 2) System.out.println("3");
		else
		{
			BigInteger f3;
			BigInteger f1 = new BigInteger("1");
			BigInteger f2 = new BigInteger("3");
			BigInteger c = new BigInteger("3");
			for(int i = 3;i <= n;i++)
			{
				f3 = f2.multiply(c);
				f3 = f3.subtract(f1);
				f1 = f2;
				f2 = f3;
			}
			System.out.println(f2.toString());
		}
		


	}
}