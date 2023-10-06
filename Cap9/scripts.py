# Maior substring comum
import numpy as np
import time
def MaiorSubString(primeira, segunda):
    celula = np.zeros((len(primeira),len(segunda)))
    for i in range(len(primeira)):
        for j in range(len(segunda)):
            if(primeira[i] == segunda[j]):
                celula[i,j] = celula[i-1,j-1] + 1
    print(celula)
    return int(celula.max())

x="52jqwxybkxh2zxtmpro76qry3vz9qm"
y="qvgrlxiif8hcgb4bhzt9zwpvxl1qm"


import hashlib
z="mama"
ti=time.time()
#print(MaiorSubString(x, y))
print(hashlib.sha256(z.encode()))
print(time.time()-ti)
