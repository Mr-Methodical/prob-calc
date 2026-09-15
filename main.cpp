#ifdef __INTELLISENSE__
#include <iostream>
#else
import <iostream>;
#endif

int main() {
  int sidesA = 0;
  int sidesB = 0;
  int sidesC = 0;

  if (!(std::cin >> sidesA >> sidesB >> sidesC)) {
    // ex. if they put in string instead of integer
    std::cerr << "Expected 3 integers" << "\n";
    return 1;
  }

  std::cout << "First die: " << sidesA << "\n";
  std::cout << "First die: " << sidesB << "\n";
  std::cout << "First die: " << sidesC << "\n";
}
