# PID_LDR_LED

1. Código de controle da resistência de um LDR (Light Dependent Resistor) através da intensidade luminosa de um LED.

![image](https://github.com/TallesSilva/PID_LDR_LED/blob/master/documents/image/circuito.PNG?raw=true)

2. Curva caracteristica de um LDR.

![image](https://github.com/TallesSilva/PID_LDR_LED/blob/master/documents/image/LDR.PNG?raw=true)

3. O potenciômetro funcionará como uma perturbação, assim, o LED irá variar sua luminosidade com a finalidade de compensar a diferença de tensão lida no LDR e no potenciômetro, tentando igualar as duas tensões.
![image](https://github.com/TallesSilva/PID_LDR_LED/blob/master/documents/image/Grafico.PNG?raw=true)
É possível notar que o Integrador tende ao infinito quando o sistema satura e o PI só consegue voltar a compensar quando o Integrador retoma seus valores normais. Com a observação do gráfico podemos notar outros aspectos do sistema e com coleta dos dados poderíamos futuramente montar a função de transferência do sistema e analisar os compensadores de forma mais profissional.
