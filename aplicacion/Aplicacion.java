package aplicacion;

import libevaluador.Evaluador;

public class Aplicacion {
  Evaluador e = null;

  static {
    System.loadLibrary("evaluador");
  }

  public Aplicacion() {
    e = new Evaluador();
    String code = "import java.util.Scanner;\n" +
        "public class WayTooLongWords {\n\n" + "\tpublic static void main(String[] args) {\n\t\t" +
        "Scanner sc = new Scanner(System.in);\n\t\t" +
        "int n = sc.nextInt();\n\t\t" +
        "for (int i = 0; i < n; i++) {\n\t\t" +
        "String line = sc.next();\n\t\t\t" +
        "if (line.length() > 10)\n\t\t\t\t" +
        "System.out.println(String.valueOf(line.charAt(0)) + (line.length() - 2)\n\t\t\t\t\t" +
        "+ String.valueOf(line.charAt(line.length() - 1)));\n\t\t\t" +
        "else\n\t\t\t\t" +
        "System.out.println(line);\n\t\t\t" +
        "}\n\t\t\t" +
        "}\n\t\t" +
        "}\n\t";
    String respuesta = e.evaluar("WayTooLongWords", 1000, code);
    System.out.println(respuesta);
  }

  public static void main(String[] args) {
    new Aplicacion();
  }
}
