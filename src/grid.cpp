#include "grid.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

Grid::Grid(int nx, int ny) : nx(nx), ny(ny) {
    // TODO: Allocate contiguous memory
    // 1. Allocate data array of size nx*ny using aligned_alloc
    // 2. Allocate rows array of size nx
    // 3. Set each rows[i] to point to &data[i*ny]
    
    // Hint for students:
    // data = (double*)aligned_alloc(64, nx * ny * sizeof(double));
    // rows = new double*[nx];
    // for (int i = 0; i < nx; i++) {
    //     rows[i] = &data[i * ny];
    // }
}

Grid::~Grid() {
    // TODO: Free memory
    // 1. Delete rows array
    // 2. Free data array
}

void Grid::fill(double value) {
    // TODO: Fill entire grid with constant value
}

void Grid::initialize(int init_type, double T_initial, double Lx, double Ly) {
    double dx = Lx / (nx - 1);
    double dy = Ly / (ny - 1);
    
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            double x = i * dx;
            double y = j * dy;
            
            switch (init_type) {
                case 0: // Uniform
                    (*this)(i, j) = T_initial;
                    break;
                    
                case 1: { // Gaussian hotspot in center
                    double cx = Lx / 2.0;
                    double cy = Ly / 2.0;
                    double sigma = Lx / 8.0;
                    double r2 = (x-cx)*(x-cx) + (y-cy)*(y-cy);
                    (*this)(i, j) = T_initial + 100.0 * exp(-r2/(2*sigma*sigma));
                    break;
                }
                    
                case 2: // Random
                    (*this)(i, j) = T_initial + (rand() % 100) / 100.0 * 50.0;
                    break;
                    
                default:
                    (*this)(i, j) = T_initial;
            }
        }
    }
}

void Grid::swap(Grid& other) {
    // TODO: Swap data pointers between two grids
    // This should be O(1) - just swap pointers, not copy data
}

bool Grid::is_approx_equal(const Grid& other, double tolerance) const {
    if (nx != other.nx || ny != other.ny) return false;
    
    // TODO: Check if all elements are within tolerance
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            if (std::abs((*this)(i, j) - other(i, j)) > tolerance) {
                return false;
            }
        }
    }
    return true;
}
