#pragma once
#include "ConsoleColorOutput.hpp"
#include <string>

using ConsoleColor = std::ostream& (*)(std::ostream&);

class Console {
private:
  std::string m_Type = "Log";
  ConsoleColor m_Color = ccolor::light_gray;

public:
  Console& type(std::string newType) {
    m_Type = std::move(newType);

    return *this;
  }

  Console& color(ConsoleColor newColor) {
    m_Color = newColor;

    return *this;
  }

  template<typename T>
  Console& log(T&& message) {
    std::cout
      << ccolor::dark_gray << "["
      << m_Color << m_Type
      << ccolor::dark_gray << "] "
      << m_Color << message
      << ccolor::dark_gray << "!"
      << ccolor::reset << '\n';

    return *this;
  }

  template<typename T>
  Console& info(T&& message) {
    return this->type("Info").color(ccolor::dark_blue).log(message);
  }

  template<typename T>
  Console& warn(T&& message) {
    return this->type("Warn").color(ccolor::gold).log(message);
  }

  template<typename T>
  Console& error(T&& message) {
    return this->type("Error").color(ccolor::dark_red).log(message);
  }
};
