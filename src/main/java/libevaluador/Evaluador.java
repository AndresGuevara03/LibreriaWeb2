package libevaluador;

/**
 *  Clase que representa las funciones de la biblioteca dinamica JNI
 */
public class Evaluador {

    public native String evaluar(String problemName, String[][] outputs, String[][] inputs, int timeLimit,
                                 String content);

    public Evaluador() {
        try {
            System.loadLibrary("evaluador");
            System.out.println("Biblioteca cargada exitosamente!");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Carga de la biblioteca fallida: " + e.getMessage());
        }
    }
}