#include "Pseudopotential.h"

#define _USE_MATH_DEFINES 1
#include <cmath>

#include "Constants.hpp"

namespace EmpiricalPseudopotential {

Pseudopotential::Pseudopotential(double V3S, double V4S, double V8S, double V11S, double V3A, double V4A, double V8A, double V11A)
    : m_V3S(V3S),
      m_V4S(V4S),
      m_V8S(V8S),
      m_V11S(V11S),
      m_V3A(V3A),
      m_V4A(V4A),
      m_V8A(V8A),
      m_V11A(V11A) {}

std::complex<double> Pseudopotential::GetValue(const Vector3D<int>& G, const Vector3D<double>& tau, double lattice_constant) const {
    constexpr double const_two = 2.0;
    const int        G2        = G * G;
    const double     Gtau      = (const_two * M_PI / lattice_constant) * tau * G;

    double VS = 0;
    double VA = 0;

    if (G2 == 3) {
        VS = m_V3S;
        VA = m_V3A;
    } else if (G2 == 4) {
        VS = m_V4S;
        VA = m_V4A;
    } else if (G2 == 8) {
        VS = m_V8S;
        VA = m_V8A;
    } else if (G2 == 11) {
        VS = m_V11S;
        VA = m_V11A;
    }

    return std::complex<double>(cos(Gtau) * VS, sin(Gtau) * VA);
}

void Pseudopotential::print_parameters() const {
    std::cout << "V3S = " << m_V3S << std::endl;
    std::cout << "V4S = " << m_V4S << std::endl;
    std::cout << "V8S = " << m_V8S << std::endl;
    std::cout << "V11S = " << m_V11S << std::endl;
    std::cout << "V3A = " << m_V3A << std::endl;
    std::cout << "V4A = " << m_V4A << std::endl;
    std::cout << "V8A = " << m_V8A << std::endl;
    std::cout << "V11A = " << m_V11A << std::endl;
}

}  // namespace EmpiricalPseudopotential