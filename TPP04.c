#include <stdio.h>		// Trabalho Feito por:  
#include <stdlib.h>		//Luciano Carlos Simeão Junior
#include <ctype.h>		//Matheus Henrique Patrizi
#include <math.h>       			
#include <locale.h>         //Para definir regiao da escrita e utilizar a funcao setlocale
#define euller 2.7182818284	//Constante de Euller Para o Fatorial de Stirling com 10 casas decimais
#define PULA  "\n\n\n"

int Menu(void);                                 //Protótipos das Funções
short Continua(void);                          
int Menu(void);
int Primo(int n);
void Golbach(void);
void PrimosIntervalo(void);
void PrimosGemeos(void);
void MersenePrimos(void);
int NumerosFelizes(int n);
double FatorialStirling(int n); 



int Primo(int n){ 			//Se n for igual a 2 retorna que o numero eh primo                                        
    int i;					//se ele for par e nao for dois vai retornar que nao eh primo
    if(n==2)				//se ele for impar no for ira iniciar a verificacao da primalidade
        return(1);
    if(n%2==0) return (0);
    for(i=3;i<n;i=i+2){	
        if(n%i==0) return 0;//se for divisivel em algum momento, ele nao eh primo
    }
    return 1; 				//se nao dividir em nenhum momento, ira chegar ate aqui significando
}							//que o numero nao eh primo


int Menu(void) {
int opcao;

  system("CLS");		                
  printf("                         BEM VINDO AO MENU TEXTUAL\n\n");	 
  printf("  ||   1 - Executar o Código de Golbach Para Os Números Entre 4 e 1000 \n");
  printf("  ||   2 - Encontrar Todos Os Primos Em Um Intervalo \n");
  printf("  ||   3 - Encontrar Todos Os Primos Gêmeos Em Um Intervalo \n");
  printf("  ||   4 - Encontrar Os Primos de Mersene Entre 1 e 30 \n");
  printf("  ||   5 - Encontrar Todos os Números Felizes entre 4 e Mil \n");
  printf("  ||   6 - Fatorial de Stirling \n");
  
  
  printf("\n\n Escolha a opcao desejada : ");
  scanf("%d", &opcao);
  
  return(opcao);
}


short Continua(void) {
int ch;

  do {
		system("cls");//limpa a tela
        printf("\n\n\n      Voce deseja executar outra funcao? [S,N] : ");
		ch = getchar();//recebe o caractere inserido pelo usuario
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );	//vai retornar 1 ou 0, de acordo com o que o usuario
										//digitar, e caso seja 1 vai continuar, caso contrario 
  if(ch == 'S') return(1);				//ira encerrar a execucao
  else return(0);
}



int main(void) {
int a, b, op = 0,p1=5,p2=1000,i,f;
setlocale(LC_ALL,"Portuguese");//Define a localidade da escrita para o Brasil
 do {
	op = Menu();
	system("cls");
	printf("\n\n Opcao escolhida foi: %d\n\n", op);
	system("Pause"); 
	
    switch(op)  {
	case 1:
		 printf("Golbach Para o Intervalo Entre 4 e 1000 \n\n\n");
       			Golbach();
		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: GOLBACH.\n\n");
         system("Pause");
         break;

	case 2:
		 printf("Números Primos Em Um Intervalo \n\n\n");	
		 PrimosIntervalo();
		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: NÚMEROS PRIMOS EM UM INTERVALO.\n\n");
		 system("Pause");
         break;

	case 3:
		 printf("Números Primos Gêmeos Em Um Intervalo \n\n\n");
		 PrimosGemeos();
		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: NÚMEROS PRIMOS GÊMEOS EM UM INTERVALO.\n\n");
		 system("Pause");
		 break;

	case 4:
		 printf("Números de Mersene Primos \n\n\n");
		 MersenePrimos();
		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: NÚMEROS DE MERSENE PRIMOS.\n\n");
		 system("Pause");
		 break;

	case 5:
		 printf("Números Felizes Entre 4 e 1000");
    		for(i=p1;i<=p2;i++){
        		if(NumerosFelizes(i)){
        		    printf("%i \n",i);
        		}
   		 }
   		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: NÚMEROS FELIZES ENTRE 4 E 1000.\n\n");
   		 system("pause");
		 break;

	case 6:
		 printf("Fatorial de Stirling Para Determinado Número \n\n\n");
		 printf("Insira o valor: \n");
		 scanf("%i",&f);
		 printf("\n\n %lf \n",FatorialStirling(f));
		 printf("\n\n VOCÊ ACABOU DE EXECUTAR A FUNÇÃO: FATORIAL DE STIRLING.\n\n");
		 system("pause");
		 break;

	}	

  } while ( Continua() );
 printf("\n\n OBRIGADO POR USAR O CÓDIGO!!! :)");
 printf(PULA);		//esses switches sao responsaveis por chamar as funcoes necessarias de acordo
 system("Pause");	//com o caratere inserido pelo usuario
 return(0);			//testa-se o valor de retorno da funcao continua, que retorna 0 ou 1, afim de
					//saber se o usuario deseja continuar a execucao do programa
} 


void Golbach(void){
	int n1,n2,n;
    		for(n=4;n<=1000;n=n+2){	       //A função verifica de 4 ate 1000 enquanto a soma dos dois 
    			n1=1; n2=2;                //numeros que serao verificados a primalidade (n1 e n2).
    		while(n1+n2<n && n1<=n/2){     //Também verifica se a soma deles resulta no valor par cujo
        		n1++;					   //se deseja verificar os dois primos que resultam nele
        		while(n1+n2<=n && n1<=n/2){ // <---- Verifica se a soma resulta em n, e se n1 eh
        		if (Primo(n1) && Primo(n2)){ //menor ou igual a n/2 (primeira metade de divisores)
               		 if(n1+n2==n) printf(" %i = %i  %i \n",n,n1,n2);
                		n2++;
              		}
              		else n2++;
            		}
            		n2=2;
    		}
		}
		return;
}

void PrimosIntervalo(void){
	int a,b,i;
			printf("Insira o primeiro valor: \n");//Recebe o primeiro delimitador do intervalo
			scanf("%i",&a);
			printf("Insira o segundo valor: \n");//Recebe o segundo numero delimitador do intervalo
			scanf("%i",&b);
			for(i=a;i<=b;i++){	//Vai verificar a primalidade dos numeros dentro do intervalo
				if(Primo(i)) printf("%i \n\n",i);//inserido
			}
}

void PrimosGemeos(void){
	int i,i1,i2,a,b;
			printf("Insira o primeiro valor: \n");//Recebe o primeiro valor que delimita o intervalo
			scanf("%i",&a);
			printf("Insira o segundo valor: \n");//Recebe o segundo valor delimitador
			scanf("%i",&b);
			for(i=a;i<=b-2;i++){ //Varia o numero dentro do intervalo inserido
				i1=i;
				i2=i1+2;
				if (Primo(i1) && Primo(i2)) //Verifica se são primos gemeos (Primo(i2), com i2==i1+2
					printf("%i  %i \n\n",i1,i2);
			}
}

void MersenePrimos(void){
	int i,m;
	for(i=1;i<=30;i++){		//Varia o numero de 1 ate 30
		m=pow(2,i)-1;		//calcula o numero de mersene
		if(Primo(m)) printf("%i \n",m);//verifica se eh primo
	}
	return;
}

int NumerosFelizes(int n){
	int soma=0,d=0,m=n;
    while(m!=0){		 //Esse while extrai os digitos do numero, os eleva ao quadrado e soma,
        d=m%10;			 //e passa isso para a parte recursiva da função, que possui os casos bases
        soma=soma+(d*d); //para 1, caso seja um numero feliz, para 4, nesse caso sera um numero triste
        m=m/10;			 //e caso volte no valor inicial significa que isso ira ficar em um loop, logo
        }				 //nao teria sentido mante-lo assim. Caso seja um numero diferente, sera
        if(soma==1){	 //chamada a propria funcao novamente, passando o valor obtido no while
            return(1);	 //como parametro
        }
        else if(soma==4 || soma==n){
            return(0);
        }
            else{
                NumerosFelizes(soma);
            }
}

double FatorialStirling(int n){	//A funcao recebe um inteiro inserido pelo usuario como parametro
	double fatorial=0;			//calcula-se pela formula de stirling o valor aproximado
	fatorial = sqrt(2.0 * euller) * pow(((double)n/euller),n);//do fatorial do numero.
	return (fatorial);
}
