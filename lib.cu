#include "lib.cuh"
#include <thrust/device_vector.h>
#include <thrust/reduce.h>
#include <thrust/scan.h>

auto callScan(thrust::device_vector<uint32_t> const &a)
    -> thrust::device_vector<uint32_t> {
  auto res = thrust::device_vector<uint32_t>(a.size());
  thrust::exclusive_scan(a.begin(), a.end(), res.begin());
  return res;
}
