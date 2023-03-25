#include "cache_simulator.h"


CacheSimulator::CacheSimulator(std::string trace_file) {
    input_.open(trace_file);
}


void CacheSimulator::run() {
    std::string line;
    while (std::getline(input_, line)) {
        auto [access_type, access_address, num_instructions] = parse_line(line);
    }
}


TraceLine CacheSimulator::parse_trace_line(std::string access) {
    int access_type;
    std::uint64_t access_address;
    int num_instructions;

    sscanf(
        access.c_str(),
        "# %d %lx %d",
        &access_type,
        &access_address,
        &num_instructions
    );

  return {access_type, access_address, num_instructions};
}


CacheSimulator::~CacheSimulator() {
    input_.close();
}
