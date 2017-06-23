import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	static BigInteger sCat[] = new BigInteger[27];
	static BigInteger fact[] = new BigInteger[53];

	public static void fill(){
		fact[0] = fact[1] = sCat[1] = sCat[2] = BigInteger.ONE;
		for(int i = 2; i<fact.length; i++) 
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		for(int i = 3; i<sCat.length; i++)
			sCat[i] = sCat[i-1].multiply(BigInteger.valueOf(3*(2*i-3))).
			subtract(sCat[i-2].multiply(BigInteger.valueOf(i-3))).
			divide(BigInteger.valueOf(i));
	}

	public static BigInteger cat(int n){
		return fact[2*n].divide(fact[n].multiply(fact[n+1]));
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		BigInteger ans;
		int n;
		fill();
		while(sc.hasNext()){
			n = sc.nextInt();
			ans = sCat[n].subtract(cat(n-1));
			System.out.print(ans + "\n");
		}
	}
}