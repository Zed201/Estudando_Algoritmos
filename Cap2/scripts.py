def Busca_Menor(arr):
    menor_index = 0
    menor_elemento = arr[menor_index]
    for i in range(1, len(arr)):
        if arr[i] < menor_elemento:
            menor_elemento = arr[i]
            menor_index = i
    return menor_index

def Ordem_selecao(arr):
    novo_arr = []
    x = len(ar)
    for i in range(0, len(arr)):
        novo_arr.append(arr.pop(Busca_Menor(arr)))
    return novo_arr

array = [3,56,7,1,0.1,4,2,4,5,6,1,2,10,12,12,4,3,4.2,5,212,45,654]
print(array)
n_array = Ordem_selecao(array)
print(n_array)
