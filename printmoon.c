/*		printmond.c      		22.3.2007/Pe
** Modul fuer Versuche im C-Praktikum 
** (nicht vergessen, die Prototypdeklaration:
void printmoon( int phase );
**  in Kopf des Hauptmoduls einzufuegen!)  */
#include <stdio.h>

// fuer verwendete Mathematik:
#include <math.h>

// X/Y-Kreis-Koordinaten, YM ist auch Radius
#define XM		40
#define YM		10

// Kreis-Symmetrie
#define SYM		1.5	

// Darstell-Elemente
#define RAND	'.'
#define VOLL	'#'
#define BLANK	' '


void printmoon( int phase )
{
	int x1, x2, y, i, m;
	
	for( y = 0  ;  y <= 2*YM  ;  y++ )
	{
		x1 = XM - (int)(SYM * sqrt(2 * y * YM - y * y) + 0.5) -1;
		x2 = XM + (int)(SYM * sqrt(2 * y * YM - y * y) + 0.5) -1;
		for( i=0  ;  i<x1  ;  i++ )
			putchar( ' ' );
		if( phase > 14 )	// Voll- oder abnehmender Mond
		{
			m = (30 - phase)/15.0 * (x2 - x1) + 0.5;
			if( phase > 25  &&  (x2-x1)==0 )
				putchar( RAND );
			else
				putchar( VOLL );
			for( i=1  ; i < x2-x1  ;  i++ )
			{
				if( i >= m )
					putchar( BLANK );
				else
					putchar( VOLL );
			}
			if( (x2-x1) > 0 )
			{
				if( phase == 15 )
					putchar( VOLL );
				else
					putchar( RAND );
			}
		}
		else	// Neu- oder zunehmender Mond
		{
			m = (15-phase)/15.0  * (x2 - x1) + 0.5;
			if( (x2-x1) > 0 )
				putchar( RAND );
			for( i=1  ; i < x2-x1  ;  i++ )
			{
				if( i <= m )
					putchar( BLANK );
				else
					putchar( VOLL );
			}
			if( phase == 0  || (((x2-x1)==0) && (phase < 7)) )
				putchar( RAND );
			else
				putchar( VOLL );
		}
		putchar( '\n' );
	}
}
