/* === BIBLIOTECAS === */
#include <stdio.h>
#include <string.h>
typedef struct{
	char sigla[3];
	int casos;
}Estado;
int por_estados(){
	Estado estados[27] = {
    {"AC", 0}, {"AL", 0}, {"AM", 0}, {"AP", 0}, {"BA", 0},
    {"CE", 0}, {"DF", 0}, {"ES", 0}, {"GO", 0}, {"MA", 0},
    {"MG", 0}, {"MS", 0}, {"MT", 0}, {"PA", 0}, {"PB", 0},
    {"PE", 0}, {"PI", 0}, {"PR", 0}, {"RJ", 0}, {"RN", 0},
    {"RO", 0}, {"RR", 0}, {"RS", 0}, {"SC", 0}, {"SE", 0},
    {"SP", 0}, {"TO", 0}
	};
	/* Abre o arquivo consolidado para leitura */
		FILE *f=fopen("arquivo.csv","r");
		if (f==NULL){
			printf("ERRO: arquivo inexistente ou nao pode ser aberto\n");
			return 1;
		}
		char linha[10000];
		char *pedaco;
    /* Pula o cabecalho (primeira linha) */
		fgets(linha,sizeof(linha),f);
    /* Le linha por linha */
		while (fgets(linha,sizeof(linha),f)!=NULL){
       	pedaco = strtok(linha,";");
	
		for(int i=0;i<22;i++){
			if(i==21){
				for(int j=0;j<27;j++){
					char sg[3];
					sg[0]=pedaco[1];
					sg[1]=pedaco[2];
					sg[2]='\0';
					
					if(strcmp(sg,estados[j].sigla)==0){
						estados[j].casos++;
						break;
					}
				}
			}
			pedaco=strtok(NULL,";");
		}// FOR
		}
		FILE *estados_csv=fopen("estados.csv","w");
			for(int j=0;j<27;j++){
				fprintf(estados_csv,"%s %d\n",estados[j].sigla,estados[j].casos);
			}
		fclose(estados_csv);
	return 0;
}
int generos(){
	int masculino_2019=0,feminino_2019=0;
	int masculino_2020=0,feminino_2020=0;
	int masculino_2021=0,feminino_2021=0;
	int masculino_2022=0,feminino_2022=0;
	int masculino_2023=0,feminino_2023=0;
	int masculino_2024=0,feminino_2024=0;
	int masculino_2025=0,feminino_2025=0;
	int masculino_2026=0,feminino_2026=0;
	char ano[5];
	/* Abre o arquivo consolidado para leitura */
		FILE *f=fopen("arquivo.csv","r");
		if (f==NULL){
			printf("ERRO: arquivo inexistente ou nao pode ser aberto\n");
			return 1;
		}
		char linha[10000];
		char *pedaco;
    /* Pula o cabecalho (primeira linha) */
		fgets(linha,sizeof(linha),f);
    /* Le linha por linha */
		while (fgets(linha,sizeof(linha),f)!=NULL){
       	pedaco = strtok(linha,";");
			for(int i=0;i<11;i++){
				if(i==1){ //ano
					ano[0]=pedaco[1];
					ano[1]=pedaco[2];
					ano[2]=pedaco[3];
					ano[3]=pedaco[4];
					ano[4]='\0';
				}	
					if(i==10){ //genero	
						if(pedaco[1] == 'M'){
							if(strcmp(ano,"2019")==0){
								masculino_2019++;
							}else if(strcmp(ano,"2020")==0){
								masculino_2020++;
							}else if(strcmp(ano,"2021")==0){
								masculino_2021++;
							}else if(strcmp(ano,"2022")==0){
								masculino_2022++;
							}else if(strcmp(ano,"2023")==0){
								masculino_2023++;
							}else if(strcmp(ano,"2024")==0){
								masculino_2024++;
							}else if(strcmp(ano,"2025")==0){
								masculino_2025++;
							}else if(strcmp(ano,"2026")==0){
								masculino_2026++;
							}
						}else if(pedaco[1]=='F'){
							if(strcmp(ano,"2019")==0){
								feminino_2019++;
							}else if(strcmp(ano,"2020")==0){
								feminino_2020++;
							}else if(strcmp(ano,"2021")==0){
								feminino_2021++;
							}else if(strcmp(ano,"2022")==0){
								feminino_2022++;
							}else if(strcmp(ano,"2023")==0){
								feminino_2023++;
							}else if(strcmp(ano,"2024")==0){
								feminino_2024++;
							}else if(strcmp(ano,"2025")==0){
								feminino_2025++;
							}else if(strcmp(ano,"2026")==0){
								feminino_2026++;
							}
						}
					}
					pedaco = strtok(NULL, ";");
				}
			}
        /* Salva resultado em obitos.csv para uso no GNUplot */
			FILE *generos_csv = fopen("generos.csv", "w");
			fprintf(generos_csv,"2019 %d %d\n",masculino_2019,feminino_2019);
			fprintf(generos_csv,"2020 %d %d\n",masculino_2020,feminino_2020);
			fprintf(generos_csv,"2021 %d %d\n",masculino_2021,feminino_2021);
			fprintf(generos_csv,"2022 %d %d\n",masculino_2022,feminino_2022);
			fprintf(generos_csv,"2023 %d %d\n",masculino_2023,feminino_2023);
			fprintf(generos_csv,"2024 %d %d\n",masculino_2024,feminino_2024);
			fprintf(generos_csv,"2025 %d %d\n",masculino_2025,feminino_2025);
			fprintf(generos_csv,"2026 %d %d\n",masculino_2026,feminino_2026);
			fclose(generos_csv);
    return 0;
}
int obitos() {
    /* Contadores de obitos por ano */
		int obitos_2019=0;
		int obitos_2020=0;
		int obitos_2021=0;
		int obitos_2022=0;
		int obitos_2023=0;
		int obitos_2024=0;
		int obitos_2025=0;
		int obitos_2026=0;
    /* Abre o arquivo consolidado para leitura */
		FILE *f=fopen("arquivo.csv","r");
		if (f==NULL){
			printf("ERRO: arquivo inexistente ou nao pode ser aberto\n");
			return 1;
		}
		char linha[10000];
		char *pedaco;
    /* Pula o cabecalho (primeira linha) */
		fgets(linha,sizeof(linha),f);
    /* Le linha por linha */
		while (fgets(linha,sizeof(linha),f)!=NULL){
        char ano[5];
        char evolucao;
        /* Primeira chamada: coluna 1 (NU_NOTIFIC) */
			pedaco = strtok(linha,";");
        /* Percorre as colunas ate chegar em DT_NOTIFIC (col 2) e EVOLUCAO (col 111) */
			for (int i=1;i<111;i++) {
            /* Coluna 2: DT_NOTIFIC — extrai os 4 primeiros digitos (ano) */
				if (i==2){
					ano[0]=pedaco[1]; /* pula aspas */
					ano[1]=pedaco[2];
					ano[2]=pedaco[3];
					ano[3]=pedaco[4];
					ano[4]='\0';
				}
            /* Coluna 111: EVOLUCAO — 1=cura, 2=obito, 3=obito por outras causas */
				if (i == 110){
					evolucao=pedaco[1]; /* pula aspas */
				}
            pedaco=strtok(NULL,";");
        }
        /* Se EVOLUCAO == 2, incrementa o contador do ano correspondente */
			if(evolucao=='2'){
				if (strcmp(ano,"2019")==0){
					obitos_2019++;
				}
				else if (strcmp(ano,"2020")==0){
					obitos_2020++;
				}
				else if (strcmp(ano,"2021")==0){
					obitos_2021++;
				}
				else if (strcmp(ano, "2022")==0){
					obitos_2022++;
				}
				else if (strcmp(ano, "2023")==0){
					obitos_2023++;
				}
				else if (strcmp(ano, "2024")==0){
					obitos_2024++;
				}
				else if (strcmp(ano, "2025")==0){
					obitos_2025++;
				}
				else if (strcmp(ano, "2026")==0){
					obitos_2026++;
				}
			}
    }
    fclose(f);
    /* Salva resultado em obitos.csv para uso no GNUplot */
		FILE *obitos_csv = fopen("obitos.csv", "w");
		fprintf(obitos_csv,"2019 %d\n",obitos_2019);
		fprintf(obitos_csv,"2020 %d\n",obitos_2020);
		fprintf(obitos_csv,"2021 %d\n",obitos_2021);
		fprintf(obitos_csv,"2022 %d\n",obitos_2022);
		fprintf(obitos_csv,"2023 %d\n",obitos_2023);
		fprintf(obitos_csv,"2024 %d\n",obitos_2024);
		fprintf(obitos_csv,"2025 %d\n",obitos_2025);
		fprintf(obitos_csv,"2026 %d\n",obitos_2026);
		fclose(obitos_csv);
    return 0;
}
int casos(){
	    /* Contadores de casos por ano */
		int casos_2019=0;
		int casos_2020=0;
		int casos_2021=0;
		int casos_2022=0;
		int casos_2023=0;
		int casos_2024=0;
		int casos_2025=0;
		int casos_2026=0;
    /* Abre o arquivo consolidado para leitura */
    FILE *f=fopen("arquivo.csv", "r");
    if (f==NULL) {
        printf("ERRO: arquivo inexistente ou nao pode ser aberto\n");
        return 1;
    }
    char linha[10000];
    /* Le linha por linha, extrai o ano de DT_NOTIFIC e incrementa o contador */
		while(fgets(linha,sizeof(linha),f)!=NULL){
			/* Coluna 1: NU_NOTIFIC (descartada) */
				char *pedaco=strtok(linha,";");
			/* Coluna 2: DT_NOTIFIC */
				pedaco=strtok(NULL,";");
			/* Extrai os 4 primeiros digitos do campo de data */
				char ano[5];
				ano[0]=pedaco[1]; /* pula aspas */
				ano[1]=pedaco[2];
				ano[2]=pedaco[3];
				ano[3]=pedaco[4];
				ano[4]='\0';
			/* Incrementa o contador do ano correspondente */
				if(strcmp(ano,"2019")==0){
				casos_2019++;
				}
				else if(strcmp(ano,"2020")==0){
					casos_2020++;
				}
				else if(strcmp(ano,"2021")==0){
					casos_2021++;
				}
				else if(strcmp(ano,"2022")==0){
					casos_2022++;
				}
				else if(strcmp(ano,"2023")==0){
					casos_2023++;
				}
				else if(strcmp(ano,"2024")==0){
					casos_2024++;
				}
				else if(strcmp(ano,"2025")==0){
					casos_2025++;
				}
				else if(strcmp(ano,"2026")==0){
					casos_2026++;
				}
		}
		fclose(f);
		/* Salva resultado em ano.csv para uso no GNUplot */
			FILE *ano_csv = fopen("ano.csv", "w");
			fprintf(ano_csv,"2019 %d\n",casos_2019);
			fprintf(ano_csv,"2020 %d\n",casos_2020);
			fprintf(ano_csv,"2021 %d\n",casos_2021);
			fprintf(ano_csv,"2022 %d\n",casos_2022);
			fprintf(ano_csv,"2023 %d\n",casos_2023);
			fprintf(ano_csv,"2024 %d\n",casos_2024);
			fprintf(ano_csv,"2025 %d\n",casos_2025);
			fprintf(ano_csv,"2026 %d\n",casos_2026);
			fclose(ano_csv);
	return 0;
}
int internacoes(){
    /* Contadores de obitos por ano */
		int internacoes_2019=0;
		int internacoes_2020=0;
		int internacoes_2021=0;
		int internacoes_2022=0;
		int internacoes_2023=0;
		int internacoes_2024=0;
		int internacoes_2025=0;
		int internacoes_2026=0;
   /* Abre o arquivo consolidado para leitura */
		FILE *f=fopen("arquivo.csv","r");
		if (f==NULL){
			printf("ERRO: arquivo inexistente ou nao pode ser aberto\n");
			return 1;
		}
		char linha[10000];
		char *pedaco;
    	fgets(linha,sizeof(linha),f);
    	while (fgets(linha,sizeof(linha),f)!=NULL){
		char ano[5];
        char inter;
    		pedaco = strtok(linha,";");
    		for (int i=1;i<111;i++) {
    			if (i==2){
					ano[0]=pedaco[1]; /* pula aspas */
					ano[1]=pedaco[2];
					ano[2]=pedaco[3];
					ano[3]=pedaco[4];
					ano[4]='\0';
				}
    			if (i == 70){
					inter=pedaco[1]; /* pula aspas */
				}
            pedaco=strtok(NULL,";");
        }
			if(inter!='"'){
				if (strcmp(ano,"2019")==0){
					internacoes_2019++;
				}
				else if (strcmp(ano,"2020")==0){
					internacoes_2020++;
				}
				else if (strcmp(ano,"2021")==0){
					internacoes_2021++;
				}
				else if (strcmp(ano, "2022")==0){
					internacoes_2022++;
				}
				else if (strcmp(ano, "2023")==0){
					internacoes_2023++;
				}
				else if (strcmp(ano, "2024")==0){
					internacoes_2024++;
				}
				else if (strcmp(ano, "2025")==0){
					internacoes_2025++;
				}
				else if (strcmp(ano, "2026")==0){
					internacoes_2026++;
				}
			}
		}
    fclose(f);		
	/* Salva resultado em obitos.csv para uso no GNUplot */
		FILE *internacoes_csv = fopen("internacoes.csv", "w");
		fprintf(internacoes_csv,"2019 %d\n",internacoes_2019);
		fprintf(internacoes_csv,"2020 %d\n",internacoes_2020);
		fprintf(internacoes_csv,"2021 %d\n",internacoes_2021);
		fprintf(internacoes_csv,"2022 %d\n",internacoes_2022);
		fprintf(internacoes_csv,"2023 %d\n",internacoes_2023);
		fprintf(internacoes_csv,"2024 %d\n",internacoes_2024);
		fprintf(internacoes_csv,"2025 %d\n",internacoes_2025);
		fprintf(internacoes_csv,"2026 %d\n",internacoes_2026);
		fclose(internacoes_csv);
		
	return 0;
}
int main(void) {
	printf("CASOS");
		casos();
	printf("\nOBITOS");
		obitos();
	printf("\nGENEROS");
		generos();
	printf("\nESTADOS");
		por_estados();
	printf("\nINTERNAÇÕES");
		internacoes();
    printf("\nOK");
    
    return 0;
}
