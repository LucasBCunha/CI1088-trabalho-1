# sis-dis-trabalho1
  Trabalho 1 de sistemas distribuidos. Implementação de uma simulação do algoritmo VCube utilizando SMPL.

## Pontos importantes do VCube "v1"

* O testador continua testando no cluster, até encontrar processo correto ou testar todos os processos falhos

## Pontos importantes do VCube "v2"

* o testador do nodo j no cluster s é o primeiro nodo sem-falha em C(j,s)
* Ao testar um processo correto, o testador obtém qualquer “novidade” que o testado tenha
  - Na simulação basta comparar os vetores State[] do testado e testador
