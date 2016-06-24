/*
Ciò premesso, si lavori al seguente progetto:
a) Caricare da file di testo l'immagine su cui lavorare (il nome del file va fornito da tastiera);
b) Specchiare la metà sinistra sulla metà destra e stampare a video l'immagine modificata;
c) Ruotare l'immagine di 180 gradi in senso antiorario e stampare a video l'immagine ruotata;
d) Stampare a video l'immagine;
e) Salvare su file di testo l'ultima versione dell'immagine (il nome del file va fornito da tastiera);
f) Uscire dal menù.
*/
#include <iostream>
#include <fstream>
using namespace std;

struct pixel{
unsigned char rosso;
unsigned char verde;
unsigned char blu;
};

void specchia_immagine(pixel [][10],pixel[][10]);
void carica_immagine(pixel[][10],char []);
void ruota_di_180(pixel [][10], pixel [][10]);
void stampa_matrice(pixel [][10]);
void salva_immagine(pixel[][10], char[]);
void copia_matrice(pixel [][10], pixel [][10]);

int main(){
    char s;
    char file[15];
    pixel iniziale[10][10];
    pixel modificata[10][10];
    pixel immagine[10][10];
    do{
    do{
        cout << "\nMENU'\n";
        cout << "a) CARICA DA FILE L'IMMAGINE\n";
        cout << "b) SPECCHIA LA META' SINISTRA NELLA META' DESTRA\n";
        cout << "c) RUOTA DI 180 GRADI L'IMMAGINE ORIGINALE IN SENSO ANTIORARIO\n";
        cout << "d) STAMPA A VIDEO L'IMMAGINE ORIGINALE\n";
        cout << "e) SALVA SU FILE L'IMMAGINE\n";
        cout << "f) ESCI\n";
        cout << "Scelta: ";
        cin>>s;
        if(s!='a'&&s!='b'&&s!='c'&&s!='d'&&s!='e'&&s!='f')
            cout<<"lettera non consentita"<<endl;
    }while(s!='a'&&s!='b'&&s!='c'&&s!='d'&&s!='e'&&s!='f');
        cout<<endl;
        switch(s){
        case 'a':{
            cout<<"\nScrivi il nome del file contenente l'immagine da caricare:"<<endl;
            cin>>file;
            carica_immagine(iniziale,file);
            copia_matrice(iniziale,immagine);
            copia_matrice(immagine,modificata);
        break;
        }
        case 'b':{
            specchia_immagine(immagine, modificata);
            copia_matrice(modificata,immagine);
            stampa_matrice(modificata);
        break;
        }
        case 'c':{
            ruota_di_180(immagine,modificata);
            copia_matrice(modificata,immagine);
            stampa_matrice(modificata);
        break;
        }
        case 'd':{
            stampa_matrice(iniziale);
        break;
        }
        case 'e':{
            cout<<"Inserisci il nome del file"<<endl;
            cin>>file;
            salva_immagine(modificata,file);
        break;
        }
        }
}while(s!='f');
return 0;
}

void carica_immagine(pixel m[][10], char nomefile[15]){//carica i dati della matrice dal file
fstream input;
input.open(nomefile,ios::in);
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++)
        input>>m[i][j].rosso>>m[i][j].verde>>m[i][j].blu;//carica i dati dal file e li salva nella struct
}
input.close();
}

void copia_matrice(pixel a[][10], pixel b[][10]){//copia i dati di righe e colonne della matrice a nella matrice b
for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        b[i][j]=a[i][j];
}

void salva_immagine(pixel m[][10], char nomefile[15]){
fstream output;
output.open(nomefile,ios::out);
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        output<<m[i][j].rosso<<m[i][j].verde<<m[i][j].blu;//salva nel file i dati dalla struct
    }
        output<<endl;
}
cout<<"matrice salvata nel file "<<nomefile<<" con successo"<<endl;
}

void ruota_di_180(pixel m[][10], pixel t[][10]){
    for(int i=9;i>=0;i--){
       for(int j=9;j>=0;j--){
            t[i][j]=m[i][j];
        }
}
}

void specchia_immagine(pixel m[][10],pixel s[][10]){//copia l immagine della parte sinistra della matrice nella matrice destra
    /*
for (int i = 0; i < 10; i++)
    for (int j = 0; j < 5; j++){
        s[i][j] = m[i][j];
        s[i][9-j] = m[i][j];
    }
    */
    for(int i=0;i<10;i++)
        for(int j=0;j<6;j++){
            s[i][j]=m[i][j];
            s[i][j-5]=m[i][j];
        }

}

void stampa_matrice(pixel g[][10]){
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        cout<<g[i][j].rosso<<g[i][j].verde<<g[i][j].blu<<" ";
    }
    cout<<endl;
}
}

//Coded by DarkCerfa
