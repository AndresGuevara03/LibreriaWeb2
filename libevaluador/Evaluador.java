package libevaluador;

public class Evaluador {
	public native String evaluar(String problemName, int timeLimit, String content);

	public native String evaluar(String problemName, int timeLimit, byte[] content);

	public native String cargarProblema(String problemName, int timeLimit, String inputs, String answers);

	public native String cargarProblema(String problemName, int timeLimit, byte[] inputs, byte[] answers);
}
