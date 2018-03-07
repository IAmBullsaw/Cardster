# Cardster
A flash card based learning system.

## Build instructions
### Prerequesites
|            |source                |tests                 |documentation
|------------|:--------------------:|:--------------------:|:--------------------:|
|make        |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|cmake 3.9.6 |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|clang++-4.0 |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|SDL2        |:heavy_check_mark:    |:heavy_check_mark:    |                      |
|GTest 1.8.0 |                      |:heavy_check_mark:    |                      | 
|Doxygen     |                      |                      |:heavy_check_mark:    |

### Instructions
To build run the following commands
```bash
user@machine:~/Code$ git clone git@github.com:IAmBullsaw/Cardster.git
user@machine:~/Code$ cd Cardster
user@machine:~/Code/Cardster$ mkdir build
user@machine:~/Code/Cardster$ cd build
user@machine:~/Code/Cardster/build$ cmake ..
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
