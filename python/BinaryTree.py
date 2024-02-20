class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
        self.level = None

    def __str__(self):
        return str(self.info)

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def create(self, val):
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root

            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info):
          self.info = info
          self.left = None
          self.right = None


       // this is a node of the tree , which contains info as data, left , right
'''
def height(root):
    if root is None:
        return -1
    return max(height(root.left), height(root.right)) + 1

def em_ordem(root):
    if root is None:
        return

    # Visita filho da esquerda.
    em_ordem(root.left)

    # Visita nodo corrente.
    print(root.info),

    # Visita filho da direita.
    em_ordem(root.right)

def pre_ordem(root):
    if not root:
        return

    # Visita nodo corrente.
    print(root.info),

    # Visita filho da esquerda.
    em_ordem(root.left)

    # Visita filho da direita.
    em_ordem(root.right)

def pos_ordem(root):
    if not root:
        return

    em_ordem(root.left)
    # Visita filho da esquerda.

    # Visita filho da direita.
    em_ordem(root.right)

    # Visita nodo corrente.
    print(root.info),


def insere(root, Node):
    """Insere um Node em uma árvore binária de pesquisa."""
    # Node deve ser inserido na root.
    if root is None:
        root = Node

    # Node deve ser inserido na subárvore right.
    elif root.info < Node.info:
        if root.right is None:
            root.right = Node
        else:
            insere(root.right, Node)

    # Node deve ser inserido na subárvore left.
    else:
        if root.left is None:
            root.left = Node
        else:
            insere(root.left, Node)


def busca(root, info):
    """Procura por uma info em uma árvore binária de pesquisa."""
    # Trata o caso em que a info procurada não está presente.
    if root is None:
        return None

    # A info procurada está na root da árvore.
    if root.info == info:
        return root

    # A info procurada é maior que a da root.
    if root.info < info:
        return busca(root.right, info)

    # A info procurada é menor que a da root.
    return busca(root.left, info)

def minimo(root):
    node = root
    while node.left is not None:
        node = node.left
    return node.info

def maximo(root):
    node = root
    while node.right is not None:
        node = node.right
    return node.info

def identicas(a, b):
    # 1. As duas árvores são vazias.
    if a is None and b is None:
        return True

    # 2. Nenhuma das árvores é vazia. Precisamos compará-las.
    if a is not None and b is not None:
        return ((a.info == b.info) and
                identicas(a.left, b.left) and
                identicas(a.right, b.right))

    # 3. Uma árvore é vazia mas a outra não.
    return False

def balanceada(root):
    # Uma árvore binária vazia é balanceada.
    if root is None:
        return True

    altura_esq = height(root.left)
    altura_dir = height(root.right)
    # Alturas diferem em mais de uma unidade.
    if abs(altura_esq - altura_dir) > 1:
        return False

    return balanceada(root.left) and balanceada(root.right)

def checa_simetrica(root):
    def simetricas(subarvore_esq, subarvore_dir):
        if not subarvore_esq and not subarvore_dir:
            return True
        elif subarvore_esq and subarvore_dir:
            return (subarvore_esq.info == subarvore_dir.info and
                    simetricas(subarvore_esq.left, subarvore_dir.right) and
                    simetricas(subarvore_esq.right, subarvore_dir.left))
        # Uma sub-árvore é vazia e a outra não.
        return False

    return not root or simetricas(root.left, root.right)

if __name__ == '__main__':
    tree = BinarySearchTree()
    t = int(input("quantos nós terá a arvore: "))

    arr = list(map(int, input().split()))

    for i in range(t):
        tree.create(arr[i])

    print("altura da arvore")
    print(height(tree.root))

    print("visita da orvore em ordem")
    print(em_ordem(tree.root))

    print("visita da orvore pre ordem")
    print(pre_ordem(tree.root))

    print("visita da orvore pos ordem")
    print(pos_ordem(tree.root))

    info = int(input("qual ramo que buscar: "))
    resultado = busca(tree.root, info)
    if resultado:
        print("Busca pela chave {}: Sucesso!".format(info))
    else:
        print("Busca pela chave {}: Falha!".format(info))

    print("menor elemento da BST: ", minimo(tree.root))
    print("maior elemento da BST: ", maximo(tree.root))