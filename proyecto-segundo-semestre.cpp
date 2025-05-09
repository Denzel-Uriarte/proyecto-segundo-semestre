// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos SSSSSSSSADSUBFUSGSFGGESBIFBTVEUBFJERNHVBGYEVCYFSHBFUSYRVESGYVCFHSBVURESYV.
// Diana G.
// Diego


#include <iostream>
#include <string>
using namespace std;

class Corazoncito {
private:
    int edad;
    string sexo;
    double peso;
    double altura;
};

class Emocion {

};

class Habito {

};

class HabitoDiario : public Habito {

};

class HabitoSemanal : public Habito {

};

class HabitoMensual : public Habito {

};

class Calendario {

};

class Logro {

};

class Meta {

};

/*
* Lo que se va a hacer enn esta clase es:
* cada que se incumpla con un hábito, esta va a llamar a una consecuencia negativa y le quitara puntos a corazonsito (CLASS EMOCION) :(
* Lo opuesto sucede si el habito de cumple
* Cada habito afectara en menor o mayor medida a corasonsito
*/

class Consecuencia {
    string nombre;
    int valorEstres;
    int valorAnimo;
public:
    void mostrarConsecuencias;
};

class ConsecuenciaPositiva : public Consecuencia {

};

class ConsecuenciaNegativa : public Consecuencia {

};




int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
