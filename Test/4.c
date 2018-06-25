#include<stdio.h>
#include<conio.h>
#define MAX 50

void next(char str[], int l);

int main(void)
{
clrscr();
	char ch, str[MAX];
	int i = 0, l;
	while((ch = getchar()) != '\n') str[i++] = ch;
	l= i;
	next(str, l);
	for(i = 0; i < l; i++) printf("%c", str[i]);
	printf("\n");
	getch();
	return 0;
}

void next(char str[], int l)
{
	int p = 0, i = 0, j = l - 1;
	while(((j - i) != 1) && ((j - i) != 0)){
		if(str[j] < str[i])
		p = 1;
		else if(str[j] > str[i])
		p = 0;
		str[j--] = str[i++];
	}
	if((j - i) == 1){
		if(str[i] < str[j]) str[i] = str[j];
		else if(str[i] > str[j]) str[j] = str[i];
		else if((str[i] == str[j]) && (p == 0)){
			if(str[i] != '9'){
				str[i]++;
				str[j]++;
			}
			else{
				do{
					str[i] = '0';
					str[j] = '0';
					i--;
					j++;
				}while((i >= 0) && (j < l) && (str[i] == '9') && (str[j] == '9'));
				str[i]++;
				str[j]++;
			}
		}
	}
	if((j - i) == 0){
		if((p == 0) && (str[j] != '9')) str[j]++;
		else if((p == 0) && (str[j] == '9')){
			do{
				str[i] = '0';
				str[j] = '0';
				i--;
				j++;
			} while((i >= 0) && (j < l) && (str[i] == '9') && (str[j] == '9'));
			str[i]++;
			str[j]++;
		}
	}
}
