#include "app/app.h"

#include "game/damath.h"

namespace DamathZero::App {

static auto Clear(sf::RenderWindow* window) -> void {
  window->clear();

  auto size = sf::Vector2f(800, 800);

  sf::RectangleShape background[64];
  for (int i = 0; i < 64; i++) {
    background[i].setPosition(i % 8 * size.x / 8, i / 8 * size.y / 8);
    background[i].setSize(sf::Vector2f(size.x / 8, size.y / 8));
    if (i % 2 == i / 8 % 2) {
      background[i].setFillColor(sf::Color::White);
    } else {
      background[i].setFillColor(sf::Color::Black);
    }

    window->draw(background[i]);
  }
}

static auto Display(sf::RenderWindow* window, Game::Board* board) -> void {
  auto size = sf::Vector2f(800, 800);

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      if (!((*board->pieces())[x][y])) {
        continue;
      }

      sf::CircleShape shape(std::min(size.x, size.y) / 8 / 2 - 10);
      shape.setPosition(x * size.x / 8 + 10, y * size.y / 8 + 10);

      if (*(*board->pieces())[x][y]->owner() == Game::Player::White) {
        shape.setFillColor(sf::Color{0, 0, 255});
      } else {
        shape.setFillColor(sf::Color{255, 0, 0});
      }
      window->draw(shape);
    }
  }
}

auto Run() -> int {
  Game::Damath game{};

  sf::RenderWindow window(sf::VideoMode(800, 800), "damath.ai");

  sf::View view{sf::FloatRect{0, 0, 800, 800}};

  // Start the game loop
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.setView(view);

    Clear(&window);

    Display(&window, game.board());

    window.setView(window.getDefaultView());

    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}

}  // namespace DamathZero::App
