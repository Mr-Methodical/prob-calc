module experiment;

namespace Prob {
  bool readExperiment(std::istream& in, Experiment& e) {
    if (!(in >> e.sidesA >> e.sidesB >> e.threshold)) {
      return false;
    }
    return true;
  }

  void printExperiment(std::ostream& out, const Experiment& e) {
    out << "Die A: " << e.sidesA << "\n";
    out << "Second die: " << e.sidesB << "\n";
    out << "Minimum sum: " << e.threshold << "\n";
  }

  int countFavourable(const Experiment& e) {
    int count = 0;
    for (int i = 1; i <= e.sidesA; ++i) {
      for (int j = 1; j <= e.sidesB; ++j) {
        if (i + j >= e.threshold) {
          count++;
        }
      }
    }
    return count;
  }
}
