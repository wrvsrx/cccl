#pragma once
#include <cstdint>
#include <thrust/device_vector.h>

auto callScan(thrust::device_vector<uint32_t> const &)
    -> thrust::device_vector<uint32_t>;
