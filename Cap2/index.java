import java.util.ArrayList;

/**
 * index
 */
public class index {

    public static void main(String[] args) {
        int[] x = { 3, 56, 7, 1, 1, 4, 2, 4, 5, 6, 1, 2, 10, 12, 12, 4, 3, 42, 5, 212, 45, 654, -1};
        ArrayList<Integer> l = new ArrayList<Integer>();
        for (int i : x) {
            l.add(i);
        }
        Listas listinhas = new Listas(l);
        System.out.println(listinhas.LD.toString());
        listinhas.OrdSelecao();
        System.out.println(listinhas.LO.toString());
        
    }
}

class Listas{
    public ArrayList<Integer> LD, LO = new ArrayList<Integer>();

    Listas(ArrayList<Integer> x) {
        this.LD = x;
    }

    public int menorElemento() {
        int menor_i = 0, menor_e = this.LD.get(0);
        for (int i = 0; i < this.LD.size(); i++) {
            if (this.LD.get(i) < menor_e) {
                menor_e = this.LD.get(i);
                menor_i = i;
            }
        }
        return menor_i;
    }

    public void OrdSelecao() {
        int menor_e = -1, tam = this.LD.size();
        for (int i = 0; i < tam; i++) {
            menor_e = this.menorElemento();
            this.LO.add(this.LD.get(menor_e));
            this.LD.remove(menor_e);
        }
    }
}