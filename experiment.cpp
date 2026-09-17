export module experiment;

import <iostream>;

namespace Prob {
  export struct Experiment {
    int sidesA;
    int sidesB;
    int sidesC;
    int threshold;
  };
  
  export int countFavourable(const Experiment& e);
  
  export bool readExperiment(std::istream& in, Experiment& e);

  export void printExperiment(std::ostream& out, const Experiment& e);
}
