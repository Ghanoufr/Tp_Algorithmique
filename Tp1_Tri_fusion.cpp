#include <iostream>

#include<vector>

#include <chrono>

using std::vector;

using namespace std;

using namespace std::chrono;

void div_Table_in_two(vector<int>&V, int p, int q, int r);

void tri_fusion(vector<int>&V, int l, int r);

int main(){

    vector <int> V;

    int n;

    cout<<"donner la taille du tableau";

    cin>>n;

    int i=n;

    while (i>0)

    {

        V.push_back(i);

        i--;

    }

    auto start = high_resolution_clock::now();

    tri_fusion(V, 0, V.size()- 1);

    auto stop = high_resolution_clock::now();

 

    cout << "le temps d'exécution de la fonction tri par fusion: "

         << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds" << endl;

   return (0);

}

void div_Table_in_two(vector<int>&V, int p, int q, int r){

    int n1 = q - p + 1;

    int n2 = r - q;

    vector<int>L, M;

    for (int i = 0; i < n1; i++){

        L.push_back(V[p + i]);

    }

    for (int i = 0; i < n2; i++){

        M.push_back(V[q + 1 + i]);

    }

    int i, j, k;

  i = 0;

  j = 0;

  k = p;

   while (i < n1 && j < n2){

    if (L[i] <= M[j]){

        V[k] = L[i];

        i++;

    }else{

        V[k] = M[j];

      j++;

    }

    k++;

   }

   while (i < n1) {

    V[k] = L[i];

    i++;

    k++;

  }

  while (j < n2) {

    V[k] = M[j];

    j++;

    k++;

  }

}

void tri_fusion(vector<int>&V, int l, int r){

    if (l < r) {

    int m = l + (r - l) / 2;

    tri_fusion(V, l, m);

    tri_fusion(V, m + 1, r);

    div_Table_in_two(V, l, m, r);

  }

}

