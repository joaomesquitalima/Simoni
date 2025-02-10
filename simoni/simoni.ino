#include <avr/wdt.h>


#define BUZZER_PIN 9
#define btn1 12
#define btn2 8
#define btn3 2
#define LED_VERDE 4
#define LED_VERMELHO 11
#define LED_AZUL 6

#define START 5

bool estadoBtn1 = false, estadoBtn2 = false, estadoBtn3 = false;

void setup() {
    pinMode(btn1, INPUT);
    pinMode(btn2, INPUT);
    pinMode(btn3, INPUT);
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
    randomSeed(analogRead(0));
    
}

void Start(){
  tone(BUZZER_PIN, 400, 300);
  digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);
  tone(BUZZER_PIN, 500, 300);
  digitalWrite(LED_AZUL, HIGH);
  delay(100);
  digitalWrite(LED_AZUL, LOW);

  tone(BUZZER_PIN, 600, 300);
  digitalWrite(LED_VERDE, HIGH);
  delay(100);
  digitalWrite(LED_VERDE, LOW);
  tone(BUZZER_PIN, 600, 300);
  digitalWrite(LED_VERDE, HIGH);
  delay(100);
  digitalWrite(LED_VERDE, LOW);
  tone(BUZZER_PIN, 500, 300);
  digitalWrite(LED_AZUL, HIGH);
  delay(100);
  digitalWrite(LED_AZUL, LOW);
  tone(BUZZER_PIN, 500, 300);
  digitalWrite(LED_AZUL, HIGH);
  delay(100);
  digitalWrite(LED_AZUL, LOW);
  
  tone(BUZZER_PIN, 400, 300);
  digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);

  tone(BUZZER_PIN, 400, 300);
  digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);


  tone(BUZZER_PIN, 400, 300);
   digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);


  tone(BUZZER_PIN, 500, 300);
  digitalWrite(LED_AZUL, HIGH);
  delay(100);
  digitalWrite(LED_AZUL, LOW);

  tone(BUZZER_PIN, 400, 300);
   digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);


  tone(BUZZER_PIN, 400, 300);
   digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);

  
   tone(BUZZER_PIN, 400, 300);
   digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);

   tone(BUZZER_PIN, 400, 300);
   digitalWrite(LED_VERMELHO,HIGH);
  delay(100);
  digitalWrite(LED_VERMELHO,LOW);


  gerador();
}

bool compararVetores(int v1[], int v2[], int tam) {
  for (int i = 0; i < tam; i++) {
    if (v1[i] != v2[i]) {  // Se um elemento não for igual
      return false;  // Vetores não são iguais
    }
  }
  return true;  // Vetores são iguais
}

void gerador(){
  int numero = random(2);
  int tam = 10;
  int* v[tam];
  int tamanho_lista = (tam * (tam + 1) ) / 2;
  int lista[tamanho_lista]; 
  int indice_lista = 0; 

  //  cria a lista
    for (int i = 0; i <tam; i++) {
        for (int j = 0; j <= i; j++) {
            int newNumber = random(3);
            lista[indice_lista] = newNumber;
            indice_lista = indice_lista + 1;
        }
    }

  // cria o vetor de vetores
  for (int i = 0; i <tam; i++) {
        v[i] = new int[i + 1];  
        for (int j = 0; j <= i; j++) {
            v[i][j] = lista[j];
        }
    }


    for (int i = 0; i < tam; i++) {
      delay(1000);
      int tamanho = 0;
      for (int j = 0; j <= i; j++) {
        
        if (v[i][j] == 0){
          digitalWrite(LED_VERMELHO,HIGH);
          tone(BUZZER_PIN, 400, 700);
          delay(700); 
          digitalWrite(LED_VERMELHO, LOW);
        }

        if (v[i][j] == 1){
          digitalWrite(LED_AZUL,HIGH);
          tone(BUZZER_PIN, 400, 700);
          delay(700); 
          digitalWrite(LED_AZUL, LOW);
        }

        if (v[i][j] == 2){
          digitalWrite(LED_VERDE,HIGH);
          tone(BUZZER_PIN, 400, 700);
          delay(700); 
          digitalWrite(LED_VERDE, LOW);
        }
        tamanho = tamanho + 1;
      }
      // logica pra espera da sequencia
      int vetor_temp[tamanho];
      int btns_apertados = 0;

      
      vetor_temp[tamanho] = new int[tamanho];  
      for (int i = 0; i < tamanho; i++) {
        while(true){  
          // apertar botão 1 
          if (digitalRead(btn1) == HIGH && !estadoBtn1) {  
              estadoBtn1 = true;  
              digitalWrite(LED_VERMELHO, HIGH);
              tone(BUZZER_PIN, 400, 400);
              delay(400); 
              digitalWrite(LED_VERMELHO, LOW);
              vetor_temp[i] = 0;
              break;
          }
          if (digitalRead(btn1) == LOW) {estadoBtn1 = false;}

          if (digitalRead(btn2) == HIGH && !estadoBtn2) {  
            estadoBtn2 = true;  
            digitalWrite(LED_AZUL, HIGH);
            tone(BUZZER_PIN, 500, 200);
            delay(400);
            digitalWrite(LED_AZUL, LOW);
            vetor_temp[i] = 1;
            break;
          }
          if (digitalRead(btn2) == LOW) estadoBtn2 = false; 

          if (digitalRead(btn3) == HIGH && !estadoBtn3) {  
            estadoBtn3 = true;  
            digitalWrite(LED_VERDE, HIGH);
            tone(BUZZER_PIN, 600, 200);
            delay(200);
            digitalWrite(LED_VERDE, LOW);
            vetor_temp[i] = 2;
            break;
            }
            if (digitalRead(btn3) == LOW) estadoBtn3 = false;  

                      
        }
      }  
      if (compararVetores(v[tamanho - 1],vetor_temp,tamanho) == false){
        tone(BUZZER_PIN, 102, 400);
        digitalWrite(LED_VERDE, HIGH);
        delay(400);
        digitalWrite(LED_VERDE, LOW);
        tone(BUZZER_PIN, 202, 400);
        digitalWrite(LED_AZUL, HIGH);
        delay(400);
        digitalWrite(LED_AZUL, LOW);
        
        tone(BUZZER_PIN, 102, 400);
        digitalWrite(LED_VERMELHO, HIGH);
        delay(400);
        digitalWrite(LED_VERMELHO, LOW);
        
        
        wdt_enable(WDTO_15MS);  // Configura o WDT para 15ms
        while (1) {
            // Loop infinito para aguardar o reset
        }
      };   
    }

}

void loop() {
    if(digitalRead(START) == HIGH){
      Start();
    }



    

    
}

