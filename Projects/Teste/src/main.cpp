#include <iostream>

#define SIZE 5

int main(){

// Para cada um dos itens seguintes, escreva uma única instrução que realiza a tarefa indicada (os comentários servem apenas para lhe auxiliar). Suponha que as variáveis do tipo long value1 e value2 tenham sido declaradas e que value1 tenha sido inicializado como 200000. As perguntas que não tem saída, não serão avaliadas mas podem ser feitas como revisão.

// Todas as impressões devem ser feitas na mesma linha, ou seja, não utilize endl. Deve ser adicionado um espaço em branco (" ") entre as impressões.

// Suponha que a constante simbólica SIZE foi definida como 5.

// 1. Declare a variável long_ptr como um ponteiro para um objeto do tipo long.

// 2. Atribua o endereço da variável value1 à variável ponteiro long_ptr

// 3. Imprima o valor do objeto apontado por long_ptr.

// 4. Atribua o valor do objeto apontado por long_ptr à variável value2

// 5. Imprima o valor de value2.

// 6. Imprima o endereço de value1

// 7. Imprima o endereço armazenado em long_ptr. 

// 8. O valor impresso é o mesmo que o endereço de value1? Imprima o resultado da comparação entre os endereços.

// 9. Declare um array do tipo unsigned int chamado values com cinco elementos e inicialize os elementos para os inteiros pares de 2 a 10. 

// 10. Declare um ponteiro v_ptr que aponta para um objeto do tipo unsigned int.

// 11. Utilize uma instrução for para imprimir os elementos do array values usando notação de array com [].

// 12. Escreva duas instruções separadas que atribuem o endereço inicial do array values à variável ponteiro v_ptr.

// 13. Utilize uma instrução for para imprimir os elementos do array values utilizando a notação de ponteiro/deslocamento.

// 14. Utilize uma instrução for para imprimir os elementos do array values utilizando a notação de ponteiro/deslocamento com o nome do array como o ponteiro.

// 15. Utilize uma instrução for para imprimir os elementos do array values utilizando [] no ponteiro para o array.

// 16. Referencie o quinto elemento de values utilizando a notação [] de array, a notação de ponteiro/deslocamento com o nome de array como o ponteiro, a notação de subscrito de ponteiro e a notação de ponteiro/deslocamento.

// 17. Mostre que endereço é referenciado por v_ptr + 3, e que valor é armazenado nessa localização.

// 18. Supondo que v_ptr aponte para values[4], que endereço é referenciado por v_ptr -= 4? Que valor é armazenado nessa localização?
   
    
    long value1=200000;
    long value2;
    
    long *long_ptr = &value1;
    //imprima o valor do objeto apontado por long_ptr
    std::cout << *long_ptr << " ";
    //Imprima o valor de value2
    value2 = *long_ptr;  
    std::cout << value2  << " ";
    //Imprima o endereço de value1
    std::cout << &value1  << " "; 
    //Imprima o endereço armazenado em long_ptr
    std::cout << long_ptr  << " ";
    //Imprima a comparação entre o endereço de value1 com o endereço armazenado em long_ptr
    std::cout << (&value1==long_ptr)  << " ";
    //imprimir os elementos do array values usando notação de array subscrito.
    unsigned int values[] = {2,4,6,8,10};
    
    unsigned int *v_ptr = nullptr;
    for(int i=0; i < 5; i++) {
        std::cout << values[i] << " ";
    }
    
    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento.
    v_ptr = &values[0]; 
    v_ptr = values; 
    
    for(int i=0; i < 5; i++) {
        std::cout << *(v_ptr+i) << " ";
    }
    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento com o nome de array como o ponteiro.
    for(int i=0; i < 5; i++) {
        std::cout << *(values+i) << " ";
    }
    //imprimir os elementos do array values utilizando subscritos no ponteiro para o array.
    for(int i=0; i < 5; i++) {
        std::cout << v_ptr[i] << " ";
    }
    //imprimir o quinto elemento de values utilizando a notação de subscrito de array,
    std::cout << values[4] << " "; // - Notação []


    
    //a notação de ponteiro/deslocamento com o nome de array como o ponteiro, 
        std::cout << *(values + 4)  << " "; // - Notação Ponteiro de deslocamento + nome do array
    //a notação de subscrito de ponteiro,
        
    std::cout << v_ptr[4] << " "; // - Notação Ponteiro como array
    //a notação de ponteiro/deslocamento.
    
    std::cout << *(v_ptr + 4) << " "; // - Notação Ponteiro com ponteiro de deslocamento
    //imprimir a comparação entre o valor armazenado em (v_ptr-4) e values[0]
    std::cout << (v_ptr+3) << " "; 
    std::cout << *(v_ptr+3) << " ";
    std::cout << *(v_ptr+3) << " ";
    
    
    std::cout << (v_ptr-4) << " ";
    std::cout << *(v_ptr-4) << " ";
    
    return 0;
}