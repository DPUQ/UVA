import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	static BigInteger fibo[] = new BigInteger[101];

	public static void fill(){
		fibo[0] = BigInteger.valueOf(1);
		fibo[1] = BigInteger.valueOf(2);
		for(int i = 2; i<fibo.length; i++)
			fibo[i] = fibo[i-1].add(fibo[i-2]);
	}

	public static BigInteger fib2num(String n){
		BigInteger ret = BigInteger.valueOf(0);
		int j = 0;
		for(int i = n.length()-1 ; i>=0; i--)
			ret = ret.add(BigInteger.valueOf(n.charAt(i) - '0').multiply(fibo[j++]));

		return ret;
	}

	public static String num2fib(BigInteger n){
		String ret = "";
		int i = fibo.length-1;

		if(n.compareTo(BigInteger.valueOf(0))==0) return "0";

		while(fibo[i].compareTo(n)>0 && i>=0)
			i--;
		
		for(; i>=0;i--){
			if(fibo[i].compareTo(n)<=0){
				n = n.subtract(fibo[i]);
				ret += "1";
			}
			else ret += "0";
		}

		return ret;
	}

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		String n1,n2,res; BigInteger sum;
		fill();
		boolean flag = false;
		while(sc.hasNext()){
			if(!flag) flag = true;
			else System.out.print("\n");
			n1 = sc.next();
			n2 = sc.next();
			sum = fib2num(n1).add(fib2num(n2));
			System.out.print(num2fib(sum)+"\n");
		}
	}
}