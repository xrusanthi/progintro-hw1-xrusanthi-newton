#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to evaluate the polynomial
double Polynomial_fun(double a0, double a1, double a2, double a3, double a4, double a5, double x) {
  return a0 + a1*x + a2*x*x + a3*x*x*x + a4*x*x*x*x + a5*x*x*x*x*x;
}

// Function to evaluate the derivative of the polynomial
double Derivative_fun(double a1, double a2, double a3, double a4, double a5, double x) {
  return a1 + 2*a2*x + 3*a3*x*x + 4*a4*x*x*x + 5*a5*x*x*x*x;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 8) // Check if the correct number of arguments is provided
    return 1;    // Exit code 1 (error)

  // Convert the arguments to the variables
  double a0 = strtod(argv[1], NULL);
  double a1 = strtod(argv[2], NULL);
  double a2 = strtod(argv[3], NULL);
  double a3 = strtod(argv[4], NULL);
  double a4 = strtod(argv[5], NULL);
  double a5 = strtod(argv[6], NULL);
  double x0 = strtod(argv[7], NULL);

  double xn = x0;
  int iterations = 0;
  double error = 1e-6 + 1;

  // Newton's method
  while (error > 1e-6 && iterations < 1000) {
    double fxn = Polynomial_fun(a0, a1, a2, a3, a4, a5, xn);
    double dfxn = Derivative_fun(a1, a2, a3, a4, a5, xn);
    // Check if the algorithm diverges 
    if (dfxn == 0) {
      printf("nan\n");
      return 0;
    }

    // Update the value of xn
    double xn1 = xn - fxn / dfxn; // Newton's method formula
    double diff = fabs(xn1 - xn); // Calculate the absolute difference

    // Check if the algorithm has converged
    if (diff < 1e-6) {
      printf("%.2f\n", xn1);
      return 0;
    }

    // Update the values of xn and iterations
    xn = xn1;
    error = diff;
    iterations++;
  }

  // Check if the maximum number of iterations is reached
  if (iterations >= 1000) {
    printf("incomplete\n");
  }
  return 0;
}
