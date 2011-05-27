#include "hermes2d.h"

/* Exact solution */

class CustomExactSolution : public ExactSolutionScalar
{
public:
  CustomExactSolution(Mesh* mesh) : ExactSolutionScalar(mesh) {};

  virtual scalar value (double x, double y) const {
    return x*x +y*y;
  }

  virtual void derivatives (double x, double y, scalar& dx, scalar& dy) const {
    dx = 2*x;
    dy = 2*y;
  };

  virtual Ord ord(Ord x, Ord y) const {
    return x*x + y*y;
  }
};

/* Weak forms */

class CustomWeakFormPoisson : public WeakForm
{
public:
  CustomWeakFormPoisson(bool is_matfree = false) : WeakForm(1) {
    this->is_matfree = is_matfree;

    // Jacobian.
    add_matrix_form(new WeakFormsH1::DefaultJacobianDiffusion(0, 0));

    // Residual.
    add_vector_form(new WeakFormsH1::DefaultResidualDiffusion(0));
    add_vector_form(new WeakFormsH1::DefaultVectorFormVol(0, HERMES_ANY, new HermesFunction(4.0)));
  };
};

