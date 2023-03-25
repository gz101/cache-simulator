#include <fstream>
#include <string>
#include <tuple>


typedef std::tuple<bool, std::uint64_t, int> TraceLine;


struct CacheSimulator {
private:
    std::ifstream input_;

    TraceLine parse_trace_line(std::string access);

public:
    CacheSimulator(std::string trace_file);
    void run();
    ~CacheSimulator();
};
