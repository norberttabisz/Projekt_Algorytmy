#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

void wyswietlTablice(int tab[], int rozmiar) { //funkcja wyœwietlajaca tablice 
    cout << "Przykladowa tablica A: [";
    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i];
        if (i < rozmiar - 1) cout << ", ";
    }
    cout << "]" << endl;
}

bool czyTeSameElementy(const pair<int,int> para1, const pair<int,int> para2) { // sprawdza czy dwie pary zawieraj¹ te same elementy (niezale¿nie od kolejnoœci)
    return (para1.first == para2.first && para1.second == para2.second) || (para1.first == para2.second && para1.second == para2.first);
}

vector<pair<int,int>> znajdzPary(int A[], int n, int k) { //szuka wszystkie pary o roznicy k
    vector<pair<int,int>> Z;  // wektor przechowuj¹cy unikalne pary spe³niaj¹ce warunek

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (abs(A[j] - A[i]) == abs(k)) {
                pair<int,int> potencjalnaPara;

                if (A[j] - A[i] == k) { //ustalanie kolejnosci wyswietlanych liczb w zaleznosci od znaku roznicy 
                    potencjalnaPara.first = A[i];
                    potencjalnaPara.second = A[j];
                } else {
                    potencjalnaPara.first = A[j];
                    potencjalnaPara.second = A[i];
                }

                bool juz_jest = false;
                for (int m = 0; m < Z.size(); m++) {
                    if (czyTeSameElementy(potencjalnaPara, Z[m])) {
                        juz_jest = true;
                        break;
                    }
                }

                if (!juz_jest) {
                    Z.push_back(potencjalnaPara);
                }
            }
        }
    }
    return Z;
}
int main() {
    int A[] = {1, 5, 2, 2, 2, 5, 5, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int k;

    wyswietlTablice(A, n);
    cout << "Podaj roznice k: ";
    cin >> k;

    vector<pair<int,int>> Z = znajdzPary(A, n, k);

    if (Z.empty()) {
        cout << "Brak par o roznicy k." << endl;
    } else {
        cout << "Pary o roznicy k: ";
        for (int i = 0; i < Z.size(); i++) {
            cout << "[" << Z[i].first << "," << Z[i].second << "]";
        }
        cout << endl;
    }

    return 0;
}