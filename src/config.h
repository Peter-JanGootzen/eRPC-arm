/**
 * @file config.h
 * @brief Compile-time constants mostly derived from CMake
 */
#ifndef ERPC_CONFIG_H
#define ERPC_CONFIG_H

#include <assert.h>
#include <stdlib.h>

namespace erpc {

static constexpr bool kDatapathStats = false;

static inline void dpath_stat_inc(size_t &stat, size_t val) {
  if (kDatapathStats) stat += val;
}

#ifdef TESTING
static constexpr bool kTesting = true;
#else
static constexpr bool kTesting = false;
#endif
}

#endif  // ERPC_CONFIG_H