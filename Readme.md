# Pes Project1 Readme
Team : Sundar Krishnakumar
## Repository Comments
### Directory structure

Parent Directory : Pes_Project1
```
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
```

### Directory description
- exec  - Contains all the executable files.
- obj - Contains all the object files.
- program1, program2, program3 - Contain three folders each namely : data, inc,src containing the application, header and its implementation file respectively.
- Makefile - Containes the recipes : all, one, two, three, clean.
- .out files - Contain the piped output for all input values.

## Project Comments 
- It is challenging to make a clean alignment of output in program1
- Minor algorithm issues, subtle to notice and may cause misrepresentation of binary data in program1.And the same in the case of rotation/shift operations too in program3.
- Suggestions : The project helps the programmer touch a number of aspects of the C language and is good for a beginner project.I prefer no future suggestions.

## Installation/execution notes
- Environment used: Linux(Ubuntu)
- Compiler : GCC

NOTE :
- For Windows users : Follow steps in this [link](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/) for installing GCC and Make.
- For Linux users -  Install the build-essential package.(Contains gcc and make) 

### To build

1. Create a directory and give a name(say:Pes_Project1) and make it your current directory.
2. Clone the above github repository.Link to [repo](https://github.com/sundarkrish/Pes_Project1.git).
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
Program One : \
![Program1](https://github.com/sundarkrish/Pes_Project1/blob/master/images/program1.png) \
Program Two :\
![Program2](https://github.com/sundarkrish/Pes_Project1/blob/master/images/program2.png) \
Program Three : \
![Program3](https://github.com/sundarkrish/Pes_Project1/blob/master/images/program3.png) 

NOTE : 
 - In program one, negative zeros are considered equal to positive zeros as c language uses 2s compliment internally for comparison.

 - In program two : null,space,backspace,horizontal tab,vertical tab,new line,form feed,carriage return are considered as whitespace characters.And apart from the mentioned types : lower case, upper case, digit,white space and special character.Other ascii characters are classified as Others(like DEL, Esc)

 - In program three, only if exactly three out of the last four bits of the 16 bit binary is ON(i.e.1) the program gives a TRUE output.
 
 ## References :
 Decimal to binary conversion : \
![Dec2bin](https://github.com/sundarkrish/Pes_Project1/blob/master/images/dec_to_bin.png) \
 2s compliment:
1. https://codeforwin.org/2015/08/c-program-to-find-twos-complement-of-binary-number.html

ascii:
1. https://canvas.colorado.edu/files/13180389/download?download_frd=1 
2. https://icecube.wisc.edu/~dglo/c_class/charfunc.html
3. https://www.petefreitag.com/cheatsheets/ascii-codes/

bit rotation in c:
1. https://codeforwin.org/2017/12/c-program-rotate-number-bits.html
   (Note:Right shift of signed nos adds in a 1 instead of a 0)

makefile for codes with directory structure:
1. https://stackoverflow.com/questions/1139271/makefiles-with-source-files-in-different-directories
 

