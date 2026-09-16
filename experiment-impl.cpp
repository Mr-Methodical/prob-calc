module experiment;

namespace Prob {
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
}
