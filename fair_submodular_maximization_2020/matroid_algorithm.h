// Copyright 2020 The Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Matroid constrained submodular maximization.
//

#ifndef FAIR_SUBMODULAR_MAXIMIZATION_2020_MATROID_ALGORITHM_H_
#define FAIR_SUBMODULAR_MAXIMIZATION_2020_MATROID_ALGORITHM_H_

#include "algorithm.h"

class MatroidAlgorithm : public Algorithm {
 public:
  // Handles insertion of an element.
  void Insert(std::pair<int, int> element, bool non_monotone = false);

  // Initializes the algorithm state (also saves bounds and k).
  void Init(SubmodularFunction& sub_func_f,
            std::vector<std::pair<int, int>> bounds, int cardinality_k);

  // Gets current solution value.
  double GetSolutionValue();

  // Gets current solution.
  std::vector<std::pair<int, int>> GetSolutionVector();

  // Get name of algorithm.
  std::string GetAlgorithmName() const;

 private:
  // Set of the chosen elements.
  //   first = id of the element.
  //   second = color of the element.
  std::vector<std::pair<int, int>> elements_;

  // Value of the solution.
  double solution_value_;

  // Submodulaer function.
  std::unique_ptr<SubmodularFunction> sub_func_f_;

  // Number from each color.
  std::vector<int> colors_;

  // Lower and upper bound constraints.
  std::vector<std::pair<int, int>> bounds_;

  // Cardinality Constraint.
  int cardinality_k_;
};

#endif  // FAIR_SUBMODULAR_MAXIMIZATION_2020_MATROID_ALGORITHM_H_
