#include "device/cgastr.h"
#include "machine/keyctrl.h"


char level_line[64];
unsigned int left[20];
unsigned int right[20];

void decode(int pos)
{
	unsigned int zahl1 = left[pos];
	unsigned int zahl2 = right[pos];
	char* zeiger1 = level_line;
	char* zeiger2 = level_line+32;
	for(int i = 0; i < 32 ; i++)
	{
		if( (zahl1 % 2) == 0)
			*zeiger1 = ' ';
		else
			*zeiger1 = '#';
		zahl1 /= 2;
		*zeiger1++;

		if( (zahl2 % 2) == 0)
			*zeiger2 = ' ';
		else
			*zeiger2 = '#';
		zahl2 /= 2;
		*zeiger2++;
	}
}
void init_level()
{
	left[0] =  0xffffffff;
	right[0] = 0xffffffff;
	left[19] = 0xffffffff;
	right[19] = 0xffffffff;
	for(int i=1; i < 19; i++)
	{
		left[i] = 0x00000001;
		right[i]= 0x80000000;
	}
}

int main() 
{
	CGA_Stream kout;
	kout << "Start" <<endl;
	Keyboard_Controller keycont;	
	kout << "Init" <<endl;
	Key down;
	do
	{
		
		down =keycont.key_hit();
		if(down.valid())
		{
			char outc = (char)down.ascii();
			if(outc == '\n')
				kout << endl;
			else{
				kout << outc;
				kout.flush();
			}
		}
	}while(down.ascii() != 'q');
	kout <<endl;
	// Level initialisieren
	init_level();
	
	int y=2;
	int x=2;
	unsigned int men;
	do{
	/*	
	// Position des Männchen reseten
		men = 0x00000001;
	if(x<32){
		men = men << x;
		left[y] &= ~men; 
	}else{
		men = men << (x-32);
		right[y] &= ~men;
	}	*/
	down =keycont.key_hit();
	// Positionstasten
	switch(down.ascii()){
		case 'a':
			x--;
		break;
		case 'd':
			x++;
		break;
		case 'w':
			y--;
		break;
		case 's':
			y++;
		break;
	}
	// Fehler abfangen
	if(x<1)
		x = 1;
	if(x>63)
		x = 63;
	if(y<1)
		y = 1;
	if(y>19)
		y = 19;

	// Position des Männchen
		men = 0x00000001;
	if(x<32){
		men = men << x;
		left[y] |= men; 
	}else{
		men = men << (x-32);
		right[y] |= men;
	}

	//Ausgabe
	for(int y = 0; y < 20; y++)
	{
		decode(y);
		for(int i=0; i<64; i++)
		{
			kout <<level_line[i];
		}
		kout << endl;
	}
		// Bildschirm füllen
		kout << endl << endl << endl;	
	}while(down.ascii() != 'q');
	kout << "Ende" << endl;

  return 0;
}
