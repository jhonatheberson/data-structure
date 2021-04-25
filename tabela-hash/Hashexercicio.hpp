#include <vector>
#include<iostream>
#include <list>
#include <string>
using namespace std;

template<typename K, typename V>
class Tupla {
private:

public:
    K chave;
    V valor;
    Tupla(K c, V v) {
        chave = c;
        valor = v;
    }
    bool operator==(const Tupla<K, V> &t) {
        return t.chave == this->chave;
    }
};

template <typename Chave, typename Valor>
class TabelaHash {
		typedef std::list<Tupla<Chave, Valor> > Bucket;
	private:
		std::vector<Bucket *> *baldes;
        //quantidade de elementos já inseridos na baldes
        std::size_t quantidadeDeElementosInseridos;

	public:
	/**
    * Inicializar o array de tuplas com capacidade = qtde_buckets.
    * Lembrar de setar todas as posições do array inicializado
    * para NULL.
    * construtor
    * vamos iniciar com 16 o tamanho do bickets
    **/
    TabelaHash() {
        quantidadeDeElementosInseridos = 0;
        baldes = new std::vector<Bucket *>(8);

    }
    /**
     * descrutor
     * 
     * **/
    ~TabelaHash() {
        delete baldes;
    }
    /**
    * Essa é a função pública que nos permite inserir
    * uma tupla <c,v> na baldes. Nessa função nós
    * verificamos se é preciso aumentar o array de acordo
    * com o load factor. Essa função pode reusar sua versão
    * sobrecarregada para inserir a tupla na baldes.
    * Essa função também incrementa a quantidade de elementos
    * na baldes (variável quantidadeDeElementosInseridos).
    **/
    std::size_t getPos(Chave chave) {
        auto currentSize = baldes->size();
        return std::hash<Chave>{}(chave) % currentSize;
    }

    Bucket *getBucket(Chave chave) {
        auto pos = getPos(chave);
        return baldes->at(pos);
    }
    void inserir(Chave c, Valor v) {
        auto pos = getPos(c);
        if (baldes->at(pos) == nullptr)
            baldes->at(pos) = new Bucket;
        baldes->at(pos)->push_back(Tupla<Chave, Valor>(c, v));
        quantidadeDeElementosInseridos++;
        if (quantidadeDeElementosInseridos == baldes->size())
            resizeBuckets();
    }

    /**
    * Essa função retorna o fator de carga da Tabela Hash.
    **/
    double load_factor() {
        double tamanhoBalde{baldes->size()};
        double quantidadeDeElementos{this->quantidadeDeElementosInseridos};
        return quantidadeDeElementos / tamanhoBalde;
    }
    /**
    * Há apenas um valor associado a uma chave.
    * Essa função retorna esse valor, caso a chave exista.
    * Se a chave não existir a função retorna NULL.
    * Lembre-se: em caso de colisão, é preciso navegar
    * no Bucket (lista ligada) para ter certeza se a chave
    * existe ou não.
    **/
    Valor getValor(Chave chave) {
        auto balde = getBucket(chave);
        if (balde == nullptr)
            return NULL;
        for (auto &tupla : *balde)
            if (tupla.chave == chave)
                return tupla.valor;
        return NULL;
    }
    /**
    * Essa função retorna true caso a chave exista,
    * false caso contrário.
    * Lembre-se: em caso de colisão, é preciso navegar
    * no Bucket (lista ligada) para ter certeza se a chave
    * existe ou não.
    **/
    bool contemChave(Chave chave) {
        auto balde = getBucket(chave);
        if (balde == nullptr)
            return false;
        for (auto &tupla : *balde)
            if (tupla.chave == chave)
                return true;
        return false;
    }
    /**
    * Essa função retorna um vetor com todas as chaves
    * já inseridas na baldes.
    **/
    std::vector<Chave> getChaves() {
        std::vector<Chave> chaves;
        for (auto &balde : *baldes)
            if (balde != nullptr)
                for (auto &tupla : *balde)
                    chaves.push_back(tupla.chave);
        return chaves;
    };
    /**
    * Essa função desaloca os nós previamente alocados, e muda
    * o quantidadeDeElementosInseridos do array de tuplas para 8.
    **/
    void clear() {
        delete baldes;
        quantidadeDeElementosInseridos = 0;
        baldes = new std::vector<Bucket *>(8);
    };
    /**
    * Há apenas um nó associado com uma mesma chave.
    * Essa função remove esse nó da baldes, caso a chave exista.
    * Se a chave não existir a função não faz nada.
    * Lembre-se: em caso de colisão, é preciso navegar
    * no Bucket (lista ligada) para ter certeza se a chave
    * existe ou não.
    * Dica: olhar algoritmo de remoção em lista ligada, pois
    * após a remoção de um nó a lista precisa permanecer íntegra,
    * ou seja, navegável.
    **/
    void remover(Chave chave) {
        auto pos = getPos(chave);
        auto balde = baldes->at(pos);
        if (balde == nullptr)
            return;
        for (auto it = balde->begin(); it != balde->end(); it++) {
            if (it->chave == chave) {
                balde->remove(*it);
                break;
            }
        }
        quantidadeDeElementosInseridos--;
    }
    /**
    * Essa função retorna a quantidade de pares
    * que já foram inseridos na Tabela Hash.
    **/
    int size() {
        return quantidadeDeElementosInseridos;
    }
    /**
    * Essa função retorna o quantidadeDeElementosInseridos atual do
    * array usado para armazenar a Tabela Hash.
    **/
    int bucket_count() {
        return baldes->size();
    }
    void resizeBuckets() {
        auto currentSize = this->baldes->size();
        auto newSize = currentSize * 8;
        auto novoBalde = new std::vector<Bucket *>(newSize);
        for (auto &balde: *baldes) {
            if (balde == nullptr)
                continue;
            for (auto &tupla : *balde) {
                auto newPos = std::hash<Chave>{}(tupla.chave) % newSize;
                if (novoBalde->at(newPos) == nullptr)
                    novoBalde->at(newPos) = new Bucket;
                novoBalde->at(newPos)->push_back(tupla);
            }
        }
        delete baldes;
        baldes = novoBalde;
		}
};