#include <stdio.h>
#include <cjson/cJSON.h>
#include <libeval.h>

int main(int cantArgs, char** args){
  char *caso0[] = {"4", "word", "localization", "internationalization", "pneumonoultramicroscopicsilicovolcanoconiosis"};
  char *caso1[] = {"5", "abcdefgh", "abcdefghi", "abcdefghij", "abcdefghijk", "abcdefghijklm"};
  char *caso2[] = {"3", "njfngnrurunrgunrunvurn", "jfvnjfdnvjdbfvsbdubruvbubvkdb", "ksdnvidnviudbvibd"};
  char *caso3[] = {"1", "tcyctkktcctrcyvbyiuhihhhgyvyvyvyvjvytchjckt"};
  char *caso4[] = {"24", "you", "are", "registered", "for", "practice", "you", "can", "solve", "problems", "unofficially", "results", "can", "be", "found", "in", "the", "contest", "status", "and", "in", "the", "bottom", "of", "standings"};
  char *caso5[] = {"1", "a"};
  char *caso6[] = {"26", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  char *caso7[] = {"1", "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"};
  char *caso8[] = {"10", "gyartjdxxlcl", "fzsck", "uidwu", "xbymclornemdmtj", "ilppyoapitawgje", "cibzc", "drgbeu", "hezplmsdekhhbo", "feuzlrimbqbytdu", "kgdco"};
  char *caso9[] = {"20", "lkpmx", "kovxmxorlgwaomlswjxlpnbvltfv", "hykasjxqyjrmybejnmeumzha", "tuevlumpqbbhbww", "qgqsphvrmupxxc", "trissbaf", "qfgrlinkzvzqdryckaizutd", "zzqtoaxkvwoscyx", "oswytrlnhpjvvnwookx", "lpuzqgec", "gyzqfwxggtvpjhzmzmdw", "rlxjgmvdftvrmvbdwudra", "vsntnjpepnvdaxiporggmglhagv", "xlvcqkqgcrbgtgglj", "lyxwxbiszyhlsrgzeedzprbmcpduvq", "yrmqqvrkqskqukzqrwukpsifgtdc", "xpuohcsjhhuhvr", "vvlfrlxpvqejngwrbfbpmqeirxlw", "svmasocxdvadmaxtrpakysmeaympy", "yuflqboqfdt"};

  char **casos_originales[] = {caso0, caso1, caso2, caso3, caso4, caso5, caso6, caso7, caso8, caso9};
  int tamanios_originales[10] = {5, 6, 4, 2, 25, 2, 27, 2, 11, 21};
  
  char *casoP0[] = {"word", "l10n", "i18n", "p43s"};
  char *casoP1[] = {"abcdefgh", "abcdefghi", "abcdefghij", "a9k", "a11m"};
  char *casoP2[] = {"n20n", "j27b", "k15d"};
  char *casoP3[] = {"t41t"};
  char *casoP4[] = {"you", "are", "registered", "for", "practice", "you", "can", "solve", "problems", "u10y", "results", "can", "be", "found", "in", "the", "contest", "status", "and", "in", "the", "bottom", "of", "standings"};
  char *casoP5[] = {"a"};
  char *casoP6[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  char *casoP7[] = {"a98j"};
  char *casoP8[] = {"g10l", "fzsck", "uidwu", "x13j", "i13e", "cibzc", "drgbeu", "h12o", "f13u", "kgdco"};
  char *casoP9[] = {"lkpmx", "k26v", "h22a", "t13w", "q12c", "trissbaf", "q21d", "z13x", "o17x", "lpuzqgec", "g18w", "r19a", "v25v", "x15j", "l28q", "y26c", "x12r", "v26w", "s27y", "y9t"};
  char **casos_procesados[] = {casoP0, casoP1, casoP2, casoP3, casoP4, casoP5, casoP6, casoP7, casoP8, casoP9};
  int tamanios_procesados[10] = {4, 5, 3, 1, 24, 1, 26, 1, 10, 20};
  const char* java_code = 
"import java.util.Scanner;\n"
"public class WayTooLongWords {\n"
"        public static void main(String[] args) {\n"
"                Scanner sc = new Scanner(System.in);\n"
"                int n = sc.nextInt();\n"
"                for (int i = 0; i < n; i++) {\n"
"                String line = sc.next();\n"
"                        if (line.length() > 10)\n"
"                                System.out.println(String.valueOf(line.charAt(0)) + (line.length() - 2)\n"
"                                        + String.valueOf(line.charAt(line.length() - 1)));\n"
"                        else\n"
"                                System.out.println(line);\n"
"                        }\n"
"                        }\n"
"                }";
  createSolution("WayTooLongWords", java_code);
  cJSON* result = getVeredict("WayTooLongWords", casos_originales, casos_procesados, 10, tamanios_originales, tamanios_procesados, 1000);
  printf("%s\n", cJSON_Print(result));
  cJSON_Delete(result);
  return (EXIT_SUCCESS);
}
