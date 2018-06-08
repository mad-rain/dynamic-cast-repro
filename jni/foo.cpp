
#include <dlfcn.h>
#include <stdlib.h>

#include <iostream>

typedef const char * (*test_func)();

void *load_library(const char *name) {
  void *lib = dlopen(name, RTLD_NOW);
  if (lib == nullptr) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return lib;
}

test_func load_func(void *lib, const char *name) {
  test_func sym = reinterpret_cast<test_func>(dlsym(lib, name));
  if (sym == nullptr) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return sym;
}

int main(int argc, char**) {

  void *libtest = load_library("libtest.so");

  test_func do_test = load_func(libtest, "do_test");
  std::cout << do_test() << std::endl;

  return EXIT_SUCCESS;
}

