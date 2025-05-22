#include <SFML/Graphics.hpp>
#include <iostream>

int menuAbierto = 0;
sf::Clock typeDelay;          // Reloj para controlar el tiempo entre letras
sf::Time typingDelay = sf::milliseconds(200);  // Delay entre letras (100ms)

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




// Inicializar botones

sf::Font fontArial;
sf::Font fontPixelBig;
sf::Font fontPixelSlim;
sf::Font fontPixelSlimBold;
sf::Text inputTextMenu2;
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

sf::RectangleShape botonCorrecto_HB;
sf::RectangleShape s_botonCorrecto_HB;
sf::Texture botonCorrectoTex;
sf::Sprite botonCorrecto;
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
sf::RectangleShape botonSalir_HB;
sf::RectangleShape s_botonSalir_HB;
sf::Texture botonSalirTex;
sf::Sprite botonSalir;
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

sf::Text tituloInicio; //Texto Inicio
sf::RectangleShape botonInputTextoInicio; //Boton Escribir Inicio
sf::RectangleShape s_botonInputTextoInicio;
sf::Text inputTextInicio; //Insertar Texto Inicio
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
    s_botonInputTextoInicio.setPosition(350+5, 450+5);
    s_botonInputTextoInicio.setOutlineThickness(5);
    s_botonInputTextoInicio.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonInputTextoInicio.setFillColor(sf::Color(0, 25, 50, 80));

    inputTextInicio.setFont(fontPixelSlim);
    inputTextInicio.setCharacterSize(30);
    inputTextInicio.setFillColor(sf::Color(0,0,0,200));
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

sf::Texture corazonTxt;
sf::Sprite corazon;

void initMenu0() {
    if (!corazonTxt.loadFromFile("Textures/CorazonSano.png"))
        std::cout << "Could not load CorazonSano.png\n";
    corazon.setTexture(corazonTxt);
    corazon.setScale(sf::Vector2f(10, 10));

    backgroundMargin.setOutlineThickness(20);
    backgroundMargin.setOutlineColor(sf::Color(120, 170, 190));
    backgroundMargin.setFillColor(sf::Color(170, 210, 220));
    backgroundMargin.setPosition(10, 10);
    backgroundMargin.setSize(sf::Vector2f(680, 880));

    corazon.setPosition(250, 300);
}
sf::RectangleShape s_botonCalendario;
sf::RectangleShape botonCalendario;
sf::Texture calendarioIconTxt;
sf::Sprite calendarioIcon;

sf::RectangleShape botonEditarMeta;
sf::RectangleShape s_botonEditarMeta;

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

void initMenu1() {
    lineaNombreCorazon.setSize(sf::Vector2f(300, 10));
    lineaNombreCorazon.setPosition(200, 150);
    lineaNombreCorazon.setFillColor(sf::Color(220, 160, 180));

    s_lineaNombreCorazon.setSize(sf::Vector2f(300, 10));
    s_lineaNombreCorazon.setPosition(200+5, 150+5);
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
    calendarioIcon.setPosition(57,60);

    barraProgreso.setSize(sf::Vector2f(600, 70));
    barraProgreso.setOutlineThickness(7);
    barraProgreso.setOutlineColor(sf::Color(210, 110, 140));
    barraProgreso.setPosition(50, 800);
    barraProgreso.setFillColor(sf::Color(220, 160, 180));

    s_barraProgreso.setSize(sf::Vector2f(600, 70));
    s_barraProgreso.setOutlineThickness(7);
    s_barraProgreso.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_barraProgreso.setPosition(50+5, 800+5);
    s_barraProgreso.setFillColor(sf::Color(0, 25, 50, 80));

    botonEditarMeta.setSize(sf::Vector2f(200, 70));
    botonEditarMeta.setOutlineThickness(7);
    botonEditarMeta.setOutlineColor(sf::Color(210, 110, 140));
    botonEditarMeta.setPosition(50, 700);
    botonEditarMeta.setFillColor(sf::Color(220, 160, 180));

    s_botonEditarMeta.setSize(sf::Vector2f(200, 70));
    s_botonEditarMeta.setOutlineThickness(7);
    s_botonEditarMeta.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonEditarMeta.setPosition(50+5, 700+5);
    s_botonEditarMeta.setFillColor(sf::Color(0, 25, 50, 80));

    botonCalendario.setSize(sf::Vector2f(125, 125));
    botonCalendario.setOutlineThickness(7);
    botonCalendario.setOutlineColor(sf::Color(230, 190, 140));
    botonCalendario.setPosition(50, 50);
    botonCalendario.setFillColor(sf::Color(235, 240, 170));

    s_botonCalendario.setSize(sf::Vector2f(125, 125));
    s_botonCalendario.setOutlineThickness(7);
    s_botonCalendario.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_botonCalendario.setPosition(50+5, 50+5);
    s_botonCalendario.setFillColor(sf::Color(0, 25, 50, 80));
    
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
    s_botonHabito.setPosition(525+5, 50+5);
    s_botonHabito.setFillColor(sf::Color(0, 25, 50, 80));
}

sf::RectangleShape bloqueTituloCalendario;
sf::RectangleShape s_bloqueTituloCalendario;
sf::RectangleShape bloqueCalendario;
sf::RectangleShape s_bloqueCalendario;
void initMenuCalendario() {

    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0,0,0,100));

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
    s_bloqueCalendario.setPosition(100+5, 250+5);
    s_bloqueCalendario.setFillColor(sf::Color(0, 25, 50, 80));

    bloqueTituloCalendario.setSize(sf::Vector2f(500, 70));
    bloqueTituloCalendario.setOutlineThickness(7);
    bloqueTituloCalendario.setOutlineColor(sf::Color(230, 190, 140));
    bloqueTituloCalendario.setPosition(100, 150);
    bloqueTituloCalendario.setFillColor(sf::Color(235, 240, 170));

    s_bloqueTituloCalendario.setSize(sf::Vector2f(500, 70));
    s_bloqueTituloCalendario.setOutlineThickness(7);
    s_bloqueTituloCalendario.setOutlineColor(sf::Color(0, 25, 50, 80));
    s_bloqueTituloCalendario.setPosition(100+5, 150+5);
    s_bloqueTituloCalendario.setFillColor(sf::Color(0, 25, 50, 80));

    botonCorrecto.setPosition(550, 770);
    botonCorrecto_HB.setPosition(550, 770);
    s_botonCorrecto_HB.setPosition(550+5, 770+5);

    botonSalir.setPosition(495, 770);
    botonSalir_HB.setPosition(495 + 5, 770 + 5);
    s_botonSalir_HB.setPosition(495 + 5, 770 + 5);
}

sf::RectangleShape botonEditarNombre;
sf::RectangleShape s_botonEditarNombre;
sf::Text inputTextEditarNombre;

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
    s_botonEditarNombre.setPosition(100+5, 150+5);
    s_botonEditarNombre.setFillColor(sf::Color(0, 25, 50, 80));

    inputTextEditarNombre.setFont(fontPixelSlim);
    inputTextEditarNombre.setCharacterSize(30);
    inputTextEditarNombre.setFillColor(sf::Color(0, 0, 0, 200));
    inputTextEditarNombre.setPosition(100, 150);

    botonCorrecto.setPosition(150, 550);
    botonCorrecto_HB.setPosition(150, 550);
    s_botonCorrecto_HB.setPosition(150+5, 550+5);

    botonSalir.setPosition(495, 770);
    botonSalir_HB.setPosition(495 + 5, 770 + 5);
    s_botonSalir_HB.setPosition(495 + 5, 770 + 5);
}

void drawInicio(sf::RenderWindow& window) {
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

void drawMenu0(sf::RenderWindow& window) {
    window.draw(backgroundMargin);
    window.draw(corazon);
}

// Dibujar botones en la ventana
void drawMenu1(sf::RenderWindow& window) {
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
}



void drawMenuCalendario(sf::RenderWindow& window) {
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

void drawMenuEditarNombre(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(s_botonEditarNombre);
    window.draw(botonEditarNombre);
    window.draw(inputTextEditarNombre);
    window.draw(s_botonCorrecto_HB);
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
        }
        else if (isMouseOver(nombreCorazon_HB, mousePos)) {
            std::cout << "Boton EditarNombre" << std::endl;
            menuAbierto = 3;
            initMenuEditarNombre();
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
    }
}

void inputTeclado( sf::RenderWindow& window, sf::Event& event, sf::Text& text) { //window, event, texto
    
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

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 900), "Proyecto Final Parcial 2");
    
    initFonts();
    initBotonCorrecto();
    initBotonSalir();
    initMenuEditarNombre();
    initMenu0();
    initMenu1();
    initMenuCalendario();
    initInicio();
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
                handleMouseClick(window);
        }
        

        window.clear(sf::Color(190,195,210));
        switch (menuAbierto) {
        case 0:
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

        }
        window.display();
    }
    std::string input = inputTextInicio.getString();
    std::cout << input << std::endl;
    
    input = inputTextMenu2.getString();
    std::cout << input << std::endl;
    return 0;
}




