#include <iostream> 
#include <fstream>
 
using namespace std;
fstream input,output;
struct pixel{
 unsigned char rosso;
 unsigned char verde;
 unsigned char blu; };
 /* Questa procedura legge da un file i 300 caratteri e li dispone nei 3 campi delle 100 caselle della matrice m[][] */
void carica_immagine(pixel m[][10], char nomefile[15])
{
    char c; 
	input.open (nomefile,ios::in);
	while(input.good())
	{
		for (int i=0;i<10;i++)
		{
		for (int j=0;j<10;j++)
			{
			input.get(c);
			m[i][j].rosso=c; // legge il rosso e lo inserisce nella matrice
			input.get(c);
			m[i][j].verde=c; // legge il verde e lo inserisce nella matrice
		   input.get(c);
			m[i][j].blu=c; // legge il blu e lo inserisce nella matrice
			input.get(c); // legge lo spazio
		}
	}
  }
	input.close();  
  }
    /* Questa procedura stampa a video i 300 caratteri ottenuti dai 3 campi delle 100 caselle della matrice w[][] */
void stampa_matrice(pixel w[][10])
{

 for (int i=0;i<10;i++)
		{
		for (int j=0;j<10;j++)
		{
		cout << w[i][j].rosso;	
	    cout << w[i][j].verde;
		cout << w[i][j].blu;
			cout << " ";
		}
		cout << endl; 
	}
	}
  /* Questa procedure prende la metà sinistra dell'immagine e la specchia nella metà destra*/
void specchia_immagine(pixel m[][10],pixel s[][10])
{
	int i=0,j=0,f;
	int z=1;
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
         if (j<5)s[i][j]=m[i][j]; //sono gli elementi da non specchiare
        else if(j>=5) //sono gli elementi da specchiare
            {
			f=j-z;	
        	s[i][j]=m[i][f]; 
        	z+=2;
        	}
		}
		z=1; //fa ripartire il ciclo, per specchiare gli elementi delle righe successive 
		}
		
	}
/* Questa procedura ruota di 180 gradi in senso antiorario l'immagine */
void ruota_di_180(pixel m[][10], pixel t[][10])
{
	int i=0,j=0,f,l;
	for (int i=0;i<10;i++)
	{
		f=9-i; //inverte le righe(es:l'ultima diventa prima e la prima diventa ultima)
		for (int j=0;j<10;j++)
		{
			l=9-j; //inverte le colonne(es:l'ultima diventa prima e la prima diventa ultima)
			t[i][j]=m[f][l];
		}
	}
 }
	/* Questa procedura salva su un file i 300 caratteri presi dai 3 campi delle 100 caselle della matrice m[][] */
void salva_immagine(pixel m[][10], char nomefile[15])
{  
output.open(nomefile,ios::out);
for (int i=0;i<10;i++)
		{
		for (int j=0;j<10;j++)
		{
		output << m[i][j].rosso;	
	    output << m[i][j].verde;
		output << m[i][j].blu;
		output << " ";
		}
		output << endl; 
	}
	output.close();
 }
/* Questa procedura copia il contenuto di una matrice in un altra matrice*/
void copia_matrice(pixel a[][10], pixel b[][10]) //(destinazione,fonte)
{
		for (int i=0;i<10;i++){
		for (int j=0;j<10;j++)
		{
			a[i][j]=b[i][j];
			
		}
	}
 }
int main()
{
	char nome[15];
	pixel m[10][10];
	pixel s[10][10];
	pixel t[10][10];
	pixel ori[10][10];
	char r;
	do {
		cout << "MENU'\n"
		"a) CARICA DA FILE L'IMMAGINE\n"
"b) SPECCHIA LA META' SINISTRA NELLA META' DESTRA\n"
"c) RUOTA DI 180 GRADI L'IMMAGINE IN SENSO ANTIORARIO\n"
"d) STAMPA A VIDEO L'IMMAGINE ORIGINALE\n"
"e) SALVA SU FILE L'IMMAGINE\n"
"f) ESCI" << endl << "Scelta:";
cin >> r;
	switch (r)
	{
		case 'a': {
		cout <<	"Scrivi il nome del file contenente l'immagine da caricare: " << endl;
	cin >> nome;
	carica_immagine(m,nome);
    cout << "Immagine caricata dal file " << nome << endl;;
		}break;
		case 'b':{
			specchia_immagine(m,s);
			cout << "L'immagine specchiata è la seguente: " << endl;
			copia_matrice(m,s);
			stampa_matrice(m);
		}break;
		case 'c':{
			ruota_di_180(m,t);
			cout << "L'immagine ruotata di 180 gradi è la seguente: " << endl;
			copia_matrice(m,t);
			stampa_matrice(m);
		}break;
		case 'd':{
			cout << "L'immagine è:" << endl;
			carica_immagine(ori,nome);
			stampa_matrice(ori);
		}break;
		case 'e':{
			char nomeout[15];
			cout << "Scrivi il nome del file su cui salvare l'immagine:" << endl;
			cin >> nomeout;
			salva_immagine(m,nomeout);
            cout << "Immagine salvata sul file" << nomeout << endl;
		}break;
		case 'f':{}break;
		default : cout << "Hai inserito un carattere non consentito !!!" << endl;
	}
	
	}
	while (r!='f');
}
