#include <iostream>
#include <time.h>
using namespace std;

template <typename t>
class Lista{
public:
    int Tam;
    t *Vetor;

    void addVetor(t*vet){
        for (int i = 0; i < this->Tam; i++)
        {
            this->Vetor[i] = vet[i];
        }
    }
    Lista(int tamanho, t* vet){
        this->Tam = tamanho;
        this->Vetor = (t*) malloc(sizeof(t) * this->Tam);
        this->addVetor(vet);
    }
    // chama com o 0 e o tamanho - 1

    void Quick_Sort(int start, int end){
        if (start >= end)
            return;

        t pivo = this->Vetor[start];
        int i = start, j = end, count = 0;

        for (int i = start + 1; i <= end; i++)
            if(this->Vetor[i] <= pivo)
                count++;
        int pivoI = count + start;
        swap(this->Vetor[pivoI], this->Vetor[start]);

        while (i < pivoI && j > pivoI)
        { // se atentar que um e <= e o outro e >, tem que ser nessa ordem para essa logica
            while (this->Vetor[i] <= pivo)
                i++;
            while (this->Vetor[j] > pivo)
                j--;
            if (i < pivoI && j > pivoI)
                swap(this->Vetor[i++], this->Vetor[j--]);
        };
        this->Quick_Sort(start, pivoI - 1);
        this->Quick_Sort(pivoI + 1, end);
    }
};


int main(){
    int vet2[] = { 18,47, 58, 1, 11, 22, 18, 2, 4, 99, 67, 27};
    Lista<int> ls(12, vet2);
    ls.Quick_Sort(0, ls.Tam - 1);
    for (int i = 0; i < ls.Tam; i++)
    {
        cout << ls.Vetor[i] << endl;
    }

    return 0;
}

