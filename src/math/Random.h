#ifndef MATH_RANDOM_H
#define MATH_RANDOM_H

#include <cassert>
#include <random>


/**
 * Random class, for generating random values.
 * Currently not thread safe.
 *
 * @author SwarmingLogic (Roald Fernandez)
 */
class Random
{
public:
  static float get() {
    return dist_(device_);
  }

  static float get(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(device_);
  }

  static int getInt(int min, int max) {
    assert(min <= max);
    std::uniform_int_distribution<int> dist(min, max);
    return dist(device_);
  }

  static void seed(unsigned int s) {
    seed_ = s;
    device_.seed(s);
  }

  static unsigned int seed() {
    return seed_;
  }

private:
  Random(){}
  ~Random();

  static std::mt19937 device_;
  static std::uniform_real_distribution<float> dist_;
  static unsigned int seed_;

  // NonCopyable
  Random(const Random& c);
  Random& operator=(const Random& c);
};

std::mt19937 Random::device_ = std::mt19937(std::random_device{}());
std::uniform_real_distribution<float> Random::dist_(0.0f, 1.0f);
unsigned int Random::seed_(0);
#endif
