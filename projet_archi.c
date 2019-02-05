#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

/*variables globale*/
int pid;//retourne le pid du fils
int tube[2];//tube du pere vers le fils
	    //tub[0] est le descripteur pour la lecture
	    //tube[1] est le descripteur pour l'ecriture	
int tube2[2];//tube du fils vers le pere

typedef struct
   {
        int x,y;
   } point;

/*prototype fonction*/
void pere();
void fils();
void addMatrix(int matrix1[30][30], int matrix2[30][30],int addition[30][30],int r1,int c1,int r2,int c2) {
    if (r1 == r2 && c1 == c2) {
        for (int row = 0; row < r1; row++) {
            for (int col = 0; col < c1; col++) {
                addition[row][col] = matrix1[row][col] + matrix2[row][col];
            }
        }
    } else {
        printf("Addition impossible, format incorrect");
    }
}
void subMatrix(int matrix1[30][30], int matrix2[30][30],int soustraction[30][30],int r1,int c1,int r2,int c2) {
    if (r1 == r2 && c1 == c2) {
        for (int row = 0; row < r1; row++) {
            for (int col = 0; col < c1; col++) {
                soustraction[row][col] = matrix1[row][col] - matrix2[row][col];
            }
        }
    } else {
        printf("Soustraction impossible, format incorrect");
    }
}

void multMatrix(int matrix1[30][30], int matrix2[30][30],int multiplication[30][30],int r1,int c1,int r2,int c2) {
    if (c1 == r2) {
        for (int row = 0; row < r1; row++) {
			for (int colIndex = 0; colIndex <c2; colIndex++) {
				for (int col = 0; col <r2; col++) {
					multiplication[row][colIndex] = multiplication[row][colIndex] + matrix1[row][col] * matrix2[col][colIndex];
				}
			}
        }
    } else {
        printf("Multiplication impossible, format incorrect");
    }
}

double getDistance(point a, point b){
    double distance;
    distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return distance;
}

void distEucli(point listPoints[30], double distance[30][30], int nbPoints) {
    int r1, c1 = nbPoints;
    for (int row = 0; row < r1; row++) {
            for (int col = 0; col < c1; col++) {
                for int()
                distance[row][col] = getDistance(listPoints[col], listPoints[col]);
            }
        }
}

/*fonction principale*/
int main()
{
	pipe(tube);//creation du tube pere vers le fils
	pipe(tube2);//creation du tube fils vers le pere
	printf("\n tube lecture %d ecriture %d",tube[0],tube[1]);
	printf("\n tube2 lecture %d ecriture %d",tube2[0],listPoints[col],tube2[1]);
	int x;
	int choix;
	printf("\n 1 --> Addition Entiers ");
    printf("\n 2 --> Soustraction Entiers"); 
    printf("\n 3 --> Multiplication Entiers"); 
    printf("\n 4 --> Addition Matrice"); 
    printf("\n 5 --> Soustraction Matrice"); 
    printf("\n 6 --> Multiplication Matrice"); 
    printf("\n 7 --> Calcul distance Euclidienne"); 
    printf("\n \n Que voulez vous faire ? ");
	for(x=0;x<1;x++)
	scanf("%d",&choix);
	switch(pid=fork())//pid prend le pid du fils et fork crée pere et fils
	{
		case -1:perror("fork");break; //en cas d'erreur
		case  0:fils(choix);break;//chez le fils
		default:pere(choix);break;//chez le pere	
	}  	
 
	return 0;
}

/*fonction client*/
void pere(int choix)
{
    /*1000
     Partie de calcul des entiers.
     1 --> Addition
     2 --> Soustraction
     3 --> Multiplication 
     */
	if(choix == 1 || choix == 2 || choix == 3){
		int nbre[2];
		int res=0;
		int i;
		printf("\n Ecrire 2 chiffres : ");
		for(i=0;i<2;i++)
		scanf("%d,",&nbre[i]);
		//tube pere vers le fils on ne lit pas on ecrit
		close(tube[0]);
		//si on a pas ecrit les 2 chiffres erreur
		if(write(tube[1],&nbre,2*sizeof(int))!=2*sizeof(int))
			perror("[pere tube] write");
		//plus besoin d'ecrire
		close(tube[1]);
		//on attend la fin de l'action du fils qu'il est finit de faire le calcul
		wait(0);
		//printf("\n[pere] %d + %d = ",nbre[0],nbre[1]);
		//dans le deuxieme tube le pere n'ecrit pas, il lit
		close(tube2[1]);
		/*si on a pas un entier a lire on ecrit l'erreur*/
		if(read(tube2[0],&res,sizeof(int))!=sizeof(int))
			perror("[pere tube2] read");
		//plus besoin de lire dans le deuxieme tube c'est finit
		printf("%d",res);
		close(tube2[0]);
    /*
     Partie de calcul des matrices.
     4 --> Addition
     5 --> Soustraction
     6 --> Multiplication 
     */  
	}else if(choix == 4 || choix == 5 || choix == 6){
		int matrix1[30][30];
		int matrix2[30][30];
		int res[30][30];
		int rows,cols,r=0,c=0;
		printf("*** Matrix Addition ***\n ");
		printf("Nombre de lignes:");
		scanf("%d",&rows);
		printf("Nombre de colonnes:");
		scanf("%d",&cols);
		printf("\nValorisez la première matrice : %d * %d (Entiers uniquement)\n" ,rows,cols);
		for (r = 0; r < rows; r++) {
			for (c = 0; c < cols; c++) {
				scanf("%d",&matrix1[r][c]);
			}
		}
		printf("Valorisez la seconde matrice: %d * %d (Entiers uniquement)\n" ,rows,cols);
		for (r = 0; r < rows; r++) {listPoints[col]
			for (c = 0; c < cols; c++) {
				scanf("%d",&matrix2[r][c]);
			}
		}
		//tube pere vers le fils on ne lit pas on 
		for (r = 0; r < rows; r++) {
			printf("| ");
			for (c = 0; c < cols; c++) {
				printf("%d ",matrix2[r][c]);
			}
		printf("|\n");
		}ecrit
		close(tube[0]);
		//si on a pas ecrit les 2 chiffres erreur
		if(write(tube[1],&matrix1,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[pere tube] write");
		else if(write(tube[1],&matrix2,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[pere tube] write");
		else if(write(tube[1],&rows,sizeof(int))!=sizeof(int))
			perror("[pere tube] write");
		else if(write(tube[1],&cols,sizeof(int))!=sizeof(int))
			perror("[pere tube] write");

		//plus besoin d'ecrire
		close(tube[1]);
		//on attend la fin de l'action du fils qu'il est finit de faire le calcul
		wait(0);
		//printf("\n[pere] %d + %d = ",matrix1,matrix2);
		//dans le deuxieme tube le pere n'ecrit pas, il lit
		close(tube2[1]);
		//si on a pas un entier a lire on ecrit l'erreur
		if(read(tube2[0],&res,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[pere tube2] read");
		//plus besoin de lire dans le deuxieme tube c'est finit
		printf("Résultat du calcul:\n");
		for (r = 0; r < rows; r++) {
			printf("| ");
			for (c = 0; c < cols; c++) {
				printf("%d ",res[r][c]);
			}
		printf("|\n");
		}
		close(tube2[0]);

		return 0;
	}
	else if(choix == 7){
        int nbPoints,n;
        int res[30][30];
        printf("Nombre de points à calculer:");
        scanf("%d",&nbPoints);
        point listPoints[30];
        for (n = 0; n < nbPoints; n++) {
            printf("\nPoint n°%d\n", n);
            printf("x: ");
            scanf("%d",&listPoints -> x);
            printf("y: ");
            scanf("%d",&listPoints -> y);
            }
        printf("Point 1, x --> %d", listPoints[0].x);
        printf("Point 1, y --> %d", listPoints[0].y);
        close(tube[0]);
		//si on a pas ecrit les 2 chiffres erreur
		if(write(tube[1],&listPoints,30*sizeof(point))!=30*sizeof(point))
			perror("[pere tube] write");
        else if(write(tube[1],&nbPoints,sizeof(int))!=sizeof(int))
			perror("[pere tube] write");
        //plus besoin d'ecrire
		close(tube[1]);
        wait(0);
		//printf("\n[pere] %d + %d = ",matrix1,matrix2);
		//dans le deuxieme tube le pere n'ecrit pas, il lit
		close(tube2[1]);
		//si on a pas un entier a lire on ecrit l'erreur
		if(read(tube2[0],&res,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[pere tube2] read");
		//plus besoin de lire dans le deuxieme tube c'est fini
		printf("Résultat du calcul:\n");
		for (int r = 0; r < rows; r++) {
			printf("| ");
			for (int c = 0; c < cols; c++) {
				printf("%d ",res[r][c]);
			}
		printf("|\n");
		}
		close(tube2[0]);

		return 0;
    }
}

/*fonction serveur*/
void fils(int choix)
{    
	if(choix == 1 || choix == 2 || choix == 3){         
        int nbre[2];
        int x;
        int res=0;
        //dans le premier tube le fils ne fait que lire
        close(tube[1]);
        /*si on ne lit pas 2 entier dans le tube*/
            if(read(tube[0],&nbre,2*sizeof(int))!=2*sizeof(int))
            perror("[fils tube] read");
        //plus rien a lire
        close(tube[0]); 
        //printf("\n[fils] j'ai recu %d et %d \n",nbre[0],nbre[1]);
        //on fait l'addition
        if(choix == 1)
            res=nbre[0]+nbre[1];
        else if(choix == 2)
            res=nbre[0]-nbre[1];
        else if(choix == 3)
            res=nbre[0]*nbre[1];
        printf("\n[fils] je dois retourner %d \n",res);
        //on ne lit pas dans le deuxieme tube
        close(tube2[0]);
        /*si on ecrit pas un entier dans le tube*/
        if(write(tube2[1],&res,sizeof(int))!=sizeof(int))
            perror("[fils tube2] write");
        //on n'a plus rien a ecrire
        close(tube2[1]);
    /*
     Partie de calcul des matrices.
     4 --> Addition
     5 --> Soustraction
     6 --> Multiplication 
     */ 
	}else if(choix == 4 || choix == 5 || choix == 6){
		int matrix1[30][30];
		int matrix2[30][30];
		int res[30][30];
		int rows,cols,r=0,c=0;
		close(tube[1]);
		if(read(tube[0],&matrix1,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[fils tube] read");
		else if(read(tube[0],&matrix2,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[fils tube] read");
		else if(read(tube[0],&rows,sizeof(int))!=sizeof(int))
			perror("[fils tube] read");
		else if(read(tube[0],&cols,sizeof(int))!=sizeof(int))
			perror("[fils tube] read");
		close(tube[0]); 
		//printf("rows = %d, cols = %d", rows, cols);
		if(choix == 4)
            addMatrix(matrix1, matrix2, res, rows,cols,rows,cols);
        else if(choix == 5)
            subMatrix(matrix1, matrix2, res, rows,cols,rows,cols);
        else if(choix == 6)
            multMatrix(matrix1, matrix2, res, rows,cols,rows,cols);
		close(tube2[0]);
		if(write(tube2[1],&res,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[fils tube2] write");
		close(tube2[1]);
	}
	else if(choix == 100){
        int nbPoints;
        int res[30][30];
        point listPoints[30];
        close(tube[1]);
        if(read(tube[0],&nbPoints,sizeof(int))!=sizeof(int))
			perror("[fils tube] read");
        else if(read(tube[1],&listPoints,30*sizeof(point))!=30*sizeof(point))
			perror("[fils tube] read");
        printf(">>%d",nbPoints);
        close(tube[0]); 
        distEucli(listPoints, res, nbPoints);
        for (int r = 0; r < nbPoints; r++) {
			printf("| ");
			for (int c = 0; c < nbPoints; c++) {
				printf("%d ",res[r][c]);
			}
		printf("|\n");
		}
		close(tube2[0]);
		if(write(tube2[1],&res,sizeof(int[30][30]))!=sizeof(int[30][30]))
			perror("[fils tube2] write");
		close(tube2[1]);
    }
}
