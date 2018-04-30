import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Poj2325
{
	static int[][] choice = new int[15][15];
	static BigInteger n;
	static String ans;
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		ycl();
		while(cin.hasNext())
		{
			n = cin.nextBigInteger();
			ans = "";


		}
	}
	public static void ycl()
	{
		choice[0][0] = 3 ; choice[0][1] = 8; choice[0][2] = 6;choice[0][3] = 5;
		choice[1][0] = 2 ; choice[1][1] = 9; choice[1][2] = 7;
		choice[2][0] = 6 ; choice[2][1] = 9; choice[2][2] = 8;choice[2][3] = 7;choice[2][4] = 6;choice[2][5] = 4;choice[2][6] = 2;
		choice[4][0] = 6 ; choice[4][1] = 9; choice[4][2] = 8;choice[4][3] = 7;choice[4][4] = 6;choice[4][5] = 4;choice[4][6] = 2;
		choice[3][0] = 2 ; choice[3][1] = 9; choice[3][2] = 3;
		choice[5][0] = 3 ; choice[5][1] = 9; choice[5][2] = 7;choice[5][3] = 5;
		choice[6][0] = 5 ; choice[6][1] = 9; choice[6][2] = 8;choice[6][3] = 6;choice[6][4] = 4;choice[6][5] = 3;
		choice[7][0] = 3 ; choice[7][1] = 9; choice[7][2] = 7;choice[7][3] = 4;
		choice[2][0] = 6 ; choice[8][1] = 9; choice[8][2] = 8;choice[8][3] = 7;choice[8][4] = 6;
		choice[9][0] = 3 ; choice[9][1] = 9; choice[9][2] = 7;choice[9][3] = 3;
	}

}