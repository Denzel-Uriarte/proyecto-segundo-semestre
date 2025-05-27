#pragma once
#pragma once
#ifndef EMOCION_H
#define EMOCION_H

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <iostream>

using namespace std;

class Habito;
class Meta;
class Corazoncito;

class Emocion {
    int nivelAnimo;
    int nivelEstres;

public:
    Emocion(int animo = 10, int estres = 0);

    int getNivelAnimo() const;
    int getNivelEstres() const;

    void setNivelAnimo(int animo);
    void setNivelEstres(int estres);

    void aumentarEstres();
    void aumentarAnimo();

    void disminuirEstres();
    void disminuirAnimo();
};

class Calendario {
private:
    time_t tiempoActual;
    time_t nacimiento;
public:
    void revisarNacimiento();
};

class Logro {
private:
    string nombre;
    string fechaDeObtencion;
    string descripcion;
public:
    Logro(string nombre, string fechaDeObtencion, string descripcion);

    string getNombre();
    string getFechaDeObtencion();
    string getDescripcion();

    void completarLogro() const;
};

class Meta {
private:
    string tipoMeta;
    double cantidadMeta;
    bool metaCumplida;
    double progresoMeta;
public:
    Meta(string tipoMeta, double cantidadMeta);

    // Sets
    void setTipoMeta(string Meta);
    void setCantidadMeta(double Cantidad);
    void setProgreso(double progreso);
    void setProgresoMeta(bool progreso);

    // Gets
    string getTipoMeta() const;
    double getCantidadMeta() const;
    double getProgresoMeta() const;
    bool getMetaCumplida() const;

    int marcarMeta();

    void aumentarProgreso();

    void calcularPorcentajeMeta() const;
};

class Consecuencia {
protected:
    vector<string> frases;

public:
    Consecuencia();
    virtual ~Consecuencia();

    virtual void mostrarFrase(const Emocion& emocion);
};

class ConsecuenciaPositiva : public Consecuencia {
public:
    ConsecuenciaPositiva();
    void mostrarFrase(const Emocion& emocion) override;
};

class ConsecuenciaNegativa : public Consecuencia {
public:
    ConsecuenciaNegativa();
    void mostrarFrase(const Emocion& emocion) override;
};

class Habito {
private:
    string nombre;
    string descripcionHabito;
public:
    Habito(string nombre, string descripcionHabito);

    void setNombre(const string& nuevoNombre);
    string getNombre() const;

    void setDescripcion(const string& nuevaDescripcion);
    string getDescripcion() const;
};

class Corazoncito {
private:
    int edad;
    string sexo, color;
    double peso, altura;
    Emocion emocionDeCora;
    unique_ptr<Habito> habitosCreados[3];
    unique_ptr<Meta> MetasCreadas;
    static int habitosGuardados;

public:
    Corazoncito(int edad, string sexo, double peso, double altura, Emocion emocionDeCora);

    void setEdad(int& edad);
    void setSexo(const string& sexo);
    void setColor(const string& color);
    void setPeso(double& peso);
    void setAltura(double& altura);
    void setEmocion(const Emocion& emocion);

    int getEdad() const;
    string getSexo() const;
    string getColor() const;
    double getPeso() const;
    double getAltura() const;
    Emocion getEmocion() const;

    void evaluarEstado() const;

    // Manejo de Habitos
    void crearHabito();
    void borrarHabito(int indice);
    void ImprimirHabitos();
    void revisarHabitosHechos();

    // Manejo de Metas
    void crearMeta();
    void revisarMeta();
    void aumentarProgreso();
};

#endif // EMOCION_H
