#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "interfaceUsuario.h" //Declaracao de subrotina Interface de Usuario.
#define QTDECORRENTISTA 1000  //Numero maximo de contas que podem ser cadastradas


//Struct para cadastro de clientes
struct Tipo_Endereco{
  char sRua [50];
  int  iNum;
  char sBairro [30];
  char sCidade [30];
  char sEstado [3];
} ;

struct Tipo_ContaCorrente{
  int iContaCorrente;
  char sNome [50];
  struct Tipo_Endereco stcEndereco;
  char sMail [50];
} ;

int cadastrarContaCorrent(int iQtdeCC);
void listarContaCorrente (int iQtdeCC);
void impUmaCC(int i);
int excluirContaCorrente(int iQtdeCC);
void excluirCC(int i,int iQtdeCC);

//Clientes para testes:
struct Tipo_ContaCorrente cadConta[QTDECORRENTISTA]=
    {{111,"Carlos da Silva", {"R.Mal.Deodoro",321,"Centro","Curitiba","PR"},
    "carlos@Gmail.com"},
    {222,"Marcos da Silva", {"R.Vic.Machado",333,"Batel","Curitiba","PR"},
    "marcos@gmail.com"},
	{333,"jose da Silva", {"R.luiz Tramontin",2340,"Campo Comprido","Curitiba","PR"},
    "jose@gmail.com"}};
    
//Fim das definicoes de testes;    
    
int main(){
  
  int iOpcao=1;
  int iQtdeCC=3;
  while (iOpcao != 4){
  	
   MenuPrincipal();
   scanf("%d",& iOpcao);
   system("cls");
  
  	if(iOpcao){ 		
  		switch (iOpcao){
  			case 1:
  				iQtdeCC = cadastrarContaCorrent(iQtdeCC);			
  				getch();
  				system("cls");
  				break;
  			case 2:
  				ListaCC();
  				printf("\n%d - Contas Cadastradas\n",iQtdeCC);
  				listarContaCorrente(iQtdeCC);
  				printf("\n\nAperte qualquer tecla para continuar");
  				getche();
  				system("cls");
  				break;
  			case 3:  				
  			    iQtdeCC = excluirContaCorrente(iQtdeCC);
  				getch();
  				system("cls");
  				break;
  			default:
			  if (iOpcao != 4){
			  	printf("\n\nOpcao Invalida\n\n");
			    getch();
			  }
  	      } 
  	  }
  }  
  system("pause");
}

int cadastrarContaCorrent(int iQtdeCC){
	int iConta, i, iExist;
	CadastroCC();
	fflush(stdin);
	scanf("%d",&iConta);
	
	while(iConta !=0 && iQtdeCC < QTDECORRENTISTA){
		
		if(iConta<=100){ //Tratamento de execao para numero de conta menor que 100.
			printf("\nNumero da conta corrente deve ser maior que 100\n");
			printf("\nEntre com um novo Numero de Conta:");			
		}
		else{
			iExist = 0;
			for(i=0; i<iQtdeCC; i++){
				if(cadConta[i].iContaCorrente == iConta){ //Tratamento de execao para numero de conta ja existente.
					printf("\nConta Corrente %d ja existente!\n",iConta);
					printf("\nEntre com um novo Numero de Conta:");
					iExist = 1;			
				}
			}
			if(!iExist){
				i=iQtdeCC;
				cadConta[i].iContaCorrente = iConta;
				fflush(stdin);
				printf("Informe o Nome do Correntista:");
				gets(cadConta[i].sNome);
				fflush(stdin);
				printf("Endereco - Informe a Rua:");
				gets(cadConta[i].stcEndereco.sRua);
				printf("Endereco - Informe o Numero do Imovel:");
				scanf("%d",&cadConta[i].stcEndereco.iNum);
				fflush(stdin);
				printf("Endereco - Informe o Bairro:");
				gets(cadConta[i].stcEndereco.sBairro);
				fflush(stdin);
				printf("Endereco - Informe o Cidade:");
				gets(cadConta[i].stcEndereco.sCidade);
				fflush(stdin);
				printf("Endereco - Informe o Estado:");
				gets(cadConta[i].stcEndereco.sEstado);
				fflush(stdin);
				printf("Informe o e-mail:");
				gets(cadConta[i].sMail);
				printf("\nConta Cadastrada\n");
				iQtdeCC++;
				if(iQtdeCC == QTDECORRENTISTA){ //Tratamento de execao para numero maximo de contas excedida.
					printf("\n\nNumero maximo de contas cadastradas.\n\n");
				}
				else{
					printf("\n\n==> Informe Numero da nova Conta:");
				}										
			}			
		}
		if(iQtdeCC < QTDECORRENTISTA){
			fflush(stdin);
	        scanf("%d",&iConta);
		}
	}
	return iQtdeCC;
}

//Subrotina de listagem de conta corrente utilizando recursividade.
void listarContaCorrente(int iQtdeCC){
	if(iQtdeCC>1){
		listarContaCorrente(iQtdeCC-1);
	}
	impUmaCC(iQtdeCC-1);
}

void impUmaCC(int i){
	printf("\n\n==>Numero Conta Corrente %d",cadConta[i].iContaCorrente);
	printf("\nNome do Correntista: %s",cadConta[i].sNome);
	printf("\nEndereco-Rua: %s",cadConta[i].stcEndereco.sRua);
	printf("\nEndereco-Numero do Imovel: %d",cadConta[i].stcEndereco.iNum);
	printf("\nEndereco-Bairro: %s",cadConta[i].stcEndereco.sBairro);
    printf("\nEndereco-Cidade: %s",cadConta[i].stcEndereco.sCidade);
	printf("\nEndereco-Estado: %s",cadConta[i].stcEndereco.sEstado);
	printf("\nE-mail do Correntista %s",cadConta[i].sMail);
}

int excluirContaCorrente(int iQtdeCC){
	int iConta, i, iAchou;
	char cRes;
	ExcluirCC();	
	fflush(stdin);
	printf("\n==> Informe Numero da Conta a ser excluida:");
	scanf("%d",&iConta);
	while(iConta !=0 && iQtdeCC <= QTDECORRENTISTA){
		iAchou = 0;
		for(i=0;i<=iQtdeCC;i++){
			if(cadConta[i].iContaCorrente == iConta){				
				iAchou=1;
				impUmaCC(i);
				printf("\n\nConfirmar exclusao (S/N):"); //Criterio para CONCLUSAO ou DESISTENCIA de exclusao de conta.
				fflush(stdin);
				cRes=getche();
				if(cRes == 'S' || cRes == 's'){
					excluirCC(i,iQtdeCC);
					iQtdeCC--;
					system("cls");
					printf("\n\nConta Corrente %d excluida com sucesso!\n\n\n",iConta); // Mensagem de CONCLUSAO de exclusao da conta.
					system("pause");
					system("cls");														
				}				
				else{
					if(cRes == 'N' || cRes == 'n'){
						system("cls");
						printf("\n\nConta Corrente %d NAO EXCLUIDA!\n",iConta);  // Mensagem de DESISTENCIA de exclusao da conta.
						system("pause");
						system("cls");                   						
					}
				}								
			}				    
		}
        if(!iAchou){ //Tratamento de excecao para conta corrente nao encontrada
            system("cls");
            printf("\n\nConta Corrente %d NAO ENCONTRADA!\n",iConta);
			system("pause");
			system("cls");	
        }
        ExcluirCC();
		printf("\n==> Informe Numero da Conta a ser excluida:");
		scanf("%d",&iConta);
    }
    return iQtdeCC;
}

void excluirCC(int i,int iQtdeCC){
	for(;i<iQtdeCC;i++){
		cadConta[i].iContaCorrente = cadConta[i+1].iContaCorrente;
		cadConta[i].stcEndereco.iNum = cadConta[i+1].stcEndereco.iNum;
		strcpy(cadConta[i].sNome, cadConta[i+1].sNome);
	    strcpy(cadConta[i].stcEndereco.sRua, cadConta[i+1].stcEndereco.sRua);
	    strcpy(cadConta[i].stcEndereco.sBairro, cadConta[i+1].stcEndereco.sBairro);
	    strcpy(cadConta[i].stcEndereco.sCidade, cadConta[i+1].stcEndereco.sCidade);
	    strcpy(cadConta[i].stcEndereco.sEstado, cadConta[i+1].stcEndereco.sEstado);
	    strcpy(cadConta[i].sMail, cadConta[i+1].sMail);
	}
}
