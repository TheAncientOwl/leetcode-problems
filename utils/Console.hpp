#pragma once
#include <iostream>
#include <sstream>
#include <string>

using ConsoleColor = std::ostream& (*)(std::ostream&);
#define ccolor Console::ColorOutput

class Console {
private:
  class ColorOutput;
  std::string m_Type = "Log";
  std::string m_Sep = " ";
  ConsoleColor m_TypeColor = ColorOutput::light_green;
  ConsoleColor m_MessageColor = ColorOutput::light_gray;

public:
  Console& reset();
  Console& sep(std::string newSep);
  Console& color(ConsoleColor newColor);
  Console& tcolor(ConsoleColor newTypeColor);
  Console& mcolor2(ConsoleColor newMessageColor);

  template<typename Arg, typename... Args>
  Console& type(Arg&& arg, Args&&... args) {
    std::stringstream sstr;
    sstr << std::forward<Arg>(arg);
    ((sstr << std::forward<Args>(args)), ...);

    m_Type = sstr.str();

    return *this;
  }

  template<typename Arg, typename... Args>
  Console& log(Arg&& arg, Args&&... args) {
    std::cout
      << ccolor::dark_gray << "["
      << m_TypeColor << m_Type
      << ccolor::dark_gray << "] "
      << m_MessageColor << std::forward<Arg>(arg);

    ((std::cout << m_Sep << std::forward<Args>(args)), ...);

    std::cout << ccolor::reset << '\n';

    return *this;
  }

  template<typename Arg, typename... Args>
  Console& info(Arg&& arg, Args&&... args) {
    return this->type("Info").color(ccolor::dark_blue).log(std::forward<Arg>(arg), std::forward<Args>(args)...);
  }

  template<typename Arg, typename... Args>
  Console& warn(Arg&& arg, Args&&... args) {
    return this->type("Warn").color(ccolor::gold).log(std::forward<Arg>(arg), std::forward<Args>(args)...);
  }

  template<typename Arg, typename... Args>
  Console& error(Arg&& arg, Args&&... args) {
    return this->type("Error").color(ccolor::dark_red).log(std::forward<Arg>(arg), std::forward<Args>(args)...);
  }

  struct ColorOutput {
    static void setColor(int colorCode);

    static std::ostream& light_blue(std::ostream& out);
    static std::ostream& dark_blue(std::ostream& out);

    static std::ostream& light_aqua(std::ostream& out);
    static std::ostream& dark_aqua(std::ostream& out);

    static std::ostream& light_green(std::ostream& out);
    static std::ostream& dark_green(std::ostream& out);

    static std::ostream& light_red(std::ostream& out);
    static std::ostream& dark_red(std::ostream& out);

    static std::ostream& dark_purple(std::ostream& out);
    static std::ostream& light_purple(std::ostream& out);

    static std::ostream& gold(std::ostream& out);
    static std::ostream& yellow(std::ostream& out);

    static std::ostream& light_gray(std::ostream& out);
    static std::ostream& dark_gray(std::ostream& out);
    static std::ostream& white(std::ostream& out);

    static std::ostream& reset(std::ostream& out);
  };
};

extern Console console;
