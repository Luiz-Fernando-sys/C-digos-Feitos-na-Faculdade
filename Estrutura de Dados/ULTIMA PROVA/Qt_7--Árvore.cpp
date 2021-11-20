// QUEST�O 7 DA PROVA DE ESTRUTURA DE DADOS  |  �LTIMA PROVA DE ESTRUTURA DE DADOS
// A � menor que B, B � menor que C, e assim por diante.

// ALUNO: Luiz Fernando Adami dos Reis

// CURSO: An�lise e Desenvolvimento de Sistemas.

// OBJETIVO: Fazer o programa exibir qual � a ordem, pr�-ordem e p�s-ordem da sequ�ncia informada.

// S�o 9 letras, come�ando na letra A valendo 10 e indo at� a letra I valendo 90, terei que fazer o programa exibir qual � a ordem, pr�-ordem e p�s-ordem da sequ�ncia dada ao programa.

// ------------------------------------------------------------------------------------------------
 
#include <iostream>
#include <stdlib.h>

using namespace std;

// Estrutura para criar o necess�rio para um n�.
struct NO {
    int item_do_no;
    NO *esquerda;
    NO *direita;
};

class Arvore{
  private: NO *raiz; // Aqui definimos qual ser� a raiz da nossa �rvore.

  public: Arvore(){
  	  raiz = NULL;
	} // A �rvore come�a tendo a raiz valendo NULL

// FUN��O RESPONS�VEL POR INSERIR ELEMENTOS NA �RVORE
void inserir(int valor){
    NO *novo_no = new NO(); // Primeiramente, precisamo criar um novo n� atrav�s deste comando.
    novo_no->item_do_no = valor; // O �tem deste N� criado guardar� o valor que o usu�rio falou que quer inserir na �rvore.
    novo_no->direita = NULL;
    novo_no->esquerda = NULL;
    if(raiz == NULL) raiz = novo_no; // Se a raiz ainda estiver como NULL, aplicamos o novo_no como sendo a raiz da �rvore.
    else{
      NO *no_atual = raiz;
      NO *anterior;
      while(true){
        anterior = no_atual;
        if(valor <= no_atual->item_do_no){
          no_atual = no_atual->esquerda;
          if (no_atual == NULL){
            anterior->esquerda = novo_no;
            return;
          } 
        }
        else{
           no_atual = no_atual->direita;
           if (no_atual == NULL){
             anterior->direita = novo_no;
             return;
           }
        }
      }
    }

  }

// FUN��O RESPONS�VEL POR REMOVER UM �TEM DA �RVORE.
bool remover(int valor_a_remover){
    if (raiz == NULL) return false; // Valida��o para verificar a situa��o do n� raiz da �rvore.
    NO *no_atual = raiz;
    NO *pai_do_no = raiz;
    bool filho_esquerda = true;
    
    while (no_atual->item_do_no != valor_a_remover){
      pai_do_no = no_atual;
      if(valor_a_remover < no_atual->item_do_no ){
        no_atual = no_atual->esquerda;
        filho_esquerda = true;
      }
      else{
        no_atual = no_atual->direita; 
        filho_esquerda = false;
      }
      if (no_atual == NULL) return false;
    }

// Caso encontrarmos um n� folha, teremos apag�-lo da �rvore...
    if (no_atual->esquerda == NULL && no_atual->direita == NULL) {
      if (no_atual == raiz ) raiz = NULL;
      else if (filho_esquerda) pai_do_no->esquerda = NULL;
           else pai_do_no->direita = NULL;
    }

// Se � pai somente de elementos a esquerda, substituiremos pela sub �rvore da direita.
    else if (no_atual->direita == NULL) {
       if (no_atual == raiz) raiz = no_atual->esquerda;
       else if (filho_esquerda) pai_do_no->esquerda = no_atual->esquerda;
            else pai_do_no->direita = no_atual->esquerda;
    }

// Se este n� for pai somente de elementos a direita, substituiremos pela sub �rvore da esquerda.    
    else if (no_atual->esquerda == NULL) {
       if (no_atual == raiz) raiz = no_atual->direita;
       else if (filho_esquerda) pai_do_no->esquerda = no_atual->direita;
            else pai_do_no->direita = no_atual->direita;
    }

// Caso este n� possua um grau de parentesco maior em rela��o, ent�o prosseguiremos com a seguinte situa��o.
    else {
      NO *proximo_a_ser_sucedido = proximo_no(no_atual);
      if (no_atual == raiz) raiz = proximo_a_ser_sucedido;
      else if(filho_esquerda) pai_do_no->esquerda = proximo_a_ser_sucedido; // para o caso de filho a esquerda
           else pai_do_no->direita = proximo_a_ser_sucedido; // para o caso de filho a direita
      proximo_a_ser_sucedido->esquerda = no_atual->esquerda;    
    }

    return true;
  }
  
  private: NO *proximo_no(NO *remove){
     NO *pai_do_proximo_a_ser_sucedido = remove;
     NO *proximo_a_ser_sucedido = remove;
     NO *no_atual = remove->direita;

     while (no_atual != NULL){
       pai_do_proximo_a_ser_sucedido = proximo_a_ser_sucedido;
       proximo_a_ser_sucedido = no_atual;
       no_atual = no_atual->esquerda;
     }

     if (proximo_a_ser_sucedido != remove->direita){
       pai_do_proximo_a_ser_sucedido->esquerda = proximo_a_ser_sucedido->direita; // Ocorr�ncia da heran�a de filhos de proximo_a_ser_sucedido
       proximo_a_ser_sucedido->direita = remove->direita;
     }
     return proximo_a_ser_sucedido;
  }
  
// FUN��O RESPONS�VEL POR EXIBIR OS ELEMENTOS INSERIDOS NA �RVORE
    public: void exibir_arvore() {
    cout << "\n\nEm Ordem:  "; // Exibi��o em ORDEM
    inOrder(raiz);
    cout << "\nPr�-Ordem: "; // Exibi��o em PR�-ORDEM
    preOrder(raiz);
    cout << "\nP�s-Ordem: "; // Exibi��o em P�S-ORDEM
    posOrder(raiz);
    cout << "\n";
  }

  // Exibi��o em ORDEM
  private: void inOrder(NO *no_atual) {
    if (no_atual != NULL) {
      inOrder(no_atual->esquerda);
      cout << no_atual->item_do_no << "  |  ";
      inOrder(no_atual->direita);
    }
  }
  
  // Exibi��o em PR�-ORDEM
  private: void preOrder(NO *no_atual) {
    if (no_atual != NULL) {
      cout << no_atual->item_do_no << "  |  ";
      preOrder(no_atual->esquerda);
      preOrder(no_atual->direita);
    }
  }
  
  // Exibi��o em P�S-ORDEM
  private: void posOrder(NO *no_atual) {
    if (no_atual != NULL) {
      posOrder(no_atual->esquerda);
      posOrder(no_atual->direita);
      cout << no_atual->item_do_no << "  |  ";
    }
  }

};

// FUN��O PRINCIPAL DO C�DIGO
int main() {
	
	setlocale(LC_ALL, "Portuguese");

    Arvore tree;
    int op, valor_a_inserir, valor_a_remover;

    do {
    	system("cls");
        cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
        cout << "\n|||||||||||||| �RVORE BIN�RIA ||||||||||||||||";
        cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
        cout << "\n                                         |||||";
        cout << "\nQual a��o deseja fazer?                  |||||";
		cout << "\n1 - Inserir elemento na �rvore           |||||";
		cout << "\n2 - Excluir elemento da �rvore           |||||";
		cout << "\n3 - Exibir os elementos da �rvore        |||||";
		cout << "\n4 - Sair do programa                     |||||";
		cout << "\n                                         |||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n";
		cin >> op;
		// O usu�rio escolhe o que deseja fazer.
		switch(op) {
			// Caso queira inserir elementos na �rvore.
	 		case 1: {
	 			system("cls");
		       cout << "\nQual n�mero voc� deseja inserir na �rvore?  ";
		       cin >> valor_a_inserir; // Usu�rio diz o n�mero que quer inserir na �rvore.
		       tree.inserir(valor_a_inserir); // Chamamos a fun��o respons�vel por inserir elementos na �rvore, que est� dentro da classe "Arvore", e passamos o valor dito pelo usu�rio como par�metro.
		       system("cls");
		       break;
			}
			// Caso queira remover elementos na �rvore.
			case 2: {
				system("cls");
		       cout << "\nQual n�mero voc� deseja remover da �rvore?";
		       cin >> valor_a_remover; // Guardamos o valor que o usu�rio quer excluir da �rvore.
		       if ( !tree.remover(valor_a_remover) ) // chamamos a fun��o que est� dentro da classe "Arvore" e que � respons�vel por efetuar a exclus�o do elemento dito pelo usu�rio. 
       	   	   	   cout << "\nEste valor n�o est� inserido na �rvore! Tente novamente com um valor v�lido."; // Se o valor n�o estiver na �rvore, o programa exibe esta mensagem dizendo que o elemento n�o est� inserido na �rvore.				
				system("PAUSE");
		       break;
			}
			// Caso queira ver os elementos que tem na �rvore. 
			case 3: {
				system("cls");
		      tree.exibir_arvore(); // Chamamos a fun��o respons�vel por exibir os elementos e suas disposi��es dentro da �rvore.
		      system("PAUSE");
		      break; 
			}
        }
	// Caso queira sair do programa.
    } while(op != 4);
}