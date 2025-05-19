#include <SFML/Graphics.hpp>
#include <iostream>

int menuAbierto = -1;
sf::Clock typeDelay;          // Reloj para controlar el tiempo entre letras
sf::Time typingDelay = sf::milliseconds(200);  // Delay entre letras (100ms)

sf::RectangleShape background;

sf::Text tituloInicio; //Texto Inicio
sf::RectangleShape boton1Inicio; //Boton Escribir Inicio
sf::Text inputTextInicio; //Insertar Texto Inicio
sf::RectangleShape boton2Inicio; //Boton Salir Inicio
sf::Text textoBoton2Inicio; //Texto Boton Salir Inicio

sf::RectangleShape boton1menu1; //Boton 
sf::RectangleShape boton2menu1; //Boton Abrir Menu2

sf::RectangleShape boton1menu2; //Boton Escribir
sf::RectangleShape boton2menu2; //Boton Salir Menu2

sf::CircleShape corazon;

sf::Font font;
sf::Text inputTextMenu2;
bool typingActive = false;
std::string currentInput = "";

bool isInicioOpen = 1;
bool isMenu0Open = 0;
bool isMenu1Open = 0;
bool isMenu2Open = 0;

sf::Texture catTex;
sf::Sprite cat;



// Inicializar botones
void initInicio() {
    tituloInicio.setFont(font);
    tituloInicio.setString("Ingrese Nombre:");
    tituloInicio.setCharacterSize(30);
    tituloInicio.setFillColor(sf::Color::Black);
    tituloInicio.setPosition(210, 345);

    boton1Inicio.setSize(sf::Vector2f(250, 100));
    boton1Inicio.setOrigin(125, 50);
    boton1Inicio.setPosition(350, 450);
    boton1Inicio.setOutlineThickness(5);
    boton1Inicio.setOutlineColor(sf::Color(175, 175, 175));
    boton1Inicio.setFillColor(sf::Color(200, 200, 200));

    inputTextInicio.setFont(font);
    inputTextInicio.setCharacterSize(40);
    inputTextInicio.setFillColor(sf::Color::Black);
    inputTextInicio.setPosition(250, 450);

    boton2Inicio.setSize(sf::Vector2f(50, 50));
    boton2Inicio.setPosition(440, 515);
    boton2Inicio.setFillColor(sf::Color::Red);

    textoBoton2Inicio.setFont(font);
    textoBoton2Inicio.setString("x");
    textoBoton2Inicio.setCharacterSize(40);
    textoBoton2Inicio.setFillColor(sf::Color::White);
    textoBoton2Inicio.setPosition(460, 515);
}

void initMenu0() {
    //Diseñando Corazon

    corazon.setRadius(100);
    corazon.setOrigin(50, 50);
    corazon.setPosition(350, 450);
    corazon.setFillColor(sf::Color(255, 100, 100));
}
void initMenu1() {
    boton1menu1.setSize(sf::Vector2f(150, 50));
    boton1menu1.setPosition(50, 100);
    boton1menu1.setFillColor(sf::Color::Blue);

    boton2menu1.setSize(sf::Vector2f(150, 50));
    boton2menu1.setPosition(200, 100);
    boton2menu1.setFillColor(sf::Color::Green);
}

void initMenu2() {
    if (!catTex.loadFromFile("Textures/cat.png"))
        std::cout << "Could not load cat.png\n";
    cat.setTexture(catTex);
    cat.setPosition(150, 350);
    cat.setScale(sf::Vector2f(0.05f, 0.05f));

    background.setSize(sf::Vector2f(700, 900));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(0,0,0,100));

    boton1menu2.setSize(sf::Vector2f(150, 50));
    boton1menu2.setPosition(50, 150);
    boton1menu2.setFillColor(sf::Color::Yellow);

    boton2menu2.setSize(sf::Vector2f(150, 50));
    boton2menu2.setPosition(200, 150);
    boton2menu2.setFillColor(sf::Color::Red);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "No se pudo cargar la fuente 'arial.ttf'" << std::endl;
    }

    inputTextMenu2.setFont(font);
    inputTextMenu2.setCharacterSize(20);
    inputTextMenu2.setFillColor(sf::Color::Black);
    inputTextMenu2.setPosition(55, 155);
}
void drawInicio(sf::RenderWindow& window) {
    window.draw(tituloInicio);
    window.draw(boton1Inicio);
    window.draw(inputTextInicio);
    window.draw(boton2Inicio);
    window.draw(textoBoton2Inicio);
}
void drawMenu0(sf::RenderWindow& window) {

    inputTextInicio.setPosition(250, 200);
    inputTextInicio.setFillColor(sf::Color(100,120,120));
    window.draw(inputTextInicio);
    window.draw(corazon);
}

// Dibujar botones en la ventana
void drawMenu1(sf::RenderWindow& window) {
    window.draw(boton1menu1);
    window.draw(boton2menu1);
    

}

void drawMenu2(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(boton1menu2);
    window.draw(boton2menu2);
    window.draw(inputTextMenu2);
    window.draw(cat);

    
}

// Verificar si el mouse está sobre un botón
bool isMouseOver(const sf::RectangleShape& button, sf::Vector2f mousePos) {
    return button.getGlobalBounds().contains(mousePos);
}

// Manejar eventos del mouse
void handleMouseClick(const sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    switch (menuAbierto) {
    case -1:
        if (isMouseOver(boton1Inicio, mousePos)) {
            std::cout << "Boton 1 Inicio" << std::endl;
            typingActive = true;
        }
        else {
            currentInput = "";
            typingActive = false;
        }
        if (isMouseOver(boton2Inicio, mousePos)) {
            std::cout << "Boton 2 Inicio" << std::endl;
            menuAbierto = 0;
        }
        break;
    case 0:
        menuAbierto = 1;
        break;
    case 1:
        if (isMouseOver(boton1menu1, mousePos)) {
            std::cout << "Boton 1 Menu1" << std::endl;
        }
        else if (isMouseOver(boton2menu1, mousePos)) {
            std::cout << "Boton 2 Menu1" << std::endl;
            menuAbierto = 2;
        }
        break;
    case 2:
        if (isMouseOver(boton1menu2, mousePos)) {
            std::cout << "Boton 1 Menu2" << std::endl;
            typingActive = true;  // Activar escritura
        }
        else if (isMouseOver(boton2menu2, mousePos)) {
            std::cout << "Boton 2 Menu2" << std::endl;
            menuAbierto = 1;
            currentInput = "";
            typingActive = false; // Desactivarla si se clickea fuera
        }
        else {
            currentInput = "";
            typingActive = false; // Desactivarla si se clickea fuera
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
            text.setString(currentInput);

            // Reiniciar el reloj
            typeDelay.restart();
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 900), "Botones con SFML");
    
    initMenu0();
    initInicio();
    initMenu1();
    initMenu2();
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
                handleMouseClick(window);
        }
        

        window.clear(sf::Color(210,205,200));
        switch (menuAbierto) {
        case -1:
            drawInicio(window);
            inputTeclado(window, event, inputTextInicio);
            break;
        case 0:
            drawMenu0(window);
            break;
        case 1:
            drawMenu0(window);
            drawMenu1(window);
            break;
        case 2:
            drawMenu0(window);
            drawMenu1(window);
            drawMenu2(window);
            inputTeclado(window, event, inputTextMenu2);
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




