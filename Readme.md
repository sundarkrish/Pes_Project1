# Pes Project1 Readme
Team : Sundar Krishnakumar
## Repository Comments
### Directory structure

Parent Directory : Pes_Project1
├── exec
│   ├── one
│   ├── three
│   └── two
├── Makefile
├── obj
│   ├── asciiclassifier.o
│   ├── conversions.o
│   ├── one.o
│   ├── operations.o
│   ├── three.o
│   └── two.o
├── program1
│   ├── data
│   │   └── one.c
│   ├── inc
│   │   └── conversions.h
│   └── src
│       └── conversions.c
├── program2
│   ├── data
│   │   └── two.c
│   ├── inc
│   │   └── asciiclassifier.h
│   └── src
│       └── asciiclassifier.c
├── program3
│   ├── data
│   │   └── three.c
│   ├── inc
│   │   └── operations.h
│   └── src
│       └── operations.c
├── ProgramOne.out
├── ProgramThree.out
└── ProgramTwo.out
### Directory description
- exec  - Contains all the executable files.
- obj - Contains all the object files.
- program1, program2, program3 - Contain three folders each namely : data, inc,src containing the application, header and its implementation file respectively.
- Makefile - Containes the reccipes : all, one, two, three, clean.
- .out files - Contain the piped output for all input values.

## Project Comments 
## Installation/execution notes
- Environment used: Linux(Ubuntu)
- For Windows users : Follow steps in this [link](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/) for installing GCC and Make.
- For Linux users -  Install the build-essential package.(Containes gcc and make) 
- Compiler : GCC
### To build

1. Create a directory and give a name(say:Pes_Project1) and make it your current directory.
2. Clone the above github repository.Link to [repo]().
3. Run the following commands:

Clean the existing object and executable files by running 
```sh
make clean
```
To build all three programs at once:
```sh
make all
```
To build the 3 programs individually
```sh
make one
make two
make three
```
Now, the **obj** and **exec** sub-directories will be populated with newly created object(.o) and executable files(one, two and three).

### To run
These individual commands execute the programs one,two and three respectively.Run them from the project directory(i.e. Pes_Project1 or the name you have given for your parent directory)
```sh
./exec/one
./exec/two
./exec/three
```
### Output
Program One :
Program Two :
Program Three :

NOTE : 
 - In program one, negative zeros are considered equal to positive zeros as c language uses 2s compliment internally for comparison.

 - In program two : null,space,backspace,horizontal tab,vertical tab,new line,form feed,carriage return are considered as whitespace characters.And apart from the mentioned types : lower case, upper case, digit,white space and special character other ascii characters are classified as Others(like DEL, Esc)

 - In program three, only if exactly three out of the last 4 bits of the 16 bit binary is ON(i.e.1) the program gives a TRUE output.

