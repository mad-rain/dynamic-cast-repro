
#include <exception>

extern void throw_exception();


const char *method() {

    const char *str = "no_except";

    try {

        throw_exception();

    } catch (const std::exception &e) {
        str = "std_exception (compiler ok)";
    } catch (...) {
        str = "unhandled exception (compiler bug)";
    }

    return str;
}

extern "C" const char *do_test() {
	return method();
}
