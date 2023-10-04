import time

from collections import deque

grafo = {}
grafo["1"] = ["3"]
grafo["2"] = ["3"]
grafo["3"] = ["5", "6", "4"]
grafo["4"] = ["6"]
grafo["5"] = ["6", "7"]
grafo["6"] = ["8"]
grafo["7"] = ["8"]
grafo["8"] = []


# Retorna true se achar um caminhoo entre os vertices indicados
def Pesquia_Largura(ini, fin):
    fila = deque()
    fila += grafo[ini]
    verificados = []
    while fila:
        vert = fila.popleft()
        if not vert in verificados:
            if vert == fin:
                return True
            else:
                fila += grafo[vert]
                verificados.append(vert)
    return False

t1=time.time()
#----------------------------------------------
print(Pesquia_Largura("6", "2"))

#----------------------------------------------
print("Time elapsed: ",float(time.time()-t1), "s")