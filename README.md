# AFT — Another Frequency Thing

AFT is a statically-typed, LLVM-backed educational compiler project implementing a complete DSL pipeline, including lexing, parsing, AST construction, semantic analysis, and IR code generation.

1. Project Overview

AFT (Another Frequency Thing) is a small, imperative, function-based DSL designed to demonstrate end-to-end compiler construction.

The implementation includes:

Lexer implemented using Flex

Parser built with Bison

AST generator with structured node hierarchy

Semantic analyzer (scope management, type checking, symbol tables)

LLVM-based backend for IR generation

Runtime library implementing built-in language functions

AST Printer for visualization and debugging

Comprehensive testcases (syntax + semantics + general + builtins)

The repository contains a Makefile that builds all compiler components and tools.

2. Building the Project

Requirements
AFT depends on the following external tools and libraries:

Component	Purpose : 

LLVM (16–19)	Target backend, IR builder, system libraries
Flex	Lexical analysis
Bison	Grammar and parser generation
Clang/LLVM Toolchain	Linking, executing IR
Standard C++ compiler (clang++ recommended)	Core implementation

# Build Instructions
To build the entire toolchain (compiler + AST printer):

make
This produces:

aft – the AFT compiler

ast_printer – standalone AST visualization tool

3. Usage

Compile an AFT program into LLVM IR
./aft program.af -o program.ll

Execute using LLVM interpreter
lli program.ll

Compile to a native binary
clang program.ll -o program
./program

View the Abstract Syntax Tree
./ast_printer program.af

4. Language Features 

Primitive types: int, bool, void

Variables and assignments
Arithmetic and boolean expressions
Conditional control flow: if, else if, else
Iterative control flow: for, while
First-class functions
Typed parameters
Typed return values
Recursive calls

Block scoping and shadowing

