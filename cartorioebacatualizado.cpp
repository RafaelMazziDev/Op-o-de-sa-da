#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
    //início criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usário
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file, "cpf"); // salva o valor da variável
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "-");   // separador
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "-");   // outro separador
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "sobrenome"); // salva o texto "sobrenome"
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo); // salva o valor digitado para cargo
    fclose(file);

    return 0;
}

void consulta()
{
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // abre o arquivo com o nome do CPF

    if (file == NULL) {
        printf("CPF não encontrado!\n");
    } else {
        printf("\n=== Dados do CPF %s ===\n", cpf);
        while (fgets(conteudo, 200, file) != NULL) {
            printf("%s", conteudo); // imprime o conteúdo do arquivo
        }
        fclose(file);
    }
    
    system("pause"); // pausa para o usuário ver o resultado
}

void deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
    
}

int main() {
    setlocale(LC_ALL, "portuguese");
    
    int opcao = 0;
    
    do {
        printf("\n### Cartório da EBAC ###\n"); //início do menu
        printf("1 - Registrar nomes\n");
        printf("2 - Consultar nomes\n");
        printf("3 - Deletar nomes\n");
        printf("4 - Sair do sistema4\n");
        printf("Escolha uma opção: "); //fim do menu
        scanf("%d", &opcao); //armazenando a escolha do usuário

        switch (opcao) //inicio da seleção do menu
        {
        case 1:
            registro(); //chamada de funções
            break;
        case 2:
            consulta();
            break;
        case 3:
            deletar();
            break;
        case 4:
            printf("Obrigado por utilizar o sistema!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        } //fim da seleção
    } while (opcao != 0);
    
    return 0;
}
