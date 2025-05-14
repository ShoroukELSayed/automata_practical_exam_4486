# Automata-Practical-Exam-4486-

---
##  Information

-  Name: Shorouk ELSayed Hassan Mohamed
-  Sec: 3
-  Department: CS, Level 4
-  Task being solved:
  - Task 1: Minimizes a given DFA
  - Task 3: Generate a PDA from a given CFG
  - Task 4: Turing Machine that increments a binary number by 1

---

##  Introduction

This project is part of the Automata practical exam. It has three task and we will talk about them in details .

---
##  DFA Minimization using Partition Refinement

A C++ program that minimizes a (DFA) using the partition refinement method, covered in the Theory of Computation.

##  First Task Description

Write a C++ program that:

- Takes a DFA from the user : number of states, states , number of alphabet, alphabet , start state , number of final states , final states, and transitions table.

- Applies the partition refinement method to minimize the DFA.

- Displays the Equivalent State Groups , Minimized DFA with start state , states ,final states , and transitions table .

---
##  Highlights
 Software Resources
- Language: C++
- Compiler: g++ (tested with C++17)
- Dependencies: Standard Library only (no external libraries)

---
# Usage

---
##  Running the code 

1. You can run the code using any C++ compiler (C++11 or above) .

2. When you run the program, it will ask about:
   Number of states.
   State names .
   Number of input symbols.
   Symbols.
   Start state.
   Number of final states.
   Names of final states.
   Transition table (currentState + symbol => nextState).


3. Output the Equivalent State Groups , Minimized DFA with start state , states ,final states , and transitions table . 
   bash
   Output The program prints:
   Partitions after minimization.
   Start States.
   States.
   Final States.
   DFA transitions.
   The resulting minimized DFA (grouped states).

<p align="center"><img src="Dfa_output.png"/></p>



---
## Generate a PDA from a given CFG

Simple C++ program to automatically generate a PDA from a given CFG and simulate it on input strings. using the knowledge of Theory of Computation.

##  Second Task Description

Write a C++ program that:

Takes a Context-Free Grammar (CFG) from the user.

Based on the CFG, a PDA is generated. A PDA uses a stack to store symbols during the computation.

Given an input string ,the PSA simulates the string.

Displays  PDA Description ( Start symbol, Accepting condition, Transitions table),and if the string is accepted or rejected.


---
##  Highlights
 Software Resources
- C++ (Tested with g++ 17)
- Standard Library only (no external dependencies).

---
# Usage
Enter number of production rules.
Enter production rules in the form:
- Variable->Production1|Production2 (like S -> aA | b)
- Use i to represent epsilon (empty string).

The program will display the PDA Description ( Start symbol, Accepting condition, Transitions table),and if the string is accepted or rejected.

---
##  Running the code 

1. You can run the code using any C++ compiler (C++11 or above) 
  
2. Input the number of rules and each rule in this format:
   
   bash
   Enter number of production rules: 2
   Enter production rules (like S -> aA | b) and Use i to represent epsilon (empty string)
   Enter the 1 rule : S -> aTb | b
   Enter the 2 rule : T -> Ta | i
   
3. Output PDA Description ( Start symbol, Accepting condition, Transitions table " Use o to represent δ(transition function)),and if the string is accepted or rejected. 
   bash
   PDA Description
   Start symbol: S
   Accepting condition: empty stack

   Transitions:
   o(q, a, S) -> (q, bTa)
   o(q, b, S) -> (q, b)
   o(q, T, T) -> (q, aT)
   o(q, i, T) -> (q, i)
   
   Test passed for input: aaab
   Test failed for input: a
   Test passed for input: b
   Test passed for input: ab

<p align="center"><img src="CNF_output2.png"/></p>


---
## Turing Machine that increments a binary number by 1

This C++ program simulates a simple Turing Machine that increments a binary number by one.

## Third Task Description

Write a C++ program that:

It reads a binary string from the user.

The program checks that the input only contains 0 and 1.

It adds _ (blank symbol) to both ends of the input to simulate the Turing tape.

Starting from the right, the machine does the following:

   If it sees a 1, it changes it to 0 and moves left .

   If it sees a 0, it changes it to 1 and stops .

   If it reaches _, it means all were 1s, so it adds 1 at the beginning .

output is the incremented binary number.

---
##  Highlights
 Software Resources
- C++ (Tested with g++ 17)
- Standard Library only (no external dependencies)

---
# Usage
1. When you run the program, it will ask to Enter a binary number.
2. the program verifies the input is binary (only 0 and 1).
3. The binary number is padded with _ characters (to simulate blanks on the tape)
4. output is the incremented binary number.

---
##  Running the code 

1. You can run the code using any C++ compiler (C++11 or above)

2. Input the binary number:
   
   bash
   Enter a binary number: 101.

3. Output the binary number after increment ,and the result for 10 tests.

   bash
   Result after increment: 110

   [PASS] 0 -> 1
   [PASS] 1 -> 10
   [PASS] 10 -> 11
   [PASS] 11 -> 100
   [PASS] 100 -> 101
   [PASS] 101 -> 110
   [PASS] 1111 -> 10000
   [PASS] 000 -> 001
   [PASS] 1001 -> 1010
   [PASS] 11111111 -> 100000000

   10/10 test cases passed.


<p align="center"><img src="CNF_output1.png"/></p>


---

##  Getting Started

### Infrastructure Setup and Installation

1. Clone the source code using Git:
   bash
   git clone https://github.com/ShoroukELSayed/automata_practical_exam_4486

---
