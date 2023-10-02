import java.util.ArrayList;

public class index {
    public static void main(String[] args) {
        ArrayList<Integer> lista = new ArrayList<Integer>();
        for (int i = 0; i <= 10000; i++) {
            lista.add(i);
        }
        Lista_Busca_Binarya Nova = new Lista_Busca_Binarya(lista);
        int x = Nova.Busca(678);
        System.out.println(x);
        System.out.println(Nova.Listinha.get(x));
        
    }
}

/**
 * Lista_Busca_Binarya
 */
class Lista_Busca_Binarya {
    ArrayList<Integer> Listinha;

    Lista_Busca_Binarya(ArrayList<Integer> x) {
        this.Listinha = x;
    }

    int Busca(int x) {
        int in = 0, fin = this.listinha.size();
        while (in <= fin) {
            int meio = (in + fin) / 2;
            //System.out.println(meio);
            int chute = this.Listinha.get(meio);
            if (chute == x) {
                return meio;
            } else if(chute > x){
                fin = meio - 1;
            } else if (chute < x) {
                in = meio + 1;
            }
        }
        return -1;
    }
}