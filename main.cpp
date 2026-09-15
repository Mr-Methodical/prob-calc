#ifdef __INTELLISENSE__
#include <iostream>
#include <fstream>
#else
import <iostream>;
import <fstream>;
#endif

struct Experiment {
  int sidesA;
  int sidesB;
  int threshold;
};

// a reference to the input stream
bool readExperiment(std::istream& in, Experiment& e) {
  if (!(in >> e.sidesA >> e.sidesB >> e.threshold)) {
    return false;
  }
  return true;
}

void printExperiment(std::ostream& out, const Experiment& e) {
  out << "First die: " << e.sidesA << "\n";
  out << "Second die: " << e.sidesB << "\n";
  out << "Minimum sum: " << e.threshold << "\n";
}

int runExperiment(std::istream& in, std::ostream& out) {
  // empty braces initialize all values to 0
  Experiment experiment{};

  if (!readExperiment(in, experiment)) {
    // ex. if they put in string instead of integer
    std::cerr << "Expected 3 integers\n";
    return 1;
  }

  if ((experiment.sidesA < 1 || experiment.sidesA > 100) ||
      (experiment.sidesB < 1 || experiment.sidesB > 100)) {
    std::cerr << "Each die must have between 1 and 100 sides\n";
    return 1;
  }

  printExperiment(out, experiment);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    return runExperiment(std::cin, std::cout);
  }

  if (argc != 2) {
    // square brackets means optional
    std::cerr << "Usage: ./dice [input-file]\n";
    return 1;
  }

  // now we know argc must be 2

  // we do not need close file because of RAII where it will manage its own
  // resources when it goes out of scope. Object's lifetime controls cleanup
  std::ifstream file{argv[1]};

  if (!file) {
    std::cerr << "Cannot open " << argv[1] << "\n";
    return 1;
  }

  return runExperiment(file, std::cout);
}
