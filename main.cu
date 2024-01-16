#include "lib.cuh"
#include <thrust/device_vector.h>
#include <thrust/scan.h>

auto main() -> int {
  auto const vec = thrust::device_vector<uint32_t>(100, 1);
  std::cout << "THRUST_VERSION: " << THRUST_VERSION << std::endl;
  auto const b = callScan(vec);
  auto c = thrust::device_vector<uint32_t>(vec.size());
  thrust::exclusive_scan(vec.begin(), vec.end(), c.begin());
}
