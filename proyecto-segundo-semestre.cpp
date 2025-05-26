// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos Andres Salazar - 34539
// Diana Gabriela Aguilar - 3823
// Diego Alberto Ortega Munoz - 38900
#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <memory>


using namespace std;

class Habito;
class Meta;
class Corazoncito;

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

class Calendario {
private:
    time_t tiempoActual;
    time_t nacimiento;
public:


    void revisarNacimiento() {
        string nombre;
        ifstream inFile("corazoncito.txt");
        string line;
        if (inFile.is_open()) {
            getline(inFile, line); // Lee la primer linea del archivo
            cout << "El nombre de tu Corazoncito: " << line << endl; // Imprimimos la linea
            getline(inFile, line); // Lee la segunda linea del archivo
            cout << "Nacio el dia: " << line << endl; // Imprimimos la linea
            inFile.close();
        }
        else {
            cout << "Parece que es tu primera vez interactuando con Corazoncito." << endl;
            cout << "Creando..." << endl;
            cout << "Como lo quieres nombrar?" << endl;
            getline(cin, nombre);
            cout << "Corazoncito: " << nombre << endl;
            tiempoActual = time(0);
            struct tm datetime;
            localtime_s(&datetime, &tiempoActual);
            cout << "Creado el dia de hoy: "
                << datetime.tm_mday << "/" // Dia
                << (datetime.tm_mon + 1) << "/" // Mes
                << (datetime.tm_year + 1900) << endl; // Anio
            ofstream outFile("corazoncito.txt");
            if (outFile.is_open()) {
                outFile << nombre << endl; // Guardamos el nombre en el archivo
                outFile << datetime.tm_mday << "/" // Dia
                    << (datetime.tm_mon + 1) << "/" // Mes
                    << (datetime.tm_year + 1900) << endl; // Anio
                outFile.close();
            }
            else {
                cout << "Error leyendo/creando archivo";
            }
        }
    }

};

class Logro {
private:
    string nombre;
    string fechaDeObtencion;
    string descripcion;
public:
    Logro(string nombre, string fechaDeObtencion, string descripcion)
        : nombre(nombre), fechaDeObtencion(fechaDeObtencion), descripcion(descripcion) {}

    string getNombre() {
        return nombre;
    }
    string getFechaDeObtencion() {
        return fechaDeObtencion;
    }
    string getDescripcion() {
        return descripcion;
    }

    void completarLogro()const {
        cout << "Logro completado: " << nombre << endl;
        cout << "Fecha de obtencion: " << fechaDeObtencion << endl;
        cout << "Descripcion: " << descripcion << endl;
        // fechaDeObtencion = time(0);
    }
};

class Meta {
private:
    string tipoMeta;
    double cantidadMeta;// Se guarda cuanto quiere hacer de la meta
    bool metaCumplida; // marca si la meta ya fue cumplida
    double progresoMeta; // Marca el porcentaje de la meta
public:

    Meta(string tipoMeta, double cantidadMeta) {
        this->tipoMeta = tipoMeta;
        this->cantidadMeta - cantidadMeta;
        metaCumplida = 0;
        progresoMeta = 0;
    }

    // Sets
    void setTipoMeta(string Meta) {
        this-> tipoMeta = Meta;
    }
    void setCantidadMeta(double Cantidad) {
        this->cantidadMeta = Cantidad;
    }
    void setProgreso(double progreso) {
        this->progresoMeta = progreso;
    }
    void setProgresoMeta(bool progreso) {
        this->metaCumplida = progreso;
    }

    // Gets
    string getTipoMeta() const{
        return tipoMeta;
    }
    double getCantidadMeta() const{
        return cantidadMeta;
    }
    double getProgresoMeta() const{
        return progresoMeta;
    }
    bool getMetaCumplida() const{
        return metaCumplida;
    }


    int marcarMeta() { // Automaticamente revisa el progreso y una vez completado marca metaCumplida a 1
        if (progresoMeta >= cantidadMeta) {
            cout << "Felicidades, la Meta ha sido completada";
            metaCumplida = 1;
            return 1;
        }
        else {
            cout << "Sigue asi, pronto completaras la Meta";
            metaCumplida = 0;
            return 2;
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

class Consecuencia {
protected:
    vector<string> frases;

public:

    Consecuencia() {}

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
    unique_ptr<Habito> habitosCreados[3]; //Uso de smart pointers para que el manejo de la memoria se haga automaticamente
    unique_ptr<Meta> MetasCreadas;
    static int habitosGuardados;


public:
    Corazoncito(int edad, string sexo, double peso, double altura, Emocion emocionDeCora)
        : edad(edad), sexo(sexo), peso(peso), altura(altura), emocionDeCora(emocionDeCora) {}

    void setEdad(int& edad) { this->edad = edad; }
    void setSexo(const string& sexo) { this->sexo = sexo; }
    void setColor(const string& color) { this->color = color; }
    void setPeso(double& peso) { this->peso = peso; }
    void setAltura(double& altura) { this->altura = altura; }
    void setEmocion(const Emocion& emocion) { this->emocionDeCora = emocion; }

    int getEdad() const { return edad; }
    string getSexo() const { return sexo; }
    string getColor() const { return color; }
    double getPeso() const { return peso; }
    double getAltura() const { return altura; }
    Emocion getEmocion() const { return emocionDeCora; }



    void evaluarEstado() const {  //funcion que llama los niveles de corazoncito
        int estres = emocionDeCora.getNivelEstres();
        int animo = emocionDeCora.getNivelAnimo();

        Consecuencia* consecuencia{};

        if (estres > 6 && animo < 6) { //dependiendo de su niveles, da una consecuencia negativa o positiva
            consecuencia = new ConsecuenciaNegativa();
        }
        else if (estres > 6 && animo > 6) {
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

        consecuencia->mostrarFrase(emocionDeCora);
        delete consecuencia;
    }

    //Manejo de las clase Habito
    void crearHabito() {
        string habitoTemp;
        string descripcionTemp;
        cout << "Que Habito deseas agregar" << endl;
        cin.ignore();
        getline(cin, habitoTemp);

        cout << "Descripcion del habito" << endl;
        getline(cin, descripcionTemp);

        habitosCreados[habitosGuardados] = std::make_unique<Habito>(habitoTemp, descripcionTemp);
        habitosGuardados++;
    }

    void borrarHabito(int indice) {
        if (indice >= 0 && indice < 3) {
            habitosCreados[indice].reset(); //reset limpia el aputandor, sacandalo del scope
            habitosGuardados--;
        }
    }

    void ImprimirHabitos() {
        for (int i = 0; i < 3; i++) {
            cout << "Habito: " << endl;
            cout << habitosCreados[i]->getNombre();
        }
    }

    void revisarHabitosHechos() //funcion de revisar habitos para el fin del dia (va ser usado dentro de la clase de calendario//
    {
        cout << "Marca si has cumplido tus habitos de hoy! :D" << endl;

        for (int i = 0; i < 3; ++i) { //ciclo for que itera la cantidad de habitos
            cout << habitosCreados[i]->getNombre() << ": " << habitosCreados[i]->getDescripcion() << endl; //desplega
            cout << "¿Has cumplido este hábito? (s/n): ";
            char respuesta; //una letra
            cin >> respuesta;

            do {
                if (respuesta == 's' || respuesta == 'S') {
                    cout << "YAYYY!!!!! Corazoncito te ama!" << endl;
                    emocionDeCora.aumentarAnimo(); //aumente el animo actual
                    emocionDeCora.disminuirEstres(); // disminuya el estres actual
                    break;
                }
                else if (respuesta == 'n' || respuesta == 'N') {
                    cout << "........ :(" << endl;
                    emocionDeCora.aumentarEstres(); //aumenta el estres actual
                    emocionDeCora.disminuirAnimo(); //disminuia el animo actual
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
    //Manejo de la clase de Meta

    void crearMeta() {//Se crea un objeto de Meta y se guarda en 

        string meta;
        double cantidad;
        cout << "Eliga la meta que desea realizar" << endl;
        //Metas disponibles: dormir, correr, comer, ejercicio.
        cin.ignore();
        getline(cin, meta);



        cout << "Cuanto desea ralizar de la meta " << endl;
        //slider o botones para marcar cuanto quiere realizar de la meta
        cin >> cantidad;

        MetasCreadas = std::make_unique<Meta>(meta, cantidad);

    }
    void revisarMeta() {// Funcion que revisa si la meta ya fue completada llamando a la funcion de marcar Meta
        int valorRetorno = MetasCreadas->marcarMeta();
        if (valorRetorno == 1) {
            emocionDeCora.disminuirEstres();
            emocionDeCora.aumentarAnimo();
        }
       
    }
};

int habitosGuardados = 0;
