# GSTI
Sensor de enchente
Uma aplicação IoT com diversos sensores para coleta de dados foi implementada em um rio, onde é coletado o nível da água.

Os dados da aplicação são enviados através de uma API e estão organizados da seguinte forma:
diaSemana;
horario;
nivelRio;

A aplicação irá executar um script toda vez que a boia emitir o sinal de que o nível da água subiu.
Com esses dados, gerar um arquivo (txt/CSV) com as informações coletadas.
Estrutura do arquivo:
diaSemana;
horario;
nivelRio;
alertaEnviado

Se a boia emitir sinais 3x no dia, a mesma envia um alerta de segurança 
