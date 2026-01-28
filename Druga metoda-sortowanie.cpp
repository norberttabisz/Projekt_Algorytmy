#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <chrono>
#include <functional>
using namespace std;

void wyswietlTablice(const vector<int>& A) { //funkcja wyswietlajaca tablice
    for (int x : A) {    //skrócony zapis petli foreach w c++
        cout << x << " ";
    }
}

vector<pair<int,int>> znajdzPary(const vector<int>& A, int k) { 
    int n = A.size();
    int i = 0, j = i + 1;
	vector<pair<int,int>> pLiczb; // wektor przechowujący znalezione pary
    while (i < n && j < n) {
        if (i == j) {
            j++;
        }
        
        if (A[j] - A[i] == abs(k)) {
				 
        		if (k > 0) { // w zależności od znaku k zapisujemy parę w odpowiedniej kolejności
        			pair<int,int> para(A[i],A[j]);
        				pLiczb.push_back(para);
            	}else {
            		pair<int,int> para(A[j],A[i]);
            		pLiczb.push_back(para);
            	}
            	
            int vi = A[i], vj = A[j];
            while (i < n && A[i] == vi) i++;
            while (j < n && A[j] == vj) j++;
           
        }
        else if (A[j] - A[i] < abs(k)) {
            j++;
        }
        else {
            i++;
        }
    }
   return pLiczb;
}
int main() {
    vector<int> A = {1, 5, 2, 2, 2, 5, 5, 4};
    int k;
    cout << "Tablica przed sortowaniem:\n";
    cout << "[ ";
    wyswietlTablice(A);
    cout << "]";

    sort(A.begin(), A.end()); //sortowanie rosnąco tablicy

    cout << "\nPodaj k: ";
    cin >> k;
    cout << endl;

    cout << "Tablica po posortowaniu:\n";
    cout << "[ ";
   	wyswietlTablice(A);
    cout << "]"<<endl<<endl;
    
	
	vector<pair<int,int>> pary=znajdzPary(A, k); //funckja zwraca do zmiennej pary, vector par liczb ktore spelniaja warunek 
	
	if(pary.size()==0){
		cout<<"Brak par o podanej roznicy k"<<endl;
		return 0;
	}else{
        cout << "Znalezione pary: "<<endl;
	    for(int i=0;i<pary.size();i++){
		pair<int,int> para=pary.at(i);
		cout<<"[ "<<para.first<<","<<para.second<<" ]  "; //wypisanie par
	   }
    }
	  
    return 0;
}