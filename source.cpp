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
#include "source.h"

using namespace std;

class Habito;
class Meta;
class Corazoncito;

Emocion::Emocion(int animo, int estres) : nivelAnimo(animo), nivelEstres(estres) {}

int Emocion::getNivelAnimo() const { return nivelAnimo; }
int Emocion::getNivelEstres() const { return nivelEstres; }

void Emocion::setNivelAnimo(int animo) { nivelAnimo = animo; }
void Emocion::setNivelEstres(int estres) { nivelEstres = estres; }

void Emocion::aumentarEstres() { nivelEstres++; }
void Emocion::aumentarAnimo() { nivelAnimo++; }
void Emocion::disminuirEstres() { nivelEstres--; }
void Emocion::disminuirAnimo() { nivelAnimo--; }



void Calendario::revisarNacimiento() {
    string nombre;
    ifstream inFile("corazoncito.txt");
    string line;

    if (inFile.is_open()) {
        getline(inFile, line);
        cout << "El nombre de tu Corazoncito: " << line << endl;
        getline(inFile, line);
        cout << "Nació el día: " << line << endl;
        inFile.close();
    }
    else {
        cout << "Primera vez interactuando con Corazoncito. Creandolo..." << endl;
        cout << "¿Como lo quieres nombrar?" << endl;
        getline(cin, nombre);
        tiempoActual = time(0);
        struct tm datetime;
        localtime_s(&datetime, &tiempoActual);
        cout << "Creado el: " << datetime.tm_mday << "/" << (datetime.tm_mon + 1) << "/" << (datetime.tm_year + 1900) << endl;
        ofstream outFile("corazoncito.txt");
        if (outFile.is_open()) {
            outFile << nombre << endl;
            outFile << datetime.tm_mday << "/" << (datetime.tm_mon + 1) << "/"
                << (datetime.tm_year + 1900) << endl;
            outFile.close();
        }
    }
}


Logro::Logro(string nombre, string fechaDeObtencion, string descripcion)
    : nombre(nombre), fechaDeObtencion(fechaDeObtencion), descripcion(descripcion) {
}

string Logro::getNombre() { return nombre; }
string Logro::getFechaDeObtencion() { return fechaDeObtencion; }
string Logro::getDescripcion() { return descripcion; }

void Logro::completarLogro() const {
    cout << "Logro completado: " << nombre << endl;
    cout << "Fecha de obtencion: " << fechaDeObtencion << endl;
    cout << "Descripción: " << descripcion << endl;
}


Meta::Meta(string tipoMeta, double cantidadMeta)
    : tipoMeta(tipoMeta), cantidadMeta(cantidadMeta), metaCumplida(false), progresoMeta(0) {
}

void Meta::setTipoMeta(string Meta) { tipoMeta = Meta; }
void Meta::setCantidadMeta(double Cantidad) { cantidadMeta = Cantidad; }
void Meta::setProgreso(double progreso) { progresoMeta = progreso; }
void Meta::setProgresoMeta(bool progreso) { metaCumplida = progreso; }

string Meta::getTipoMeta() const { return tipoMeta; }
double Meta::getCantidadMeta() const { return cantidadMeta; }
double Meta::getProgresoMeta() const { return progresoMeta; }
bool Meta::getMetaCumplida() const { return metaCumplida; }

void Meta::aumentarProgreso() {
    progresoMeta += 5;
}

int Meta::marcarMeta() {  // ✅ Implementation in `Meta.cpp`
    if (progresoMeta >= cantidadMeta) {
        std::cout << "Felicidades, la Meta ha sido completada!" << std::endl;
        metaCumplida = true;
        return 1;
    }
    else {
        std::cout << "Sigue asi, pronto completaras la Meta." << std::endl;
        metaCumplida = false;
        return 2;
    }
}



void Meta::calcularPorcentajeMeta() const {
    double porcentaje = (progresoMeta / cantidadMeta) * 100.0;
    cout << porcentaje << "%" << endl;
}


Consecuencia::Consecuencia() {}
Consecuencia::~Consecuencia() {}

void Consecuencia::mostrarFrase(const Emocion& emocion) {
    int estres = emocion.getNivelEstres();
    int animo = emocion.getNivelAnimo();
}


ConsecuenciaPositiva::ConsecuenciaPositiva() {
    frases = { "Estoy feliz!", "Me siento genial!", "Boom boom pow!" };
}

void ConsecuenciaPositiva::mostrarFrase(const Emocion& emocion) {
    int indiceDeFrases = rand() % frases.size();
    cout << frases[indiceDeFrases] << endl;
}


ConsecuenciaNegativa::ConsecuenciaNegativa() {
    frases = { "Estoy triste...", "Me siento debil...", "Por favor... ya no mas..." };
}

void ConsecuenciaNegativa::mostrarFrase(const Emocion& emocion) {
    int indiceDeFrases = rand() % frases.size();
    cout << frases[indiceDeFrases] << endl;
}


Habito::Habito(string nombre) : nombre(nombre) {}

void Habito::setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

string Habito::getNombre() const {
    return nombre;
}



Corazoncito::Corazoncito(Emocion emocionDeCora) : emocionDeCora(emocionDeCora) {}

void Corazoncito::setEmocion(const Emocion& emocion) {
    emocionDeCora = emocion;
}

Emocion Corazoncito::getEmocion() const {
    return emocionDeCora;
}

void Corazoncito::evaluarEstado() const {
    int estres = emocionDeCora.getNivelEstres();
    int animo = emocionDeCora.getNivelAnimo();

    Consecuencia* consecuencia = nullptr;

    if (estres > 6 && animo < 6 || estres > 6 && animo > 6) {
        consecuencia = new ConsecuenciaNegativa();
    }
    else {
        consecuencia = new ConsecuenciaPositiva();
    }

    consecuencia->mostrarFrase(emocionDeCora);
    delete consecuencia;
}

void Corazoncito::crearHabito(string habitoTemp) {
    if (habitosGuardados < 3) {
        habitosCreados[habitosGuardados] = std::make_unique<Habito>(habitoTemp);
        habitosGuardados++;
    }
    else {
        cout << "Maximo de habitos alcanzado." << endl;
    }
}

void Corazoncito::borrarHabito(int indice) {
    if (indice >= 0 && indice < 3 && habitosCreados[indice]) {
        habitosCreados[indice].reset();
        habitosGuardados--;
    }
}

void Corazoncito::ImprimirHabitos() {
    for (int i = 0; i < habitosGuardados; i++) {
        if (habitosCreados[i]) {  //Verifica si el puntero no es nulo antes de acceder
            cout << "Habito: " << habitosCreados[i]->getNombre() << std::endl;
        }
        else {
            cout << "No has creado este habito " << std::endl;
        }
    }
}

string Corazoncito::getNombreHabito(int i) {
    if (i >= 0 && i < 3 && habitosCreados[i]) {
        return habitosCreados[i]->getNombre();
    }
    return "";
}

void Corazoncito::revisarHabitosHechos() {
    cout << "Marca si has cumplido tus habitos de hoy! :D" << endl;

    for (int i = 0; i < habitosGuardados; i++) {
        cout << habitosCreados[i]->getNombre() << endl;
        cout << "Has cumplido este habito? (s/n): ";
        char respuesta;
        cin >> respuesta;

        do {
            if (respuesta == 's' || respuesta == 'S') {
                cout << "YAYYY!!!!! Corazoncito te ama!" << endl;
                emocionDeCora.aumentarAnimo();
                emocionDeCora.disminuirEstres();
                break;
            }
            else if (respuesta == 'n' || respuesta == 'N') {
                cout << "........ :(" << endl;
                emocionDeCora.aumentarEstres();
                emocionDeCora.disminuirAnimo();
                break;
            }
            else {
                cout << "Error! Letra invalida! o_O Pon 's' o 'n'" << endl;
            }
        } while (true);
    }

    evaluarEstado();
}

void Corazoncito::crearMeta(string meta, double cantidad) {
    MetasCreadas = std::make_unique<Meta>(meta, cantidad);
    cout << "Meta creada: " << meta << " con frecuencia " << cantidad << endl;
}

void Corazoncito::revisarMeta() {
    if (MetasCreadas->marcarMeta() == 1) {
        emocionDeCora.disminuirEstres();
        emocionDeCora.aumentarAnimo();
    }
}

void Corazoncito::aumentarProgreso() {
    MetasCreadas->aumentarProgreso();
}


int Corazoncito::habitosGuardados = 0;