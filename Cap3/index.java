/**
 * index
 */
public class index {
    static public void main(String[] args){
        int vet[] = {-2, -3, -5, -6, -8, 10, 4, 56, 7, 4};
        Lista_Ord listinha = new Lista_Ord(9, vet);
        listinha.Quicksort(0, listinha.Tam - 1);
        for (int i : listinha.vetor) {
            System.out.println(i);
        }
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
    
    public void Quicksort(int start, int End) {
        // verificar a existencia de algo melhor para dar swap
        int pivo = this.vetor[start], count = 0, swap = 0, i = start, j = End;
        if (start >= End) {
            return;
        }
        for (int j2 = start + 1; j2 < this.Tam; j2++) {
            if (this.vetor[j2] <= pivo) {
                count++;
            }
        }
        swap = this.vetor[start];
        this.vetor[start] = this.vetor[start+count];
        this.vetor[start + count] = swap;
        
        while (i < start + count && start + count < j) {
            while (this.vetor[i] <= pivo) {
                i++;
            }
            while (this.vetor[j] >= pivo) {
                j--;
            }
            if (i < start + count && start + count < j) {
                swap = this.vetor[i];
                this.vetor[i] = this.vetor[j];
                this.vetor[j] = swap;
                i++;
                j--;
            }
        };
    
        this.Quicksort(start, start + count - 1);
        this.Quicksort(start + count + 1, End);

    }

}