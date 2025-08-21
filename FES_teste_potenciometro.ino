// Variáveis para gerar os pulsos de estímulo elétrico
int potenciometro = 4;      
int sinalPin = 5;
int sinal2Pin = 18;
int valorPotenciometro = 0;  
int periodoTON;
int tempoEntrePulsos = 28;
int tempoAlternar = 10;

// Variáveis para gerar a frequência do conversor boost
int pinFreq = 23;
int resol = 8; // 2^8
int frequencia = 40000;
int duty = ((1 << resol) / 2); // 50% duty cycle

void setup() {
  ledcAttach(pinFreq, frequencia, resol);
  ledcWrite(pinFreq, duty);
  pinMode(sinalPin, OUTPUT);
  pinMode(sinal2Pin, OUTPUT);
  Serial.begin(9600);   
}
// Código base
void loop() {

  valorPotenciometro = analogRead(potenciometro);

  periodoTON = map(valorPotenciometro, 0, 1023, 0, 50);

  if(periodoTON > 0){
    
    digitalWrite(sinalPin, HIGH);
    digitalWrite(sinal2Pin, LOW);
    delayMicroseconds(periodoTON);
    digitalWrite(sinalPin, LOW);
    digitalWrite(sinal2Pin, LOW);

    delayMicroseconds(tempoAlternar);

    digitalWrite(sinalPin, LOW);
    digitalWrite(sinal2Pin, HIGH);
    delayMicroseconds(periodoTON);
    digitalWrite(sinalPin, LOW);
    digitalWrite(sinal2Pin, LOW);

    delay(tempoEntrePulsos-(2*periodoTON+tempoAlternar));
  }
  else{
    digitalWrite(sinalPin, LOW);
    digitalWrite(sinal2Pin, LOW);
  }

  Serial.print(periodoTON);
}