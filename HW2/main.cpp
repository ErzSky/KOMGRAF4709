#include <iostream>

using namespace std;

int a=1; int b=3; int c=2; int d=4;
int w=1; int x=1; int y=0; int z=0;
int skala;


void tambah(){9
    cout << "A+B = |" << a+w << " " << b+x << "|" << endl;
    cout << "      |" << c+y << " " << d+z << "|" << endl;
    cout << endl;
}

void kurang(){
    cout << "A-B = |" << a-w << " " << b-x << "|" << endl;
    cout << "      |" << c-y << " " << d-z << "|" << endl;
    cout << endl;
}

void skalar(){
    cout << "A X " << skala << " = |" << a << " " << b << "| X " << skala<< endl;
    cout << "        |" << c << " " << d << "|"<< endl;
    cout << endl;
    cout << "      = |" << a*skala << " " << b*skala << "|"<<endl;
    cout << "        |" << c*skala << " " << d*skala << "|"<< endl;
    cout << endl;
}

int main()
{
    int pilih;
    cout << "A = |" << a << " " << b << "|"<< endl;
    cout << "    |" << c << " " << d << "|"<< endl;
    cout << endl;
    cout << "B = |" << w << " " << x << "|"<< endl;
    cout << "    |" << y << " " << z << "|"<< endl;
    cout << endl;

    for(int i=0; i<=100; i++){
        cout << "============== MENU ============" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian Skalar" << endl;
        cout << "================================" << endl;
        cout << "Pilih : ";cin >> pilih;
        cout << endl;

        if(pilih==1){
            tambah();
        }else if(pilih==2){
            kurang();
        }else{
            cout << "Masukkan angka: "; cin >>skala;
            skalar();
        }


    }
    return 0;
}
