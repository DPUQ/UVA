import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	static BigInteger fact[] = new BigInteger[201];

	public static void fill(){
		fact[0] = fact[1] = BigInteger.ONE;
		for(int i = 2; i<fact.length; i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		fill();
		int t = sc.nextInt(),n,k,code[],tot;
		BigInteger ans;
		while(t --> 0){
			n = sc.nextInt(); k = sc.nextInt(); tot = 0;
			code = new int[k];
			for(int i = 0; i < code.length; i++){
				code[i] = sc.nextInt();
				tot += code[i];
			}
			tot = n - tot; tot++;
			if(k>tot) System.out.print("0\n");
			else{
				ans = fact[tot].divide(fact[k].multiply(fact[tot-k]));
				System.out.print(ans + "\n");
			}
		}
	}
}