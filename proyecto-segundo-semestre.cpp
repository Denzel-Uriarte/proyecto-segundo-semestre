// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos 
// Diana G. - 38239
// Diego


#include <iostream>
#include <string>
#include <ctime>   
#include <cstdlib> 
#include <vector>

using namespace std;


class Emocion {
    int nivelAnimo ;
    int nivelEstres ;

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
    Emocion getEmocion() const { return emocionDeCora; }


    void personalizarCora()
    {

    }

    void actualizarColor(string& color)
    {

    }

    void evaluarEstado() const {
        int estres = EmocionDeCora.getNivelEstres();
        int animo = EmocionDeCora.getNivelAnimo();

        if (estres < 6 || animo > 6) {
            ConsecuenciaNegativa negativa;
            negativa.mostrarFrase(EmocionDeCora);
        }
        else if (estres < 6 || animo > 6)  {
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

class Consecuencia {
protected:
    vector<string> frases;

public: 

    Consecuencia() { } 

    virtual ~Consecuencia() {}

    virtual void mostrarFrase(const Emocion& emocion) {
        int estres = emocion.getNivelEstres();
        int animo = emocion.getNivelAnimo();

            int indiceDeFrases = rand() % frases.size();
            cout << frases[indiceDeFrases] << endl;
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
            "Me siento rojito :D"
        };
    }

    void mostrarFrase(const Emocion& emocion) override {
        Consecuencia::mostrarFrase(emocion);
    }

       

};

class ConsecuenciaNegativa : public Consecuencia {

   

public: 

    ConsecuenciaNegativa() {
        frases = {
            "Siento que mis arterias estan obstruidas...",
            "Oye... no te importa como me siento?",
            "Por que tienes que hacerme sentir así...",
            "Dx",
            ");",
            "ayudame... ):"
        };
    }

    void mostrarFrase(const Emocion& emocion) override {
        Consecuencia::mostrarFrase(emocion);
    }

};




int main()
{
    std::cout << "Hello World!\n";
}

