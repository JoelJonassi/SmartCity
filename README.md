# Smart City project

Novas formas de mobilidade, nomeadamente aquelas que ocorrem entre distâncias curtas através de meios
elétricos, têm surgido ao longo dos últimos anos. Esta transformação na forma de mobilidade urbana, fator
essencial para o desenvolvimento das cidades, irá depender de ações que permitam agilizar a utilização dos meios
de transporte que suportem uma mobilidade mais limpa e económica, como por exemplo as trotinetes elétricas, as
bicicletas elétricas, etc.
O problema que aqui se apresenta tem como objetivo desenvolver uma solução digital que permita agilizar a
gestão (registo, partilha, utilização) de meios de mobilidade urbana num contexto de uma smart-city, considerando
que os meios de mobilidade elétrica serão sempre levantados e entregues pelos utilizadores no mesmo local.
Apresente uma solução para a gestão de meios de mobilidade elétrica num contexto de uma smart-city, aplicando o
paradigma de programação imperativa (linguagem de programação C) de modo a responder às seguintes
operações:
2
1. Leitura de um ficheiro de texto contendo os dados de vários pedidos de utilização de meios de mobilidade
elétrica. Considere a informação estruturada em várias linhas. Cada linha identifica sequencialmente o
número de ordem do pedido, o número de identificação fiscal do utilizador, o código do meio de
mobilidade pretendido (trotinetes, bicicleta, carro, etc), o tempo (minutos) de utilização pretendido e a a
distância (quilómetros) pretendida. O meio de mobilidade atribuído deverá ter autonomia suficiente para
completar a distância definida pelo utilizador.
Apresenta-se, a seguir, com cor azul, um exemplo de conteúdo de um ficheiro com sete pedidos:

Número Ordem | NIF | Código | Tempo (min) | Distância (km)
-----|------|-----|-----|----
 1 | 12345678 | M_1 | 75 | 3
 2 | 11223344 | M_2 | 100 | 2
 3 | 10203040 | M_4 | 50 | 2
 4 | 111222333| M_3 | 100 | 20
 5 | 11112222 | M_1 | 30 | 4
 6 | 22223333 | M_3 | 150 | 50
 7 | 44448888 | M_3 | 50 | 100
 
Os dados do ficheiro deverão ser automaticamente validados e carregados para um array de registos.
Cada registo da estrutura de dados deverá conter toda a informação de um determinado pedido.
2. Leitura de um ficheiro de texto contendo os dados dos meios de mobilidade urbana. Considere a
informação estruturada em várias linhas. Cada linha identifica sequencialmente o código de identificação
do meio de mobilidade, o seu tipo, o custo de utilização por minuto e a sua autonomia.

Apresenta-se a seguir, com cor azul, um exemplo de conteúdo de um ficheiro.

Código | Tipo | Custo | Autonomia
--|---|---|--
 M_1 | Trotinete | 0,20 | 15
 M_2 | Trotinete | 0,20 | 13
 M_3 | Carro | 0,80 | 320
 M_4 | Bicicleta | 0,30 | 19
 
Os dados do ficheiro deverão ser automaticamente validados e carregados para um array de registos.
Cada registo da estrutura de dados deverá conter toda a informação de um determinado meio elétrico.
3
3. Inserção de um novo meio de mobilidade elétrica;
4. Remoção de um meio de mobilidade elétrica a partir do seu código;
5. Inserção de um novo pedido de utilização;
6. Remoção de um pedido de utilização a partir do seu código;
7. Listagem dos dados de todos os meios de mobilidade elétrica;
8. Listagem de todo os pedidos de utilização;
9. Cálculo do custo associado a um pedido de utilização a partir da indicação do seu número de ordem;
10. Distribuição dos meios de mobilidade pelos vários utilizadores, respeitando a ordem dos pedidos, o meio
elétrico solicitado por cada utilizador, e as necessidades em termos de distância. Caso a autonomia pretendida
não seja suficiente então procurar atribuir, se possível, um outro meio de mobilidade, do mesmo tipo, com
autonomia suficiente.
11. Listagem do plano de utilização de um determinado meio de mobilidade elétrica, a partir do seu código, por
ordem crescente de número de ordem do pedido. Cada linha deverá conter o número de ordem do pedido, o
número de identificação fiscal do utilizador, o tempo de início de utilização, o tempo de término de utilização, a
autonomia inicial e o código do meio elétrico atribuído.
Apresenta-se a seguir, com cor azul, um exemplo de listagem para o meio de mobilidade elétrica M_3:

Número Ordem | NIF | Tempo Início | Tempo Término | Autonomia | Inicial Código
--|---|---|--|----|---
  4 | 111222333 | 0 | 100 | 320 | M_3
  6 | 22223333 | 100 | 250 | 300 | M_3
  7 | 44448888 | 250 | 300 | 250 | M_3
  
12. Armazenamento dos pedidos de utilização em ficheiro;
13. Armazenamento dos meios de mobilidade elétrica em ficheiros.
