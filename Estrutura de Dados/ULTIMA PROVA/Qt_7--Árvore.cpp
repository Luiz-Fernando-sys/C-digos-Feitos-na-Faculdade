// QUESTÃO 7 DA PROVA DE ESTRUTURA DE DADOS  |  ÚLTIMA PROVA DE ESTRUTURA DE DADOS
// A é menor que B, B é menor que C, e assim por diante.

// ALUNO: Luiz Fernando Adami dos Reis

// CURSO: Análise e Desenvolvimento de Sistemas.

// OBJETIVO: Fazer o programa exibir qual é a ordem, pré-ordem e pós-ordem da sequência informada.

// São 9 letras, começando na letra A valendo 10 e indo até a letra I valendo 90, terei que fazer o programa exibir qual é a ordem, pré-ordem e pós-ordem da sequência dada ao programa.

// ------------------------------------------------------------------------------------------------
 
#include <iostream>
#include <stdlib.h>

using namespace std;

// Estrutura para criar o necessário para um nó.
struct NO {
    int item_do_no;
    NO *esquerda;
    NO *direita;
};

class Arvore{
  private: NO *raiz; // Aqui definimos qual será a raiz da nossa árvore.

  public: Arvore(){
  	  raiz = NULL;
	} // A árvore começa tendo a raiz valendo NULL

// FUNÇÃO RESPONSÁVEL POR INSERIR ELEMENTOS NA ÁRVORE
void inserir(int valor){
    NO *novo_no = new NO(); // Primeiramente, precisamo criar um novo nó através deste comando.
    novo_no->item_do_no = valor; // O ítem deste Nó criado guardará o valor que o usuário falou que quer inserir na árvore.
    novo_no->direita = NULL;
    novo_no->esquerda = NULL;
    if(raiz == NULL) raiz = novo_no; // Se a raiz ainda estiver como NULL, aplicamos o novo_no como sendo a raiz da árvore.
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

// FUNÇÃO RESPONSÁVEL POR REMOVER UM ÍTEM DA ÁRVORE.
bool remover(int valor_a_remover){
    if (raiz == NULL) return false; // Validação para verificar a situação do nó raiz da árvore.
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

// Caso encontrarmos um nó folha, teremos apagá-lo da árvore...
    if (no_atual->esquerda == NULL && no_atual->direita == NULL) {
      if (no_atual == raiz ) raiz = NULL;
      else if (filho_esquerda) pai_do_no->esquerda = NULL;
           else pai_do_no->direita = NULL;
    }

// Se é pai somente de elementos a esquerda, substituiremos pela sub árvore da direita.
    else if (no_atual->direita == NULL) {
       if (no_atual == raiz) raiz = no_atual->esquerda;
       else if (filho_esquerda) pai_do_no->esquerda = no_atual->esquerda;
            else pai_do_no->direita = no_atual->esquerda;
    }

// Se este nó for pai somente de elementos a direita, substituiremos pela sub árvore da esquerda.    
    else if (no_atual->esquerda == NULL) {
       if (no_atual == raiz) raiz = no_atual->direita;
       else if (filho_esquerda) pai_do_no->esquerda = no_atual->direita;
            else pai_do_no->direita = no_atual->direita;
    }

// Caso este nó possua um grau de parentesco maior em relação, então prosseguiremos com a seguinte situação.
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
       pai_do_proximo_a_ser_sucedido->esquerda = proximo_a_ser_sucedido->direita; // Ocorrência da herança de filhos de proximo_a_ser_sucedido
       proximo_a_ser_sucedido->direita = remove->direita;
     }
     return proximo_a_ser_sucedido;
  }
  
// FUNÇÃO RESPONSÁVEL POR EXIBIR OS ELEMENTOS INSERIDOS NA ÁRVORE
    public: void exibir_arvore() {
    cout << "\n\nEm Ordem:  "; // Exibição em ORDEM
    inOrder(raiz);
    cout << "\nPré-Ordem: "; // Exibição em PRÉ-ORDEM
    preOrder(raiz);
    cout << "\nPós-Ordem: "; // Exibição em PÓS-ORDEM
    posOrder(raiz);
    cout << "\n";
  }

  // Exibição em ORDEM
  private: void inOrder(NO *no_atual) {
    if (no_atual != NULL) {
      inOrder(no_atual->esquerda);
      cout << no_atual->item_do_no << "  |  ";
      inOrder(no_atual->direita);
    }
  }
  
  // Exibição em PRÉ-ORDEM
  private: void preOrder(NO *no_atual) {
    if (no_atual != NULL) {
      cout << no_atual->item_do_no << "  |  ";
      preOrder(no_atual->esquerda);
      preOrder(no_atual->direita);
    }
  }
  
  // Exibição em PÓS-ORDEM
  private: void posOrder(NO *no_atual) {
    if (no_atual != NULL) {
      posOrder(no_atual->esquerda);
      posOrder(no_atual->direita);
      cout << no_atual->item_do_no << "  |  ";
    }
  }

};

// FUNÇÃO PRINCIPAL DO CÓDIGO
int main() {
	
	setlocale(LC_ALL, "Portuguese");

    Arvore tree;
    int op, valor_a_inserir, valor_a_remover;

    do {
    	system("cls");
        cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
        cout << "\n|||||||||||||| ÀRVORE BINÁRIA ||||||||||||||||";
        cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
        cout << "\n                                         |||||";
        cout << "\nQual ação deseja fazer?                  |||||";
		cout << "\n1 - Inserir elemento na árvore           |||||";
		cout << "\n2 - Excluir elemento da árvore           |||||";
		cout << "\n3 - Exibir os elementos da árvore        |||||";
		cout << "\n4 - Sair do programa                     |||||";
		cout << "\n                                         |||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n";
		cin >> op;
		// O usuário escolhe o que deseja fazer.
		switch(op) {
			// Caso queira inserir elementos na árvore.
	 		case 1: {
	 			system("cls");
		       cout << "\nQual número você deseja inserir na árvore?  ";
		       cin >> valor_a_inserir; // Usuário diz o número que quer inserir na árvore.
		       tree.inserir(valor_a_inserir); // Chamamos a função responsável por inserir elementos na árvore, que está dentro da classe "Arvore", e passamos o valor dito pelo usuário como parâmetro.
		       system("cls");
		       break;
			}
			// Caso queira remover elementos na árvore.
			case 2: {
				system("cls");
		       cout << "\nQual número você deseja remover da árvore?";
		       cin >> valor_a_remover; // Guardamos o valor que o usuário quer excluir da árvore.
		       if ( !tree.remover(valor_a_remover) ) // chamamos a função que está dentro da classe "Arvore" e que é responsável por efetuar a exclusão do elemento dito pelo usuário. 
       	   	   	   cout << "\nEste valor não está inserido na árvore! Tente novamente com um valor válido."; // Se o valor não estiver na árvore, o programa exibe esta mensagem dizendo que o elemento não está inserido na árvore.				
				system("PAUSE");
		       break;
			}
			// Caso queira ver os elementos que tem na árvore. 
			case 3: {
				system("cls");
		      tree.exibir_arvore(); // Chamamos a função responsável por exibir os elementos e suas disposições dentro da árvore.
		      system("PAUSE");
		      break; 
			}
        }
	// Caso queira sair do programa.
    } while(op != 4);
}