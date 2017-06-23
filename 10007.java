import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	static BigInteger fact[] = new BigInteger[601];

	public static void fill(){
		fact[0] = fact[1] = BigInteger.ONE;
		for(int i = 2; i<fact.length; i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n;
		fill();
		BigInteger ans;
		while((n = sc.nextInt()) > 0){
			ans = fact[2*n];
			ans = ans.divide(fact[n].multiply(BigInteger.valueOf(n+1)));
			System.out.print(ans +"\n");
		}
	}
}