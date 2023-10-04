#include <iostream>
#include <time.h>
using namespace std;

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
    void Quick_Sort(int start, int End){
        if (start >= End){
            return;
        }

        t pivo = this->Vetor[start];
        int i = start, j = End, count = 0;

        for (int i = start + 1; i <= End; i++)
            if(this->Vetor[i] <= pivo)
                count++;
        int pivoI = count + start;
        swap(this->Vetor[pivoI], this->Vetor[start]);

        while (i < pivoI && j > pivoI)
        {
            while (this->Vetor[i] <= pivo)
            {
                i++;
            }
            while (this->Vetor[j] >= pivo)
            {
                j--;
            }
            if (i < pivoI && j > pivoI)
            {
                swap(this->Vetor[i++], this->Vetor[j--]);
            }
        };
        this->Quick_Sort(start, start + count - 1);
        this->Quick_Sort(start + count + 1, End);
        
    }
};


int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}


int main(){
    int tam = 12;
    Lista<int> ls(tam);
    int vet[12] = {18, 47, 58, 1, 11, 22, 18, 2, 4, 99, 67, 27};
    ls.addVetor(vet);
    time_t t0 = clock();
    ls.Quick_Sort(0, tam-1);
    //quickSort(ls.Vetor, 0, ls.Tam - 1);
    time_t t1 = clock();
    for (int i = 0; i < ls.Tam; i++)
    {
        cout << ls.Vetor[i] << endl;
    }
    cout << "Tempo de execucao: " << (t1 - t0) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}