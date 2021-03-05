# O Principio da substituição de Barbara Liskov

Barbara Liskov, uma cientista da computação,  introduziu em 1987 os primeiros principios da substituição de liskov: 


### O Principio da substituição:

> Se S é subtipo de T, então S deve poder ser usado em qualquer situação em que T pode ser usado.

Por exemplo: 

```c++
struct Retangle {
    // code ...
}
struct Square: Retangle {
    // code ...
}

int main () {
    Retangle* r = new Square();
    return 0;
}
```

No caso acima é possivel quebrar o comportamento da substituição ?

SIm, quando os coportamentos da classe Square não condizem com os da classe retangle.

Vamos ver em código: 


```c++
#include "assert.h"
#include "doctest.h"

class Rectangle {
    public: 
        Rectangle(double width, double height) {
            setWidth(width);
            setHeight(height);
        }
        double getWidth() const {return _width;}
        double getHeight() const {return _height;}
        void setWidth(double width) {
            assert(width >= 0.0 && "Width Cannot Bet Negative");
            _width = width;
        }
        void setHeight(double height) {
            assert(height >= 0.0 && "Height Cannot Bet Negative");
            _height = height;
        }
        double getArea() const { return _width * _height; }
    private: 
        double _width;
        double _height;
};

//  As unicas mudanças foram as implementações do método SET.
class Square: public Rectangle [
    public: 
        Square(double side): Rectangle (side, side) {         
        }
        virtual void setWidth(double side) {
            assert(side >= 0.0 && "Width cannot be negative");
            Rectangle::setWidth(side);
            Rectangle::setHeight(side); // Problema de pos condição para Height
        }
        virtual void setHeight(double side) {
            assert(side >= 0.0)
        }
}


// Utilização de TDD;

TEST_CASE("Testing the rectangle class:" ) {
    Rectangle rect(2.0, 3.0);
    CHECK(rect.getWidth() == 2.0);
    CHECK(rect.getHeight() == 3.0);
    CHECK(rect.getArea() == 6.0);
    rect.setWidth(4.0);
    CHECK(rect.getWidth() == 4.0);
    CHECK(rect.getHeight() == 3.0);
    CHECK(rect.getArea() == 12.0);
    rect.setHeight(5.0);
    CHECK(rect.getWidth() == 4.0);
    CHECK(rect.getHeight() == 5.0);
    CHECK(rect.getArea() == 20.0);
}


TEST_CASE("Testing the Square class:" ) {
    Square sq(3.0);
    CHECK(rect.getWidth() == 3.0);
    CHECK(rect.getHeight() == 3.0);
    CHECK(rect.getArea() == 9.0);
    rect.setWidth(4.0);
    CHECK(rect.getWidth() == 4.0);
    CHECK(rect.getHeight() == 4.0);
    CHECK(rect.getArea() == 16.0);
    rect.setHeight(5.0);
    CHECK(rect.getWidth() == 5.0);
    CHECK(rect.getHeight() == 5.0);
    CHECK(rect.getArea() == 25.0);
}
```

Certo, até aqui tudo está lindoo!! 

Mas vamos implementar algumas funções e vamos fazer um novo teste: 

```c++
void incAreas(std::vector<Rectangle*>& vec, const double factor) {
    for (Rectangle* r: vec) {
        r->setHeight(r->getHeight() * factor);
    }
}
double sumAreas(std::vector<Rectangle*>& vec) {
    double sum = 0.0;
    for (Rectangle* r: vec) {
        sum += r->getArea();
    }
    return sum;
}

TEST_CASE("Testing the function that manipulate areas:") {
    Rectangle *r0 = new Rectangle(2.0, 3.0);
    Rectangle *r1 = new Square(5.0);
    std::vector<Rectangle*> vec;
    vec.push_back(r0);
    vec.push_back(r1)
    SUBCASE("sumAreas:") {
        CHECK(sumAreas(vec) == 31.0);
    }
    SUBCASE("incAreas:") {
        incAreas(vec, 1.1);
        CHECK(sumAreas(vec) == 1.1 * 31.0);
    }
}
```

No codigo acima o teste vai falhar, pois não há uma asserção garantindo o valor que vai chegar em height do **Square**. Além de tudo não é um bom código.

com isso temos a: 

### Lei da Herança

Se S é subtipo de T, então: 

* Pré-condições em S não podem ser mais restritivas que em T
* Pos-condições em S não podem ser mais relaxadas que em T
* Invariantes de T tem de ser preservadas em S



Em Rectangle, tinhamos uma pos condição implicita que ao alterar a altura tinha a largura inalterada.

Mas em square isso não é definido para Square, ja que se alterar um, altera o outro.

Como vamos corrigir o código ?

Teste para Rectangle

```c++
TEST_CASE("Testing the rectangle class:" ) {
    Rectangle rect(2.0, 3.0);
    CHECK(rect.getWidth() == 2.0);
    CHECK(rect.getHeight() == 3.0);
    CHECK(rect.getArea() == 6.0);
}
```

Classe retangulo:
Vamos remover as funções de Set e manter Height e Width como constantes.
```c++
class Rectangle {
    public: 
        Rectangle(double width, double height): _width(width), _height(height) {}
            
        double getWidth() const {return _width;}
        double getHeight() const {return _height;}
        double getArea() const { return _width * _height; }
    private: 
        const double _width;
        const double _height;
};
```

Classe Square: 
vamos apenas extender de triangulo e redefinir o construtor: 

```c++
class Square: public Rectangle {
    public: 
        Square(double side): Rectangle (side, side) {}
}
```

Métodos de serviços para lidarem com constantes: 

```c++

void incAreas( std::vector<Rectangle*>& src, std::vector<Rectangle*>& dst,  const double factor) {
    dst.clear();
    for (Rectangle* r: src) {
        dst.push_back(new Rectangle(r->getWidth(), r->getHeight() * 1.1));
    }
}
```

Por fim a implementação dos testes: 

```c++

TEST_CASE("Testing the function that manipulate areas:") {
    Rectangle *r0 = new Rectangle(2.0, 3.0);
    Rectangle *r1 = new Square(5.0);
    std::vector<Rectangle*> vec;
    vec.push_back(r0);
    vec.push_back(r1);
    std::vector<Rectangle*> dst;
    SUBCASE("sumAreas:") {
        CHECK(sumAreas(vec) == 31.0);
    }
    SUBCASE("incAreas:") {
        incAreas(vec, dst, 1.1);
        CHECK(sumAreas(dst) == 1.1 * 31.0);
        for (Rectangle* r: dst) { // Limpar o vector:
            delete r;
        } 
    }
    delete r0;
    delete r1;
    }
}

```


## Quando iremos utilizar a Herança ?

A herança é um mecanismo para estender um software já implementado.

Algumas boas praticas citadas por Bertrand Meyer são> 

1. Adicionar uma nova funcionalidade
2. Redefinir uma funcionalidade já existente ao módulo.
3. Adicionar uma nova propriedade invariante.

<hr>

# Comparação entre objetos

Imagine uma classe de ponto: 

```c++
class Point {
    public: 
        Point(double xx, double yy): x(xx), y(yy) {}
        const double x,y;
}

bool operator == (const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

// testando: 

#include "Point.h"
int main () {
    Point p0(1.0, 1.0);
    Point p1(1.0, 1.0);
    Point p2(1.0, 1.0);

    std::cout << (p0 == p0) << std::endl;
    std::cout << (p0 == p1) << std::endl;
    std::cout << (p1 == p0) << std::endl;
    std::cout << (p1 == p2) << std::endl;
    std::cout << (p0 == p2) << std::endl;
}

```
Aqui temos uma relação de igualdade entre os objetos: 

* Reflexiva: p0 == p0
* Simétrica: p0 == p1 -> p1 == p0
* Transitiva: p0 == p1 ^ p1 == p2 -> p0 == p2


Mas acontece que nem sempre é facil garantir isso em modelos orientados a objetos, (principalmente quando há o uso da herança).

por exemplos: 

```c++
class ColoredPooint: publice Point {
    public:
        ColoredPoint (double xx, double yy, unsigned rr, unsigned gg, unsigned bb): 
            Point(xx, yy), r(rr), g(gg), b(bb) {}
        const unsigned r, g, b;
};
```

O que aconteceria se fizessemos isso:

```c++ 
int main () {
    Point p0(2.3, 4.1);
    ColoredPoint p1(2.3, 4.1, 34, 21, 110); 
    std::cout << (p0==p1) << std::endl; //  True, com o operador == já definido
}
```

mas e se adicionarmos o código: 
```c++ 

bool operator == (const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator == (const ColoredPoint &lhs, const ColoredPoint &rhs) {
    return (Point&)lhs == (Point&)rhs &&
    lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}


int main() {
    Point p0(2.3, 4.1);
    Point p1(2.3, 4.1);
    ColoredPoint p2(2.3, 4.1, 34, 21, 110);
    ColoredPoint p3(2.3, 4.1, 43, 12, 11);
    std::cout << (p2 == p3) << std::endl; // Falso, segundo ==
    std::cout << (p0 == p2) << std::endl; // True, primeiro == 
    std::cout << (p0 == p3) << std::endl; // True, primeiro == 
    std::cout << (p2 == p3) << std::endl; // False, segundo ==
}
```

Aqui o == perdeu a propriedade de equivalência.

<hr>

Um dos grandes problemas de POO  é implementar igualdade em relação de equivalencia mantendo Reflexividade, Simetria, transitividade sem quebrar o principio de liskov.


<hr>

Vamos mostrar como implementar a comparação de ==  de uma forma que **não é boa**

podemos fazer da seguinte forma: 


Vamos considerar o tipo para fazer a comparação, assim se for de tipos diferentes, sempre vamos dizer que é diferete: 


```c++
#include <typeinfo>
bool operator == (const Point &lhs, const Point &rhs) {
    bool t_lhs = typeid(lhs) == typeid(Point); // Verifica se o tipo é estritamente Point
    bool t_rhs = typeid(rhs) == typeid(Point); // Verifica se o tipo é estritamente Point
    if (t_lhs && t_rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    } else {
        return false;
    }
}

bool operator == (const ColoredPoint &lhs, const ColoredPoint &rhs) {
    bool t_lhs = typeid(lhs) == typeid(ColoredPoint); // Verifica se o tipo é ColoredPoint
    bool t_rhs = typeid(rhs) == typeid(ColoredPoint); // Verifica se o tipo é ColoredPoint
    if (t_lhs && t_rhs) {
        return lhs.x == rhs.y && lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
    } else {
        return false;
    }
}
```

Para tudo ocorrer certo, tempos que definir a classe com um método virtual, para que a classe **Point** aja de maneira polimorfica. Assim a operação vai considerar o tipo dinâmico da classe e não o seu tipo estático. : 

```c++
class Point {
    public:
        Point(double xx, double yy): x(xx), y(yy) {}
        virtual ~Point() {}
        const double x, y;
};
```

Para que o seguinte possa acontecer: 

```c++
int main() {
    Point *p0 = new Point(1.0, 1.0); //O tipo estatico é Point e o Dinamico é Point
    Point *p1 = new ColoredPoint(1.0, 1.0, 0, 0, 0); //O tipo estatico é Point e o Dinamico é ColoredPoint
    std::cout << (*p0 == *p1) << std::endl; // aqui vai ser comparado Point == ColoredPoint
    // Retorna False.
    return 0;
}
```


Por fim chegamos ao seguinte reusltado: 
```c++
int main() {
    Point p0(1.0, 1.0);
    Point p1(1.0, 1.0);
    ColoredPoint p2(1.0, 1.0, 0, 0, 0);
    ColoredPoint p3(1.0, 1.0, 0, 0, 0);
    std::cout << (p0 == p1) << std::endl; // True
    std::cout << (p0 == p2) << std::endl; // False 
    std::cout << (p2 == p3) << std::endl; // True
}
```


O problema agora é que o nosso código não obedece mais o ***Principio da Substituição de Lisckov***

Exemplo da quebra do principio:

```c++
bool containsCenter(std::vector<Point*> &points) {
 Point center(.0, .0);
 for (Point *p: points) {
        if (*p == center) {
            return true;
        }
    }
    return false;
}
int main() {
    std::vector<Point*> points;
    for (int i = 0; i < 5; i++) {
        points.push_back(new ColoredPoint(i,i,0,0,0));
    }
    std::cout << containsCenter(points) << std::endl;
}
```


#### A chave para corrigir isso é utilizar a composição ao invés de herança:

Vamos usar composição para colocar Cor à um ponto: 

<u>Classe Point: </u>
```c++
class Point {
    public:
        Point(double xx, double yy): x(xx), y(yy) {}
        const double x, y;
};
bool operator == (const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
```

<u>Classe Color: </u>
```c++
class Color {
    public:
        Color(unsigned rr, unsigned gg, unsigned bb):
            r(rr), g(gg), b(bb) {}
        const unsigned r, g, b;
};
bool operator == (const Color &lhs, const Color &rhs) {
    return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}
```

<u>Classe ColorePoint</u> 
```c++
class ColoredPoint {
    Color& _c;
    Point& _p;
    public:
        ColoredPoint(Color &c, Point &p): _c(c), _p(p){}
        operator Point() const { return _p; } // Ensinamoes ColoredPoint a comportar como Point
};
```

assim podemos fazer: 

```c++
int main() {
    Point p(2.7, 3.1);
    Color c(100, 0, 0);
    ColoredPoint cp(c, p);
    Point p0 = cp;
    std::cout << p0.x;

    std::vector<Point> points;
    Color c(0, 0, 0);
    for (int i = 0; i < 5; i++) {
        Point p(i, i);
        ColoredPoint cp(c, p);
        points.push_back(cp);
    }
    std::cout << containsCenter(points);

    Point p(2.7, 3.1);
    Color c0(100, 0, 0);
    Color c1(100, 1, 1);
    ColoredPoint cp0(c0, p);
    ColoredPoint cp1(c1, p);
    std::cout << (p == cp0) << std::endl;
    std::cout << (p == cp1) << std::endl;
    std::cout << (cp0 == cp1) << std::endl; // depende de qual comparador vai ser usado.
}
```

A ideia e não manter omparações dieretas de ColoredPoints pois assim não vamos perder a transitividade.
