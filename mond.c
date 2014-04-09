#include <stdio.h>
#include <time.h>

/**
 * Functions
**/

double lese_f( void );
void printmoon( int phase );

int main() {
	int tag=0, monat=0, jahr=0,mphase=0,amijahr=0;
	
	printf("Geben Sie einen Tag (1-31): ");
	tag = lese_f();
	
	while(tag>31 || tag<1) {
		printf("Geben Sie bitte einen gültigen Tag ein(1-31): ");
		tag=lese_f();
	}
	
	printf("Geben Sie einen Monat (1-12): ");
	monat=lese_f();
	
	while(monat<1 || monat>12){
		printf("Geben Sie bitte einen gültigen Monat ein (1-12): ");
		monat=lese_f();		
	}
	
	printf("Geben Sie ein Jahr (im Format JJJJ): ");
	jahr=lese_f();
	
	amijahr = jahr%1000;
	amijahr = amijahr%100;
		
	mphase = mondphase(tag,monat,jahr);
	
	printf("Die Mondphase an das Datum (Deutscheformat) %d.%d.%d (Americanischeformat) %d/%d/%d ist:  %d \n\n", tag,monat,jahr,monat,tag,amijahr,mphase);
	printmoon(mphase);
	
	return 0;
	
}

int mondphase(int tag,int monat,int jahr) {
	int value=0,korrektur1=0,korrektur2=0,korrektur3=0;
	
	monat = monat - 2;
	
	korrektur1 = jahr/300;
	korrektur2 = jahr/400;
	korrektur3 = jahr/100;
	
	if(monat<1){
		monat+=12;
		jahr--;
	}
		
	value=(jahr%19)*11+monat+tag+korrektur1+korrektur2-korrektur3+8;
	
	while(value>30){
		value-=30;
	}	
	
	return value;
}

