#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

int main()
{
    sf::Vector2f vect[4] = {{0, 200}, {200, 0}, {0, 200}, {200, 200}};
    Rectangle rect(vect, {100, 100});

    // rect.print();

    // rect.rotate(2);
    // rect.print();

    constexpr int32_t window_width = 1000;
    constexpr int32_t window_height = 1000;

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "2D SAT Collision Detection",
                            sf::Style::Default, sf::State::Windowed, settings);

    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    sf::RectangleShape rectangle({200, 200});
    rectangle.setOrigin(rect.rotation_centre);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            rect.move({-10, 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            rect.move({10, 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            rect.move({0, -10});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            rect.move({0, 10});
        }

        window.clear(sf::Color::Black);

        rect.draw(window, rectangle);

        rect.rotate(0.01);

        window.display();
    }

    return 0;
}