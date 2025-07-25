#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"


typedef struct estrutura{
    int *vetor;
    int tamanho;
    int qtdElementos; 
}estrutura;

estrutura vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao --;
    int retorno = 0;

    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }

    if(vetorPrincipal[posicao].vetor != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR; 
        return retorno;
    }

    if(retorno == 0){
        vetorPrincipal[posicao].vetor = malloc(tamanho * sizeof(int));
        if(vetorPrincipal[posicao].vetor == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
            return retorno;
        }else{
            vetorPrincipal[posicao].tamanho = tamanho;
            vetorPrincipal[posicao].qtdElementos = 0;
            retorno = SUCESSO;
            return retorno;
        }
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao--;
    int retorno;

    if (posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao].vetor == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    if (vetorPrincipal[posicao].qtdElementos >= vetorPrincipal[posicao].tamanho)
    {
        retorno = SEM_ESPACO;
        return retorno;
    }

    //insere
    vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].qtdElementos] = valor;
    vetorPrincipal[posicao].qtdElementos++;
    retorno = SUCESSO;
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    posicao--;
    int retorno;

    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if (vetorPrincipal[posicao].vetor == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if (vetorPrincipal[posicao].qtdElementos == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    while(vetorPrincipal[posicao].qtdElementos == 0)
    {
        vetorPrincipal[posicao].qtdElementos--;
    }
    vetorPrincipal[posicao].qtdElementos--;
    vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].qtdElementos] = 0;

    retorno = SUCESSO;
    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao --;
    int retorno, encontrou = 0, i;

    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (i = 0; i < vetorPrincipal[posicao].qtdElementos; i++) {
        if (vetorPrincipal[posicao].vetor[i] == valor) {
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0)
        return NUMERO_INEXISTENTE;

    for (int j = i; j < vetorPrincipal[posicao].qtdElementos - 1; j++) {
        vetorPrincipal[posicao].vetor[j] = vetorPrincipal[posicao].vetor[j + 1];
    }

    vetorPrincipal[posicao].qtdElementos--;

    return SUCESSO;
}


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int *posicao)
{
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    int retorno;

    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].qtdElementos == 0){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    else{
        for (int i = 0; i < vetorPrincipal[posicao].qtdElementos; i++) {
            vetorAux[i] = vetorPrincipal[posicao].vetor[i];
        }
        retorno = SUCESSO;
        return retorno;
    }

}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    int retorno;
    int qtd = vetorPrincipal[posicao].qtdElementos;
        
    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].vetor == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    for(int i = 0; i < qtd; i++) {
        vetorAux[i] = vetorPrincipal[posicao].vetor[i];
    }

    for(int i = 0; i < qtd; i++) {
        for(int j = 0; j < qtd; j++) {
            if(vetorAux[i] < vetorAux[j]) {
                int aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;
            }
        }
    }
    
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno;
    int totalElementos = 0;
    int k = 0; 

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0) {
            for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
                vetorAux[k] = vetorPrincipal[i].vetor[j];
                k++;
                totalElementos++;
            }
        }
    }

    if (totalElementos == 0)
        return retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno;
    int totalElementos = 0;
    int k = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0) {
            for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
                vetorAux[k] = vetorPrincipal[i].vetor[j];
                k++;
                totalElementos++;
            }
        }
    }

    if (totalElementos == 0)
        return retorno =TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int i = 0; i < totalElementos - 1; i++) {
        for (int j = 0; j < totalElementos - i - 1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao --;
    int retorno;

    if(posicao < 0 || posicao > 9)
        return retorno = POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetor == NULL)
        return retorno = SEM_ESTRUTURA_AUXILIAR;

    int tamanho = novoTamanho + vetorPrincipal[posicao].tamanho;

    if(tamanho < 1)
        return retorno = NOVO_TAMANHO_INVALIDO;
    
    int *vetorAux = realloc(vetorPrincipal[posicao].vetor, tamanho * sizeof(int));
    if(vetorAux == NULL)
        return retorno = SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].vetor = vetorAux;
    vetorPrincipal[posicao].tamanho = tamanho;

    if (vetorPrincipal[posicao].qtdElementos > tamanho)
        vetorPrincipal[posicao].qtdElementos = tamanho;

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;
    int retorno;
    int qtd = vetorPrincipal[posicao].qtdElementos;

    if(posicao < 0 || posicao > 9)
        return retorno = POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetor == NULL)
        return retorno = SEM_ESTRUTURA_AUXILIAR;

    if(qtd == 0)
        return retorno = ESTRUTURA_AUXILIAR_VAZIA;

    retorno = vetorPrincipal[posicao].qtdElementos;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    No *cabeca = malloc(sizeof(No));
    if (cabeca == NULL)
        return NULL;

    cabeca->prox = NULL;

    No *ultimo = cabeca;
    int elementosEncontrados = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0) {
            for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
                No *novo = malloc(sizeof(No));
                if (novo == NULL) {
                    free(cabeca);
                    return NULL;
                }

                novo->conteudo = vetorPrincipal[i].vetor[j];
                novo->prox = NULL;

                ultimo->prox = novo;
                ultimo = novo;
                elementosEncontrados++;
            }
        }
    }

    if (elementosEncontrados == 0) {
        free(cabeca); 
        return NULL;
    }

    return cabeca;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;

    No *atual = inicio->prox; 

    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{

    if (inicio == NULL || *inicio == NULL)
        return;

    No *atual = *inicio;
    No *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL; 

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].qtdElementos = 0;
        vetorPrincipal[i].vetor = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar()
{

    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetor != NULL)
        {
            free(vetorPrincipal[i].vetor);
            vetorPrincipal[i].vetor = NULL;
        }
    }
    
}
