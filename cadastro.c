#include <stdio.h> // Biblioteca padrão para entrada e saída de dados
#include <stdlib.h> // Biblioteca contendo funções para uso geral
#include <locale.h> // Biblioteca que permite a inserção da função setlocale no programa, o que permitirá adaptar a linguagem para Português
typedef struct //Struct definida para armazenar as informações do produto nos vetores nome, código e valor
{
 char nome[40];
 char codigo[10];
 char valor[10];
} dados; //Nome da definição da struct
int main() // Função principal
{
 setlocale(LC_ALL,"Portuguese"); /* Função que fará com que o programa seja adaptado ao idioma português, fazendo com que sejam aceitos caracteres especiais e acentuação
 nos comentários e nos códigos do programa. Para que a função funcione no Visu-al Studio Code, é necessário ir no canto inferior direito do programa, clicar em "UTF-8",
 em seguida em "Reabrir com codificação" e clicar em "Western (ISO 8859-
1)", feito isso, basta apertar Ctrl + Z caso necessário */
 
 
 
 int x; //Variável auxiliar para a estrutura de repetição "for"
 FILE *file = fopen("3561327.csv", "w"); //Criando o arquivo cujo nome é o número do meu RU
 dados registro; //Nome da struct
 for (x=1; x <= 6; x++) //Estrutura de repetição "for" que fará com que as solicitações de cadastro parem ao serem cadastrados 6 produtos
 {
 if (file == NULL) //Testando se há algum erro na abertura do arquivo, caso haja algum erro, o programa será interrompido
 {
 printf("Erro ao abrir o arquivo\n");
 system("pause");
 exit(1);
 }
 
 //Mensagem que será exibida em cada cadastro para que o usuário saiba em qual cadastro estão sendo inseridos os dados
 printf("\nCadastre o %iº produto\n\n", x);
 
 //Dados que serão solicitados ao usuário. Após serem digitados, os dados serão armazenados em cada variável da struct de acordo com o cadastro
 printf("Digite o nome do produto: ");
 gets(registro.nome);
 
 printf("Digite o código do produto: ");
 scanf("%s", &registro.codigo);
 
 printf("Digite o valor do produto: ");
 scanf("%s", &registro.valor);
 
 setbuf(stdin, NULL); // Limpeza do buffer do teclado
 
 //Confirmação dos dados digitados pelo usuário ao final de cada cadastro
 printf("\n=====DADOS DO PRODUTO CADASTRADO=====\n");
 printf("\nNome: %s", registro.nome);
 printf("\nCódigo: %s", registro.codigo);
 printf("\nValor:R$ %s\n", registro.valor);
 
 //Impressão dos dados digitados pelo usuário no arquivo .csv. O ponto e vírgula (;) será usado para separador e campo
 fprintf(file, "Nome: %s;", registro.nome);
 fprintf(file, "Código: %s;", registro.codigo);
 fprintf(file, "Valor: R$ %s\n", registro.valor);
 }
 
 fclose(file); //Função que irá efetuar o fechamento do arquivo
 
 return 0;
}
