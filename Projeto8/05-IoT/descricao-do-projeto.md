Nesta etapa do projeto consiste em desenvolver um monitor de temperatura para uma sala de servidores, utilizando o Arduino Uno R3 e o sensor de temperatura TMP36.

A ideia é criar um sistema que identifique diferentes níveis de temperatura e apresente um alerta visual por meio de três LEDs: verde, amarelo e vermelho.

Para desenvolver o projeto, utilizamos os seguintes componentes:

Arduino Uno R3: é o controlador principal. Ele recebe os dados do sensor, calcula a temperatura e controla os LEDs.
Protoboard: permite organizar as conexões elétricas sem a necessidade de soldagem.
Sensor TMP36: mede a temperatura do ambiente e fornece um sinal elétrico que pode ser interpretado pelo Arduino.
LED verde: indica que a temperatura está normal.
LED amarelo: indica que a temperatura está na faixa de atenção.
LED vermelho: indica que a temperatura atingiu o nível crítico.
Três resistores de 220 Ω: limitam a corrente elétrica de cada LED, ajudando a protegê-los.
Fios jumper: realizam as conexões entre os componentes.

A montagem foi realizada no Tinkercad, que permite simular circuitos eletrônicos sem precisar montar fisicamente os componentes.

O funcionamento começa quando o sensor TMP36 mede a temperatura.
O sensor produz uma tensão elétrica relacionada à temperatura medida. Essa tensão é lida pela entrada analógica A0 do Arduino.
Em seguida, o Arduino converte a leitura em um valor de temperatura em graus Celsius.
Depois, o programa compara a temperatura calculada com dois limites definidos: 28 °C e 32 °C.
Dependendo do resultado, o Arduino acende o LED correspondente e mantém os outros dois apagados.

Testes realizados:

|  Teste  | Temperatura esperada | LED esperado | Resultado obtido |
|------------------------------------------------------------------|
| Normal  |        24 °C         |   Verde      |     Sem erro     |
| Atenção |        29 °C         |   Amarelo    |     Sem erro     |
| Crítico |        35 °C         |   Vermelho   |     Sem erro     |