#include "Console.hpp"

#include <vector>

class Solution {
public:
  int findComplement(int num) {
    if (num == 0)
      return 1;

    std::vector<uint16_t> binary;

    // convert to binary representation
    while (num != 0) {
      binary.push_back(num % 2);
      num /= 2;
    }

    // make complement
    for (std::size_t i = 0, size = binary.size(); i < size; i++) {
      binary[i] = !binary[i];
    }

    int res = 0;
    for (int i = binary.size() - 1; i > -1; i--)
      res = res * 2 + binary[i];

    return res;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int input;
  int output;

  Test(int input, int output)
    : id(Test::TestsCount++), input(input), output(output) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test(5,2),
   Test(1,0),
  };

  for (const auto& test : tests) {
    console.reset().sep("").type("Test", test.id);
    if (sln.findComplement(test.input) == test.output) {
      console.color(ccolor::dark_green).log("Passed");
    }
    else {
      console.color(ccolor::dark_red).log("Passed");
    }
  }

  return 0;
}
