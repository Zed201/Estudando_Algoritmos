/**
 * index
 * Implementacao de grafos em Java, primeiro queria fazer sem nenhuma inclusao, 
 * mas preguica de fazer tudo na mao, entao vou usar a biblioteca do Java mesmo.
 */
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;

public class index {
    public static void main(String[] args) {
        Grafos gf = new Grafos();
        // infelizmente ter que fazer desse jeito a adicao dos pesos
        gf.addVertice("1", new Tupla("3", 2));
        gf.addVertice("2", new Tupla("3", 3));
        gf.addVertice("3", new Tupla[]{new Tupla("5", 3), new Tupla("6", 5), new Tupla("4", 4)});
        gf.addVertice("4", new Tupla("6", 3));
        gf.addVertice("5", new Tupla[]{new Tupla("6", 1), new Tupla("7", 5)});
        gf.addVertice("6", new Tupla("8", 2));
        gf.addVertice("7", new Tupla("8", 2));
        gf.addVertice("8");
        
        //System.out.println(gf.PesquisaEmLargura("4", "5"));
        
    }
}

class Tupla {
        public String Vertex;
        public Integer peso;
        public Tupla(String Vertex, Integer peso) {
            this.Vertex = Vertex;
            this.peso = peso;
        }
    }

class Grafos {
    private HashMap<String, HashMap<String, Integer>> grafo = new HashMap<String, HashMap<String, Integer>>();

    
    public boolean PesquisaEmLargura(String ini, String fin) {
        Queue<String> Fila = new ArrayDeque<String>();
        ArrayList<String> visitados = new ArrayList<String>();
        for (String i : this.grafo.get(ini).keySet()) {
            Fila.add(i);
        }
        while (!Fila.isEmpty()) {
            String Vert = Fila.poll();
            if(!visitados.contains(Vert)) {
                if (Vert.equals(fin)) {
                    return true;
                }
                for (String i : this.grafo.get(Vert).keySet()) {
                    Fila.add(i);
                }
                visitados.add(Vert);
            }
        }
        return false;
    }

    public void addVertice(String index, Tupla... dados) {
        HashMap<String, Integer> defualt = new HashMap<String, Integer>();
        if(dados.length > 0) {
            for (Tupla i : dados) {
                defualt.put(i.Vertex, i.peso);
            }
        }
        this.grafo.put(index, defualt);
    }

    public HashMap<String, Integer> getDado(String index) {
        System.out.println(this.grafo.get(index));
        return this.grafo.get(index);
    }
}
