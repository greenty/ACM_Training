import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		int t;
		t = cin.nextInt();
		for(int _=1;_<=t;_++)
		{
			BigInteger n = cin.nextBigInteger();
			BigInteger[] a = new BigInteger[5];
			a[1] = BigInteger.valueOf(3);
			a[2] = BigInteger.valueOf(20);
			if(n.compareTo(BigInteger.ONE)>=0 && n.compareTo(a[1]) <=0 )
			{
				System.out.println(a[1].toString());
				continue;
			} 
			if(n.compareTo(a[2])<=0 && n.compareTo(a[1]) >0 )
			{
				System.out.println(a[2].toString());
				continue;
			}
			for (int i = 3;i<=100000 ; i++) {
				a[3] = a[2].multiply(BigInteger.valueOf(6));
				System.out.println(a[3].toString());
				a[3] = a[3].subtract(a[1]);
				System.out.println(a[3].toString());
				a[3] = a[3].add(BigInteger.valueOf(2));
				System.out.println(a[3].toString());
				if(n.compareTo(a[3])<=0){
					System.out.println(a[3].toString());
					break;
				}
				a[1] = a[2];
				a[2] = a[3];
			}
		}
	}
}
