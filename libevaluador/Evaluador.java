package libevaluador;

public class Evaluador {
	public native String evaluar(String problemName, String[][] outputs, String[][] inputs, int timeLimit,
			String content);
}
