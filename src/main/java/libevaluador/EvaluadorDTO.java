package libevaluador;

public record EvaluadorDTO(String problemName, String[][] outputs, String[][] inputs, int timeLimit,
                           String content) {
}
