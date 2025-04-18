import java.util.Scanner;
public class WayTooLongWords {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
		String line = sc.next();
			if (line.length() > 10)
				System.out.println(String.valueOf(line.charAt(0)) + (line.length() - 2)
					+ String.valueOf(line.charAt(line.length() - 1)));
			else
				System.out.println(line);
			}
			}
		}
	