package pruebajava;

import java.math.BigInteger;
import java.util.Scanner;

public class theatreSquare {

  public static void main(String[] args) {
    long a, n, m, r;
    Scanner sc = new Scanner(System.in);
    n = sc.nextLong();
    m = sc.nextLong();
    a = sc.nextLong();
    r = Math.ceilDiv(n, a) * Math.ceilDiv(m, a);
    System.out.println(r);
  }
}
