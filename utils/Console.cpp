#include "Console.hpp"

#include <Windows.h>

Console console;

#pragma region API
Console& Console::reset() {
  m_Type = "Log";
  m_Sep = " ";
  m_TypeColor = ccolor::light_green;
  m_MessageColor = ccolor::light_gray;

  return *this;
}

Console& Console::sep(std::string newSep) {
  m_Sep = std::move(newSep);

  return *this;
}

Console& Console::color(ConsoleColor newColor) {
  m_TypeColor = newColor;
  m_MessageColor = newColor;

  return *this;
}

Console& Console::tcolor(ConsoleColor newTypeColor) {
  m_TypeColor = newTypeColor;

  return *this;
}

Console& Console::mcolor2(ConsoleColor newMessageColor) {
  m_MessageColor = newMessageColor;

  return *this;
}
#pragma endregion API

#pragma region ColorOutputAPI
void Console::ColorOutput::setColor(int colorCode) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, colorCode);
}

std::ostream& Console::ColorOutput::dark_blue(std::ostream& out) {
  Console::ColorOutput::setColor(1); return out;
}

std::ostream& Console::ColorOutput::dark_green(std::ostream& out) {
  Console::ColorOutput::setColor(2); return out;
}

std::ostream& Console::ColorOutput::dark_aqua(std::ostream& out) {
  Console::ColorOutput::setColor(3); return out;
}

std::ostream& Console::ColorOutput::dark_red(std::ostream& out) {
  Console::ColorOutput::setColor(4); return out;
}

std::ostream& Console::ColorOutput::dark_purple(std::ostream& out) {
  Console::ColorOutput::setColor(5); return out;
}

std::ostream& Console::ColorOutput::gold(std::ostream& out) {
  Console::ColorOutput::setColor(6); return out;
}

std::ostream& Console::ColorOutput::light_gray(std::ostream& out) {
  Console::ColorOutput::setColor(7); return out;
}

std::ostream& Console::ColorOutput::dark_gray(std::ostream& out) {
  Console::ColorOutput::setColor(8); return out;
}

std::ostream& Console::ColorOutput::light_blue(std::ostream& out) {
  Console::ColorOutput::setColor(9); return out;
}

std::ostream& Console::ColorOutput::light_green(std::ostream& out) {
  Console::ColorOutput::setColor(10); return out;
}

std::ostream& Console::ColorOutput::light_aqua(std::ostream& out) {
  Console::ColorOutput::setColor(11); return out;
}

std::ostream& Console::ColorOutput::light_red(std::ostream& out) {
  Console::ColorOutput::setColor(12); return out;
}

std::ostream& Console::ColorOutput::light_purple(std::ostream& out) {
  Console::ColorOutput::setColor(13); return out;
}

std::ostream& Console::ColorOutput::yellow(std::ostream& out) {
  Console::ColorOutput::setColor(14); return out;
}

std::ostream& Console::ColorOutput::white(std::ostream& out) {
  Console::ColorOutput::setColor(15); return out;
}

std::ostream& Console::ColorOutput::reset(std::ostream& out) {
  out << ccolor::light_gray; return out;
}
#pragma endregion ColorOutputAPI
