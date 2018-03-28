# Cardster
A flash card based learning system.

# Status [![Build Status](https://travis-ci.org/IAmBullsaw/Cardster.svg?branch=master)](https://travis-ci.org/IAmBullsaw/Cardster)
Currently setting up the project.

## Build instructions
### Prerequesites
|            |source                |tests                 |documentation
|------------|:--------------------:|:--------------------:|:--------------------:|
|make        |:heavy_check_mark:    |:heavy_check_mark:    |:heavy_check_mark:    |
|cmake 3.9.6 |:heavy_check_mark:    |:heavy_check_mark:    |:heavy_check_mark:    |
|clang++-4.0 |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|SDL2        |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|GTest 1.8.0 |                      |:heavy_check_mark:    |                      | 
|Doxygen     |                      |                      |:heavy_check_mark:    |

*notes: to download GTest via make one needs curl with https, so ./bootstrap cmake with --system-curl*

### Instructions
#### Build
To build run the following commands
```bash
user@machine:~/Code$ git clone git@github.com:IAmBullsaw/Cardster.git
user@machine:~/Code$ cd Cardster
user@machine:~/Code/Cardster$ mkdir build
user@machine:~/Code/Cardster$ cd build
user@machine:~/Code/Cardster/build$ cmake ..
user@machine:~/Code/Cardster/build$ make [Cardster or tests or docs (and more)]
```
And to build tests now run
```bash
user@machine:~/Code/Cardster/build$ make GTest
user@machine:~/Code/Cardster/build$ cmake ..
user@machine:~/Code/Cardster/build$ make tests
```
This downloads and installs GTest, then `cmake ..` will update accordingly.

#### Default options
Currently the default options are:
```
BUILD_SOURCE = ON
BUILD_DOC = ON
BUILD_TESTS = OFF
COVERAGE = OFF
```

#### Usage
Run all tests
```bash
user@machine:~/Code/Cardster/build$ cd tests/
user@machine:~/Code/Cardster/build/tests$ ./tests
```

Read all documents
```bash
user@machine:~/Code/Cardster/build$ cd doc/
user@machine:~/Code/Cardster/build/doc$ cd html/
user@machine:~/Code/Cardster/build/doc/html$ firefox index.html
```

Start the program
```bash
user@machine:~/Code/Cardster/build$ ./Cardster
```

## Documentation
The documentation is generated via Doxygen.   
Run this command to generate them:
```bash
user@machine:~/Code/Cardster/build$ make docs
```

## Testing
Tests are done using the framework Google Test.
```bash
user@machine:~/Code/Cardster/build$ make tests
```
