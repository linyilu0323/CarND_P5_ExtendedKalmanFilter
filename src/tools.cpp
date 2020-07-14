#include "tools.h"
#include <iostream>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using std::cout;
using std::endl;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  // initialize an empty rmse array
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // determine if any bad inputs
  if (estimations.size() == 0) {
    cout << "Estimation vector size should not be zero!" << endl;
    return rmse;
  }
  if (estimations.size() != ground_truth.size()){
    cout << "Estimation vector size should equal to ground truth vector size!" << endl;
    return rmse;
  }

  // calculate total squared residuals
  for (unsigned int i=0; i < estimations.size(); ++i) {
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }

  // calculate the final rmse
  rmse = rmse / estimations.size();
  rmse = rmse.array().sqrt();

  return rmse;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {

    // initialize an empty Hj matrix
    MatrixXd Hj(3,4);
    // recover state parameters
    float px = x_state(0);
    float py = x_state(1);
    float vx = x_state(2);
    float vy = x_state(3);

    // calculate Jacobian
    float c1 = px*px + py*py;
    float c2 = sqrt(c1);
    float c3 = c1 * c2;
    // check division by zero
    // compute the Jacobian matrix
    if (fabs(c1) > 0.0001) {
      Hj << (px/c2), (py/c2), 0, 0,
            -(py/c1), (px/c1), 0, 0,
            py*(vx*py-vy*px)/c3, px*(vy*px-vx*py)/c3, px/c2, py/c2;
    }
    else{
      cout << "CalculateJacobian() - Error - Division by zero" << endl;
    }

    return Hj;
}
