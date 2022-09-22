#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  for (const auto& value : v)
    out << value << ' ';

  return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s) {
  for (const auto& value : s)
    out << value << ' ';

  return out;
}

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& out, const std::map<Key, Value>& map) {
  for (const auto& [key, value] : map)
    out << "(" << key << ": " << value << ") ";

  return out;
}

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<Key, Value>& umap) {
  for (const auto& [key, value] : umap)
    out << "(" << key << ": " << value << ") ";

  return out;
}
