def Binary(lista, item):
    alto = len(lista) -1
    baixo = 0
    while baixo <= alto:
        # por algum motivo nao tava convertendo para int então usei a classe int
        meio = int((baixo + alto) / 2)
        chute = lista[meio]
        if chute == item:
            return meio
        if chute > item:
            alto = meio - 1 
        else:
            baixo = meio + 1
    return None

listinha = []
i = 0
while i <= 10000:
    listinha.append(i)
    i += 1
print (Binary(listinha, 671))
    