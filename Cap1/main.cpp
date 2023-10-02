#include <iostream>
#include <vector>
#define tam 10000

using namespace std;

int Binary(vector<int> vetor, int item, int tamanho){
    int alto = tamanho - 1, baixo = 0;
    while (baixo <= alto)
    {
        int meio = (alto + baixo) / 2;
        int chute = vetor[meio];
        //cout << meio << endl;
        if(chute == item) {
            return meio;
        }
        if (chute > item)
        {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }
    return -1;
}

int main(){
    /*
    int *vetor = (int *)malloc(sizeof(int) * tam);
    int item = 99;
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = i;
    }
    cout << Binary(vetor, item, tam) << endl;
    */

    vector<int> listinha;
    int item = 671;
    for (int i = 0; i < tam; i++)
    {
        listinha.push_back(i);
    }
    int x = Binary(listinha, item, tam);
    cout << x << endl;
    cout << listinha[x];

    return 0;
}