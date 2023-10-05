/*
 * index
 * Implementacao de grafos em Java, primeiro queria fazer sem nenhuma inclusao, 
 * mas preguica de fazer tudo na mao, entao vou usar a biblioteca do Java mesmo.
 * Usei consideravelmente o copilot, pois basicamente copiei oque tinha no .py
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
        gf.addVertice("3", new Tupla[]{new Tupla("5", 3), new Tupla("6", 2), new Tupla("4", 4)});
        gf.addVertice("4", new Tupla("6", 3));
        gf.addVertice("5", new Tupla[]{new Tupla("6", 3), new Tupla("7", 5)});
        gf.addVertice("6", new Tupla("8", 8));
        gf.addVertice("7", new Tupla("8", 2));
        gf.addVertice("8");
        
        gf.MenorCaminho("1", "8");
        
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
    private HashMap<String, String> Pais = new HashMap<String, String>();
    private HashMap<String, Integer> Custos = new HashMap<String, Integer>();
    private ArrayList<String> visitados = new ArrayList<String>();

    
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
    
    public String menor_custo() {
        Integer menor = Integer.MAX_VALUE;
        String index = null;
        for (String i : this.Custos.keySet()) {
            if (this.Custos.get(i) < menor && !this.visitados.contains(i)) {
                menor = this.Custos.get(i);
                index = i;
            }
        }
        return index;
    }

    public void MenorCaminho(String ini, String fin) {
        if (this.PesquisaEmLargura(ini, fin)) {
            for (String i : this.grafo.keySet()) {
                if (this.grafo.get(ini).containsKey(i)) {
                    Custos.put(i, this.grafo.get(ini).get(i));
                    Pais.put(i, ini);
                }
                if (i != ini) {
                    Custos.put(i, Integer.MAX_VALUE);
                    Pais.put(i, null);
                }
            }
            String nodo = this.menor_custo();
            while (nodo != null) {
                Integer custo = this.Custos.get(nodo);
                HashMap<String, Integer> custo_vizinhos = this.grafo.get(nodo);
                for (String i : custo_vizinhos.keySet()) {
                    Integer novo_custo = custo + custo_vizinhos.get(i);
                    if (novo_custo < this.Custos.get(i)) {
                        this.Custos.put(i, novo_custo);
                        this.Pais.put(i, nodo);
                    }
                }
                this.visitados.add(nodo);
                nodo = this.menor_custo();
            }
            String path = new String();
            path = path.concat(fin);
            String nodo_analisado = Pais.get(fin);
            while (nodo_analisado != null) {
                path = path.concat(" <--- ").concat(nodo_analisado);
                nodo_analisado = Pais.get(nodo_analisado);
            }
            System.out.println("Caminho: " + path);
            System.out.println("Custo Mínimo: " + this.Custos.get(fin));
            Pais.clear();
            Custos.clear();
            visitados.clear();
        } else {
            System.out.println("Não existe caminho entre os vértices");
        }
    }
}
