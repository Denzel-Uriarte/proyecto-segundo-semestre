// Proyecto-segundo-semestre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>

bool isMouseOver(const sf::RectangleShape& button, const sf::Vector2f& mousePos) {
    return button.getGlobalBounds().contains(mousePos);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Corazoncito");

    // --
    const int numButtons = 3;
    sf::RectangleShape buttons[numButtons];
    sf::Text labels[numButtons];
    std::string buttonTexts[] = { "Boton 1", "Boton 2", "Boton 3" };

    for (int i = 0; i < numButtons; ++i) {
        buttons[i].setSize({ 500, 50 });
        buttons[i].setFillColor(sf::Color(100, 100, 250));
        buttons[i].setPosition(150, 400 + i * 60);

        
        labels[i].setString(buttonTexts[i]);
        labels[i].setCharacterSize(20);
        labels[i].setFillColor(sf::Color::White);

        // Centrar texto
        sf::FloatRect textRect = labels[i].getLocalBounds();
        labels[i].setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        labels[i].setPosition(buttons[i].getPosition().x + buttons[i].getSize().x / 2,
            buttons[i].getPosition().y + buttons[i].getSize().y / 2);
    }

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                for (int i = 0; i < numButtons; ++i) {
                    if (isMouseOver(buttons[i], mousePos)) {
                        std::cout << "Presionado: " << buttonTexts[i] << std::endl;
                    }
                }
            }
        }

        window.clear(sf::Color::Yellow);
       
        for (int i = 0; i < numButtons; ++i) {
            window.draw(buttons[i]);
            window.draw(labels[i]);
        }
        window.display();
    }

    return 0;
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
