/*
  Programa: um exemplo para aprender simulação SMPL
    no programa tempo.c os processos simplesmente contam o tempo.
    Autor: Prof. Elias e alunos de Sistemas Distríbuidos ERE4
    Data da última modificação: 25/10/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "smpl.h"

/* ---- Eventos ----*/
#define test 1   // Um processo testa outro processo
#define fault 2  // Um processo falha
#define repair 3 // Um processo se recupera

/* --- Descritor do nodo SMPL --- */
typedef struct
{
  int id; /* Identificador da facility SMPL */
  //  outras variáveis locais dos processos são declaradas aqui
} tnodo;

tnodo *nodo;

int main(int argc, char *argv[])
{
  static int N, /* número total de processos, recebido da linha de comando */
      token,    /* o processo que "está executando" em um instante de tempo */
      event, r, i;

  static char fa_name[5]; /* nome da facility */

  if (argc != 2)
  {
    puts("Uso correto: tempo <num-nodos>");
    exit(1);
  }

  N = atoi(argv[1]);
  printf("Número de processos: %d\n", N);
  smpl(0, "Um exemplo de simulação");
  reset();
  stream(1);

  /* --- Inicialização de variáveis --- */
  nodo = (tnodo *) malloc(sizeof(tnodo) * N);

  for (i = 0; i < N; i++)
  {
    memset(fa_name, '\0', 5);
    sprintf(fa_name, "%d", i);
    nodo[i].id = facility(fa_name, 1);
  }

  /* --- escalonar os eventos --- */
  for (i = 0; i < N; i++)
  {
    schedule(test, 30.0, i); /* estamos escalonando testes para todos os novos (processos) executarem no tempo(t) 30.0*/
  }
  schedule(fault, 31.0, 1);  /* o processo 1 falha no tempo 31 */
  schedule(repair, 61.0, 1); /* o processo 1 recupera no tempo 61 */

  /* Loop principal da simulação */
  while (time() < 150.0)
  {
    cause(&event, &token);
    switch (event)
    {
    case test:
      if (status(nodo[token].id) != 0)
        break; /* se o testar está falho: ele não testa */
      printf("O nodo %d vai testar no tempo %3.1f\n", token, time());
      schedule(test, 30.0, token);
      break;
    case fault:
      // Nodo "ocupado" -> falho
      r = request(nodo[token].id, token, 0); /* O request causa uma facility of SMPL para estar "ocupada" */
      if (r != 0)
      {
        puts("Não foi possível falhar o nodo...");
        break;
      }
      printf("O nodo %d falhou no tempo %3.1f\n", token, time());
      break;
    case repair:
      // Nodo não ocupado -> sem-falha
      release(nodo[token].id, token); /* O release libera a facility SMPL */
      printf("O nodo %d recuperou no tempo %3.1f\n", token, time());
      schedule(test, 30.0, token);
      break;
    }
  }

  exit(0);
}
