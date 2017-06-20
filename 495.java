import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	static BigInteger fibo[] = new BigInteger[5001];

	public static void fill(){
		fibo[0] = BigInteger.valueOf(0);
		fibo[1] = BigInteger.valueOf(1);
		for(int i = 2; i<5001; i++)
			fibo[i] = fibo[i-1].add(fibo[i-2]);
		
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n;
		fill();
		while(sc.hasNext()){
			n = sc.nextInt();
			System.out.print("The Fibonacci number for " + n + " is "+ fibo[n] +"\n");
		}
	}
}