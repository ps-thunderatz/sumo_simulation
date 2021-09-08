<h1 align="center">
    🤼 Sumo Simulation 🤖
</h1>
<p align="center">
<img src="https://img.shields.io/badge/ROS%20version-noetic-informational?style=for-the-badge" href="http://wiki.ros.org/noetic"/>
<img src="https://img.shields.io/badge/Gazebo%20version-11-important?style=for-the-badge" href="http://gazebosim.org/"/>

</p>

<p align="center">
<img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" href ="https://forthebadge.com"/>
<img src="https://forthebadge.com/images/badges/built-with-love.svg" href ="https://forthebadge.com"/>
<img src="https://forthebadge.com/images/badges/it-works-why.svg" href ="https://forthebadge.com"/>

</p>

- [🎈 Introdução](#-introdução)
- [:camera: Capturas de tela](#camera-capturas-de-tela)
- [📂 Arquivos no projeto](#-arquivos-no-projeto)
- [:space_invader: Iniciando o projeto](#space_invader-iniciando-o-projeto)
  - [:woman_cartwheeling: Compilando](#woman_cartwheeling-compilando)
  - [:rocket: Iniciando a simulação](#rocket-iniciando-a-simulação)
- [:joystick: Controle](#joystick-controle)
- [:pushpin: Tópicos](#pushpin-tópicos)
  - [:arrow_left: Entrada](#arrow_left-entrada)
  - [:arrow_right: Saída](#arrow_right-saída)

## 🎈 Introdução

Esse repositório contém a simulação do robô de sumô que você irá controlar! Lembre-se de baixar (ou clonar) no mesmo workspace catkin que está o repositório do [pacote de controle](https://github.com/ps-thunderatz/sumo_controller/).

## :camera: Capturas de tela

<p align="center">
  <img height=200px src="./docs/sumo_1.jpg" />
  <img height=200px src="./docs/sumo_2.jpg" />
</p>

## 📂 Arquivos no projeto

- **config/** - Variáveis de configuração que serão utilizadas na simulação, contidas em arquivos .yml ou .perspective.
- **docs/** - Imagens que estão sendo usadas nesse README.
- **launch/** - Arquivos para executar os mundos, os robôs e as jogadas específicas.
- **meshes/** - Arquivos .STL do sumô.
- **models/** - Modelo dos objetos utilizados na simulação.
- **plugins/** - Plugins de sensores.
- **urdf/** - Modelo do sumô.
- **worlds/** - Arquivos .world para invocar o dojô.

## :space_invader: Iniciando o projeto

### :woman_cartwheeling: Compilando

Antes de iniciar a simulação, é necessário se certificar que você está dentro da raíz de uma workspace válida. É possível compilar o código com o seguinte comando:

```bash
catkin_make
```

### :rocket: Iniciando a simulação

Esse pacote de simulação possui diversos modos de inicialização que serão descritos abaixo:

- **mini_match.launch** - Arquivo que invoca a pista com dois sumôs em posição inicial de luta.

```bash
roslaunch sumo_simulation mini_match.launch
```

- **tiebreaker.launch** - Arquivo que invoca apenas os dois sumôs em posição de desempate.

```bash
roslaunch sumo_simulation tiebreaker.launch
```

- **gazebo.launch** - Arquivo que contém o dojô, que será usado durante os combates.

```bash
roslaunch sumo_simulation gazebo.launch
```

- **spawn.launch** - Arquivo que invoca apenas um dos robôs. Para especificar a cor do time é necessário adicionar ```team:=cor_do_time``` no final do comando.

```bash
roslaunch sumo_simulation spawn.launch team:=red
```

- **robots.launch** - Arquivo que invoca apenas os dois sumôs em posição para lutar.

```bash
roslaunch sumo_simulation robots.launch
```

- **calibrate_line.launch** - Arquivo para iniciar a calibração.

```bash
roslaunch sumo_simulation calibrate_line.launch
```

## :joystick: Controle

Para controlar os sumôs, inicie o [pacote de controle](https://github.com/ps-thunderatz/sumo_controller/) de acordo com o ensinado durante as aulas e no README dele!

## :pushpin: Tópicos

Para controlar algumas partes da simulação, o ROS funciona se **inscrevendo** e **publicando** em tópicos. Para listar os tópicos que a simulação está publicando, basta abrir um novo terminal e utilizar o seguinte comando:

```bash
rostopic list
```

### :arrow_left: Entrada

Para controlar a velocidade do robô é necessário publicar nos tópicos do ROS de cada roda. A simulação recebe mensagens do tipo[std_msgs/Float64](http://docs.ros.org/en/noetic/api/std_msgs/html/msg/Float64.html). Os tópicos que controlam as rodas são:

- **robot_left_controller/command**
- **robot_right_controller/command**

O controle do robô é feito pelo [sumo_controller](https://github.com/ps-thunderatz/sumo_controller). Nesse repositório, existem bibliotecas que auxiliarão a movimentação.

### :arrow_right: Saída

O pacote de simulação publica alguns tópicos que serão importantes no desenvolvimento de estratégias no [sumo_controller](https://github.com/ps-thunderatz/sumo_controller). Os tópicos publicados são:

- **distance_sensor_[0..2]/reading** - Tópico da leitura dos dados dos sensores de distância.
- **imu/** - Tópico da leitura dos dados da IMU. A partir dessa leitura é possível, no pacote de controle, receber a velocidade angular e a aceleração linear do robô.
- **left_line_sensor/reading** - Tópico da leitura do sensor de linha no lado esquerdo do robô.
- **right_line_sensor/reading** - Tópico da leitura do sensor de linha no lado direito do robô.
