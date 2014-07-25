#include <boost/random.hpp>
#include <boost/timer.hpp>
#include <mcmc/observable.hpp>
#include <cmath>

inline double f(double x) { return 2 / std::cosh(x); }

inline double p(double x) { return std::exp(-x); }

template<typename RNG>
void mc_integration(long ns, RNG rng) {
  mcmc::observable pi;
  boost::timer tm;
  for (long m = 0; m < ns; ++m) {
    double x = -std::log(rng());
    pi << (f(x) / p(x));
  }
  std::cout << ns << ' ' << pi.mean() << ' ' << pi.error() << ' '
            << ns * pi.error() * pi.error() << std::endl;
  std::cerr << "# elapsed = " << tm.elapsed() << " sec\n";
}

int main() {
  boost::mt19937 eng(29411u);
  boost::variate_generator<boost::mt19937&, boost::uniform_real<> >
    rng(eng, boost::uniform_real<>());
  std::cout << "# number of samples, average, standard deviation, "
            << "asymptotic variance\n";
  for (long ns = 100; ns <= 1000000000; ns *= 10) mc_integration(ns, rng);
}
