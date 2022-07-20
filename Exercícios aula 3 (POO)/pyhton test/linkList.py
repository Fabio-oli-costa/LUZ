from no import No

class linkedList:
    def __init__(self): 
        self.inicio = None
        self.fim = None
        self._tam = 0

#insere no fim
    def append (self, elem):
        if self.inicio:
            pointer = self.inicio
            while(pointer.prox):
                pointer = pointer.prox
            pointer.prox = No(elem)
        else:
           self.inicio = No(elem) # caso seja primeira inserção
        self._tam = self._tam + 1

    def __len__(self):
        return self._tam #tamanho da lista

    def get(self, index):
        pass
    
    def set(self, index, elem):
        pass

    def __getitem__(self, index):
        pointer = self.inicio
        for i in range(index):
            if pointer:
                pointer = pointer.prox
            else:
                raise IndexError("Index fora do alcance")
        if pointer:
            return pointer.chave
        else:
            raise IndexError("Index fora do alcance")

    def __setitem__(self, index, elem):
        pointer = self.inicio
        for i in range(index):
            if pointer:
                pointer = pointer.prox
            else:
                raise IndexError("Index fora do alcance")
        if pointer:
            pointer.chave = elem
        else:
            raise IndexError("Index fora do alcance")