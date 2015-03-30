// Euklid.c
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int win(char a[9], char znak){
	if (a[0] == znak){
		if ((a[1] == znak&&a[2] == znak) || (a[4] == znak&&a[8] == znak) || (a[3] == znak&&a[6] == znak))
			return 1;
	}
	else if (a[8] == znak){
		if ((a[6] == znak&&a[7] == znak) || (a[2] == znak&&a[5] == znak))
			return 1;
	}
	else if (a[4] == znak){
		if ((a[3] == znak&&a[5] == znak) || (a[1] == znak&&a[7] == znak) || (a[2] == znak&&a[6] == znak))
			return 1;
	}
	return 0;

}

int dobrota(char a[9],int player){
	
	if (player == 1){
		if (win(a, 'O') == 1)
			return -128;
	}
	else if (player==-1)
		if (win(a, 'X') == 1)
			return -128;
	int max = -200;
	int vrijednost;
	for (int i = 0; i < 9; i++) {
		if (a[i] != 'X' && a[i] != 'O'){
			if (player == -1)
				a[i] = 'O';
			else if (player == 1)
				a[i] = 'X';
			
			vrijednost = -dobrota(a, -player)/2;
			a[i] = i + 1+'0';
			if (vrijednost > max)
				max = vrijednost;
		}
	}
	return max;
}

int najbolji_potez(char a[9]){
	int max = -100;
	int vrijednost;
	int najboljipotez;
	for (int i = 0; i < 9; i++) {
		if (a[i] != 'X' && a[i] != 'O'){
			a[i] = 'O';
			vrijednost = -dobrota(a,1);
			a[i] = i + 1+'0';
			if (vrijednost > max)
			{
				max = vrijednost;
				najboljipotez = i;
			}
		}
	}
	return najboljipotez;
}


void ispisi_mrezu(char a [9]) {
	printf("_______________\n|%c|%c|%c|\n|%c|%c|%c|\n|%c|%c|%c|",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
}

int main()
{
	int unos,potez=10;
	char mreza[9] = { '1', '2', '3', '4','5','6', '7', '8', '9' };
	ispisi_mrezu(mreza);
	for (int i = 0; i < 3; i++){
		printf("Upišite broj polja kolje želite zauzeti sa X");
		scanf("%d", &unos);
		mreza[unos-1] = 'X';
		potez = najbolji_potez(mreza);
		mreza[potez] = 'O';
		ispisi_mrezu(mreza);
	}
	printf("Upišite broj polja kolje želite zauzeti sa X");
	scanf("%d", &unos);
	mreza[unos - 1] = 'X';
	potez = najbolji_potez(mreza);
	for (int i = 0; i < 9;i++)
		if (mreza[i] != 'X' && mreza[i] != 'O'&& i!=potez)
	mreza[i] = 'O';
	ispisi_mrezu(mreza);
	getchar();
	getchar();
}