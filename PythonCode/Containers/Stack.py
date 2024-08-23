from abc import ABC, abstractmethod
class IInsert(ABC):
    @abstractmethod
    def insert(self, value):pass

class IStack(IInsert):
    #@abstractmethod
    #def insert(self, value):pass
    @abstractmethod
    def remove(self):pass
    @abstractmethod
    def top(self):pass
    @abstractmethod
    def clear(self):pass
    @abstractmethod
    def __str__(self):pass
    @abstractmethod
    def __repr__(self):pass

class Stack(IStack):
    def __init__(self, *ints):
        self._data_holder = [ints]
    def __init__(self):
        self._data_holder = []

    @property
    def top_id(self):
        return len(self._data_holder) - 1

    @property
    def is_empty(self):
        return len(self._data_holder) == 0

    @property
    def count(self):
        return len(self._data_holder)

    def insert(self, value):
        self._data_holder.append(value)

    def remove(self):
        if self.is_empty:
            return False
        self._data_holder.pop()
        return True

    def clear(self):
        self._data_holder.clear()

    def top(self):
        return self._data_holder[self.top_id] if not self.is_empty else None

    def __str__(self):
        elems = "Empty" if self.is_empty else "".join(f"[{item}]" for item in self._data_holder)
        return f"{super().__str__()}{{Count:{self.count},Top:{self.top()},Elems:{elems}}}"
    
    def __repr__(self):
        return f"Collection:Stack"