/**
 * index
 */
public class index {
    static public void main(String[] args) {
        int vet[] = {18, 47, 58, 1, 11, 22, 18, 2, 4, 99, 67, 27};
        Lista_Ord listinha = new Lista_Ord(12, vet);
        listinha.QuickSort(0, listinha.Tam - 1);
        listinha.view();
    }
}

class Lista_Ord{
    public int Tam;
    public int vetor[];

    Lista_Ord(int Tam, int vtr[]) {
        this.Tam = Tam;
        this.vetor = new int[this.Tam];
        for (int i = 0; i < this.Tam; i++)
            this.vetor[i] = vtr[i];
    }
    
    public void view() {
        for (int i : this.vetor) {
            System.out.println(i);
        }
    }

    public void Swap(int vet[], int x, int y) {
        int swap = vet[x];
        vet[x] = vet[y];
        vet[y] = swap;
    }
    
    public void QuickSort(int ini, int fin){
        if (ini >= fin) {
            return;
        }
        int pivo = this.vetor[ini], i = ini, j = fin, count = 0;
        for (int k = ini + 1; k <= fin; k++) {
            if (this.vetor[k] <= pivo) {
                count++;
            }
        }

        int pvI = ini + count;
        this.Swap(this.vetor, ini, pvI);
        while (i < pvI && pvI < j) {
            while (this.vetor[i] <= pivo) {
                i++;
            }
            while (this.vetor[j] > pivo) {
                j--;
            }
            if (i < pvI && pvI < j) {
                this.Swap(this.vetor, i, j);
                i++;
                j--;
            }
        };
        this.QuickSort(ini, pvI - 1);
        this.QuickSort(pvI + 1, fin);
    }


}