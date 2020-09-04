#ifndef INC_PLATFORM_BENCHMARK_H
#define INC_PLATFORM_BENCHMARK_H

#include <stdint.h>

float startTime1;
float startTime2;
float endTime;
float bench1;
float bench2;
uint32_t bench_c;

void start_bench(int bench);

void stop_bench(int bench);

void print_bench(void);

#endif //INC_PLATFORM_BENCHMARK_H
