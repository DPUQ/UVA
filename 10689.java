import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	static long fib[] = new long[15001];
	static long tenP[] = {1,10,100,1000,10000};

	public static int fill(int a, int b, int m){
		fib[0] = a;
		fib[1] = b;
		int lim = 60 * (int) Math.pow(5,m-1);
		if(m>1) lim *= Math.floor(m/2);
		for(int i = 2; i<lim; i++)
			fib[i] = (fib[i-1] % tenP[m] + fib[i-2] % tenP[m] ) % tenP[m];
		return lim;
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int a,b,m,t;
		long n;
		t = sc.nextInt();
		while(t-- > 0){
			a = sc.nextInt(); 	b = sc.nextInt(); 
			n = sc.nextLong(); 	m = sc.nextInt();
			int mod = fill(a,b,m);
			System.out.print(fib[(int)(n%mod)]%tenP[m]+"\n");
		}
	}
}