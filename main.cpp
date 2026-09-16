import <iostream>;
import <fstream>;
import experiment;

int runExperiment(std::istream& in, std::ostream& out) {
  // empty braces initialize all values to 0
  Prob::Experiment experiment{};

  if (!Prob::readExperiment(in, experiment)) {
    // ex. if they put in string instead of integer
    std::cerr << "Expected 3 integers\n";
    return 1;
  }

  if ((experiment.sidesA < 1 || experiment.sidesA > 100) ||
      (experiment.sidesB < 1 || experiment.sidesB > 100)) {
    std::cerr << "Each die must have between 1 and 100 sides\n";
    return 1;
  }

  Prob::printExperiment(out, experiment);
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
