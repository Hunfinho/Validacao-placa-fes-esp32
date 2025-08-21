# Validação de Hardware para FES com ESP32

Este repositório contém o código-fonte para a validação do hardware para Estimulação Elétrica Funcional (FES).

Hardware Necessário
* Placa de FES - Conversor CC-CC do tipo *boost* (Hardware sob teste)
* Microcontrolador ESP32
* Bateria de 4.2V
* Potenciômetro de 10kΩ
* Osciloscópio utilizado para medição

 ![IMG_0536](https://github.com/user-attachments/assets/4aa8f1a5-53cc-414b-a9ce-32cdfc0acb08)

Conexões Principais
* Potenciômetro: GPIO 4
* PWM (*Boost*): GPIO 23
* Ponte H (Sinal 1): GPIO 5
* Ponte H (Sinal 2): GPIO 18
