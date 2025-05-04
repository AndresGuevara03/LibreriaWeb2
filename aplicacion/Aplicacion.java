package aplicacion;

import libevaluador.Evaluador;

public class Aplicacion {
  Evaluador e = null;

  static {
    System.loadLibrary("evaluador");
  }

  public Aplicacion() {
    e = new Evaluador();
    String[][] in = {
        {
            "4",
            "word",
            "localization",
            "internationalization",
            "pneumonoultramicroscopicsilicovolcanoconiosis"
        },
        {
            "5",
            "abcdefgh",
            "abcdefghi",
            "abcdefghij",
            "abcdefghijk",
            "abcdefghijklm"
        },
        {
            "3",
            "njfngnrurunrgunrunvurn",
            "jfvnjfdnvjdbfvsbdubruvbubvkdb",
            "ksdnvidnviudbvibd"
        },
        {
            "1",
            "tcyctkktcctrcyvbyiuhihhhgyvyvyvyvjvytchjckt"
        },
        {
            "24",
            "you",
            "are",
            "registered",
            "for",
            "practice",
            "you",
            "can",
            "solve",
            "problems",
            "unofficially",
            "results",
            "can",
            "be",
            "found",
            "in",
            "the",
            "contest",
            "status",
            "and",
            "in",
            "the",
            "bottom",
            "of",
            "standings"
        },
        {
            "1",
            "a"
        },
        {
            "26",
            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
            "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
        },
        {
            "1",
            "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
        },
        {
            "10",
            "gyartjdxxlcl",
            "fzsck",
            "uidwu",
            "xbymclornemdmtj",
            "ilppyoapitawgje",
            "cibzc",
            "drgbeu",
            "hezplmsdekhhbo",
            "feuzlrimbqbytdu",
            "kgdco"
        },
        {
            "20",
            "lkpmx",
            "kovxmxorlgwaomlswjxlpnbvltfv",
            "hykasjxqyjrmybejnmeumzha",
            "tuevlumpqbbhbww",
            "qgqsphvrmupxxc",
            "trissbaf",
            "qfgrlinkzvzqdryckaizutd",
            "zzqtoaxkvwoscyx",
            "oswytrlnhpjvvnwookx",
            "lpuzqgec",
            "gyzqfwxggtvpjhzmzmdw",
            "rlxjgmvdftvrmvbdwudra",
            "vsntnjpepnvdaxiporggmglhagv",
            "xlvcqkqgcrbgtgglj",
            "lyxwxbiszyhlsrgzeedzprbmcpduvq",
            "yrmqqvrkqskqukzqrwukpsifgtdc",
            "xpuohcsjhhuhvr",
            "vvlfrlxpvqejngwrbfbpmqeirxlw",
            "svmasocxdvadmaxtrpakysmeaympy",
            "yuflqboqfdt"
        } };

    String[][] out = {
        {
            "word",
            "l10n",
            "i18n",
            "p43s"
        },
        {
            "abcdefgh",
            "abcdefghi",
            "abcdefghij",
            "a9k",
            "a11m"
        },
        {
            "n20n",
            "j27b",
            "k15d"
        },
        {
            "t41t"
        },
        {
            "you",
            "are",
            "registered",
            "for",
            "practice",
            "you",
            "can",
            "solve",
            "problems",
            "u10y",
            "results",
            "can",
            "be",
            "found",
            "in",
            "the",
            "contest",
            "status",
            "and",
            "in",
            "the",
            "bottom",
            "of",
            "standings"
        },
        {
            "a"
        },
        {
            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
            "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
        },
        {
            "a98j"
        },
        {
            "g10l",
            "fzsck",
            "uidwu",
            "x13j",
            "i13e",
            "cibzc",
            "drgbeu",
            "h12o",
            "f13u",
            "kgdco"
        },
        {
            "lkpmx",
            "k26v",
            "h22a",
            "t13w",
            "q12c",
            "trissbaf",
            "q21d",
            "z13x",
            "o17x",
            "lpuzqgec",
            "g18w",
            "r19a",
            "v25v",
            "x15j",
            "l28q",
            "y26c",
            "x12r",
            "v26w",
            "s27y",
            "y9t"
        } };

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
    String respuesta = e.evaluar("WayTooLongWords", out, in, 1000, code);
    System.out.println(respuesta);
  }

  public static void main(String[] args) {
    new Aplicacion();
  }
}
