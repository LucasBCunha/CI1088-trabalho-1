  <h1>Trabalho 1 do curso CI1088 - Sistemas Distribuídos</h1>
  <p>O trabalho consiste na implementação de uma simulação usando SMPL do algoritmo VCube versão 2 apresentado em aula.
  </p>
  <p>
    Para verificar o enunciado do trabalho verifique o <a href="https://www.inf.ufpr.br/elias/sisdis/">site do
      professor</a>.
  </p>
  <p>
    Como parte do processo de desenvolvimento do trabalho foram propostas 5 tarefas, sendo a tarefa 0 executada em sala.
    As minhas implementações estão listadas a seguir.
  </p>

  <h2>Tarefa 1</h2>
  <p>
    Fazer cada um dos processos testar o seguinte no anel. Implemente o teste com a função status() do SMPL e imprimir
    (printf) o resultado de cada teste executado. Por exemplo: “O processo i testou o processo j correto no tempo tal.”
  </p>
  <ul>
    <li><a href="tarefa_1/tempo.c.txt">Código</a></li>
    <li><a href="tarefa_1/saida.txt">Log da execução</a></li>
  </ul>

  <h2>Tarefa 2</h2>
  <p>
    Cada processo correto executa testes até achar outro processo correto. Lembre-se de tratar o caso em que todos os
    demais processos estão falhos. Imprimir os testes e resultados.
  </p>
  <ul>
    <li><a href="tarefa_2/tempo.c.txt">Código</a></li>
    <li><a href="tarefa_2/saida.txt">Log da execução</a></li>
  </ul>

  <h2>Tarefa 3</h2>
  <p>
    Cada processo mantém localmente o vetor State[N].
    Inicializa o State[N] com -1 (indicando estado “unknown”) para todos os demais processos e 0 para o próprio
    processo.
    Nesta tarefa ao executar um teste, o processo atualiza a entrada correspondente no vetor State[N].
    Em cada intervalo de testes, mostre o vetor State[N].
  </p>
  <ul>
    <li><a href="tarefa_3/tempo.c.txt">Código</a></li>
    <li><a href="tarefa_3/saida.txt">Log da execução</a></li>
  </ul>

  <h2>Tarefa 4</h2>
  <p>
    Quando um processo correto testa outro processo correto obtém as informações de diagnóstico do processo testado
    sobre todos os processos do sistema exceto aqueles que testou nesta rodada, além do próprio testador.
  </p>
  <ul>
    <li><a href="tarefa_4/tempo.c.txt">Código</a></li>
    <li><a href="tarefa_4/saida.txt">Log da execução</a></li>
  </ul>


  <h2>VCube V2</h2>
  <p>
    A implementação do VCube utiliza o algoritmo para cálculo dos clusters c(i,s) disponibilizado pelo professor na sua
    página.
    Para possibilitar seu funcionamento eu implementei o algoritmo de modo que há uma matriz contendo todos os clusteres
    para todos os processos/nós.
    A partir dessa matriz que é calculada uma vez, antes de realizar seus testes, cada processo i verifica quais
    processos deveria testar para o cluster s.
    Por exemplo, o processo 0 deve testar o 1 para o cluster 1. No caso do cluster 2 ele deve testar 2, mas caso o 1
    esteja falho, deve testar o 3 também.
    Dessa forma, como descrito no algoritmo VCube, caso tenha ocorrido alguma falha em 3 ela também será dectectada.
  </p>

  <p>
    O vetor state, de cada nodo/processo, é iniciado com -1 para todos os índices de processos que não o próprio.
    Quando ocorre a primeira leitura de status o valor é modificado para 0. Quando ocorre algum evento de falha ou
    recuperação o valor é somado em 1.
    Assim sendo, mesmo que um sistema seja iniciado como falha os outros conseguirão detectar. Outra consequência dessa
    modelagem é que podemos contabilizar
    a quantidade de falhas detectadas e a operação de "resto da divisão por 2" diz se o nodo está falho ou correto. Caso
    o resto seja 0 o nodo está correto, caso contrário está falho.
  </p>
  <p>
    Para cada intervalo de testes o processo i realiza o teste para todos os log2(n) clusters que deve verficar.
  </p>

  <ul>
    <li><a href="trabalho/vcube.c.txt">Algoritmo do VCube V2</a></li>
    <li><a href="trabalho/saida.txt">Log de testes para N = 8 com uma falha</a></li>
    <li><a href="trabalho/saida_2.txt">Log de testes para N = 8 com duas falhas em instantes distintos</a></li>
    <li><a href="trabalho/saida_3.txt">Log de testes para N = 13 com uma falha</a></li>
  </ul>