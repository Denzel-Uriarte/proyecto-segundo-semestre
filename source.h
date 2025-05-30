
#pragma once
#pragma once
#ifndef SOURCE_H
#define SOURCE_H

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

    void aumentarProgreso(int progreso);

    void calcularPorcentajeMeta() const;
};

class Consecuencia {
protected:
    vector<string> frases;

public:
    Consecuencia();
    virtual ~Consecuencia();

    virtual string mostrarFrase(const Emocion& emocion);
};

class ConsecuenciaPositiva : public Consecuencia {
public:
    ConsecuenciaPositiva();
    string mostrarFrase(const Emocion& emocion) override;
};

class ConsecuenciaNegativa : public Consecuencia {
public:
    ConsecuenciaNegativa();
    string mostrarFrase(const Emocion& emocion) override;
};

class Habito {
private:
    string nombre;
public:
    Habito(string nombre);

    void setNombre(const string& nuevoNombre);
    string getNombre() const;

};

class Corazoncito {
private:
    Emocion emocionDeCora;
    unique_ptr<Habito> habitosCreados[3];
    unique_ptr<Meta> MetasCreadas;
    static int habitosGuardados;
    bool metaExisten;

public:
    Corazoncito(Emocion emocionDeCora);


    void setEmocion(const Emocion& emocion);

    int getEdad() const;
    string getSexo() const;
    string getColor() const;
    double getPeso() const;
    double getAltura() const;
    Emocion getEmocion() const;
    int getEstres();
    int getAnimo();
    bool getMetaExisten();
    string getNombreMeta();


    string evaluarEstado() const;

    // Manejo de Habitos
    void crearHabito(string habitoTemp);
    void borrarHabito(int indice);
    void ImprimirHabitos();
    void revisarHabitosHechos();
    string getNombreHabito(int i);

    // Manejo de Metas
    void crearMeta(string meta, double cantidad);
    void revisarMeta();
    void aumentarProgreso(int progreso);
};

#endif // EMOCION_H