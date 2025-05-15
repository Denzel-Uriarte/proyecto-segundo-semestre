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

using namespace std;


class Habito;
class Meta;

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

class Habito {
private:
    string nombre;
    string descripcionHabito;
public:
    Habito(string nombre, string descripcionHabito) : nombre(nombre), descripcionHabito(descripcionHabito) {}

    //Sets y gets
    void setNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    // Getter para nombre
    string getNombre() const {
        return nombre;
    }

    // Setter para descripción
    void setDescripcion(const string& nuevaDescripcion) {
        descripcionHabito = nuevaDescripcion;
    }

    // Getter para descripción
    string getDescripcion() const {
        return descripcionHabito;
    }


};


class Corazoncito {
private:
    int edad;
    string sexo, color;
    double peso, altura;
    Emocion emocionDeCora;
    vector <unique_ptr<Habito>> habitosCreados; //Uso de smart pointers para que el manejo de la memoria se haga automaticamente
    vector <unique_ptr<Meta>> MetasCreadas;

public:

    Corazoncito(int edad, string sexo, double peso, double altura, Emocion EmocionDeCora) : edad(edad), sexo(sexo), peso(peso), altura(altura), emocionDeCora(emocionDeCora) {}

    //Sets
    void setEdad(int& e) { edad = e; }
    void setSexo(const string& s) { sexo = s; }
    void setColor(const string& c) { color = c; }
    void setPeso(double& p) { peso = p; }
    void setAltura(double& a) { altura = a; }
    void setEmocion(const Emocion& e) { emocionDeCora = e; }
    
    //Gets
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
        int estres = emocionDeCora.getNivelEstres();
        int animo = emocionDeCora.getNivelAnimo();

        if (estres < 6 || animo > 6) {
            ConsecuenciaNegativa negativa;
            negativa.mostrarFrase(emocionDeCora);
        }
        else if (estres > 6 || animo < 6) {
            ConsecuenciaPositiva positiva;
            positiva.mostrarFrase(emocionDeCora);
        }
    }
    //
    void crearHabito() {
        string habitoTemp;
        string descripcionTemp;
        cout << "Que Habito deseas agregar" << endl;
        cin.ignore();
        getline(cin, habitoTemp);

        cout << "Descripcion del habito" << endl;
        cin.ignore();
        getline(cin, descripcionTemp);


        habitosCreados.push_back(make_unique<Habito>(habitoTemp,descripcionTemp));//Se crea un objeto dinamico y se guarda automaticamente en el vector
    }

    void borrarHabito(int indice) {
        if (indice >= 0 && indice <= habitosCreados.size()) {

        }
    }

    void ImprimirHabitos() {
        for (auto& A : habitosCreados) {
            cout << A->getNombre() << endl;
        }
    }


};



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

    void marcarMeta()const { // Automaticamente revisa el progreso y una vez completado marca metaCumplida a 1
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

    void calcularPorcentajeMeta() const{ //Determinara automaticamente el porcentaje de la meta
        double porcentaje = (progresoMeta / cantidadMeta) * 100.0;

        cout << porcentaje << "%" << endl;
    }

};


