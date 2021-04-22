/*
 * utils.hpp
 *
 *  Created on: 21/04/2021
 *      Author: jrugis
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "global_defs.hpp"

namespace utils {
  void calc_tri_centers(MatrixN3d& centers, const MatrixN3d& vertices, const MatrixN3i& triangles);
  void fatal_error(const std::string msg, std::ofstream& out);
  void get_parameters(const std::string file_name, std::unordered_map<std::string, double>& p, std::ofstream& out);
  double get_distance(const Vector3d& p, const Vector3d& v, const Vector3d& w);
  // void read_mesh(const std::string file_name, sMeshVals& mesh_vals, std::ofstream& out);
  void save_matrix(const std::string file_name, int bytes, char* data);
} // namespace utils

#endif /* UTILS_H_ */
