# def fatorial(x):
#     if x == 1: return 1
#     else: return x * fatorial(x-1)
    
# #print(fatorial(998))

# def sum(arr):
#     if len(arr) == 1:
#         return arr[0]
#     else:
#         return (arr.pop(0) + sum(arr))

# #x = [1,3,3]
# #print(sum(x))

# def lis_qtd(arr):
#     # Basicamente uma verificacao se a list esta vazia
#     if arr == []:
#         return 0
#     else:
#         arr.pop(0)
#         return (1 + lis_qtd(arr))
# #print(lis_qtd([1,2,3]))

# # Passa o array e o primeiro elemento dele apenas
# def maior_valor(arr, i):
#     if arr != []:
#         if(arr[0] > i):
#             i = arr[0]    
#         arr.pop(0)
#         i = maior_valor(arr, i)
#     return i
# x = [1,30,4,70]

# print(maior_valor(x, x[0]))

def quickSort(arr):
    if len(arr) < 2: # ou seja = 1
        return arr
    else:
        pivo = arr[0]
        menores= []
        maiores= []
        for i in arr[1:]:
            if i <= pivo: menores.append(i)
            if i >= pivo: maiores.append(i)
        return quickSort(menores) + [pivo] + quickSort(maiores)
import time
vet = [18, 47, 58, 1, 11, 22, 18, 2, 4, 99, 67, 27]

t1=time.time()
print(quickSort(vet))
t2=time.time()
print(t2-t1)

caderno_hash = {
    "nome": "Caderno",
    "preco": 10.00,
    "qtd": 10
}
