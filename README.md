# Cardster
A flash card based learning system.

## Build instructions
### Prerequesites
* make
* cmake 3.9.6
* clang++-4.0
* SDL2
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
