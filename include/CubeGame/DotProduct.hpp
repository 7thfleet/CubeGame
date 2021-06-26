#ifndef MATHUTILS_DOTPRODUCT_HPP    //Good practice to prefix header guards with project/lib name to reduce collisions
#define MATHUTILS_DOTPRODUCT_HPP

//Keep includes to minimum in header files
#include <vector>

namespace CubeGame{
    /** Computes the dot product of two vectors containing ints.
     * @param a         The first vector
     * @param b         The second vector
     * @return          The dot product of \p a and \p b.
     * @throws std::invalid_argument if \p a and \p b do not have the same length.
     */
    int DotProduct(const std::vector<int>& a, const std::vector<int>& b);
}

#endif //MATHUTILS_DOTPRODUCT_HPP
