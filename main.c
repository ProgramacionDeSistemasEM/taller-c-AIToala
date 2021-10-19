#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//yo me llamo andres! 
int main(int argc, char **argv){
	
	int elementos = 0;
	char c = 0;
	
	
	//Aqui manejamos las opciones.
	//El argumento -p tiene un argumento, que es 
	//el numero de elementos a pedir (por eso el :)
	while ((c = getopt (argc, argv, "p:")) != -1){
		switch(c){
			case 'p':
				elementos = atoi(optarg);
				break;
			default:
				printf("Argumento invalido\n");
				exit(1);
		}
	}

	//Los resultados de sus calculos van en estas variables.
	//Puede declarar más variables si lo necesita.
	float sum = 0.0f;
	float max_imc = 0.0f;
	
	float data[elementos];

	if(elementos<=0){
		printf("Numero de personas invalido\n");
		exit(1);
	}
	for(int i=0; i<elementos;i++){
		printf("Peso: ");

		char buf1[10] ={0};
		fgets(buf1,10,stdin);
		float peso = atof(buf1);

		if(peso<0){
			printf("Numero invalido\n");
			exit(1);
		}
		printf("Altura: ");
		
		char buf[10] ={0};
		fgets(buf,10,stdin);
		float altura = atof(buf);

		if(altura<0){
			printf("Numero invalido\n");
			exit(1);
		}
		printf("\n");
		float imc;
		imc = peso / (altura * altura);
		sum += imc;
		data[i] = imc; 
	}
	
	for (int i=0; i<elementos;i++){
		if(data[i] > max_imc){
			max_imc = data[i];
		}
	}
	sum = sum / elementos;
	
	//No modifique estas lineas
	//Guarde los resultados en las 
	//variables sum y max_imc
	printf("\npromedio IMC: %.1f\n", sum);
	printf("maximo IMC: %.1f\n", max_imc);
}
