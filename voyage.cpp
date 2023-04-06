#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void vole (){
    int jour,mois,annee,heur,min;
    char ville_d[20],ville_a[20];
	printf("****** la date jj/mm/aaaa hh:mm ******\n");
	printf("entrez le jour(jj):");
	scanf("%d",&jour);
	
	while(jour < 1 || jour > 31){
		printf("erreur !!!!\a\a\nreentrez le jour (jj):");
		scanf("%d",&jour);
	}
	
	printf("entrez le mois (mm):");
	scanf("%d",&mois);
	
	while(mois < 1 || mois > 12){
		printf("erreur !!!!\a\a\nreentrez le mois(mm):");
		scanf("%d",&mois);
	}
	
	printf("entrez le annee (aaaa):");
	scanf("%d",&annee);
	
	while(annee < 2022 || annee > 2050){
		printf("erreur !!!\a\a\nreentrez l\'annee(aaaa):");
		scanf("%d",&annee);
	}
	
	printf("entrez le temp de depart:\n");
	printf("heur:");
	scanf("%d",&heur);
	
	while(heur < 0 || heur > 23){
		printf("erreur !!!\a\a\nreentrez heur:");
		scanf("%d",&heur);
	}
	
	printf("minutes:");
	scanf("%d",&min);
	
	while(min < 0 || min > 59){
		printf("erreur !!!\a\a\nreentrez minutes:");
		scanf("%d",&min);
	}
	printf("entrez le ville de depart:");
	scanf("%s",ville_d);
	printf("entrez le ville d\'arevite:");
	scanf("%s",ville_a);
	FILE *fichier = fopen("file.txt","a");
	fprintf(fichier,"%.2d/%.2d/%d\t\t%s-->%s\t\t%.2d:%.2d\n",jour,mois,annee,ville_d,ville_a,heur,min);
	fclose(fichier);
}
void affichier(){
	FILE *fichier=fopen("file.txt","r");
	char hist[1000000];
	fread(hist,sizeof(char),1000000,fichier);
	if(!feof(fichier)){
		printf("Il n'y a aucune information dans le fichier");
	}else{
		printf("\n\n afichage\n");
		printf("%s",&hist);
		printf("\n");
		fclose(fichier);
	}
}
void recharcher(){
	FILE *fichier =fopen("file.txt","r");
	char h[1000000];
	fread(h,sizeof(char),100000,fichier);
	char j[10];
	printf("entrez la de de vole qu\'il faut rechercher jj/mm/aaaa :");
	scanf("%s",j);
	char *c= strpbrk(h,j);
	printf("%s",c);
	fclose(fichier);
}
void Menu(){
	int option ;
	do{
	printf("\n-----------------------------------------------------");
	printf("\n\t\t***\tMenu\t***\n");
	printf("1)Exite le programme\n2)create un nouvelle volle\n3)affichier les vole\n4)efface tout les vol");
	printf("\nchose:");
	scanf("%d",&option);
	switch(option){
		case 1:
			printf("programe exit!!!");
			exit(-0);
			break;
		case 2:
			vole();
			break;
		case 3:
			affichier();
			break;
		case 4:
			remove("file.txt");
			break;
		case 5:
			recharcher();
			break;		
	}
}while(option !=0);

}
int main (){
	Menu();
	return 0;
}
