// Tentar fazer sem lis nem array
#include <iostream>
#include <string>
#include <list>
#include <array>
using namespace std;

// pesquisa em largura
namespace PL{
    template <class T>
    class Fila{
        private:
            unsigned int tamanho = 0;
            T *dados;
        public:
            int qtdDados = 0;
            Fila(int tam)
            {
                this->tamanho = tam;
                this->dados = (T*) malloc(sizeof(T) * tam);
            }

            void NovoTamanho(int nTam){
                this->tamanho = nTam;
                this->dados = (T *)realloc(this->dados, sizeof(T) * nTam);
            }
            T pop(){
                T Fitem = this->dados[0];
                // arrumar essa implementacao, muito lenta
                for (int i = 0; i < this->tamanho - 1; i++)
                {
                    this->dados[i] = this->dados[i + 1];
                }
                this->NovoTamanho(this->tamanho - 1);
                this->qtdDados--;
                return Fitem;
            }
            void push(T nDado){
                if (this->qtdDados == this->tamanho)
                {
                    this->dados = (T *)realloc(this->dados, sizeof(T) * this->tamanho);
                    this->NovoTamanho(this->tamanho + 1);
                }
                this->dados[this->qtdDados] = nDado;
                this->qtdDados++;
            }
            void view(){
                for (int i = 0; i < this->qtdDados; i++)
                {
                    cout << this->dados[i] << endl;
                }
            }
            bool isIn(T dado){
                for (int i = 0; i < this->qtdDados; i++)
                {
                    if (dado == this->dados[i])
                    {
                        return true;
                    }
                }
                return false;
            }
    };
    // codigo tirado da internet e modificado
    template<class KeyType, class ValueType>
    class HashTable
    {
        private:
            struct Chave_Valor
            {
                int index;
                KeyType Chave;
                ValueType Valor;
            };
            unsigned int qtd_Dados = 0;
            static const int tamanho_Total = 5;
            // tentar achar alguma implementacao sem array nem list
            array<list<Chave_Valor>, tamanho_Total> table;
            int hash(KeyType chave){
                int counter = 0;
                int i = 1;
                for (char& c: chave) {
                    counter += i++ * static_cast<int>(c);
                }
                auto index = static_cast<int>(counter % this->tamanho_Total);
                return index;
            }
        public:
            int GetSizeIndex(KeyType chave){
                int index = this->hash(chave);
                return this->table[index].size();
            }
            ValueType LookUp(KeyType chave){
                int index = this->hash(chave);
                    for (auto &e : this->table[index])
                    {
                        if (e.Chave == chave)
                        {
                            return e.Valor;
                        }
                    }
                    cout << "Dado nao encontrado, retorno aleatorio:" << endl;
                    ValueType ret;
                    return ret;
            }

            void Put(KeyType chave, ValueType Valor){
                Chave_Valor *entrada = new Chave_Valor();
                entrada->index = this->hash(chave);
                entrada->Chave = chave;
                entrada->Valor = Valor;

                this->table[entrada->index].push_front(*entrada);
                this->qtd_Dados++;
            }

            bool Del(KeyType chave){
                int index = this->hash(chave);
                auto i = this->table[index].begin();
                for (; i != this->table[index].end(); ++i)
                {
                    if (i->Chave == chave)
                    {
                        this->table[index].erase(i);
                        this->qtd_Dados--;
                        return true;
                    }
                }
                return false;
            }
    };
};

using namespace PL;
template <class t>
bool Pesquisa_Largura(HashTable<t,list<t>> grafo, t ini, t fin){
    Fila<t> fl(1);
    Fila<t> verificados(1);
    list<t> lisI = grafo.LookUp(ini);
    for (auto i : lisI)
    {
        fl.push(i);
    }
    while (fl.qtdDados > 0)
    {
        t vert = fl.pop();
        
        if (!verificados.isIn(vert))
        {
            if (vert == fin)
            {
                return true;
            } else {
                verificados.push(vert);
                list<t> lisV = grafo.LookUp(vert);
                for (t i : lisV)
                {
                    fl.push(i);
                }
            }
        }
    }
    cout << "nao achou" << endl;
    return false;
}


int main(){
    HashTable<string, list<string>> Grafo;
    list<string> l1;
    l1.push_back("3");
    Grafo.Put("1", l1);

    list<string> l2;
    l2.push_back("3");
    Grafo.Put("2", l2);

    list<string> l3;
    l3.push_back("5");
    l3.push_back("6");
    l3.push_back("4");
    Grafo.Put("3", l3);

    list<string> l4;
    l4.push_back("6");
    Grafo.Put("4", l4);

    list<string> l5;
    l5.push_back("6");
    l5.push_back("7");
    Grafo.Put("5", l5);

    list<string> l6;
    l6.push_back("8");
    Grafo.Put("6", l6);

    list<string> l7;
    l7.push_back("8");
    Grafo.Put("7", l7);

    list<string> l8;
    Grafo.Put("8", l8);
    cout << "Digite quais pontos:" << endl;
    string ini, fin;
    cin >> ini;
    cin >> fin;
    cout << Pesquisa_Largura(Grafo, ini, fin) << endl;

    return 0;
}