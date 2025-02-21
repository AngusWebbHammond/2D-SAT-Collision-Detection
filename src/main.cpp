#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

int main()
{
    sf::Vector2f vect[4] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    Rectangle rect(vect, {0, 0});

    rect.print();

    rect.rotate(1);
    rect.print();

    // constexpr int32_t window_width = 1000;
    // constexpr int32_t window_height = 1000;

    // sf::ContextSettings settings;
    // settings.antiAliasingLevel = 1;

    // sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "2D SAT Collision Detection",
    //                         sf::Style::Default, sf::State::Windowed, settings);

    // const uint32_t frame_rate = 60;
    // window.setFramerateLimit(frame_rate);

    // while (window.isOpen())
    // {
    //     while (const std::optional event = window.pollEvent())
    //     {
    //         if (event->is<sf::Event::Closed>())
    //             window.close();
    //     }

    //     window.clear(sf::Color::Black);

    //     window.display();
    // }

    return 0;
}