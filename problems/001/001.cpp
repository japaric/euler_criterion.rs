#include<cstdint>
#include<cstring>
#include<ctime>
#include<iostream>
#include<string>

using namespace std;

uint32_t solution() {
  // DON'T OPTIMIZE THIS AWAY!
  asm("");

  uint32_t sum = 0;

  for (uint32_t i = 0; i < 1000; i++)
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;

  return sum;
}

int main(int argc, char* argv[]) {
  if (argc == 2 && strcmp(argv[1], "-a") == 0) {
    cout << solution() << endl;
    return 0;
  }

  for (string line; getline(cin, line);) {
    int iters = atoi(line.c_str());

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (int i = 0; i < iters; i++) {
      solution();
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    long int secs = end.tv_sec - start.tv_sec;
    long int nsecs = end.tv_nsec - start.tv_nsec;
    cout << secs * 1000000000 + nsecs << endl;
  }

  return 0;
}
