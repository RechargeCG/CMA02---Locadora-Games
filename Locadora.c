#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 100

typedef struct
{
    char nome_cliente[tam],senha[tam],telefone[20],cpf[11],endereco[tam];
    int idade;
} Cliente;

typedef struct
{
    char nome_jogo[tam],genero[30];
    int quantidade;
    float preco;
} Jogo;

void receberjogos(int *c1, Jogo *biblioteca)
{
    *c1=0;

    char leitor[tam]; 
    FILE *jogos = fopen("jogos.txt","r");

    if(jogos==NULL)
    {
        jogos = fopen("jogos.txt","w");
        fclose(jogos);
        jogos = fopen("jogos.txt","r");
    }

    fgets(leitor,tam,jogos);

    if(jogos!=NULL&&strcmp(leitor,"")!=0)
    {
        fclose(jogos);
        jogos = fopen("jogos.txt","r");
        do
        {
            fgets(biblioteca[*c1].nome_jogo,tam,jogos);
            fgets(biblioteca[*c1].genero,tam,jogos);
            for(int cont=0;cont<tam;cont++)
            {
                if(biblioteca[*c1].nome_jogo[cont]=='\n')
                {
                    biblioteca[*c1].nome_jogo[cont]=NULL;
                }
                if(biblioteca[*c1].genero[cont]=='\n')
                {
                    biblioteca[*c1].genero[cont]=NULL;
                }
            }
            fgets(leitor,tam,jogos);
            biblioteca[*c1].quantidade=atoi(leitor);
            fgets(leitor,tam,jogos);
            biblioteca[*c1].preco=atof(leitor);

            (*c1)++;
        } while(fgets(leitor,tam,jogos)!=NULL);
        fclose(jogos);
    }
}

void receberclientes(int *c2,Cliente *cliente)
{
    *c2=0;

    char leitor[tam]; 
    FILE *listaclientes = fopen("clientes.txt","r");

    if(listaclientes==NULL)
    {
        listaclientes = fopen("clientes.txt","w");
        fclose(listaclientes);
        listaclientes = fopen("clientes.txt","r");
    }

    fgets(leitor,tam,listaclientes);

    if(leitor!=NULL&&strcmp(leitor,"")!=0)
    {
        fclose(listaclientes);
        listaclientes = fopen("clientes.txt","r");
        do
        {
            fgets(cliente[*c2].nome_cliente,tam,listaclientes);
            fgets(cliente[*c2].senha,tam,listaclientes);
            fgets(cliente[*c2].cpf,tam,listaclientes);
            fgets(cliente[*c2].endereco,tam,listaclientes);
            fgets(cliente[*c2].telefone,tam,listaclientes);
            for(int cont=0;cont<tam;cont++)
            {
                if(cliente[*c2].nome_cliente[cont]=='\n')
                {
                    cliente[*c2].nome_cliente[cont]=NULL;
                }
                if(cliente[*c2].senha[cont]=='\n')
                {
                    cliente[*c2].senha[cont]=NULL;
                }
                if(cliente[*c2].cpf[cont]=='\n')
                {
                    cliente[*c2].cpf[cont]=NULL;
                }
                if(cliente[*c2].endereco[cont]=='\n')
                {
                    cliente[*c2].endereco[cont]=NULL;
                }
                if(cliente[*c2].telefone[cont]=='\n')
                {
                    cliente[*c2].telefone[cont]=NULL;
                }
            }
            fgets(leitor,tam,listaclientes);
            cliente[*c2].idade=atoi(leitor);

            (*c2)++;
        } while(fgets(leitor,tam,listaclientes)!=NULL);
        fclose(listaclientes);
    }
}

void cadastrarcliente(int *c2,Cliente *cliente)
{
    do
    {
        system("cls");
        printf("Digite seu nome: ");
        gets(cliente[*c2].nome_cliente);
        fflush(stdin);
        printf("Digite sua senha: ");
        gets(cliente[*c2].senha);
        fflush(stdin);
        printf("Digite sua idade: ");
        scanf("%d",&cliente[*c2].idade);
        fflush(stdin);
        printf("Digite seu cpf: ");
        gets(cliente[*c2].cpf);
        fflush(stdin);
        printf("Digite seu telefone: ");
        gets(cliente[*c2].telefone);
        fflush(stdin);
        printf("Digite seu endereco: ");
        gets(cliente[*c2].endereco);
        fflush(stdin);
    } while(strcmp(cliente[*c2].nome_cliente,"")==0||strcmp(cliente[*c2].senha,"")==0||strcmp(cliente[*c2].cpf,"")==0||strcmp(cliente[*c2].telefone,"")==0||strcmp(cliente[*c2].endereco,"")==0);
    
    

    char aux[tam]="";

    FILE *listaclientes = fopen("clientes.txt","r");

    fgets(aux,tam,listaclientes);

    if(strcmp(aux,"")>0)
    {
        puts(aux);
        system("pause");
        fclose(listaclientes);
        listaclientes = fopen("clientes.txt","a");
        fputs("\n---\n",listaclientes);
        fclose(listaclientes);
    }
    listaclientes = fopen("clientes.txt","a");

    strcpy(aux,cliente[*c2].nome_cliente);
    fputs(aux,listaclientes);
    fputs("\n",listaclientes);
    strcpy(aux,cliente[*c2].senha);
    fputs(aux,listaclientes);
    fputs("\n",listaclientes);
    itoa(cliente[*c2].idade,aux,10);
    fputs(aux,listaclientes);
    fputs("\n",listaclientes);
    strcpy(aux,cliente[*c2].cpf);
    fputs(aux,listaclientes);
    fputs("\n",listaclientes);
    strcpy(aux,cliente[*c2].telefone);
    fputs(aux,listaclientes);
    fputs("\n",listaclientes);
    strcpy(aux,cliente[*c2].endereco);
    fputs(aux,listaclientes);

    fclose(listaclientes);

    (*c2)++;

    receberclientes(&c2,cliente);
}

void reescrever(int tamanho, Jogo *biblioteca, int *c1)
{
    char aux[tam]="";
    FILE *jogos = fopen("jogos.txt","w");
    
    for(int contador=0;contador<tamanho;contador++)
    {
        strcpy(aux,biblioteca[contador].nome_jogo);
        fputs(aux,jogos);
        fputs("\n",jogos);
        strcpy(aux,biblioteca[contador].genero);
        fputs(aux,jogos);
        fputs("\n",jogos);
        itoa(biblioteca[contador].quantidade,aux,10);
        fputs(aux,jogos);
        fputs("\n",jogos);
        gcvt(biblioteca[contador].preco,5,aux);
        fputs(aux,jogos);
        if(contador<tamanho-1) fputs("\n---\n",jogos);
    }

    fclose(jogos);

    receberjogos(&c1,biblioteca);
}

void inserir(int *c1, Jogo *biblioteca)
{
    do
    {
        system("cls");
        printf("Digite o nome do jogo: ");
        gets(biblioteca[*c1].nome_jogo);
        fflush(stdin);
        printf("Digite o genero do jogo: ");
        gets(biblioteca[*c1].genero);
        fflush(stdin);
        printf("Digite a quantidade do jogo: ");
        scanf("%d",&biblioteca[*c1].quantidade);
        fflush(stdin);
        printf("Digite o preco do jogo: ");
        scanf("%f",&biblioteca[*c1].preco);
        fflush(stdin);
    } while (strcmp(biblioteca[*c1].nome_jogo,"")==0||strcmp(biblioteca[*c1].genero,"")==0);
    
    char aux[tam]="";

    FILE *jogos = fopen("jogos.txt","r");

    fgets(aux,tam,jogos);

    if(strcmp(aux,"")>0)
    {
        fclose(jogos);
        jogos = fopen("jogos.txt","a");
        fputs("\n---\n",jogos);
        fclose(jogos);
    }
    jogos = fopen("jogos.txt","a");
    strcpy(aux,biblioteca[*c1].nome_jogo);
    fputs(aux,jogos);
    fputs("\n",jogos);
    strcpy(aux,biblioteca[*c1].genero);
    fputs(aux,jogos);
    fputs("\n",jogos);
    itoa(biblioteca[*c1].quantidade,aux,10);
    fputs(aux,jogos);
    fputs("\n",jogos);
    gcvt(biblioteca[*c1].preco,5,aux);
    fputs(aux,jogos);

    fclose(jogos);

    (*c1)++;
}

void exibir(int c1, Jogo *biblioteca)
{
    for(int cont=0;cont<c1;cont++)
    {
        printf("Nome: %s\n",biblioteca[cont].nome_jogo);
        printf("Genero: %s\n",biblioteca[cont].genero);
        printf("Quantidade: %d\n",biblioteca[cont].quantidade);
        printf("Preco: R$%.2f\n\n",biblioteca[cont].preco);
    }
}

int main()
{
    Cliente cliente[tam];
    Jogo biblioteca[tam];
    int c1=0,c2=0,opcao=-1;
    char leitor[tam]="";

    receberjogos(&c1,biblioteca);
    receberclientes(&c2,cliente);

    while (opcao!=0)
    {
        printf("Menu\n\nEntrada do usuario:\n1- Administrador\n2- Cliente\n\nOpcao: ");
        scanf("%d",&opcao);
        fflush(stdin);

        printf("\n");

        if(opcao==1)
        {
            char senha[10];
            printf("Digite a senha: ");
            scanf("%s",&senha);
            fflush(stdin);

            if(strcmp("123",senha)==0)
            {
                while (opcao!=3)
                {
                    system("cls");
                    printf("ADM Menu:\n\n1- Inserir jogos\n2- Visualizar jogos\n3- Sair\n0- Encerrar sistema:\n\nOpcao: ");
                    scanf("%d",&opcao);
                    fflush(stdin);
                    printf("\n");
                    if(opcao==1)
                    {
                        system("cls");
                        inserir(&c1,biblioteca);
                    }
                    else if(opcao==2)
                    {
                        system("cls");
                        exibir(c1,biblioteca);
                        system("pause");
                    }
                    else if(opcao==0)
                    {
                        system("cls");
                        break;
                    }
                }
            }
            else
            {
                system("cls");
                printf("Senha invalida.\n\n");
            }

            system("pause");
            system("cls");
        }
        else if(opcao==2)
        {
            system("cls");

            char senha[tam]="",aux[tam]="";
            bool logado=false;

            printf("Cliente Menu:\n\n1- Login\n2- Cadastro\n3- Sair\n\nOpcao: ");
            scanf("%d",&opcao);
            fflush(stdin);
            printf("\n");

            if(opcao==1)
            {
                system("cls");
                printf("Digite seu nome: ");
                gets(leitor);
                printf("Digite sua senha: ");
                gets(senha);

                FILE *listaclientes = fopen("clientes.txt","r");

                while(fgets(aux,tam,listaclientes))
                {
                    for(int cont=0;cont<tam;cont++)
                    {
                        if(aux[cont]=='\n')
                        {
                            aux[cont]=NULL;
                        }
                    }
                    if(strcmp(aux,leitor)==0)
                    {
                        fgets(aux,tam,listaclientes);
                        for(int cont=0;cont<tam;cont++)
                        {
                            if(aux[cont]=='\n')
                            {
                                aux[cont]=NULL;
                            }
                        }
                        if(strcmp(aux,senha)==0)
                        {
                            logado=true;
                            break;
                        }
                        else
                        {
                            fgets(aux,tam,listaclientes);
                            fgets(aux,tam,listaclientes);
                            fgets(aux,tam,listaclientes);
                            fgets(aux,tam,listaclientes);
                            fgets(aux,tam,listaclientes);
                        }
                    }
                    else
                    {
                        fgets(aux,tam,listaclientes);
                        fgets(aux,tam,listaclientes);
                        fgets(aux,tam,listaclientes);
                        fgets(aux,tam,listaclientes);
                        fgets(aux,tam,listaclientes);
                        fgets(aux,tam,listaclientes);
                    }
                }

                fclose(listaclientes);

                if(logado==true)
                {
                    while (opcao!=3)
                    {
                        system("cls");
                        printf("Cliente Menu:\n\n1- Visualizar jogos\n2- Efetuar compra\n3- Sair\n\nOpcao: ");
                        scanf("%d",&opcao);
                        fflush(stdin);
                        printf("\n");

                        if(opcao==1)
                        {
                            system("cls");
                            exibir(c1,biblioteca);
                            system("pause");
                        }
                        else if(opcao==2)
                        {
                            system("cls");
                            printf("Digite o nome do jogo: ");
                            gets(leitor);
                            fflush(stdin);

                            for(int cont=0;cont<c1;cont++)
                            {
                                if(strcmp(biblioteca[cont].nome_jogo,leitor)==0)
                                {
                                    if(biblioteca[cont].quantidade>0)
                                    {
                                        printf("\nConfirmar compra? (S/N): ");
                                        scanf("%c",&opcao);
                                        fflush(stdin);
                                        if(opcao=='s'||opcao=='S')
                                        {
                                            printf("\nObrigado pela compra!\n");
                                            biblioteca[cont].quantidade--;
                                            reescrever(c1,biblioteca,&c1);
                                            system("pause");
                                        }
                                    }
                                    else
                                    {
                                        printf("\nJogo esgotado\n");
                                        system("pause");
                                    }
                                }
                            }
                        }
                        else if(opcao==3)
                        {
                            logado=false;
                        }
                    }
                }
                else
                {
                    printf("\nLogin nao encontrado\n\n");
                }
            }
            if(opcao==2)
            {
                cadastrarcliente(&c2,cliente);
            }
            system("pause");
            system("cls");
        }
        else if(opcao!=0)
        {
            printf("Opcao invalida.\n\n");
            system("pause");
            system("cls");
        }
    }
    
    return 0;
}