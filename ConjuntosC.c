#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	system("COLOR 0a");
	int vetA[100], vetB[100], vetC[200];
	int opcao, item, i, j, encontrado = 0, indiceA = 0, indiceB = 0, indiceC = 0, repetido = 0;
	char AouB;

	do{
		printf ("1. Inserir os valores\n");

	    printf ("2. Limpar vetor\n");

	    printf ("3. Imprimir os valores\n");

	    printf ("4. Uni�o dos vetores\n");

	    printf ("5. Intersec��o dos vetores\n");

	    printf ("6. Diferen�a de vetores\n");

	    printf ("7. Contido\n");

	    printf ("0 ou outro caractere para Sair\n");

	    printf ("Digite a op��o desejada: ");
	    scanf ("%d", &opcao);
	    system("clear||@cls"); // Limpa a tela ap�s escolha no menu

	    if(opcao == 1){ // Op��o 1.
	    	printf ("Escolha A ou B: ");
			scanf ("\n%c", &AouB);
			// Inicio vetor A.
			if (AouB == 'A' || AouB == 'a'){
				if (indiceA < 100){ // Checagem para ver se o vetor est� cheio.
	    			do{
	    				printf ("Insira o item #%d: ", indiceA+1); // Inser��o de valores dentro do vetor.
	    				scanf ("%d", &item);
	    				for (i = 0; i < indiceA; i++){ // Enquanto o contador for menor que o valor do vetor.
	    					if (item == vetA[i]){ // Se o item inseido for igual ao valor do vetor.
	    						repetido = 1; // O numero repetido vai ser verdadeiro.
	    						printf ("N�o podem ser inseridos valores repetidos.\n");
	    						break;
	    					}
	    				}
	    				if (item != 0 && repetido == 0){ // Checando.
	    					vetA[indiceA] = item;
	    					indiceA++;
	    				}// Fim if.
	    				repetido = 0; // Zerando o contador de A novamente.


	    			}while (item != 0); // Condi��o de parada � o zero.
				}else{
					printf ("O vetor A est� cheio!\n"); // Se o vetor estiver cheio ele n�o entrar� no looping e mostrar� esta mensagem.
				}
			}else if (AouB == 'B' || AouB == 'b'){
				if (indiceB < 100){
					do{
	    				printf ("Insira o item #%d: ", indiceB+1); // Inser��o de valores dentro do vetor.
	    				scanf ("%d", &item);
	    				for (i = 0; i < indiceB; i++){
	    					if (item == vetB[i]){ // Se o item inseido for igual ao valor do vetor.
	    						repetido = 1; // O numero repetido vai ser verdadeiro.
	    						printf ("N�o podem ser inseridos valores repetidos.\n");
	    						break;
	    					}
	    				}
	    				if (item != 0 && repetido == 0){ // Checando.
	    					vetB[indiceB] = item;
	    					indiceB++;
	    				}// Fim if B.
	    				repetido = 0; // Zerando o contador de B novamente.

	    			}while (item != 0);
				}else{
					printf ("O vetor B est� cheio!\n"); // Se o vetor estiver cheio ele n�o entrar� no looping e mostrar� esta mensagem.
				}
			}else{
				printf("Escolha inv�lida!\n");
			}
		}else if(opcao == 2){ // Op��o 2.
			printf("Escolha A ou B: "); // Escolher vetor para zerar.
			scanf("\n%c", &AouB);
			if(AouB == 'A' || AouB == 'a'){
				indiceA = 0; // Ao retornar o indice para 0, o vetor esta virtualmente vazio.
				printf("Vetor A limpo.\n");
			}else if(AouB == 'B' || AouB == 'b'){
				indiceB = 0;
				printf("Vetor B limpo.\n");
			}else{
				printf("Escolha inv�lida!\n"); // Caso o usu�rio tecle qualquer outra entrada.
			}
		}else if (opcao == 3){ // Op��o 3. Esta op��o � para exibi��o de todos os valores do conjunto.
			if (indiceA == 0){ // Se o indice A for igual a 0, est� vazio.
				printf("O vetor A est� vazio.\n");
			}else{
				printf("Vetor A.\n");
				for (i = 0; i < indiceA; i++){
					printf ("%d\n", vetA[i]); // Printando o vetor A.
				}
			}
			if (indiceB == 0){ // Se o indice B for igual a 0, est� vazio.
				printf("O vetor B est� vazio.\n");
			}else{
				printf("Vetor B.\n");
				for (i = 0; i < indiceB; i++){
					printf ("%d\n", vetB[i]); // Printando o vetor B.
				}
			}
		}else if (opcao == 4){ // Uni�o, op��o 4.
			printf("Uni�o de A e B\n");
			indiceC = 0; // inicia o indice com 0 a cada loop.
			for (i = 0; i < indiceA; i++){  
				vetC[i] = vetA[i]; // vetor C recebe o vetor A.
				indiceC++; // incrementando o indice.
			}
			for (i = indiceA; i < indiceA + indiceB; i++){   
				repetido = 0; // Inicia com 0 a cada loop.
				for (j = 0; j < indiceA; j++){
					if (vetB[i - indiceA] == vetA[j]){ 
						repetido = 1;
						break;
					}
				}
				if (repetido == 0){ // Se o repetido for falso, ele entra na uni�o.
					vetC[indiceC] = vetB[i - indiceA];
					indiceC++;
				}  
			}
			for (i = 0; i < indiceC; i++){    
				printf ("%d\n", vetC[i]); // Printando a uni�o entre os vetores.
			}
			if (indiceA == 0 && indiceB == 0){
				printf ("Conjunto vazio\n");
			}
		
		}else if (opcao == 5){ // Intersec��o, op��o 5.
			printf("Intersec��o entre A e B\n");
			indiceC = 0; // Inicia com 0 a cada loop.
			for (i = 0; i < indiceA; i++){
				for (j = 0; j < indiceB; j++){
					if (vetA[i] == vetB[j]){ 
						vetC[indiceC] = vetA[i];
						indiceC++; 
						break;
					}
				}
			}
			for (i = 0; i < indiceC; i++){
				printf ("%d\n", vetC[i]);
			}
			if (indiceA == 0 && indiceB == 0){
				printf ("Conjunto vazio\n");
			}
		}else if (opcao == 6){ // Diferenca, op��o 6.
			printf ("Diferen�a\n");
			printf ("1. A - B\n");
			printf ("2. B - A\n");
			printf (">> ");
			scanf ("%d", &item);
			indiceC = 0;
			if (item == 1){ 
				for (i = 0; i < indiceA; i++){
					repetido = 0;
					for (j = 0; j < indiceB; j++){
						if (vetA[i] == vetB[j]){ // Se o valor do vetor A for igual ao valor do vetor B.
							repetido = 1; // Ser� verdadeiro e ele sair� do loop.
							break;
						}
					}
					if (repetido == 0){ // Se for falso, ele ir� igualar vetC a vetA e incrementar o �ndice.
						vetC[indiceC] = vetA[i];
						indiceC++;
					}
				}
				for (i = 0; i < indiceC; i++){
					printf ("%d\n", vetC[i]); // Printando o resultado entre a diferen�a dos vetores.
				}
			}else if (item == 2){
				for (i = 0; i < indiceB; i++){
					repetido = 0;
					for (j = 0; j < indiceA; j++){
						if (vetB[i] == vetA[j]){ // Se o vetor B conter valores de A, os vetores tem algo em comum, ent�o ele ir� interromper.
							repetido = 1;
							break;
						}
					}
					if (repetido == 0){ 
						vetC[indiceC] = vetB[i]; // Se for falso, ele ir� armazenar dentro do vetor C
						indiceC++; // E implementar o indice para pr�xima casa.
					}
				}
				for (i = 0; i < indiceC; i++){
					printf ("%d\n", vetC[i]); // Printando o resultado da difenren�a entre os vetores.
				}
			}else{
				printf ("Escolha inv�lida.\n");
			}
			if (indiceA == 0 && indiceB == 0){
				printf ("Conjunto vazio\n");
			}
		}else if(opcao == 7){ // Contido, op��o 7.
			printf ("Contido\n");
			printf ("1. A contido em B\n");
			printf ("2. B contido em A\n");
			printf (">> ");
			scanf ("%d", &item);
			if (item == 1){
				for (i = 0; i < indiceA; i++){
					encontrado = 0;
					for (j = 0; j < indiceB; j++){
					 	if (vetA[i] == vetB[j]){
					 		encontrado = 1; // Se for verdadeiro, ele vai para o pr�ximo.
					 		break;
					 	}
					 }
					 if(encontrado == 0){ // Se o loop n�o for verdadeiro alguma vez, ele n�o estar� contido e emitir� a mensagem.
					 	printf("A n�o est� contido em B.\n");
					 	break;
					 }
				}
				if(encontrado == 1){
					printf("A est� contido em B.\n"); // Se sempre for verdadeiro, no final ele printar� a mensagem.
				}

			}else if (item == 2){
				for (i = 0; i < indiceB; i++){
					encontrado = 0;
					for (j = 0; j < indiceA; j++){
					 	if (vetB[i] == vetA[j]){
					 		encontrado = 1;
					 		break;
					 	}
					 }
					 if(encontrado == 0){
					 	printf("B n�o est� contido em A.\n");
					 	break;
					 }
				}
				if(encontrado == 1){
					printf("B est� contido em A.\n");
				}
			}else{
				printf ("Escolha inv�lida.\n");
			}
			if (indiceA == 0 && indiceB == 0){
				printf ("A e B s�o conjuntos vazios\n");
			}
		}
		
		if(opcao >= 1 && opcao <= 7){
			printf ("Pressione Enter para mostrar o menu..."); // Op��o para deixar a visualiza��o mais limpa.
			getchar(); // Espera o Enter do usu�rio para retornar ao menu.
			getchar();
		}
	}while (opcao >= 1 && opcao <= 7);// Enquanto a op��o escolhida pelo usu�rio estiver entre 1 e 7.

return 0;
}
