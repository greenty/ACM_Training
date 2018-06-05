import java.util.Scanner;
import java.math.*;
import java.text.*;
public class J
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		String [] s = new String [55];
		for(int Case=1;Case<=T;Case++)
		{
			BigInteger n = cin.nextBigInteger();
			int ans = 0;
			while(ans < 50 && n.compareTo(BigInteger.valueOf(0))>0 )
			{
				String t = n.toString();
				int lenth = t.length();
				if(lenth == 1){
					ans+=1;s[ans] = t;
					break;
				}
					String t1 = "";
					String t2 = "";
					int mid = lenth/2-1;
					for(int i = 0;i<=mid;i++)
						t2 += t.charAt(i);
					t1 = t2;
					if(lenth %2!=0) t1 += t.charAt(lenth/2);
					for(int i = mid;i>=0;i--)
						t1+=t2.charAt(i);
					BigInteger m = new BigInteger(t1,10);
					if(n.compareTo(m)<0)
					{
						if(t1.compareTo("11") == 0)	t1 = "9";
						else if(t1.compareTo("101") == 0) t1 = "99";
						else{
							m = new BigInteger(t2,10);
							m = m.subtract(BigInteger.ONE);
							if(m.compareTo(BigInteger.ZERO) == 0){
								t1 = "";
								t1 += t.charAt(lenth/2);
							}
							else{
								t2 = "";
								t2+=m.toString();
								mid = t2.length()-1; 
								t1 = t2;
								if(lenth%2 != 0)
								t1 += t.charAt(lenth/2);
								for(int i = mid;i>=0;i--)	t1+=t2.charAt(i);
							}
						}
					}
				//
				ans+=1;
				s[ans] = t1;
				m = new BigInteger(t1,10);
				n = n.subtract(m);
			}
			System.out.println("Case #"+Case+":");
					System.out.println(ans);
					for(int i = 1;i<=ans;i++) System.out.println(s[i]);
		}
	}
}
