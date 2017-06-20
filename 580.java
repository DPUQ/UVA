import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	static BigInteger prec[] = new BigInteger[101];

	public static void fill(){
		prec[0] = BigInteger.valueOf(0);
		prec[1] = BigInteger.valueOf(2);
		prec[2] = BigInteger.valueOf(4);
		prec[3] = BigInteger.valueOf(7);

		for(int i = 4; i < 101; i++)
			prec[i] = prec[i-1].add(prec[i-2].add(prec[i-3]));
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n;
		fill();
		while((n = sc.nextInt()) != 0)
			System.out.print( (BigInteger.valueOf((long)Math.pow(2,n)).subtract(prec[n]))  + "\n");
		
	}
}