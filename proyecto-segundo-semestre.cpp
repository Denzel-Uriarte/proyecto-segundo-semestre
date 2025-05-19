// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos 
// Diana Aguilar - 38239
// Diego


#include <iostream>
#include <string>
#include <ctime>   
#include <cstdlib> // para funcion de system(CLS) {limpia la pantalla}
#include <vector>
#include <windows.h> //para la funcion Sleep()

using namespace std;


class Emocion {
    int nivelAnimo;
    int nivelEstres;

public:

    Emocion(int animo = 10, int estres = 0) : nivelAnimo(animo), nivelEstres(estres) {}

    int getNivelAnimo() const { return nivelAnimo; }
    int getNivelEstres() const { return nivelEstres; }


    void setNivelAnimo(int animo) { this->nivelAnimo = animo; }
    void setNivelEstres(int estres) { this->nivelEstres = estres; }

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

    virtual void mostrarFrase(const Emocion& emocion) {
        int estres = emocion.getNivelEstres();
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

class Habito {
private:
    string nombre;
    string descripcionHabito;
public:
    Habito(string nombre, string descripcionHabito) : nombre(nombre), descripcionHabito(descripcionHabito) {}

    //Sets y gets
    void setNombre(const string& nuevoNombre) {
        this->nombre = nuevoNombre;
    }

    // Getter para nombre
    string getNombre() const {
        return nombre;
    }

    // Setter para descripción
    void setDescripcion(const string& nuevaDescripcion) {
        this->descripcionHabito = nuevaDescripcion;
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
    Emocion EmocionDeCora;
    vector <unique_ptr<Habito>> habitosCreados; //Uso de smart pointers para que el manejo de la memoria se haga automaticamente
    Meta MetaCreada;

public:

    Corazoncito(int edad, string sexo, double peso, double altura, Emocion EmocionDeCora) : edad(edad), sexo(sexo), peso(peso), altura(altura), EmocionDeCora(EmocionDeCora) {}

    void setEdad(int& e) { this->edad = e; }
    void setSexo(const string& s) { this->sexo = s; }
    void setColor(const string& c) { this->color = c; }
    void setPeso(double& p) { this->peso = p; }
    void setAltura(double& a) { this->altura = a; }
    void setEmocion(const Emocion& e) { this->EmocionDeCora = e; }

    int getEdad() const { return edad; }
    string getSexo() const { return sexo; }
    string getColor() const { return color; }
    double getPeso() const { return peso; }
    double getAltura() const { return altura; }
    Emocion getEmocion() const { return EmocionDeCora; }


    void evaluarEstado() const {  //funcion que llama los niveles de corazoncito
        int estres = EmocionDeCora.getNivelEstres();
        int animo = EmocionDeCora.getNivelAnimo();

        Consecuencia* consecuencia;

        if (estres > 6 && animo < 6) { //dependiendo de su niveles, da una consecuencia negativa o positiva
            consecuencia = new ConsecuenciaNegativa();
        }
        else if (estres > 6 && animo > 6){
            consecuencia = new ConsecuenciaNegativa();
        }
        else if (estres < 6 && animo < 6)
        {
            consecuencia = new ConsecuenciaPositiva();
        }
        else if (estres < 6 && animo > 6)
        {
            consecuencia = new ConsecuenciaPositiva();
        }

        consecuencia->mostrarFrase(EmocionDeCora);
        delete consecuencia;
    }

    void crearHabito() {
        string habitoTemp;
        string descripcionTemp;
        cout << "Que Habito deseas agregar" << endl;
        cin.ignore();
        getline(cin, habitoTemp);

        cout << "Descripcion del habito" << endl;
        cin.ignore();
        getline(cin, descripcionTemp);


        habitosCreados.push_back(make_unique<Habito>(habitoTemp, descripcionTemp));//Se crea un objeto dinamico y se guarda automaticamente en el vector
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

    void revisarHabitosHechos() //funcion de revisar habitos para el fin del dia (va ser usado dentro de la clase de calendario//
    {
        cout << "Marca si has cumplido tus habitos de hoy! :D" << endl;

        for (int i = 0; i < habitosCreados.size(); ++i) { //ciclo for que itera la cantidad de habitos
            cout << habitosCreados[i]->getNombre() << ": " << habitosCreados[i]->getDescripcion() << endl; //desplega
            cout << "¿Has cumplido este hábito? (s/n): ";
            char respuesta; //una letra
            cin >> respuesta;

            do{
                if (respuesta == 's' || respuesta == 'S') {
                    cout << "YAYYY!!!!! Corazoncito te ama!" << endl;
                    EmocionDeCora.aumentarAnimo(); //aumente el animo actual
                    EmocionDeCora.disminuirEstres(); // disminuya el estres actual
                    break;
                }
                else if (respuesta == 'n' || respuesta == 'N') {
                    cout << "........ :(" << endl;
                    EmocionDeCora.aumentarEstres(); //aumenta el estres actual
                    EmocionDeCora.disminuirAnimo(); //disminuia el animo actual
                    break;
                }
                else
                {
                    cout << endl << "Error! letra invalida!!! o_O pon 's' o 'n'";
                }
        } while (true); //do while para acceptar solamente una letra valida, si no se accepta vuelva a preguntar para que ingrese una letra valida

        cout << endl;
            
        }

        evaluarEstado(); //despues de marcar cada meta, se llama evaluar estado para poner una frase neg o pos
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



        cout << "Cuanto desea realizar de la meta " << endl;
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

    void calcularPorcentajeMeta() const { //Determinara automaticamente el porcentaje de la meta
        double porcentaje = (progresoMeta / cantidadMeta) * 100.0;

        cout << porcentaje << "%" << endl;
    }

};






int main()
{
    srand(time(0));

    
}

