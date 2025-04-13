0 - stdin
1 - stdout
2 - stderr

con " > log.txt" se manda el stdout al archivo log.txt
con "2>&1" se manda al stderr al stdout, ambos quedarian en log.txt
con "0< input.txt" el contenido de input.txt es envido a el stdin
