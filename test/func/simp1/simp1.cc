// Copyright Microsoft and Project Verona Contributors.
// SPDX-License-Identifier: MIT

#include <cpp/when.h>
#include <debug/harness.h>

class Body
{
public:
  ~Body()
  {
    Logging::cout() << "Body destroyed" << Logging::endl;
  }
};

using namespace verona::cpp;

void test_body()
{
  Logging::cout() << "test_body()" << Logging::endl;

  auto log = make_cown<Body>();

  //when(log) << [=](auto) { Logging::cout() << "log" << Logging::endl; };

  //when(log) >> [=](auto) { Logging::cout() << "log" << Logging::endl; };

  //(when(log) >> [=](auto) { Logging::cout() << "log" << Logging::endl; }) + (when() >> [=](auto) { Logging::cout() << "log" << Logging::endl; });

  std::cout << "Foo\n";
}

int main(int argc, char** argv)
{
  SystematicTestHarness harness(argc, argv);

  harness.run(test_body);

  return 0;
}
