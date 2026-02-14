#include "solver.h"
#include <omp.h>
#include <iostream>

OpenMPSolver::OpenMPSolver(int threads) : Solver(), num_threads(threads) {
    if (num_threads > 0) {
        omp_set_num_threads(num_threads);
    }
}

void OpenMPSolver::time_step() {
    int nx = T_old->get_nx();
    int ny = T_old->get_ny();
    
    // TODO: Implement OpenMP parallel time step
    // Use #pragma omp parallel for collapse(2)
    // Experiment with different scheduling policies
    // Avoid false sharing by using local variables
    
    #pragma omp parallel for collapse(2) schedule(static)
    for (int i = 1; i < nx-1; i++) {
        for (int j = 1; j < ny-1; j++) {
            // TODO: Implement stencil computation
        }
    }
    
    // Apply boundary conditions (should not be parallelized)
    bc->apply(*T_new);
}
