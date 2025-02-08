# sqlite_cpp_project

Trying out cpp using cmake and sqlite3

### How to use CMake
Install cmake using  `brew install cmake` and then make a build directory and cd into it. 

```bash
mkdir build
cd build
cmake --build .
## The above step generates the build files
## And to generate the binary run the following in the root directory
cmake --build build
## The above command will generate a binary which has the same name as the executable defined in CMakeLists.txt
## In this project it creates a cpp_project binary under the build directory

#To run the program run
> build/cpp_project

Opened database successfully

Command executed successfully

Command executed successfully

Select command output:
ID: 1
NAME: Paul
AGE: 32
ADDRESS: California
SALARY: 20000.0

Command executed successfully

Closed database successfully
```
