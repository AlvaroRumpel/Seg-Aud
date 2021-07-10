    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>
    <body>
        <h1>Sensor de enchente</h1>
<p>
    Uma aplicação IoT com diversos sensores para coleta de dados foi implementada em um rio, onde é coletado o nível da água.
    <h2>Os dados da aplicação são enviados através de uma API e estão organizados da seguinte forma:</h2>
    <ul>
        <li>diaSemana</li>
        <li>horario</li>
        <li>nivelRio</li>
      </ul>
      A aplicação irá executar um script toda vez que a boia emitir o sinal de que o nível da água subiu.
    Com esses dados, gerar um arquivo (txt/CSV) com as informações coletadas.
      <h2>Estrutura do arquivo:</h2>
      <table style="width:100%">
        <tr>
          <th>diaSemana</th>
          <th>horario</th>
          <th>alertaEnviado</th>
        </tr>
        <tr>
          <td>segunda</td>
          <td>12:03:25</td>
          <td>3</td>
        </tr>
        <tr>
          <td>quarta</td>
          <td>22:15:19</td>
          <td>2</td>
        </tr>
      </table>

    Se a boia emitir sinais 3x no dia, a mesma envia um alerta de segurança
</p>
    </body>
    </html>


