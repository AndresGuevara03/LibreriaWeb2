package co.edu.uceva.springbootevaluador;

import libevaluador.Evaluador;
import libevaluador.EvaluadorDTO;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/ovaweb-service")
public class EvaluadorRestController {
    private Evaluador evaluador;

    public EvaluadorRestController() {
        this.evaluador = new Evaluador();
    }

    @GetMapping("/evaluar")
    public String evaluar(@RequestBody EvaluadorDTO args){
        return evaluador.evaluar(args.problemName(), args.outputs(), args.inputs(), args.timeLimit(), args.content());
    }
}
