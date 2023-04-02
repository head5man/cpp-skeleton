# Preparations
This guideline was written on Ubuntu 20.04 TLS.
The example uses /build as the base path.

## Required build tools
The cpp-skeleton application software requires cmake v3.3.2 to build.
During initial testing g++-10 compiler was used but the ubuntu default g++-9 should work just fine.

Following is the list of tool identified reconstruct the build setup on stock ubuntu.

```bash
sudo apt-get update
sudo apt-get install autoconf autogen automake cmake curl git libtool g++ make unzip
```

## Build log4cplus (REL_2_1_0)
The master head version (3.0.0) of the log4plus requires a compiler with c++20 features and is a bit picky while at it.
Although the tested g++ (10.3) compiler does accept flag -std=c++20 and __cplusplus evaluates to 201707L.
The log4cplus compiler test still fail due to a version checking clause.
```
#https://github.com/log4cplus/log4cplus/blob/d9521ad97ba781b8b97f5aa29b0f4476074db866/m4/ax_cxx_compile_stdcxx.m4#L990
#elif __cplusplus < 202002L && !defined _MSVER
```
#### Run the following commands:
```bash
mkdir -p /build/3rdparty && cd /build/3rdparty
git clone --branch REL_2_1_0 https://github.com/log4cplus/log4cplus.git
cd log4cplus
git submodule update --init --recursive
./configure
make -j4
# run make again if encouter warning AC_some_variable_m4
sudo make install
# verify installed
pkg-config --debug log4cplus
```

### DownloadProject
The https://github.com/Crascit/DownloadProject cmake files are used to download googletest at CMake's configure step.

And I quote from the repository README.md:
> The primary advantage of this is that the project's source code can then be included directly in the main CMake build using the add_subdirectory() command, making all of the external project's targets, etc. available without any further effort.

# Make the skeleton build
### Run the following:
```bash
mkdir -p /build/application-software && cd /build/application-software
git clone https://github.com/head5man/cpp-skeleton.git
cd cpp-skeleton
mkdir -p build && cd build
cmake ..
make
```
### Run the application
```bash
#Run the skeleton executable
src/skeleton
```
### Run the tests
```bash
#Run the skeleton-test executable
src/skeleton-test
#Run CTest alternative reporting only module level results
make test
```

