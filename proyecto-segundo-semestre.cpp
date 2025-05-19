// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos SSSSSSSSADSUBFUSGSFGGESBIFBTVEUBFJERNHVBGYEVCYFSHBFUSYRVESGYVCFHSBVURESYV.
// Diana G.
// Diego


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>

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

    Consecuencia() {}

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

class Corazoncito {
private:
    int edad;
    string sexo, color;
    double peso, altura;
    Emocion emocionDeCora;

public:

    Corazoncito(int edad, string sexo, double peso, double altura, Emocion EmocionDeCora) : edad(edad), sexo(sexo), peso(peso), altura(altura), emocionDeCora(emocionDeCora) {}

    void setEdad(int& e) { edad = e; }
    void setSexo(const string& s) { sexo = s; }
    void setColor(const string& c) { color = c; }
    void setPeso(double& p) { peso = p; }
    void setAltura(double& a) { altura = a; }
    void setEmocion(const Emocion& e) { emocionDeCora = e; }

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

    void evaluarEstado() const {  //funcion que llama los niveles de corazoncito
        int estres = emocionDeCora.getNivelEstres();
        int animo = emocionDeCora.getNivelAnimo();

        if (estres > 6 || animo < 6) { //dependiendo de su niveles, da una consecuencia negativa o positiva
            ConsecuenciaNegativa negativa;
            negativa.mostrarFrase(emocionDeCora);
        }
        else {
            ConsecuenciaPositiva positiva;
            positiva.mostrarFrase(emocionDeCora);
        }
    }


};

class Habito {
private:
    static Habito habitoDisponible[5];
    static Habito habitoLista[5];

    string nombreHabito;
    string descrpicionHabito;
    bool habitoRealizado;                               //Marca si el habito de la meta ya fue realizado
    int frecuenciaMeta;                                 //Cant. de veces necesarias para cumplir con el habito
    int frecuenciaHecha;                                //Cant. de veces realizadas
    string tipoHabito;                                  //Habito Diario, Semanal, etc.
    
public:
    Habito(string nombre, int frecuenciaMeta, string tipoHabito) : nombre(nombre), frecuenciaMeta(frecuenciaMeta), tipoHabito(tipoHabito) {}
    
    bool revisarProgreso(const Emocion& emocion, const ConsecuenciaPositiva& consPos, const ConsecuenciaNegativa& consNeg) { //Revisa que la meta se haya cumplido
        if (frecuenciaHecha >= frecuenciaMeta) {
            emocion.aumentarEstres();
            consPos.mostrarFrase(emocion);  //Si se cumple se manda a llamar a una consecuencia positiva
            return 1;
        }
        else { 
            emocion.disminuirEstres();
            consNeg.mostrarFrase(emocion); //Si NO se cumple se manda a llamar a una consecuencia negativa
            return 0;
        }
    }
    void mostrarProgreso() { 
        float progreso = (static_cast<double>(frecuenciaHecha) / static_cast<double>(frecuenciaMeta)) * 100; //establece el porcentaje 
        cout << "Tu progreso del habito " << tipoHabito << " de " << nombreHabito << " es:\n"; 
        cout << progreso << "%   (" << frecuenciaHecha << "de"<< frecuenciaMeta << ")\n"; 
        
    }

    void aumentarProgreso() { 
        int respuesta;

        cout << "Cuantas veces nuevas has realizado el habito " << nombreHabito << "? ";
        cin >> respuesta;
        frecuenciaHecha += respuesta; //A la frecuencia se le suma la respuesta para ir incrementando el progreso
        float progreso = (static_cast<double>(frecuenciaHecha) / static_cast<double>(frecuenciaMeta)) * 100; //establece el porcentaje 
        cout << "Habito actualizado\n";
    }
    /*void crearHabito() {
        int opc = 0;
        while (opc == 0) {
            cout << "Que tipo de habito deseas crear? \n";
            cout << "1. Habito Diario\n";
            cout << "2. Habito Semanal\n";
            cin >> opc;
            switch (opc) {
            case 1:
                tipoHabito = "Diario";
                break;
            case 2:
                tipoHabito = "Semanal";
                break;
            default:
                cout << "Opcion invalida.\n";
                opc = 0;
            }
        }


        
        //Lista de opciones de habitos a elegir 

        opc = 0;
        while (opc == 0) {
            cout << "Que habito desea implementar?\n";

            
        }
    }

    }

    string get_nombreHabito() { return nombreHabito; }
    string get_descrpicionHabito() { return descrpicionHabito; }
    bool get_habitoRealizado() { return habitoRealizado;} 
    int get_frecuenciaMeta() { return frecuenciaMeta; }; 
    int get_frecuenciaHecha() { return frecuenciaHecha; }; 
    string get_tipoHabito() { return tipoHabito; };*/
};
/*
void mostrarListaHabitos(const Habito& hab) {
    for (auto& c : habitoLista) {
        cout << hab.get_nombreHabito();
    }
};*/


class Calendario {

};

class Logro {

};

class Meta {
private:
    string tipoMeta;
    double cantidadMeta;// Se guarda cuanto quiere hacer de la meta
    bool metaCumplida; // marca si la meta ya fue cumplida
    double progresoMeta; // Marca el porcentaje de la meta
public:

    void crearMeta() { //Se le da la opcion de elegir entre opciones y que tanto quiere realizar de esa meta

        cout << "Eliga la meta que desea realizar" << endl;
        //Metas disponibles: dormir, correr, comer, ejercicio.



        cout << "Cuanto desea ralizar de la meta " << endl;
        //slider o botones para marcar cuanto quiere realizar de la meta
    }

    void marcarMeta() { // Automaticamente revisa el progreso y una vez completado marca metaCumplida a 1
        if (progresoMeta >= cantidadMeta) {
            cout << "La meta ha sido completada" << endl;
        }
        else {
            cout << "La meta aun no ha sido completada" << endl;
        }
    }

    void aumentarProgreso() { //Permite al usuario indicar que tanto avanzo para su meta

        double temp;// variable que suma al progesoMeta

        cin >> temp; //se puede utilizar un boton para marcar cuanto avanzo

        progresoMeta += temp;

        marcarMeta();//Automaticamente llama a la funcion

    }

    void calcularPorcentajeMeta() { //Determinara automaticamente el porcentaje de la meta
        double porcentaje = (progresoMeta / cantidadMeta) * 100.0;

        cout << porcentaje << "%" << endl;
    }

};




int main()
{
    cout << "------------------INICIO------------------\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
