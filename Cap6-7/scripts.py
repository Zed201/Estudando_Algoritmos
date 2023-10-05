import time
from collections import deque

# Retorna true se achar um caminhoo entre os vertices indicados
def Pesquia_Largura(grafo, ini, fin):
    #! Inicia a fila e vai adicionando e verificando vertice por vertice, indicando se existe ou nao caminho entre o ini e o fin
    # o .keys esta ali pois esta analisando grafos com pesos, ai so adpta o algoritmo
    fila = deque()
    fila += grafo[ini].keys()
    verificados = []
    while fila:
        vert = fila.popleft()
        if not vert in verificados:
            if vert == fin:
                return True
            else:
                fila += grafo[vert].keys()
                verificados.append(vert)
    return False

def menor_custo(custos, processados):
    # Basicamente so pega o vertice com menor custo em relacao ao inicial
    custo_mais_baixo = float("inf")
    nodo_custo_mais_baixo = None
    for nodo in custos:
        custo = custos[nodo]
        if custo < custo_mais_baixo and nodo not in processados:
            custo_mais_baixo = custo
            nodo_custo_mais_baixo = nodo
    return nodo_custo_mais_baixo


def Algoritmo_Menor_Caminho(grafo_dado, inicio, final):
    # usa o algoritmo de pesquisa em largura para ver se existe o caminho primeiro para evitar erros
    if Pesquia_Largura(grafo_dado, inicio , final):
        processados = []
        custos = {}
        pais = {}
        # Vai processar e pegar todos os custos e pais dos vertices com base no inicial, independente de quem ele seja
        for i in grafo_dado.keys():
            if i != inicio:
                pais[i] = None
                custos[i] = float("inf")
                if i in grafo_dado[inicio].keys():
                    # Basicamente aos vertices que estao diretamente ligados ao inicial ele adiciona ele aos pais e o custo deles
                    # de resto se complete com o algoritmo
                    custos[i] = grafo_dado[inicio][i]
                    pais[i] = inicio
        #------------------------(Algoritmo em si)
        # Pega o primeiro menor custo
        nodo = menor_custo(custos, processados)
        while nodo is not None:
            # enquanto tiver vertices a serem processados ele pega o custo do menor e dos seus vizinhos
            custo = custos[nodo]
            custos_vizinhos = grafo_p[nodo]
            for n in custos_vizinhos.keys():
                # ele vai atualizar a tabela apenas se o custo novo dos vertices for menor que o que ja ta salvo
                # se isso acontecer ele atualiza o novo custo e adiciona coloca o vertice analisado como pai na tabela dos pais 
                novo_custo = custo + custos_vizinhos[n]
                if custos[n] > novo_custo:
                    custos[n] = novo_custo
                    pais[n] = nodo
            # depois ele adiciona aos vertices processados e pega um novo nao processado
            processados.append(nodo)
            nodo = menor_custo(custos, processados)
        #--------------------------------------------(Interpretacao dos resultados)
        # Vai concatenando tudo numa string final montando o caminho e imprime o valor do caminho
        string_final = ""
        string_final += final
        nodo_analisar = pais[final]
        while nodo_analisar is not inicio:
            string_final += " <--- "
            string_final += nodo_analisar
            nodo_analisar = pais[nodo_analisar]
        string_final += " <--- " 
        string_final += inicio
        print("Caminho: ", string_final)
        print("Custo minimo: ", custos[final])
    else:
        print("Caminho nao existente")

grafo_p = {}
grafo_p["1"] = {"3": 2}
grafo_p["2"] = {"3": 3}
grafo_p["3"] = {"5": 3, "6": 5, "4": 4}
grafo_p["4"] = {"6": 3}
grafo_p["5"] = {"7": 5, "6": 1}
grafo_p["6"] = {"8": 2}
grafo_p["7"] = {"8": 2}
grafo_p["8"] = {}

t1=time.time()
#---------------------------------------------
Algoritmo_Menor_Caminho(grafo_p, "2", "6")
#----------------------------------------------
print("Time elapsed: ",float(time.time()-t1), "s")
