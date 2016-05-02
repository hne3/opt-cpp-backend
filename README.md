# opt-cpp-backend
prototype C/C++ backend for Online Python Tutor

Based on a hacked version of Valgrind 3.11.0, downloaded from:
http://www.valgrind.org/downloads/valgrind-3.11.0.tar.bz2

Build dependencies:
- (basic Linux C compiler toolchain)
- binutils-dev

To run:
-Ensure that all dependencies are installed
-./auto-everything.sh
-python vg_to_opt_trace.py semaphore-test
-Pass in semaphore test to frontend