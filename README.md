# Extended Kalman Filter
**Extended Kalman Filter Project**

In this project you will utilize a kalman filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. Summary of what needs to be done:

* In `tools.cpp`, fill in the functions that calculate root mean squared error (RMSE) and the Jacobian matrix.
* Fill in the code in `FusionEKF.cpp`. You'll need to initialize the Kalman Filter, prepare the Q and F matrices for the prediction step, and call the radar and lidar update functions.
* In `kalman_filter.cpp`, fill out the `Predict()`, `Update()`, and `UpdateEKF()` functions.

[//]: # "Image References"

[image1]: ./examples/nVidia_model.png "nVidia model architecture"
[image2]: ./examples/data_distribution_udacity.png "Adjusted population for Udacity dataset"
[image3]: ./examples/data_distribution_myinput.png "Adjusted population for my dataset"
[image4]: ./examples/track1_run1.gif "Results"
[image5]: ./examples/MSE_evolve.png	"MSE vs Epochs"

----

