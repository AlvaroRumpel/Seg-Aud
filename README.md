# GSTI
<img src="/Sensor de chuva.png" alt="sensor de enchente">
<h1>Sensor de enchente</h1>
    Uma aplicação IoT com diversos sensores para coleta de dados foi implementada em um rio, onde é coletado o nível da água.
    <h2>Os dados da aplicação são enviados através de uma API e estão organizados da seguinte forma:</h2>
    <ul>
        <li>dia</li>
        <li>horario</li>
        <li>nivelRio</li>
      </ul>
      A aplicação irá executar um script toda vez que a boia emitir o sinal de que o nível da água subiu.
    Com esses dados, gerar um arquivo (txt/CSV) com as informações coletadas.
      <h2>Estrutura do arquivo:</h2>
      <table style="width:100%">
        <tr>
          <th>dia</th>
          <th>horario</th>
          <th>nivelRio</th>
          <th>alertaEnviado</th>
        </tr>
        <tr>
          <td>10</td>
          <td>12:03:25</td>
          <td>2</td>
          <td>----ALERT----</td>
        </tr>
        <tr>
          <td>11</td>
          <td>22:15:19</td>
          <td>1</td>
          <td></td>
        </tr>
      </table>


* Se a boia subir ao nivel 2, é registrado um sinal de alerta

<h1>Autores</h1>

  - Álvaro C. Rumpel
  - Irakitã Luan
  - Luan V. da Costa



