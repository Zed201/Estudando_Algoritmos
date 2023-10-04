/**
 * index
 */
public class index {
    static public void main(String[] args) {
        int vet[] = {18, 47, 58, 1, 11, 22, 18, 2, 4, 99, 67, 27};
        Lista_Ord listinha = new Lista_Ord(12, vet);
        listinha.Quicksort(0, 11);
        for (int i : listinha.vetor) {
            System.out.println(i);
        }
    }
}
// por algum motivo nao quer pegar, ver outras implementacoes
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