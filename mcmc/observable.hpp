#ifndef MCMC_OBSERVABLE_HPP
#define MCMC_OBSERVABLE_HPP

#include <cmath> // for std::sqrt

namespace mcmc {

class observable {
public:
  observable() : count_(0), sum_(0), esq_(0) {}
  void operator<<(double x) { sum_ += x; esq_ += x * x; ++count_; }
  double mean() const { return (count_ > 0) ? (sum_ / count_) : 0.; }
  double error() const {
    return (count_ > 1) ?
      std::sqrt((esq_ / count_ - mean() * mean()) / (count_ - 1)) : 0.;
  }
private:
  unsigned int count_;
  double sum_, esq_;
};

} // end namespace mcmc

#endif // MCMC_OBSERVABLE_HPP
