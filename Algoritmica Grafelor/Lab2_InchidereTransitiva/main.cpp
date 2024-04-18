/*
2. Sa se determine închiderea transitivă a unui graf orientat. (Închiderea tranzitivă poate fi reprezentată ca matricea care 
descrie, pentru fiecare vârf în parte, care sunt vârfurile accesibile din acest vârf. Matricea inchiderii tranzitive arată 
unde se poate ajunge din fiecare vârf.) ex. figura inchidere_tranzitiva.png - pentru graful de sus se construieste matricea 
de jos care arata inchiderea tranzitiva.
*/

#include <iostream>
#include <fstream>

using namespace std;

int numarulDeNoduri, matriceTranzitiva[101][101];

int main()
{

    ifstream f("graf.txt");
    if (!f.is_open()) {
        cerr << "Failed to open graf.txt" << endl;
        return 1;
    }
    f >> numarulDeNoduri;
    int x,y;
    while (f >> x >> y)
        matriceTranzitiva[x][y] = 1;
    for (int k = 1; k <= numarulDeNoduri; k++)
        for (int i = 1; i <= numarulDeNoduri; i++)
            for (int j = 1; j <= numarulDeNoduri; j++)
                if (matriceTranzitiva[i][j] == 0)
                    matriceTranzitiva[i][j] = (matriceTranzitiva[i][k] && matriceTranzitiva[k][j]);

    for (int i = 1; i <= numarulDeNoduri; i++) {
        for (int j = 1; j <= numarulDeNoduri; j++)
            cout << matriceTranzitiva[i][j] << " ";
        cout << endl;
    }
    return 0;
}