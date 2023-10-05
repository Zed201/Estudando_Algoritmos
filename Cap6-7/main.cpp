#include <iostream>
#include <string>
#include <list>
#include <array>
#include <time.h>
#include <stdarg.h>
using namespace std;

// pesquisa em largura
namespace PL{
    template <class T>
    class Fila{ // implementação de uma fila sem o queue, a principio queria fazer sem lib alguma, mas na implementacao de hashtable tive que add então mudei de ponteiro para list
        private:
            //unsigned int tamanho = 0;
            //T *dados;
            list<T> dados;

        public:
            unsigned int qtdDados = 0;
            // Fila(int tam)
            // {
            //     this->tamanho = tam;
            //     //this->dados = (T*) malloc(sizeof(T) * tam);
            // }

            // void NovoTamanho(int nTam){
            //     this->tamanho = nTam;
            //     this->dados = (T *)realloc(this->dados, sizeof(T) * nTam);
            // }
            T pop(){
                // T Fitem = this->dados[0];
                // // arrumar essa implementacao, muito lenta
                // for (int i = 0; i < this->tamanho - 1; i++)
                // {
                //     this->dados[i] = this->dados[i + 1];
                // }
                // this->NovoTamanho(this->tamanho - 1);
                // this->qtdDados--;
                typename list<T>::iterator i = this->dados.begin();
                T Fitem = *i;
                this->dados.pop_front();
                this->qtdDados = this->dados.size();
                return Fitem;
            }
            void push(T nDado){
                // if (this->qtdDados == this->tamanho)
                // {
                //     this->dados = (T *)realloc(this->dados, sizeof(T) * this->tamanho);
                //     this->NovoTamanho(this->tamanho + 1);
                // }
                // this->dados[this->qtdDados] = nDado;
                // this->qtdDados++;
                this->dados.push_back(nDado);
                this->qtdDados = this->dados.size();
            }
            void view(){
                for (T i: this->dados)
                {
                    cout << i << endl;
                }
            }
            bool isIn(T dado){
                for (T i: this->dados)
                {
                    if (dado == i)
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

    
    class Grafo {
        private:
            HashTable<string, list<string>> Tabela;
        public:
            // Funcao para adicionar um vertice
            void AddVertex(string nome_p, int qtd_lig, ...){
                list<string> lista_vertices;
                if (qtd_lig != 0)
                {
                    va_list lista_args;
                    va_start(lista_args, qtd_lig);

                    for (int i = 0; i < qtd_lig; i++)
                    {
                            // o var_args não reconhece o string, e se eu colocar o tipo do grafo de char* ele da erro na funcao de hash
                            lista_vertices.push_back(va_arg(lista_args, char*));
                    }
                    va_end(lista_args);
                }
                
                Tabela.Put(nome_p, lista_vertices);
            }
    
            bool Pesquisa_Largura(string ini, string fin){
                Fila<string> fl, verificados;
                list<string> lisI = this->Tabela.LookUp(ini);
                for (auto i : lisI)
                {
                    fl.push(i);
                }
                while (fl.qtdDados > 0)
                {
                    string vert = fl.pop();
                    
                    if (!verificados.isIn(vert))
                    {
                        if (vert == fin)
                        {
                            cout << "Tem caminho" << endl;
                            return true;
                        } else {
                            verificados.push(vert);
                            list<string> lisV = this->Tabela.LookUp(vert);
                            for (string i : lisV)
                            {
                                fl.push(i);
                            }
                        }
                    }
                }
                cout << "nao achou" << endl;
                return false;
            }
    };
};

using namespace PL;

int main(){
    Grafo gf;
    gf.AddVertex("1", 1, "3");
    gf.AddVertex("2", 1, "3");
    gf.AddVertex("3", 3, "5", "6", "4");
    gf.AddVertex("4", 1, "6");
    gf.AddVertex("5", 2, "7", "6");
    gf.AddVertex("6", 1, "8");
    gf.AddVertex("7", 1, "8");
    gf.AddVertex("8", 0);

    string ini, fin;
    cin >> ini;
    cin >> fin;
    time_t t1 = clock();
    cout << gf.Pesquisa_Largura(ini, fin) << endl;
    cout << (clock() - t1) / CLOCKS_PER_SEC << "s" << endl;    

    return 0;
}