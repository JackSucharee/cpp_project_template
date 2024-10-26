#include <gtest/gtest.h>

#include <CLI/CLI.hpp>
#include <benchmark/benchmark.h>

#include "cpp_01.h"

template <typename T>
static void BM_test(benchmark::State& state, T arg_data)
{
    for (auto _ : state)
    {
        // CODE HERE
        cpp::Cpp01 c1;
        c1.set_data(arg_data);
    }
}

class Cpp01Test : public testing::Test
{
protected:
    Cpp01Test()
    {
    }

    ~Cpp01Test()
    {
    }

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(Cpp01Test, Test)
{
    cpp::Cpp01 c1;

    benchmark::RegisterBenchmark("test_cpp_01", BM_test<std::uint32_t>, 42)
        ->Unit(benchmark::kMillisecond)
        ->Iterations(3);
    benchmark::RunSpecifiedBenchmarks();
}

int main(int argc, char** argv)
{
    CLI::App app;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}