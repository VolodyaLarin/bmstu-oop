#include <SFML/Graphics.hpp>
#include <iostream>

#include "./drawer.hpp"

double scale = 1.01;
double tr = 2.;
double rt = 0.02;

int load_file_fnc(const char file[], const sf::VideoMode vm) {
  Request request;
  request.action = action_read_model;
  request.read_model.filename = file;

  int err = drawer::drawer(request);
  if (err) return err;

  request.action = action_translate;
  request.translate.x = vm.width / 2.;
  request.translate.y = vm.height / 2.;
  request.translate.z = 0;

  drawer::drawer(request);

  request.action = action_scale;
  request.scale.x = 5;
  request.scale.y = -5;
  request.scale.z = 5;

  drawer::drawer(request);

  return EXIT_SUCCESS;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "USE: ./app.exe model_name" << std::endl;
    return -1;
  }
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
  bool show_help = true;

  while (window.isOpen()) {
    sf::Event event;
    Request request;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        request.action = action_free_content;
        drawer::drawer(request);
        window.close();
      }
      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::F1) show_help = !show_help;
        if (event.key.code == sf::Keyboard::F2) {
          request.action = action_free_content;
          drawer::drawer(request);
          load_file_fnc(argv[1], vm);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        request.action = action_free_content;
        drawer::drawer(request);
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      request.action = action_translate;
      request.translate.x = -tr;
      request.translate.y = 0;
      request.translate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      request.action = action_translate;
      request.translate.x = tr;
      request.translate.y = 0;
      request.translate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      request.action = action_translate;
      request.translate.x = 0;
      request.translate.y = -tr;
      request.translate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      request.action = action_translate;
      request.translate.x = 0;
      request.translate.y = tr;
      request.translate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
      request.action = action_scale;
      request.scale.x = scale;
      request.scale.y = scale;
      request.scale.z = scale;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
      request.action = action_scale;
      request.scale.x = 1 / scale;
      request.scale.y = 1 / scale;
      request.scale.z = 1 / scale;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      request.action = action_rotate;
      request.rotate.x = rt;
      request.rotate.y = 0;
      request.rotate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      request.action = action_rotate;
      request.rotate.x = -rt;
      request.rotate.y = 0;
      request.rotate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      request.action = action_rotate;
      request.rotate.x = 0;
      request.rotate.y = rt;
      request.rotate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      request.action = action_rotate;
      request.rotate.x = 0;
      request.rotate.y = -rt;
      request.rotate.z = 0;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
      request.action = action_rotate;
      request.rotate.x = 0;
      request.rotate.y = 0;
      request.rotate.z = rt;
      drawer::drawer(request);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
      request.action = action_rotate;
      request.rotate.x = 0;
      request.rotate.y = 0;
      request.rotate.z = -rt;
      drawer::drawer(request);
    }

    request.action = action_project;
    request.project.result = nullptr;
    int err = drawer::drawer(request);
    if (err) return err;

    window.clear();
    DrawerResult *result = request.project.result;
    if (result)
      for (size_t i = 0; i < result->lines_count; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(result->cords[result->lines[i].start].x,
                                    result->cords[result->lines[i].start].y)),
            sf::Vertex(sf::Vector2f(result->cords[result->lines[i].end].x,
                                    result->cords[result->lines[i].end].y))};

        window.draw(line, 2, sf::Lines);
      }
    if (show_help) window.draw(text);

    window.display();
  }

  return 0;
}
