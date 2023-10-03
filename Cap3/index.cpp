#include <iostream>
using namespace std;
#define tamanhi 10

template <typename t>
class Lista{
public:
    int Tam;
    t *Vetor;

    Lista(int tamanho){
        this->Tam = tamanho;
        this->Vetor = (t*) malloc(sizeof(t) * this->Tam);
    }
    void addVetor(t*vet){
        for (int i = 0; i < this->Tam; i++)
        {
            this->Vetor[i] = vet[i];
        }
    }
    void Quick_Sort(int start = 0, int End = 0){
        // Apenas para deixar a chamada na main main bonita
        if (End == 0 && start == 0)
            End = this->Tam - 1;

        if (start >= End)
            return;
        t pivo = this->Vetor[start];
        int i = start, j = End, count = 0;

        for (int i = start + 1; i <= End; i++)
            if(this->Vetor[i] <= pivo)
                count++;

        swap(this->Vetor[start], this->Vetor[count + start]);

        do
        {
            while (this->Vetor[i] <= pivo)
            {
                i++;
            }
            while (this->Vetor[j] >= pivo)
            {
                j--;
            }
            if (i <= count + start && count + start < j)
            {
                swap(this->Vetor[i++], this->Vetor[j--]);
            }
        }while (i <= count + start && count + start < j);
        this->Quick_Sort(start, start + count - 1);
        this->Quick_Sort(start + count + 1, End);
        
    }
};


int main(){
    Lista<int> ls(10);
    int vet[10] = {-2, -3, -5, -6, -8, 10, 4, 56, 7, 4};
    ls.addVetor(vet);
    ls.Quick_Sort();
    for (int i = 0; i < ls.Tam; i++)
    {
        cout << ls.Vetor[i] << endl;
    }

    return 0;
}