#include <stdio.h>
#include <string.h>

#define MAX_PRODUTO 300

typedef struct{
  char nome[50];
  int quantidade;
  int id;
} Produto;

void cadastroProduto(Produto *produtos, int *qtt){

  getchar();
  printf("Digite o nome do produto: ");
  fgets(produtos[*qtt].nome, sizeof(produtos[*qtt].nome), stdin);
  produtos[*qtt].nome[strcspn(produtos[*qtt].nome, "\n")] = '\0';

  printf("Digite a quantidade de entrada: ");
  scanf("%d", &produtos[*qtt].quantidade);

  produtos[*qtt].id = *qtt + 1;
  (*qtt)++;
}

void visualizarProdutos(Produto produtos[], int qtt){

  for(int i = 0; i < qtt; i++){
    printf("ID: %d | Nome: %s | Quantidade: %d", produtos[i].id, produtos[i].nome, produtos[i].quantidade);
    printf("\n");
  }
}

void saidaProduto(Produto produtos[], int qtt){
  int id, saida;
  printf("Digite o ID do produto para registrar saida: ");
  scanf("%d", &id);
  for(int i = 0; i < qtt; i++){
    if(id == i+1){
      printf("Digite a quantidade de saida: ");
      scanf("%d", &saida);

      produtos[i].quantidade -= saida;
    }
  }
}

void entradaProduto(Produto produtos[], int qtt){
  int id, entrada;
  printf("Digite o ID do produto para registrar entrada: ");
  scanf("%d", &id);
  for(int i = 0; i < qtt; i++){
    if(id == i+1){
      printf("Digite a quantidade de entrada: ");
      scanf("%d", &entrada);

      produtos[i].quantidade += entrada;
    }
  }
}

void alterarNome(Produto produtos[], int qtt){
  int id;
  printf("Digite o ID do produto para alterar o nome: ");
  scanf("%d", &id);
  for(int i = 0; i < qtt; i++){
    if(id == i+1){
      printf("Digite o novo nome para o produto: ");
      getchar();
      fgets(produtos[i].nome,sizeof(produtos[i].nome), stdin);
      produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
    }
  }
}

// void ordenarQuantidade(Produto produtos[], int qtt){
//   Produto aux;
//   for(int i = 0; i < qtt; i++){
//     for(int j = i + 1; j < qtt; j++){
//       if(produtos[i].quantidade > produtos[j].quantidade) {
//         aux = produtos[i];
//         produtos[i] = produtos[j];
//         produtos[j] = aux;
//       }
//     }
//   }

//   for(int i = 0; i < qtt; i++){
//     printf("ID: %d | Nome: %s | Quantidade: %d", produtos[i].id, produtos[i].nome, produtos[i].quantidade);
//     printf("\n");
//   }

// }

int main(){

Produto produtos[MAX_PRODUTO];

int op,
    tam = 0;

do{

  printf("1- Cadastrar Produto\n2- Visualizar Produtos\n3- Saida de Produto\n4- Entrada de Produto \n5- Alterar nome do produto\n6- Sair\n");
  printf("Escolha a opcao desejada: "); 

    scanf("%d", &op);

    switch(op){
      case 1:
        cadastroProduto(produtos, &tam);
        break;
      case 2:
        visualizarProdutos(produtos,tam);
        break;
      case 3:
        saidaProduto(produtos, tam);
        break;
      case 4:
        entradaProduto(produtos, tam);
        break;
      case 5:
        alterarNome(produtos, tam);
        break;
      // case 6:
      //   ordenarQuantidade(produtos, tam);
      //   break;
    }

}while(op <= 5);

  return 0;
}