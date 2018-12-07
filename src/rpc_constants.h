/**
 * @file rpc_constants.h
 * @brief eRPC constants that are of interest to the user
 */
#pragma once
#include <stdint.h>
#include <stdlib.h>

namespace erpc {

/**
 * @relates Rpc
 * @brief Maximum number of eRPC processes per machine
 */
static constexpr size_t kMaxNumERpcProcesses = 32;

/**
 * @relates Rpc
 * @brief The maximum ID of an Rpc object
 */
static constexpr size_t kMaxRpcId = UINT8_MAX - 1;

/**
 * @relates Rpc
 * @brief The management port for an eRPC processes must be between
 * \p kBaseSmUdpPort and (\p kBaseSmUdpPort + \p kMaxNumERpcProcesses)
 */
static constexpr uint16_t kBaseSmUdpPort = 31850;

static_assert(kBaseSmUdpPort + kMaxNumERpcProcesses +
                      (kMaxNumERpcProcesses * kMaxRpcId) <
                  UINT16_MAX,
              "");

/**
 * @relates Rpc
 * @brief Maximum number of NUMA nodes per machine
 */
static constexpr size_t kMaxNumaNodes = 8;

/**
 * @relates Rpc
 * @brief Maximum number of background threads per process
 */
static constexpr size_t kMaxBgThreads = 8;

/**
 * @relates Rpc
 * @brief Maximum number of datapath device ports
 */
static constexpr size_t kMaxPhyPorts = 16;

/**
 * @brief Return the datapath UDP port used for an Rpc object in a process
 *
 * @param mgmt_udp_port The management UDP port of the process
 * @param rpc_id The ID of the Rpc object
 */
static uint16_t get_dpath_udp_port(uint16_t mgmt_udp_port, uint8_t rpc_id) {
  return kBaseSmUdpPort + kMaxNumERpcProcesses +
         (static_cast<uint16_t>(mgmt_udp_port - kBaseSmUdpPort) * kMaxRpcId) +
         rpc_id;
}

}  // namespace erpc