#include "solver.h"
#include <iostream>

SequentialSolver::SequentialSolver() : Solver() {}

void SequentialSolver::time_step() {
    // TODO: Implement one sequential time step
    // 1. Apply stencil to all interior points
    // 2. Update T_new from T_old using the 5-point stencil
    // 3. Apply boundary conditions to T_new
    
    // Hint:
    // for (int i = 1; i < nx-1; i++) {
    //     for (int j = 1; j < ny-1; j++) {
    //         T_new(i,j) = T_old(i,j) + factor * (
    //             T_old(i-1,j) + T_old(i+1,j) + 
    //             T_old(i,j-1) + T_old(i,j+1) - 4.0 * T_old(i,j)
    //         );
    //     }
    // }
}
