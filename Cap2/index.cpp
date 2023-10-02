// implementacao com vector
// #include <iostream>
// #include <vector>

// using namespace std;

// int MenorElemento(vector<int> vet){
//     int index_m = 0, menor_elemento = vet[0];
//     for (int i = 0; i < vet.size(); i++)
//     {
//        if (vet[i] < menor_elemento)
//        {
//            menor_elemento = vet[i];
//            index_m = i;
//        }
//     }
//     return index_m;
// }

// vector<int> OrdenacoaSelecao(vector<int> vet){
//     vector<int> Nvet;
//     int menor_elemento = 0;
//     for (int el : vet)
//     {
//         menor_elemento = MenorElemento(vet);
//         Nvet.push_back(vet[menor_elemento]);
//         vet.erase(vet.begin() + menor_elemento);
//     }

//     return Nvet;
// }

// int main(){
//     vector<int> vetor = {3, 56, 7, 1, 1, 4, 2, 4, 5, 6, 1, 2, 10, 12, 12, 4, 3, 42, 5, 212, 45, 654};
//     vector<int> NVet = OrdenacoaSelecao(vetor);
//     for (int i : NVet)
//     {
//         cout << i << endl;
//     }
//     return 0;
// }

// impementacao sem vector, apenas alocacao dinamica

#include <iostream>
#define tam 22
using namespace std;

int MenorElemento(int* vet, int tamanho){
    int index_m = 0;
    int menor_elemento = vet[0];
    for (int i = 0; i < tamanho; i++)
    {
       if (vet[i] < menor_elemento)
       {
           menor_elemento = vet[i];
           index_m = i;
       }
    }
    return index_m;
}

int *OrdenacaoSelecao(int *vet, int tamanho){
    int *vetN = NULL;
    int tamanho_O = tamanho;
    vetN = (int *)malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho_O; i++)
    {
        int menor_i = MenorElemento(vet, tamanho);
        cout << vet[menor_i] << endl;
        vetN[i] = vet[menor_i];
        tamanho--;
        for (int z = menor_i; z < tamanho; z++)
        {
            vet[z] = vet[z + 1];
        }
        vet = (int *)realloc(vet, sizeof(int) * tamanho);
    }
    return vetN;
}
int main()
{
    int *vet = NULL;
    int vet2[tam] = {3,56,7,1,1,4,2,4,5,6,1,2,10,12,12,4,3,42,5,212,45,654};
    vet = (int *)malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++)
    {
        vet[i] = vet2[i];
    }
    int *vetN = NULL;
    vetN = (int *)malloc(sizeof(int) * tam);
    vetN = (int *)OrdenacaoSelecao(vet, tam);
    // for (int i = 0; i < tam; i++)
    // {
    //     cout << vetN[i] << endl;
    // }

    return 0;
}
