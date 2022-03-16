//
//  main.cpp
//  PS0
//
//  Created by Vien Tran on 1/20/22.
//

/**
    Vien Tran
    Computing IV
    PS0
    Dr. Daly
    January 24th
    This program draws a green circle and a sprite on a SFML window.
 */

#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, const char * argv[]) {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    
    //Create the main window
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "SFML works!");
    
    //Load a circle to display
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    
    int x = 0, y = 0;
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                x -= 1;
                if (x - 1 < 0) {
                    x = desktop.width;
                }
            } else if (event.key.code == sf::Keyboard::Down) {
                y += 1;
            } else if (event.key.code == sf::Keyboard::Right) {
                x += 1;
            } else if (event.key.code == sf::Keyboard::Up) {
                y -= 1;
                if (y - 1 < 0) {
                    y = desktop.height;
                }
            }
        }
        
        if (x > desktop.width) {
            x = 0;
        } else if (y > desktop.height) {
            y = 0;
        }
               
        if (event.type == sf::Event::MouseMoved) {
            //window.setFramerateLimit(25);
            sprite.setRotation(event.mouseMove.x * -1);
        }
        
        
        // Clear screen
        window.clear();
        
        //Draw the circle
        window.draw(shape);
        
        // Draw the sprite
        sprite.setPosition(sf::Vector2f(x, y));
        window.draw(sprite);
        
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
