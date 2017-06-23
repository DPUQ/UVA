import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		String st; BigInteger number;
		String c;
		sc.useDelimiter("");
		while(sc.hasNext()){
			st = "";
			while(sc.hasNext()){
				c = sc.next();
				if(c.charAt(0) == '#') break;
				if(c.charAt(0) != '\n') st += c;
			}
			if(!sc.hasNext()) break;
			number = new BigInteger(st,2);
			if(number.mod(BigInteger.valueOf(131071)).compareTo(BigInteger.ZERO) == 0)
				System.out.print("YES\n");

			else System.out.print("NO\n");
		}
	}
}