// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos 
// Diana - 38239
// Diego


#include <iostream>
#include <string>
#include <ctime>   //para funcion rand y srand
#include <cstdlib> // para funcion de system(CLS) {limpia la pantalla}
#include <vector> //manipular vector containers
#include <windows.h> //para la funcion Sleep()

using namespace std;


class Emocion {
    int nivelAnimo;
    int nivelEstres;

public:

    Emocion(int animo = 10, int estres = 0) : nivelAnimo(animo), nivelEstres(estres) {}

    int getNivelAnimo() const { return nivelAnimo; }
    int getNivelEstres() const { return nivelEstres; }


    void setNivelAnimo(int animo) { nivelAnimo = animo; }
    void setNivelEstres(int estres) { nivelEstres = estres; }

    void aumentarEstres() { nivelEstres++; }
    void aumentarAnimo() { nivelAnimo++; }

    void disminuirEstres() { nivelEstres--; }
    void disminuirAnimo() { nivelAnimo--; }


};

class Consecuencia {
protected:
    vector<string> frases;

public:

    Consecuencia() { }

    virtual ~Consecuencia() {}

    virtual void mostrarFrase(const Emocion& emocion) { //uso de override para llamar either consecuencia negativa o positiva
        int estres = emocion.getNivelEstres(); //saca los niveles de estres
        int animo = emocion.getNivelAnimo();
    }

};

class ConsecuenciaPositiva : public Consecuencia {


public:

    ConsecuenciaPositiva() {
        frases = {
            "Mi circulacion se siente bien!",
            "Oye, me siento bastante bien :D!",
            "Badump... Badump... lo siento, lato mas fuerte cuando estoy feliz. >_<",
            "> u <",
            ":3",
            "Me siento rojito :D",
            "yeeeeyyyyy xD",
            "boom boom pow!!! yeyooo!!! xD"
        };
    }

    void mostrarFrase(const Emocion& emocion) override {

        int indiceDeFrases = rand() % frases.size(); // selecionna un numero random de frases
        cout << frases[indiceDeFrases] << endl; //desplega
        Sleep(8000); // para imprimir para 8 segundos
        system("CLS"); //limpia la consola (borra todo) 
    }



};

class ConsecuenciaNegativa : public Consecuencia {



public:

    ConsecuenciaNegativa() {
        frases = {
            "Siento que mis arterias estan obstruidas...",
            "Oye... no te importa como me siento?",
            "Por que tienes que hacerme sentir asi...",
            "Dx",
            ");",
            "ayudame... D:",
            "porfavor... ya no mas.... T_T"
            "T_T"
        };
    }

    void mostrarFrase(const Emocion& emocion) override {

        int indiceDeFrases = rand() % frases.size(); // selecionna un numero random de frases
        cout << frases[indiceDeFrases] << endl; //desplega
        Sleep(8000); // para imprimir para 8 segundos
        system("CLS"); //limpia la consola (borra todo) 
    }

};

class Corazoncito {
private:
    int edad;
    string sexo, color;
    double peso, altura;
    Emocion EmocionDeCora;

public:

    Corazoncito(int edad, string sexo, double peso, double altura, Emocion EmocionDeCora) : edad(edad), sexo(sexo), peso(peso), altura(altura), EmocionDeCora(EmocionDeCora) {}

    void setEdad(int& e) { edad = e; }
    void setSexo(const string& s) { sexo = s; }
    void setColor(const string& c) { color = c; }
    void setPeso(double& p) { peso = p; }
    void setAltura(double& a) { altura = a; }
    void setEmocion(const Emocion& e) { EmocionDeCora = e; }

    int getEdad() const { return edad; }
    string getSexo() const { return sexo; }
    string getColor() const { return color; }
    double getPeso() const { return peso; }
    double getAltura() const { return altura; }
    Emocion getEmocion() const { return EmocionDeCora; }


    void personalizarCora()
    {

    }

    void actualizarColor(string& color)
    {

    }

    void evaluarEstado() const {  //funcion que llama los niveles de corazoncito
        int estres = EmocionDeCora.getNivelEstres();
        int animo = EmocionDeCora.getNivelAnimo();

        if (estres > 6 || animo < 6) { //dependiendo de su niveles, da una consecuencia negativa o positiva
            ConsecuenciaNegativa negativa;
            negativa.mostrarFrase(EmocionDeCora);
        }
        else {
            ConsecuenciaPositiva positiva;
            positiva.mostrarFrase(EmocionDeCora);
        }
    }


};



class Habito {

};


class Calendario {

};

class Logro {

};

class Meta {

};






int main()
{
    
}


