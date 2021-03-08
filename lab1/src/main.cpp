#include <SFML/Graphics.hpp>

#include "./drawer.hpp"

double scale = 1.01;
double tr = 2.;
double rt = 0.02;

int load_file_fnc(const char file[], const sf::VideoMode vm) {
  int err = drawer::drawer(load_file, file);
  if (err) return err;

  drawer::drawer(action_translate, vm.width / 2., vm.height / 2., 0.);
  drawer::drawer(action_scale, 5., -5., 5.);

  return EXIT_SUCCESS;
}
int main(int argc, char *argv[]) {
  if (argc != 2) return -1;
  auto vm = sf::VideoMode::getDesktopMode();

  int err = load_file_fnc(argv[1], vm);
  if (err) return err;

  sf::RenderWindow window(vm, "Grapics", sf::Style::Fullscreen);
  window.setFramerateLimit(60);

  sf::Font font;
  err = !font.loadFromFile("./fonts/Roboto-Regular.ttf");
  if (err) return err;

  sf::Text text;
  text.setFont(font);
  text.setString(
      "\n" 
      "   CONTROLS:\n\n"
      "   Up, Down, Left, Right  translate\n"
      "   W,S  rotate X\n"
      "   A,D  rotate Y\n"
      "   Q,E  rotate Z\n"
      "   +,-  scale\n"
      "   F1   close this message\n"
      "   F2   reset\n"
      "   Esc  quit\n");

  text.setCharacterSize(14);

  text.setFillColor(sf::Color::White);
  // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  bool show_help = true;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        drawer::drawer(action_free_content);
        window.close();
      }
      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::F1) show_help = !show_help;
        if (event.key.code == sf::Keyboard::F2) load_file_fnc(argv[1], vm);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        drawer::drawer(action_free_content);
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      drawer::drawer(action_translate, -tr, 0., 0.);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      drawer::drawer(action_translate, tr, 0., 0.);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      drawer::drawer(action_translate, 0., -tr, 0.);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      drawer::drawer(action_translate, 0., tr, 0.);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
      drawer::drawer(action_scale, scale, scale, scale);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
      drawer::drawer(action_scale, 1 / scale, 1 / scale, 1 / scale);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      drawer::drawer(action_rotate_x, rt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      drawer::drawer(action_rotate_x, -rt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      drawer::drawer(action_rotate_y, rt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      drawer::drawer(action_rotate_y, -rt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
      drawer::drawer(action_rotate_z, rt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
      drawer::drawer(action_rotate_z, -rt);

    DrawerResult *result = nullptr;

    int err = drawer::drawer(action_project, &result);
    if (err) return err;

    window.clear();

    for (size_t i = 0; i < result->count; i++) {
      sf::Vertex line[] = {sf::Vertex(sf::Vector2f(result->lines[i].start.x,
                                                   result->lines[i].start.y)),
                           sf::Vertex(sf::Vector2f(result->lines[i].end.x,
                                                   result->lines[i].end.y))};

      window.draw(line, 2, sf::Lines);
    }
    if (show_help) window.draw(text);

    window.display();
  }

  return 0;
}
