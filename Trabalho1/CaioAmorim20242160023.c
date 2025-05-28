// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Caio Gabriel Cruz Amorim
//  email: cgabrielamorim@gmail.com
//  Matrícula: 20242160023
//  Semestre: 2025.1

// Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "CaioAmorim20242160023.h"
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{

  int datavalida = 1;
  int sDia = 0, sMes = 0, sAno = 0;
  int i = 0;

  // Verifica se tem algum caractere inválido na string
  while (data[i] != '\0')
  {
    if (data[i] != '/' && (data[i] < '0' || data[i] > '9'))
    {
      datavalida = 0;
      break;
    }
    i++;
  }
  i = 0;

  // quebrar a string data em strings sDia, sMes, sAno
  while (data[i] != '/' && data[i] != '\0')
  {
    sDia = sDia * 10 + (data[i] - '0');
    i++;
  }
  i++; // pula a barra

  while (data[i] != '/' && data[i] != '\0')
  {
    sMes = sMes * 10 + (data[i] - '0');
    i++;
  }
  i++; // pula a barra

  while (data[i] != '\0')
  {
    sAno = sAno * 10 + (data[i] - '0');
    i++;
  }

  if (sDia > 31 || sDia < 1)
    datavalida = 0;

  if (sMes > 12 || sMes < 1)
    datavalida = 0;

  if (sAno < 0)
    datavalida = 0;

  if (sAno < 100)
  {
    if (sAno >= 30)
    {
      sAno += 1900;
    }
    else
    {
      sAno += 2000;
    }
  }

  if ((sAno % 4 == 0 && sAno % 100 != 0) || (sAno % 400 == 0))
  {
    if (sDia == 29 && sMes == 2)
    {
      datavalida = 1;
    }
  }
  else
  {
    if (sDia == 29 && sMes == 2)
    {
      datavalida = 0;
    }
  }

  // printf("%s\n", data);

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

int bissexto(int ano)
{
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

void converterData(char data[], int *dia, int *mes, int *ano)
{
  *dia = (data[0] - '0') * 10 + (data[1] - '0');
  *mes = (data[3] - '0') * 10 + (data[4] - '0');
  *ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 +
         (data[8] - '0') * 10 + (data[9] - '0');
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

  DiasMesesAnos dma;

  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }

  if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }

  int dia1, mes1, ano1;
  int dia2, mes2, ano2;
  converterData(datainicial, &dia1, &mes1, &ano1);
  converterData(datafinal, &dia2, &mes2, &ano2);

  // Verifica se datainicial > datafinal
  if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2))
  {
    dma.retorno = 4;
    return dma;
  }

  int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  dma.qtdDias = dia2 - dia1;
  dma.qtdMeses = mes2 - mes1;
  dma.qtdAnos = ano2 - ano1;

  if (dma.qtdDias < 0)
  {
    dma.qtdMeses--;
    int mesAnterior = mes2 - 2; // -1 para índice 0 e -1 para anterior
    if (mesAnterior < 0)
      mesAnterior += 12;

    dma.qtdDias += diasMes[mesAnterior];

    if (mesAnterior == 1 && bissexto(ano2))
      dma.qtdDias++; // Fevereiro bissexto
  }

  if (dma.qtdMeses < 0)
  {
    dma.qtdMeses += 12;
    dma.qtdAnos--;
  }

  dma.retorno = 1;
  return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

char normaliza(char ch, int isCaseSensitive)
{
  char acentuados[] = "áàâãäÁÀÂÃÄéèêëÉÈÊËíìîïÍÌÎÏóòôõöÓÒÔÕÖúùûüÚÙÛÜçÇ";
  char normalizados[] = "aaaaaAAAAAeeeeEEEEiiiiIIIIoooooOOOOOuuuuUUUUcC";

  for (int i = 0; acentuados[i] != '\0'; i++)
  {
    if (ch == acentuados[i])
    {
      ch = normalizados[i];
      break;
    }
  }

  if (!isCaseSensitive && ch >= 'A' && ch <= 'Z')
    ch = ch + 32;
  return ch;
}

int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int i = 0;

  char letraAlvo = normaliza(c, isCaseSensitive);

  while (texto[i] != '\0')
  {
    char atual = normaliza(texto[i], isCaseSensitive);

    if (atual == letraAlvo)
      qtdOcorrencias++;

    i++;
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    char textoLimpo[250];
    int indiceTexto = 0, indiceLimpo = 0;
    int totalOcorrencias = 0, tamanhoBusca = strlen(strBusca);
    int indicePos = 0;

    // Remove caracteres inválidos (-61)
    while (strTexto[indiceTexto] != '\0') {
        if ((int)strTexto[indiceTexto] != -61) {
            textoLimpo[indiceLimpo++] = strTexto[indiceTexto];
        }
        indiceTexto++;
    }
    textoLimpo[indiceLimpo] = '\0';

    int tamanhoLimpo = strlen(textoLimpo);

    for (int i = 0; i <= tamanhoLimpo - tamanhoBusca; i++) {
        int corresponde = 1;

        for (int j = 0; j < tamanhoBusca; j++) {
            if (textoLimpo[i + j] != strBusca[j]) {
                corresponde = 0;
                break;
            }
        }

        if (corresponde) {
            posicoes[indicePos++] = i + 1;
            posicoes[indicePos++] = i + tamanhoBusca;
            totalOcorrencias++;
        }
    }

    return totalOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int invertido = 0;
  while (num > 0)
  {
    invertido = invertido * 10 + num % 10;
    num = num / 10;
  }
  num = invertido;

  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;
  int tamanhoNumero = 0;
  int aux = numerobusca;
  int divisor = 1;
  int numAux;

  // Pega o quantos digitos tem o numeroBase
  if (numerobase == 0)
    tamanhoNumero = 1;

  while (aux != 0)
  {
    aux /= 10;
    tamanhoNumero++;
  }

  for (int i = 0; i < tamanhoNumero; i++)
  {
    divisor *= 10;
  }

  while (numerobase >= divisor / 10)
  {
    numAux = numerobase % divisor;

    if (numAux == numerobusca)
      qtdOcorrencias++;

    numerobase /= 10;
  }

  return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5])
{
  int linhas = 8;
  int colunas = 10;
  int len = strlen(palavra);
  int achou = 0;

  // Direções: ↓, ↑, →, ←, ↘, ↙, ↗, ↖
  int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

  for (int i = 0; i < linhas && !achou; i++)
  {
    for (int j = 0; j < colunas && !achou; j++)
    {
      for (int d = 0; d < 8 && !achou; d++)
      {
        int k;
        for (k = 0; k < len; k++)
        {
          int ni = i + dx[d] * k;
          int nj = j + dy[d] * k;

          if (ni < 0 || ni >= linhas || nj < 0 || nj >= colunas)
            break;

          if (matriz[ni][nj] != palavra[k])
            break;
        }

        if (k == len)
        {
          achou = 1;
        }
      }
    }
  }

  return achou;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++)
  {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sDia[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++)
  {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++)
  {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4)
  {                 // testa se tem 2 ou 4 digitos
    sAno[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
