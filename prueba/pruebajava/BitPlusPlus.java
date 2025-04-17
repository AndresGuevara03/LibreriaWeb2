package pruebajava;

import java.util.Scanner;

public class BitPlusPlus {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, result = 0;
    n = sc.nextInt();
    for (int i = 0; i < n; i++) {
      String line = sc.next();
      if (line.charAt(1) == '+')
        result++;
      else
        result--;
    }
    System.out.println(result);
  }
}
