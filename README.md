# Watering Plant System

Este projeto consiste em um sistema automatizado para regar uma planta com base na umidade do solo. O sistema utiliza uma placa Arduino e sensores para monitorar o nível de umidade do solo e acionar uma bomba de água para regar a planta quando necessário.

## Componentes do Projeto

- Placa Arduino (qualquer modelo compatível)
- Sensor de umidade do solo
- Bomba de água
- LED indicador
- Resistores e componentes eletrônicos básicos
- Fios e cabos de conexão

## Configuração

Certifique-se de conectar os componentes de acordo com as definições de pinos no arquivo "constants.h".

## Funcionamento

O código principal do projeto está no arquivo "main.cpp". Aqui está uma breve explicação do funcionamento do programa:

1. **ledStart()**: Essa função é responsável por fazer um LED iniciar piscando para indicar o início do sistema. Isso pode ser útil para confirmar que o sistema foi iniciado corretamente.

2. **checkAndWaterPlant()**: Nessa função, o sistema lê o valor do sensor de umidade do solo. Se o solo estiver seco (valor de leitura acima do limiar de solo seco), a bomba de água é acionada e a planta é regada por um determinado tempo (definido pela constante "WATER_PUMP_DURATION"). Além disso, o LED indicador é ligado durante o processo de rega. Se o solo estiver úmido o suficiente, o sistema não realiza a rega e exibe a mensagem "Plant is watered" no monitor serial.

3. **setup()**: A função de configuração inicial é executada uma vez quando o sistema é iniciado. Ela inicializa as portas de entrada e saída e inicia a comunicação serial.

4. **loop()**: O loop principal do sistema chama a função "checkAndWaterPlant()" para verificar e regar a planta. Após a verificação, o sistema aguarda por um período de tempo (1 segundo neste caso) antes de repetir o processo.

### Arquivo "constants.h"

No arquivo "constants.h", estão definidas as constantes utilizadas no projeto, como os pinos dos sensores, limiares de umidade do solo e outras configurações relevantes. Essas definições permitem que o código principal seja mais legível e fácil de modificar, caso necessário.

### Observações

- Certifique-se de ajustar os valores das constantes, como "WET_SOIL" e "DRY_SOIL", para atender às necessidades específicas da sua planta e sensor de umidade.
- Utilize os pinos corretos de acordo com a conexão física dos componentes no seu projeto.
- Assegure-se de ter a biblioteca "Arduino.h" instalada para compilar e executar o código corretamente.
