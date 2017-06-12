import java.math.BigInteger;
import java.util.Scanner;


public class Ej10497{

	static BigInteger sfact[] = new BigInteger[801];

	private static void fill(){

		sfact[0] = sfact[2] = BigInteger.valueOf(1);
		sfact[1] = BigInteger.valueOf(0);


		for(int i = 3; i<sfact.length; i++){
			sfact[i] = (sfact[i-1].add(sfact[i-2])).multiply(BigInteger.valueOf(i-1));
		}

	}


	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n;
		fill();
		while( (n = sc.nextInt()) != -1){
			System.out.print(sfact[n]+"\n");
		}
	}
}