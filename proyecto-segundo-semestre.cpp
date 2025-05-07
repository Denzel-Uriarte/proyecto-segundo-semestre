// Proyecto de segundo semestre
// Programación orientada a objetos
// Denzel Isaac Uriarte Munoz - 34684
// Carlos 
// Diana G.
// Diego


#include <iostream>
#include <string>
using namespace std;

class yo{};
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
private:
    string nombreHabito;
    string descrpicionHabito;
    bool habitoRealizado; // Marca si el habito de la meta ya fue realizado
    double progreso; //Porcentaje de progreso del habito
public:
    

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
private:
    string tipoMeta;
    double cantidadMeta;// Se guarda cuanto quiere hacer de la meta
    bool metaCumplida; // marca si la meta ya fue cumplida
    double progresoMeta; // Marca el porcentaje de la meta
public:
    
    void crearMeta(){ //Se le da la opcion de elegir entre opciones y que tanto quiere realizar de esa meta
        
        cout << "Eliga la meta que desea realizar" << endl;
        //Metas disponibles: dormir, correr, comer, ejercicio.
        
        
        
        cout << "Cuanto desea ralizar de la meta " <<endl;
        //slider o botones para marcar cuanto quiere realizar de la meta
    }
    
    void marcarMeta(){ // Automaticamente revisa el progreso y una vez completado marca metaCumplida a 1
        if(progresoMeta >= cantidadMeta){
            cout << "La meta ha sido completada" << endl;
        }else{
            cout << "La meta aun no ha sido completada" << endl;
        }
    }
    
    void aumentarProgreso(){ //Permite al usuario indicar que tanto avanzo para su meta
        
        double temp;// variable que suma al progesoMeta
        
        cin >> temp; //se puede utilizar un boton para marcar cuanto avanzo
        
        progresoMeta += temp;
        
        marcarMeta();//Automaticamente llama a la funcion
        
    }
    
    void calcularPorcentajeMeta(){ //Determinara automaticamente el porcentaje de la meta
        double porcentaje = (progresoMeta / cantidadMeta) * 100.0;
        
        cout << porcentaje << "%" << endl;
    }

};

class Consecuencia {

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
