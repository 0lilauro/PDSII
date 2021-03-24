#include <iostream>
#include <vector>

template <class T, int N> class BoundedArray {
  public:
    class NegativeIndexException {
        public: std::string message = "Erro: indice negativo.";
    };
    class NotInitializedIndexException { 
        public: std::string message = "Erro: indice nao inicializado.";
    };
    class IndexGraterThanArrayException { 
        public: std::string message = "Erro: indice maior que arranjo.";
    };

    void set(int index, T value) {
        if(index < 0) {throw BoundedArray::NegativeIndexException();}
        if(index >= N) {throw BoundedArray::IndexGraterThanArrayException();}
        filledBouds.push_back(index);
        buf[index] = value;
    }

    T get(int index) {
        if(index < 0) {throw BoundedArray::NegativeIndexException();}
        if(index >= N) {throw BoundedArray::IndexGraterThanArrayException();}
        if(!indexWasChanged(index)) {throw BoundedArray::NotInitializedIndexException();}
        return buf[index];
    }
  private:
    T buf[N];
    std::vector<int> filledBouds;
    
    bool indexWasChanged(int index) {
        bool response = false;
        for(int it: this->filledBouds) {
            if(index == it) {
                response = true;
                break;
            }
        }
        return response;
    }
};

template <class T> void testArray() {
  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action) {
    int index;  
    std::cin >> index;
    try {
      if (action == 's') {
        T value;
        std::cin >> value;
        a.set(index, value);
      } else if (action == 'g') {
        std::cout << a.get(index) << std::endl;
      }
    } catch (typename BoundedArray<T, 8>::NegativeIndexException e) {
        std::cerr << e.message << std::endl;
    } catch (typename BoundedArray<T, 8>::IndexGraterThanArrayException e) {
        std::cerr << e.message << std::endl;
    } catch (typename BoundedArray<T, 8>::NotInitializedIndexException e) {
        std::cerr << e.message << std::endl;
    } catch (...) {
        std::cerr << "Erro desconhecido." << std::endl;
    }
  }
}

int main() {
  char type;
  std::cin >> type;
  switch(type) {
    case 'd':
      testArray<double>();
      break;
    case 'i':
      testArray<int>();
      break;
    case 's':
      testArray<std::string>();
      break;
  }
  return 0;
}