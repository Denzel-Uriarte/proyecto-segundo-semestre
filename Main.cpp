#include <SFML/Graphics.hpp>
#include <iostream>
#include "Corazoncito.h" 
#include <string>
#include <fstream>
#include <tuple>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <memory>


int menuAbierto = 0;
sf::Clock typeDelay;          // Reloj para controlar el tiempo entre letras
sf::Time typingDelay = sf::milliseconds(200);  // Delay entre letras (100ms)
bool metaCreada = 0;

float posTextoCorrectX = 15;
float posTextoCorrectY = -5;

sf::RectangleShape backgroundMargin;

sf::RectangleShape background; //Fondo al abrir nuevo menu

bool typingActive = false;
std::string currentInput = "";

sf::RectangleShape cursor;
sf::Clock cursorClock;
bool cursorVisible = true;
sf::Time cursorBlinkInterval = sf::milliseconds(500);

Emocion emocionCora(0,10);

Corazoncito Corazon(emocionCora);




// Inicializar botones
sf::RectangleShape botonAgregarHabito;
sf::RectangleShape s_botonAgregarHabito;

sf::RectangleShape botonBorrarHabito;
sf::RectangleShape s_botonBorrarHabito;

sf::RectangleShape botonAgregarMeta;
sf::RectangleShape s_botonAgregarMeta;

sf::RectangleShape botonAumentarMeta;
sf::RectangleShape s_botonAumentarMeta;

sf::RectangleShape botonCorrecto_HB;
sf::RectangleShape s_botonCorrecto_HB;
sf::Texture botonCorrectoTex;
sf::Sprite botonCorrecto;

sf::RectangleShape botonSalir_HB;
sf::RectangleShape s_botonSalir_HB;
sf::Texture botonSalirTex;
sf::Sprite botonSalir;

sf::RectangleShape botonSalir_HB_1;
sf::RectangleShape s_botonSalir_HB_1;
sf::Texture botonSalirTex_1;
sf::Sprite botonSalir_1;

sf::RectangleShape botonSalir_HB_2;
sf::RectangleShape s_botonSalir_HB_2;
sf::Texture botonSalirTex_2;
sf::Sprite botonSalir_2;

sf::RectangleShape botonSalir_HB_3;
sf::RectangleShape s_botonSalir_HB_3;
sf::Texture botonSalirTex_3;
sf::Sprite botonSalir_3;


sf::Font fontArial;
sf::Font fontPixelBig;
sf::Font fontPixelSlim;
sf::Font fontPixelSlimBold;
sf::Text inputTextMenu2;
sf::Text tituloInicio; //Texto Inicio
sf::RectangleShape botonInputTextoInicio; //Boton Escribir Inicio
sf::RectangleShape s_botonInputTextoInicio;
sf::Text inputTextInicio; //Insertar Texto Inicio

sf::Texture corazonTxt;
sf::Sprite corazon;

sf::RectangleShape s_botonCalendario;
sf::RectangleShape botonCalendario;
sf::Texture calendarioIconTxt;
sf::Sprite calendarioIcon;

sf::RectangleShape botonEditarMeta;
sf::RectangleShape s_botonEditarMeta;

sf::RectangleShape botonEditarHabito;
sf::RectangleShape s_botonEditarHabito;



sf::RectangleShape s_botonHabito;
sf::RectangleShape botonHabito;
sf::Texture habitoIconTxt;
sf::Sprite habitoIcon;

sf::RectangleShape barraProgreso;
sf::RectangleShape s_barraProgreso;

sf::Text nombreCorazon;
sf::RectangleShape nombreCorazon_HB;
sf::RectangleShape lineaNombreCorazon;
sf::RectangleShape s_lineaNombreCorazon;

sf::RectangleShape bloqueTituloCalendario;
sf::RectangleShape s_bloqueTituloCalendario;
sf::RectangleShape bloqueCalendario;
sf::RectangleShape s_bloqueCalendario;

sf::RectangleShape botonEditarNombre;
sf::RectangleShape s_botonEditarNombre;
sf::Text inputTextEditarNombre;

sf::Text HabitosTexto;
sf::Text MetasTexto;
sf::Text MetaTexto;
sf::Text nombreMeta;

sf::RectangleShape agregarHabito;

sf::Text TextAgregarMeta;
sf::Text TextAumentarMeta;

sf::Text TextAgregarHabito;
sf::Text TextBorrarHabito;

sf::Text IngresarHabito;
sf::Text InputIngresarHabito;
sf::RectangleShape botonInputHabito;


sf::Text IngresarMeta;
sf::Text InputIngresarMeta;
sf::RectangleShape botonInputMeta;


sf::Text IngresarCantidad;
sf::Text InputIngresarMetaCantidad;
sf::RectangleShape botonInputMetaCantidad;

sf::CircleShape bubble;
sf::Text animoCorazoncito;



vector<sf::RectangleShape> recuadrosHabitos;
vector<sf::Text> textosHabitos;


sf::Text aumentarMeta;
sf::RectangleShape CuadroAumentarMeta;
sf::Text metaAumentada;


//Funciones inicializar 
void initFonts() {
    if (!fontPixelBig.loadFromFile("Pixellari.ttf")) {
        std::cerr << "No se pudo cargar la fuente 'Pixellari.ttf'" << std::endl;
    }
    if (!fontPixelSlim.loadFromFile("PixelOperator8.ttf")) {
        std::cerr << "No se pudo cargar la fuente 'PixelOperator8.ttf'" << std::endl;
    }
    if (!fontPixelSlimBold.loadFromFile("PixelOperatorHBSC.ttf")) {
        std::cerr << "No se pudo cargar la fuente 'PixelOperatorHBSC.ttf'" << std::endl;
    }
    if (!fontArial.loadFromFile("arial.ttf")) {
        std::cerr << "No se pudo cargar la fuente 'arial.ttf'" << std::endl;
    }
}

void initBotonCorrecto() {
    if (!botonCorrectoTex.loadFromFile("Textures/BotonCorrecto.png"))
        std::cout << "Could not load BotonCorrecto.png\n";
    botonCorrecto.setTexture(botonCorrectoTex);
    botonCorrecto.setScale(sf::Vector2f(3, 3));
    botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    botonCorrecto_HB.setOutlineThickness(1);
    botonCorrecto_HB.setOutlineColor(sf::Color::Transparent);
    botonCorrecto_HB.setFillColor(sf::Color::Transparent);

    s_botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    s_botonCorrecto_HB.setOutlineThickness(0);
    s_botonCorrecto_HB.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonCorrecto_HB.setFillColor(sf::Color(0, 25, 50, 80));

  
}

void initBotonSalir() {
    if (!botonSalirTex.loadFromFile("Textures/BotonSalir.png"))
        std::cout << "Could not load BotonSalir.png\n";
    botonSalir.setTexture(botonSalirTex);
    botonSalir.setScale(sf::Vector2f(3, 3));
    botonSalir_HB.setSize(sf::Vector2f(50, 50));
    botonSalir_HB.setOutlineThickness(1);
    botonSalir_HB.setOutlineColor(sf::Color::Transparent);
    botonSalir_HB.setFillColor(sf::Color::Transparent);

    s_botonSalir_HB.setSize(sf::Vector2f(47, 47));
    s_botonSalir_HB.setOutlineThickness(0);
    s_botonSalir_HB.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB.setFillColor(sf::Color(0, 25, 50, 80));





}

void initInicio() {
    tituloInicio.setFont(fontPixelBig);
    tituloInicio.setString("Ingrese Nombre:");
    tituloInicio.setCharacterSize(30);
    tituloInicio.setFillColor(sf::Color(50, 50, 50));
    tituloInicio.setPosition(210, 345);

    botonInputTextoInicio.setSize(sf::Vector2f(300, 75));
    botonInputTextoInicio.setOrigin(125, 50);
    botonInputTextoInicio.setPosition(350, 450);
    botonInputTextoInicio.setOutlineThickness(5);
    botonInputTextoInicio.setOutlineColor(sf::Color(230, 200, 120));
    botonInputTextoInicio.setFillColor(sf::Color(240, 230, 180));

    s_botonInputTextoInicio.setSize(sf::Vector2f(300, 75));
    s_botonInputTextoInicio.setOrigin(125, 50);
    s_botonInputTextoInicio.setPosition(350 + 5, 450 + 5);
    s_botonInputTextoInicio.setOutlineThickness(5);
    s_botonInputTextoInicio.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonInputTextoInicio.setFillColor(sf::Color(0, 25, 50, 80));

    inputTextInicio.setFont(fontPixelSlim);
    inputTextInicio.setCharacterSize(30);
    inputTextInicio.setFillColor(sf::Color(0, 0, 0, 200));
    inputTextInicio.setPosition(250, 420);

    botonCorrecto.setPosition(475, 485);
    botonCorrecto_HB.setPosition(475, 485);
    s_botonCorrecto_HB.setPosition(475 + 5, 485 + 5);


    botonSalir.setPosition(420, 485);
    botonSalir_HB.setPosition(420, 485);
    s_botonSalir_HB.setPosition(420 + 5, 485 + 5);

    cursor.setSize(sf::Vector2f(2, 24)); // ancho y alto del cursor
    cursor.setFillColor(sf::Color::Black);
    cursor.setPosition(250, 420);
}

void initMenu0() {

    int estres = Corazon.getEstres();
    int animo = Corazon.getAnimo();


    if (estres > 6 && animo < 6 || estres > 6 && animo > 6) {
        if (!corazonTxt.loadFromFile("Textures/CorazonEnfermo.png"))
            std::cout << "Could not load CorazonSano.png\n";
        corazon.setTexture(corazonTxt);
        corazon.setScale(sf::Vector2f(10, 10));
    }
    else {
        if (!corazonTxt.loadFromFile("Textures/CorazonSano.png"))
            std::cout << "Could not load CorazonSano.png\n";
        corazon.setTexture(corazonTxt);
        corazon.setScale(sf::Vector2f(10, 10));
     }


    backgroundMargin.setOutlineThickness(20);
    backgroundMargin.setOutlineColor(sf::Color(120, 170, 190));
    backgroundMargin.setFillColor(sf::Color(170, 210, 220));
    backgroundMargin.setPosition(10, 10);
    backgroundMargin.setSize(sf::Vector2f(680, 880));

    corazon.setPosition(110, 300);
}

void initMenu1() {
    lineaNombreCorazon.setSize(sf::Vector2f(300, 10));
    lineaNombreCorazon.setPosition(200, 150);
    lineaNombreCorazon.setFillColor(sf::Color(220, 160, 180));

    s_lineaNombreCorazon.setSize(sf::Vector2f(300, 10));
    s_lineaNombreCorazon.setPosition(200 + 5, 150 + 5);
    s_lineaNombreCorazon.setFillColor(sf::Color(0, 25, 50, 80));

    nombreCorazon.setFont(fontPixelSlimBold);
    nombreCorazon.setCharacterSize(70);
    nombreCorazon.setPosition(200, 60);
    nombreCorazon.setFillColor(sf::Color(100, 120, 120));

    nombreCorazon_HB.setSize(sf::Vector2f(320, 100));
    nombreCorazon_HB.setPosition(190, 70);
    nombreCorazon_HB.setOutlineThickness(1);
    nombreCorazon_HB.setOutlineColor(sf::Color::Transparent);
    nombreCorazon_HB.setFillColor(sf::Color::Transparent);

    if (!calendarioIconTxt.loadFromFile("Textures/CalendarioIcon.png"))
        std::cout << "Could not load CalendarioIcon.png\n";
    calendarioIcon.setTexture(calendarioIconTxt);
    calendarioIcon.setScale(sf::Vector2f(7, 7));
    calendarioIcon.setPosition(57, 60);

    barraProgreso.setSize(sf::Vector2f(600, 70));
    barraProgreso.setOutlineThickness(7);
    barraProgreso.setOutlineColor(sf::Color(210, 110, 140));
    barraProgreso.setPosition(50, 800);
    barraProgreso.setFillColor(sf::Color(220, 160, 180));

    s_barraProgreso.setSize(sf::Vector2f(600, 70));
    s_barraProgreso.setOutlineThickness(7);
    s_barraProgreso.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_barraProgreso.setPosition(50 + 5, 800 + 5);
    s_barraProgreso.setFillColor(sf::Color(0, 25, 50, 80));

    botonEditarMeta.setSize(sf::Vector2f(300, 70));
    botonEditarMeta.setOutlineThickness(7);
    botonEditarMeta.setOutlineColor(sf::Color(210, 110, 140));
    botonEditarMeta.setPosition(50, 700);
    botonEditarMeta.setFillColor(sf::Color(220, 160, 180));

    s_botonEditarMeta.setSize(sf::Vector2f(300, 70));
    s_botonEditarMeta.setOutlineThickness(7);
    s_botonEditarMeta.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonEditarMeta.setPosition(50 + 5, 700 + 5);
    s_botonEditarMeta.setFillColor(sf::Color(0, 25, 50, 80));

    botonCalendario.setSize(sf::Vector2f(125, 125));
    botonCalendario.setOutlineThickness(7);
    botonCalendario.setOutlineColor(sf::Color(230, 190, 140));
    botonCalendario.setPosition(50, 50);
    botonCalendario.setFillColor(sf::Color(235, 240, 170));

    s_botonCalendario.setSize(sf::Vector2f(125, 125));
    s_botonCalendario.setOutlineThickness(7);
    s_botonCalendario.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonCalendario.setPosition(50 + 5, 50 + 5);
    s_botonCalendario.setFillColor(sf::Color(0, 25, 50, 80));

    botonEditarHabito.setSize(sf::Vector2f(280, 70));
    botonEditarHabito.setOutlineThickness(7);
    botonEditarHabito.setOutlineColor(sf::Color(210, 110, 140));
    botonEditarHabito.setPosition(370, 700);
    botonEditarHabito.setFillColor(sf::Color(220, 160, 180));

    s_botonEditarHabito.setSize(sf::Vector2f(280, 70));
    s_botonEditarHabito.setOutlineThickness(7);
    s_botonEditarHabito.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonEditarHabito.setPosition(370 + 5, 700 + 5);
    s_botonEditarHabito.setFillColor(sf::Color(0, 25, 50, 80));

    HabitosTexto.setFont(fontPixelBig);
    HabitosTexto.setString("Habitos");
    HabitosTexto.setCharacterSize(50);
    HabitosTexto.setFillColor(sf::Color(50, 50, 50));
    HabitosTexto.setPosition(430, 700);

    MetasTexto.setFont(fontPixelBig);
    MetasTexto.setString("Metas");
    MetasTexto.setCharacterSize(50);
    MetasTexto.setFillColor(sf::Color(50, 50, 50));
    MetasTexto.setPosition(130, 700);

    MetaTexto.setFont(fontPixelBig);
    MetaTexto.setString("Meta: ");
    MetaTexto.setCharacterSize(50);
    MetaTexto.setFillColor(sf::Color(50, 50, 50));
    MetaTexto.setPosition(90, 800);

    nombreMeta.setFont(fontPixelBig);
    if (Corazon.getMetaExisten() == 1) {
        nombreMeta.setString(Corazon.getNombreMeta());
    }
    else {
        nombreMeta.setString("No hay una meta Creada");
    }
    nombreMeta.setCharacterSize(30);
    nombreMeta.setFillColor(sf::Color(50, 50, 50));
    nombreMeta.setPosition(220, 810);




    bubble.setFillColor(sf::Color(255, 255, 255));
    bubble.setOutlineColor(sf::Color::Black);
    bubble.setOutlineThickness(2.f);
    bubble.setPosition(370, 250);
    bubble.setRadius(150);

    animoCorazoncito.setFont(fontPixelBig);
    animoCorazoncito.setString(Corazon.evaluarEstado());
    animoCorazoncito.setCharacterSize(35);
    animoCorazoncito.setFillColor(sf::Color(50, 50, 50));
    animoCorazoncito.setPosition(400, 350);


    if (!habitoIconTxt.loadFromFile("Textures/HabitoIcon.png"))
        std::cout << "Could not load HabitoIcon.png\n";
    habitoIcon.setTexture(habitoIconTxt);
    habitoIcon.setScale(sf::Vector2f(7, 7));
    habitoIcon.setPosition(530, 60);

    botonHabito.setSize(sf::Vector2f(125, 125));
    botonHabito.setOutlineThickness(7);
    botonHabito.setOutlineColor(sf::Color(230, 190, 140));
    botonHabito.setPosition(525, 50);
    botonHabito.setFillColor(sf::Color(235, 240, 170));

    s_botonHabito.setSize(sf::Vector2f(125, 125));
    s_botonHabito.setOutlineThickness(7);
    s_botonHabito.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonHabito.setPosition(525 + 5, 50 + 5);
    s_botonHabito.setFillColor(sf::Color(0, 25, 50, 80));
}

void initMenuCalendario() {

    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0, 0, 0, 100));

    inputTextMenu2.setFont(fontPixelBig);
    inputTextMenu2.setCharacterSize(20);
    inputTextMenu2.setFillColor(sf::Color::Black);
    inputTextMenu2.setPosition(55, 155);

    bloqueCalendario.setSize(sf::Vector2f(500, 500));
    bloqueCalendario.setOutlineThickness(7);
    bloqueCalendario.setOutlineColor(sf::Color(230, 190, 140));
    bloqueCalendario.setPosition(100, 250);
    bloqueCalendario.setFillColor(sf::Color(235, 240, 170));

    s_bloqueCalendario.setSize(sf::Vector2f(500, 500));
    s_bloqueCalendario.setOutlineThickness(7);
    s_bloqueCalendario.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_bloqueCalendario.setPosition(100 + 5, 250 + 5);
    s_bloqueCalendario.setFillColor(sf::Color(0, 25, 50, 80));

    bloqueTituloCalendario.setSize(sf::Vector2f(500, 70));
    bloqueTituloCalendario.setOutlineThickness(7);
    bloqueTituloCalendario.setOutlineColor(sf::Color(230, 190, 140));
    bloqueTituloCalendario.setPosition(100, 150);
    bloqueTituloCalendario.setFillColor(sf::Color(235, 240, 170));

    s_bloqueTituloCalendario.setSize(sf::Vector2f(500, 70));
    s_bloqueTituloCalendario.setOutlineThickness(7);
    s_bloqueTituloCalendario.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_bloqueTituloCalendario.setPosition(100 + 5, 150 + 5);
    s_bloqueTituloCalendario.setFillColor(sf::Color(0, 25, 50, 80));

    botonCorrecto.setPosition(550, 770);
    botonCorrecto_HB.setPosition(550, 770);
    s_botonCorrecto_HB.setPosition(550 + 5, 770 + 5);

    botonSalir.setPosition(495, 770);
    botonSalir_HB.setPosition(495 + 5, 770 + 5);
    s_botonSalir_HB.setPosition(495 + 5, 770 + 5);
}

void initMenuEditarNombre() { //Menu 3
    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0, 0, 0, 100));

    botonEditarNombre.setSize(sf::Vector2f(500, 70));
    botonEditarNombre.setOutlineThickness(7);
    botonEditarNombre.setOutlineColor(sf::Color(230, 190, 140));
    botonEditarNombre.setPosition(100, 150);
    botonEditarNombre.setFillColor(sf::Color(235, 240, 170));

    s_botonEditarNombre.setSize(sf::Vector2f(500, 70));
    s_botonEditarNombre.setOutlineThickness(7);
    s_botonEditarNombre.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonEditarNombre.setPosition(100 + 5, 150 + 5);
    s_botonEditarNombre.setFillColor(sf::Color(0, 25, 50, 80));

    inputTextEditarNombre.setFont(fontPixelSlim);
    inputTextEditarNombre.setCharacterSize(30);
    inputTextEditarNombre.setFillColor(sf::Color(0, 0, 0, 200));
    inputTextEditarNombre.setPosition(100, 150);

    botonCorrecto.setPosition(150, 550);
    botonCorrecto_HB.setPosition(150, 550);
    s_botonCorrecto_HB.setPosition(150 + 5, 550 + 5);

    botonSalir.setPosition(495, 770);
    botonSalir_HB.setPosition(495 + 5, 770 + 5);
    s_botonSalir_HB.setPosition(495 + 5, 770 + 5);
}

void initMenuEditarHabito() {
    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0, 25, 50, 120)); // Fondo oscuro transparente

    // Tamaño de los botones
    
    float spacing = 30; // Espacio entre los dos botones horizontales

    // Coordenadas para centrar horizontalmente los dos botones
    float totalWidth = 2 * 300 + spacing;
    float startX = (700 - totalWidth) / 2.0f;

    // Botón Agregar Hábito (izquierdo)
    botonAgregarHabito.setSize(sf::Vector2f(650, 70));
    botonAgregarHabito.setPosition(startX, 400);
    botonAgregarHabito.setFillColor(sf::Color(235, 240, 170));
    botonAgregarHabito.setOutlineThickness(5);
    botonAgregarHabito.setOutlineColor(sf::Color(230, 190, 140));

    s_botonAgregarHabito.setSize(sf::Vector2f(300, 70));
    s_botonAgregarHabito.setPosition(startX + 5, 405);
    s_botonAgregarHabito.setFillColor(sf::Color(0, 25, 50, 80));

    // Botón Aumentar Hábito (derecho)
    float secondButtonX = startX + 300 + spacing;


    // Botón Salir en la posición fija especificada
    botonSalir.setPosition(420, 485);
    botonSalir_HB.setPosition(420, 485);
    s_botonSalir_HB.setPosition(425, 490);



    TextAgregarHabito.setFont(fontPixelBig);
    TextAgregarHabito.setString("Agregar Habito");
    TextAgregarHabito.setCharacterSize(28);
    TextAgregarHabito.setFillColor(sf::Color(50, 50, 50));
    TextAgregarHabito.setPosition(280, 415);

}

void initMenuEditarMeta() {
    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0, 25, 50, 120)); // Fondo oscuro transparente

    // Tamaño de los botones
    float buttonWidth = 300;
    float buttonHeight = 70;
    float spacing = 30; // Espacio entre los dos botones horizontales

    // Coordenadas para centrar horizontalmente los dos botones
    float totalWidth = 2 * buttonWidth + spacing;
    float startX = (700 - totalWidth) / 2.0f;
    float centerY = 300;  // Altura fija para los botones principales

    // Botón Agregar Hábito (izquierdo)
    botonAgregarMeta.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    botonAgregarMeta.setPosition(startX, centerY + 100);
    botonAgregarMeta.setFillColor(sf::Color(235, 240, 170));
    botonAgregarMeta.setOutlineThickness(5);
    botonAgregarMeta.setOutlineColor(sf::Color(230, 190, 140));

    s_botonAgregarMeta.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    s_botonAgregarMeta.setPosition(startX + 5, centerY + 105);
    s_botonAgregarMeta.setFillColor(sf::Color(0, 25, 50, 80));

    // Botón Aumentar Hábito (derecho)
    float secondButtonX = startX + buttonWidth + spacing;

    botonAumentarMeta.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    botonAumentarMeta.setPosition(secondButtonX, centerY + 100);
    botonAumentarMeta.setFillColor(sf::Color(235, 240, 170));
    botonAumentarMeta.setOutlineThickness(5);
    botonAumentarMeta.setOutlineColor(sf::Color(230, 190, 140));

    s_botonAumentarMeta.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    s_botonAumentarMeta.setPosition(secondButtonX + 5, centerY + 105);
    s_botonAumentarMeta.setFillColor(sf::Color(0, 25, 50, 80));

    // Botón Salir en la posición fija especificada
    botonSalir.setPosition(420, 485);
    botonSalir_HB.setPosition(420, 485);
    s_botonSalir_HB.setPosition(425, 490);


    TextAgregarMeta.setFont(fontPixelBig);
    TextAgregarMeta.setString("Agregar Meta");
    TextAgregarMeta.setCharacterSize(30);
    TextAgregarMeta.setFillColor(sf::Color(50, 50, 50));
    TextAgregarMeta.setPosition(startX, centerY + 100);

    TextAumentarMeta.setFont(fontPixelBig);
    TextAumentarMeta.setString("Aumentar Meta");
    TextAumentarMeta.setCharacterSize(30);
    TextAumentarMeta.setFillColor(sf::Color(50, 50, 50));
    TextAumentarMeta.setPosition(secondButtonX, centerY + 100);
}

void initMenuAgregarHabito() {
    IngresarHabito.setFont(fontPixelBig);
    IngresarHabito.setString("Ingrese el nombre del habito:");
    IngresarHabito.setCharacterSize(30);
    IngresarHabito.setFillColor(sf::Color(255,255,255));
    IngresarHabito.setPosition(210, 345);

    InputIngresarHabito.setFont(fontPixelSlim);
    InputIngresarHabito.setCharacterSize(30);
    InputIngresarHabito.setFillColor(sf::Color(0, 0, 0, 200));
    InputIngresarHabito.setPosition(250, 420);

    botonInputHabito.setSize(sf::Vector2f(300, 75));
    botonInputHabito.setOrigin(125, 50);
    botonInputHabito.setPosition(350, 450);
    botonInputHabito.setOutlineThickness(5);
    botonInputHabito.setOutlineColor(sf::Color(230, 200, 120));
    botonInputHabito.setFillColor(sf::Color(240, 230, 180));

    botonCorrecto.setTexture(botonCorrectoTex);
    botonCorrecto.setScale(sf::Vector2f(3, 3));
    botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    botonCorrecto_HB.setOutlineThickness(1);
    botonCorrecto_HB.setOutlineColor(sf::Color::Transparent);
    botonCorrecto_HB.setFillColor(sf::Color::Transparent);

    s_botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    s_botonCorrecto_HB.setOutlineThickness(0);
    s_botonCorrecto_HB.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonCorrecto_HB.setFillColor(sf::Color(0, 25, 50, 80));


}


void initMenuAgregarMeta() {
    IngresarMeta.setFont(fontPixelBig);
    IngresarMeta.setString("Ingrese tu meta de la semana:");
    IngresarMeta.setCharacterSize(30);
    IngresarMeta.setFillColor(sf::Color(255, 255, 255));
    IngresarMeta.setPosition(210, 345);

    InputIngresarMeta.setFont(fontPixelSlim);
    InputIngresarMeta.setCharacterSize(30);
    InputIngresarMeta.setFillColor(sf::Color(0, 0, 0, 200));
    InputIngresarMeta.setPosition(250, 420);

    botonInputMeta.setSize(sf::Vector2f(300, 75));
    botonInputMeta.setOrigin(125, 50);
    botonInputMeta.setPosition(350, 450);
    botonInputMeta.setOutlineThickness(5);
    botonInputMeta.setOutlineColor(sf::Color(230, 200, 120));
    botonInputMeta.setFillColor(sf::Color(240, 230, 180));

    botonCorrecto.setTexture(botonCorrectoTex);
    botonCorrecto.setScale(sf::Vector2f(3, 3));
    botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    botonCorrecto_HB.setOutlineThickness(1);
    botonCorrecto_HB.setOutlineColor(sf::Color::Transparent);
    botonCorrecto_HB.setFillColor(sf::Color::Transparent);


    s_botonCorrecto_HB.setSize(sf::Vector2f(47, 47));
    s_botonCorrecto_HB.setOutlineThickness(0);
    s_botonCorrecto_HB.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonCorrecto_HB.setFillColor(sf::Color(0, 25, 50, 80));
}

void initMenuMetaCantidad() {

    InputIngresarMeta.setString("");

    InputIngresarMetaCantidad.setFont(fontPixelSlim);
    InputIngresarMetaCantidad.setCharacterSize(30);
    InputIngresarMetaCantidad.setFillColor(sf::Color(0, 0, 0, 200));
    InputIngresarMetaCantidad.setPosition(350, 450);

    IngresarCantidad.setFont(fontPixelBig);
    IngresarCantidad.setString("Ingrese la cantidad de la meta:");
    IngresarCantidad.setCharacterSize(30);
    IngresarCantidad.setFillColor(sf::Color(255, 255, 255));
    IngresarCantidad.setPosition(180, 345);

    botonInputMeta.setSize(sf::Vector2f(300, 75));
    botonInputMeta.setOrigin(125, 50);
    botonInputMeta.setPosition(350, 450);
    botonInputMeta.setOutlineThickness(5);
    botonInputMeta.setOutlineColor(sf::Color(230, 200, 120));
    botonInputMeta.setFillColor(sf::Color(240, 230, 180));


}

void initMenuHabitos() { 

    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0, 0, 0, 100));

    botonSalir.setPosition(420, 485);
    botonSalir_HB.setPosition(420, 485);
    s_botonSalir_HB.setPosition(425, 490);
        
    botonSalir_1.setTexture(botonSalirTex);
    botonSalir_1.setScale(sf::Vector2f(3, 3));
    botonSalir_1.setPosition(580, 160);
    botonSalir_HB_1.setSize(sf::Vector2f(50, 50));
    botonSalir_HB_1.setOutlineThickness(1);
    botonSalir_HB_1.setOutlineColor(sf::Color::Transparent);
    botonSalir_HB_1.setFillColor(sf::Color::Transparent);
    botonSalir_HB_1.setPosition(580, 160);


    s_botonSalir_HB_1.setSize(sf::Vector2f(47, 47));
    s_botonSalir_HB_1.setOutlineThickness(0);
    s_botonSalir_HB_1.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_1.setFillColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_1.setPosition(580 + 5, 160 + 5);

    botonSalir_2.setTexture(botonSalirTex);
    botonSalir_2.setScale(sf::Vector2f(3, 3));
    botonSalir_2.setPosition(580, 280);
    botonSalir_HB_2.setSize(sf::Vector2f(50, 50));
    botonSalir_HB_2.setOutlineThickness(1);
    botonSalir_HB_2.setOutlineColor(sf::Color::Transparent);
    botonSalir_HB_2.setFillColor(sf::Color::Transparent);
    botonSalir_HB_2.setPosition(580, 280);

    s_botonSalir_HB_2.setSize(sf::Vector2f(47, 47));
    s_botonSalir_HB_2.setOutlineThickness(0);
    s_botonSalir_HB_2.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_2.setFillColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_2.setPosition(580 + 5, 280 + 5);

    botonSalir_3.setTexture(botonSalirTex);
    botonSalir_3.setScale(sf::Vector2f(3, 3));
    botonSalir_3.setPosition(580, 400);
    botonSalir_HB_3.setSize(sf::Vector2f(50, 50));
    botonSalir_HB_3.setOutlineThickness(1);
    botonSalir_HB_3.setOutlineColor(sf::Color::Transparent);
    botonSalir_HB_3.setFillColor(sf::Color::Transparent);
    botonSalir_HB_3.setPosition(580, 400);

    s_botonSalir_HB_3.setSize(sf::Vector2f(47, 47));
    s_botonSalir_HB_3.setOutlineThickness(0);
    s_botonSalir_HB_3.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_3.setFillColor(sf::Color(0, 25, 50, 80));
    s_botonSalir_HB_3.setPosition(580 + 5, 400 + 5);;

    


    for (int i = 0; i < 3; i++) {
        sf::RectangleShape recuadro(sf::Vector2f(400, 100));
        recuadro.setPosition(150, 140 + (i * 120));
        recuadro.setFillColor(sf::Color::White);
        recuadrosHabitos.push_back(recuadro);

        string nombreHabito = Corazon.getNombreHabito(i);  // ✅ Obtener el nombre correctamente

        if (!nombreHabito.empty()) {  // ✅ Si no hay hábito, mostrar mensaje
            sf::Text texto(nombreHabito, fontPixelBig, 24);  // ✅ `nombreHabito` ya es un string
            texto.setPosition(recuadro.getPosition().x + 10, recuadro.getPosition().y + 40);
            texto.setFillColor(sf::Color::Black);
            textosHabitos.push_back(texto);
        }
        else {  // ✅ Si no hay hábito, mostrar mensaje
            sf::Text texto("No has creado este hábito", fontPixelBig, 24);
            texto.setPosition(recuadro.getPosition().x + 10, recuadro.getPosition().y + 40);
            texto.setFillColor(sf::Color::Red);
            textosHabitos.push_back(texto);

        }
    }
}

void initMenuAumentarMeta() {
    InputIngresarMeta.setString("");

    metaAumentada.setFont(fontPixelSlim);
    metaAumentada.setCharacterSize(30);
    metaAumentada.setFillColor(sf::Color(0, 0, 0, 200));
    metaAumentada.setPosition(350, 450);

    aumentarMeta.setFont(fontPixelBig);
    aumentarMeta.setString("Cuanto Avanzo en la meta:");
    aumentarMeta.setCharacterSize(30);
    aumentarMeta.setFillColor(sf::Color(255, 255, 255));
    aumentarMeta.setPosition(180, 345);

    CuadroAumentarMeta.setSize(sf::Vector2f(300, 75));
    CuadroAumentarMeta.setOrigin(125, 50);
    CuadroAumentarMeta.setPosition(350, 450);
    CuadroAumentarMeta.setOutlineThickness(5);
    CuadroAumentarMeta.setOutlineColor(sf::Color(230, 200, 120));
    CuadroAumentarMeta.setFillColor(sf::Color(240, 230, 180));
}


//Funciones Dibujar

void drawInicio(sf::RenderWindow& window) {// Dibuja pantalla de inicio
    window.draw(s_botonCorrecto_HB);
    window.draw(s_botonSalir_HB);
    window.draw(tituloInicio);
    window.draw(s_botonInputTextoInicio);
    window.draw(botonInputTextoInicio);
    window.draw(inputTextInicio);
    window.draw(botonCorrecto);
    window.draw(botonCorrecto_HB);
    window.draw(botonSalir);
    window.draw(botonSalir_HB);
}

void drawMenu0(sf::RenderWindow& window) { //Dibuja Corazon y el fondo
    window.draw(backgroundMargin);
    window.draw(corazon);
}

// Dibujar botones en la ventana
void drawMenu1(sf::RenderWindow& window) { //Dibuja Menu principal
    window.draw(s_botonCalendario);
    window.draw(botonCalendario);
    window.draw(s_lineaNombreCorazon);
    window.draw(lineaNombreCorazon);
    window.draw(nombreCorazon);
    window.draw(nombreCorazon_HB);
    window.draw(calendarioIcon);
    window.draw(s_botonHabito);
    window.draw(botonHabito);
    window.draw(habitoIcon);
    window.draw(s_botonEditarMeta);
    window.draw(botonEditarMeta);
    window.draw(s_barraProgreso);
    window.draw(barraProgreso);
    window.draw(s_botonEditarHabito);
    window.draw(botonEditarHabito);
    window.draw(HabitosTexto);
    window.draw(MetasTexto);
    window.draw(MetaTexto);
    window.draw(bubble);
    window.draw(animoCorazoncito);
    window.draw(nombreMeta);
}

void drawMenuCalendario(sf::RenderWindow& window) {//Dibuja Menu calendario
    window.draw(background);
    window.draw(s_bloqueCalendario);
    window.draw(s_bloqueTituloCalendario);
    window.draw(bloqueTituloCalendario);
    window.draw(bloqueCalendario);
    window.draw(s_botonSalir_HB);
    window.draw(s_botonCorrecto_HB);
    window.draw(botonCorrecto);
    window.draw(botonSalir);
}

void drawMenuEditarNombre(sf::RenderWindow& window) { //Menu editar Nombre
    window.draw(background);
    window.draw(s_botonEditarNombre);
    window.draw(botonEditarNombre);
    window.draw(inputTextEditarNombre);
    window.draw(s_botonCorrecto_HB);
    window.draw(botonCorrecto);
    window.draw(botonCorrecto_HB);
}

void drawMenuEditarHabito(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(s_botonAgregarHabito);
    window.draw(botonAgregarHabito);
    window.draw(s_botonBorrarHabito);
    window.draw(botonBorrarHabito);
    window.draw(s_botonSalir_HB);
    window.draw(botonSalir);
    window.draw(TextAgregarHabito);
    window.draw(TextBorrarHabito);
}

void drawMenuEditarMeta(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(s_botonAgregarMeta);
    window.draw(botonAgregarMeta);
    window.draw(s_botonAumentarMeta);
    window.draw(botonAumentarMeta);
    window.draw(s_botonSalir_HB);
    window.draw(botonSalir);
    window.draw(TextAumentarMeta);
    window.draw(TextAgregarMeta);
}

void drawMenuAgregarHabito(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(botonInputHabito);
    window.draw(IngresarHabito);
    window.draw(InputIngresarHabito);
    window.draw(botonCorrecto);
}

void drawMenuAgregarMeta(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(botonInputMeta);
    window.draw(IngresarMeta);
    window.draw(InputIngresarMeta);
    window.draw(botonCorrecto);
    window.draw(botonCorrecto_HB);

}


void drawMenuHabitos(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(botonCorrecto);
    window.draw(s_botonSalir_HB_1);
    window.draw(s_botonSalir_HB_2);
    window.draw(s_botonSalir_HB_3);
    window.draw(botonSalir_1);
    window.draw(botonSalir_2);
    window.draw(botonSalir_3);
    window.draw(botonSalir_HB_1);
    window.draw(botonSalir_HB_2);
    window.draw(botonSalir_HB_3);
    for (size_t i = 0; i < recuadrosHabitos.size(); i++) {
        window.draw(recuadrosHabitos[i]);  // Dibuja el rectángulo
        window.draw(textosHabitos[i]);  // Dibuja el texto dentro del rectángulo
    }

 

}

void drawMenuMetaCantidad(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(IngresarCantidad);
    window.draw(botonInputMeta);
    window.draw(InputIngresarMeta);
    window.draw(botonCorrecto);
    window.draw(botonCorrecto_HB);

}

void drawMenuAumentarMeta(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(metaAumentada);
    window.draw(aumentarMeta);
    window.draw(CuadroAumentarMeta);
    window.draw(botonCorrecto);
    window.draw(botonCorrecto_HB);
}


// Verificar si el mouse está sobre un botón
bool isMouseOver(const sf::RectangleShape& button, sf::Vector2f mousePos) {
    return button.getGlobalBounds().contains(mousePos);
}

// Manejar eventos del mouse
void handleMouseClick(const sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    switch (menuAbierto) {
    case 0:
        if (isMouseOver(botonInputTextoInicio, mousePos)) {
            std::cout << "Boton 1 Inicio" << std::endl;
            typingActive = true;
        }
        else {
            currentInput = "";
            typingActive = false;
        }
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            std::cout << "Boton 2 Inicio" << std::endl;
            menuAbierto = 1;
            nombreCorazon.setString(inputTextInicio.getString());
        }
        break;
    case 1:
        if (isMouseOver(botonCalendario, mousePos)) {
            std::cout << "Boton Calendario" << std::endl;
            menuAbierto = 2;
            initMenuCalendario();
        }
        else if (isMouseOver(botonHabito, mousePos)) {
            std::cout << "Boton Habito" << std::endl;
            menuAbierto = 8;
            initMenuHabitos();
            initBotonSalir();

        }
        else if (isMouseOver(nombreCorazon_HB, mousePos)) {
            std::cout << "Boton EditarNombre" << std::endl;
            menuAbierto = 3;
            initMenuEditarNombre();
        }
        else if (isMouseOver(botonEditarHabito, mousePos)) {
            std::cout << "Boton EditarHabito" << std::endl;
            menuAbierto = 4;
            initMenuEditarHabito();
        }
        else if (isMouseOver(botonEditarMeta, mousePos)) {
            std::cout << "Boton EditarMeta" << std::endl;
            menuAbierto = 5;
            initMenuEditarMeta();
        }
        else if (isMouseOver(botonEditarMeta, mousePos)) {
            std::cout << "Boton EditarMeta" << std::endl;

        }
        break;
    case 2:
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            std::cout << "Boton Correcto" << std::endl;
        }
        if (isMouseOver(botonSalir_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
        }
        break;
    case 3:
        if (isMouseOver(botonEditarNombre, mousePos)) {
            std::cout << "Boton EditarNombre" << std::endl;
            typingActive = true;
        }
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            std::cout << "Boton Correcto EditarNombre" << std::endl;
            typingActive = false;
            menuAbierto = 1;
            nombreCorazon.setString(inputTextEditarNombre.getString());
        }
        break;

    case 4:
        if (isMouseOver(botonSalir_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
            typingActive = false;
        }
        else if (isMouseOver(botonAgregarHabito, mousePos)) {
            std::cout << "Boton AgregarHabito" << std::endl;
            typingActive = true;
            menuAbierto = 6;
            initMenuAgregarHabito();

        }
        break;

    case 5:
        if (isMouseOver(botonSalir_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
            typingActive = false;
        }
        else if (isMouseOver(botonAgregarMeta, mousePos)) {
            std::cout << "Boton AgregarMeta" << std::endl;
            if (Corazon.getMetaExisten() == 1) {
                cout << "Ya hay una meta, no se puede crear otra" << endl;

            }
            else {
                typingActive = true;
                menuAbierto = 7;
                initMenuAgregarMeta();
                sf::sleep(sf::milliseconds(200));
            }
            

        }
        else if (isMouseOver(botonAumentarMeta, mousePos)) {
            std::cout << "Boton Aumentar" << std::endl;
            if (Corazon.getMetaExisten() == 0) {
                cout << "No hay meta Creada" << endl;
            }
            else {
                initMenuAumentarMeta();
                menuAbierto = 10;
            }
        }
        break;
    case 6:
        if (isMouseOver(botonSalir_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
            typingActive = false;
        }
        break;
    case 7:
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 9;
            initMenuMetaCantidad();
            typingActive = false;
        }
        break;
    case 8:
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            std::cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
        }
        if (isMouseOver(botonSalir_HB_1, mousePos)) {
            Corazon.borrarHabito(0);
        }
        if (isMouseOver(botonSalir_HB_2, mousePos)) {
            Corazon.borrarHabito(1);
        }
        if (isMouseOver(botonSalir_HB_3, mousePos)) {
            Corazon.borrarHabito(2);
        }
        break;
    case 9:
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
        }
        break;
    case 10:
        if (isMouseOver(botonCorrecto_HB, mousePos)) {
            cout << "Boton Salir" << std::endl;
            menuAbierto = 1;
            initMenu1();
        }

        break;
    }


}

void inputTeclado(sf::RenderWindow& window, sf::Event& event, sf::Text& text) { //window, event, texto

    if (typingActive && event.type == sf::Event::TextEntered) {
        // Verificamos si ha pasado suficiente tiempo desde la última letra
        bool diferenteChar = currentInput.empty() || currentInput.back() != static_cast<char>(event.text.unicode);

        if ((typeDelay.getElapsedTime() > typingDelay) || diferenteChar) {
            if (event.text.unicode < 128 && event.text.unicode >= 32) {
                currentInput += static_cast<char>(event.text.unicode);
            }
            else if (event.text.unicode == 8 && !currentInput.empty()) {
                currentInput.pop_back();
            }
            sf::FloatRect textBounds = text.getGlobalBounds();
            cursor.setPosition(textBounds.left + textBounds.width + 2, text.getPosition().y);

            // Parpadeo del cursor
            if (cursorClock.getElapsedTime() >= cursorBlinkInterval) {
                cursorVisible = !cursorVisible;
                cursorClock.restart();
            }
            if (typingActive && cursorVisible) {
                window.draw(cursor);
            }
            text.setString(currentInput);

            // Reiniciar el reloj
            typeDelay.restart();
        }
    }
}

// Función que maneja el slider y devuelve el valor actual (0 a 40)
int manejarSlider(sf::RenderWindow& window, sf::Vector2f posicion, float ancho) {
    static sf::CircleShape deslizador(10);
    static bool inicializado = false;
    static bool arrastrando = false;

    if (!inicializado) {
        deslizador.setFillColor(sf::Color::Red);
        deslizador.setOrigin(10, 10);
        deslizador.setPosition(posicion.x, posicion.y + 2);
        inicializado = true;
    }

    // Barra del slider
    sf::RectangleShape barra(sf::Vector2f(ancho, 5));
    barra.setPosition(posicion);
    barra.setFillColor(sf::Color(200, 200, 200));

    // Control de arrastre
    sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
    sf::Vector2f mouse = window.mapPixelToCoords(mousePixel);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (deslizador.getGlobalBounds().contains(mouse)) {
            arrastrando = true;
        }
    }
    else {
        arrastrando = false;
    }

    if (arrastrando) {
        float x = mouse.x;
        float minX = posicion.x;
        float maxX = posicion.x + ancho;
        if (x < minX) x = minX;
        if (x > maxX) x = maxX;
        deslizador.setPosition(x, posicion.y + 2);
    }

    // Dibujar
    window.draw(barra);
    window.draw(deslizador);

    // Calcular valor entre 0 y 40
    float valorRaw = 39.0f * ((deslizador.getPosition().x - posicion.x) / ancho);
    return static_cast<int>(valorRaw + 0.5f);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 900), "Proyecto Final Parcial 2");

    bool escribiendoHabito = true;
    bool habitoCreado = false;
    bool escribiendoMeta = true;
    Meta* miMeta = nullptr;
    srand(time(NULL));


    initFonts();
    initBotonCorrecto();
    initBotonSalir();
    initMenuEditarNombre();
    initMenu0();
    initMenu1();
    initMenuCalendario();
    initInicio();
    initMenuEditarHabito();
    initMenuEditarMeta();
    initMenuAgregarHabito();
    initMenuAgregarMeta();
    initMenuHabitos();
    initMenuMetaCantidad();
    initMenuAumentarMeta();


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
                handleMouseClick(window);
        }


        window.clear(sf::Color(190, 195, 210));
        switch (menuAbierto) {
        case 0: //Dibujar Menu que inicia el programa
            drawInicio(window);
            inputTeclado(window, event, inputTextInicio);
            break;
        case 1:
            drawMenu0(window);
            drawMenu1(window);
            break;
        case 2:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuCalendario(window);
            inputTeclado(window, event, inputTextMenu2);
            break;
        case 3:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuEditarNombre(window);
            inputTeclado(window, event, inputTextEditarNombre);
            break;
        case 4:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuEditarHabito(window);
            break;
        case 5:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuEditarMeta(window);
            break;
        case 6:
            escribiendoHabito = true;
            habitoCreado = false;
            drawMenu0(window);
            drawMenu1(window);
            drawMenuAgregarHabito(window);
            inputTeclado(window, event, InputIngresarHabito);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (isMouseOver(s_botonCorrecto_HB, mousePos) && !habitoCreado) {
                    string habitoString = InputIngresarHabito.getString();

                    if (!habitoString.empty()) {
                        Corazon.crearHabito(habitoString);
                        habitoCreado = true;
                        escribiendoHabito = false;
                        menuAbierto = 1;
                        cout << "Habito Creado" << endl;
                    }
                    else {
                        std::cout << "Error: No se ingreso texto!" << std::endl;
                    }
                }
            }



            break;

        case 7:
            escribiendoMeta = true;
            drawMenu0(window);
            drawMenu1(window);
            drawMenuAgregarMeta(window);
            inputTeclado(window, event, InputIngresarMeta);
            break;


        case 8:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuHabitos(window);
            break;

        case 9: {
            typingActive = true;
            drawMenu0(window);
            drawMenu1(window);
            drawMenuMetaCantidad(window);

            int valorSlider = manejarSlider(window, { 150, 550 }, 400);
            string valorString = to_string(valorSlider);
            InputIngresarMetaCantidad.setString(valorString);

            window.draw(InputIngresarMetaCantidad);

            string nombreMeta = InputIngresarMeta.getString();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (botonCorrecto_HB.getGlobalBounds().contains(mouse)) {

                    Corazon.crearMeta(nombreMeta, valorSlider);
                    cout << "Objeto " << Corazon.getNombreMeta() << "creado" << endl;
                    sf::sleep(sf::milliseconds(200));// Evitar múltiples creaciones por mantener el botón presionado
                }
            }

            break;
        }
        case 10:
            drawMenu0(window);
            drawMenu1(window);
            drawMenuAumentarMeta(window);
            double sliderValor = manejarSlider(window, { 150, 550 }, 400);

            string stringValor = to_string(sliderValor);
            metaAumentada.setString(stringValor);

            window.draw(metaAumentada);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (botonCorrecto_HB.getGlobalBounds().contains(mouse)) {
                    
                    Corazon.aumentarProgreso(sliderValor);
                    Corazon.revisarMeta();

                    sf::sleep(sf::milliseconds(200));// Evitar múltiples creaciones por mantener el botón presionado
                }
            }
            

            break;
        }
        


        window.display();
    }
    std::string input = inputTextInicio.getString();
    std::cout << input << std::endl;

    input = inputTextMenu2.getString();
    std::cout << input << std::endl;
    return 0;
}
