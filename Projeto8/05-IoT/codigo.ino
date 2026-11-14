// C++ code
// Link do Tinkercad: https://www.tinkercad.com/things/dQwS6iqosyN-monitor-de-temperatura-sala-de-servidores?sharecode=PewZ8gUtLP2H5kQKkBz0O9tnX388G2-TrmO5L6sxKbc
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}
/* 
==========================================
 PROJETO: Monitor de Temperatura IoT
 Aplicação: Sala de servidores
 Placa: Arduino Uno R3
==========================================

Identificação dos componentes
 arduino  = Arduino Uno R3
 pla_     = Placa de ensaio
 sensor_temp = Sensor TMP36
 led_1    = LED verde
 led_2    = LED amarelo
 led_3    = LED vermelho
*/

// Pinos utilizados
const int sensor_temp = A0;
const int led_1 = 8;
const int led_2 = 9;
const int led_3 = 10;

// Variáveis para leitura do sensor
int leitura_sensor;
float tensao;
float temperatura;

void loop() {
  
   // Configura os LEDs como saídas
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  // Inicia o Monitor Serial
  Serial.begin(9600);

  Serial.println("Monitor de Temperatura IoT");
  Serial.println("Sala de Servidores");
  Serial.println("------------------------------");

  // Lê o sensor de temperatura
  leitura_sensor = analogRead(sensor_temp);

  // Converte a leitura em tensão elétrica
  tensao = leitura_sensor * (5.0 / 1023.0);

  // Calcula a temperatura em graus Celsius
  temperatura = (tensao - 0.5) * 100.0;

  // Mostra a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" graus Celsius");

  // Desliga todos os LEDs
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);

  // Verifica a faixa de temperatura
  if (temperatura < 28.0) {

    // Temperatura normal
    digitalWrite(led_1, HIGH);

    Serial.println("Status: NORMAL");
    Serial.println("LED verde aceso");

  } else if (temperatura < 32.0) {

    // Temperatura de atenção
    digitalWrite(led_2, HIGH);

    Serial.println("Status: ATENCAO");
    Serial.println("LED amarelo aceso");

  } else {

    // Temperatura crítica
    digitalWrite(led_3, HIGH);

    Serial.println("Status: CRITICO");
    Serial.println("LED vermelho aceso");
  }

  Serial.println("------------------------------");

  // Aguarda um segundo para a próxima leitura
  delay(1000);
}