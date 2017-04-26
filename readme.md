# RADEC
This program was developed in several days to meet the following problem specification:

Develop a boolean logic simulator that will take two input files and create wire traces of the input and output wires (as specified in the files). Specifically, one file will detail the circuit (called the “circuit file”), while one will detail how each input wire changes as time goes by (called the “vector file”).

There are several caveats: there is no error handling for badly written Circuit/Vector files, and
there are only seven gates to choose from (NOT, OR, AND, NOR, NAND, XOR, XNOR).

The file structure is detailed below.

## CIRCUIT FILE
The circuit file will follow the format below:

CIRCUIT HEADER  
INPUT PAD DEFINITIONS  
OUTPUT PAD DEFINITIONS  
GATE DEFINITIONS

The CIRCUIT HEADER simply contains the keyword "CIRCUIT" followed by a circuit name.
This name is simply for user reference, as the program discards this line.

The INPUT PAD DEFINITIONS consist of the keyword "INPUT" followed by a name for the input and
a wire number to associate this input with.

The OUTPUT PAD DEFINITIONS are identical to INPUT PAD DEFINITIONS, except "INPUT" is replaced
with "OUTPUT."

The GATE DEFINITIONS begins with the gate type (using keyword "NOT," "AND," "OR," "XOR," 
"NAND," "NOR," or "XNOR"), followed by a delay, followed by the inputs and outputs to the gate. 
It should be noted that each gate only accepts two inputs, with the exception of NOT, which only accepts
one.

An example circuit file is shown below:

	CIRCUIT ExampleCircuit
	INPUT   A    1
	INPUT   B    2
	OUTPUT  C    3
	AND     2ns  1   2   3

## VECTOR FILE
The vector file will follow the format below:

VECTOR HEADER  
INPUT PAD VALUE DEFINITIONS

The VECTOR HEADER simply contains the keyword "VECTOR" and a name for the vector. Similar to 
the circuit header, this line is purely for user reference. The program does not use it.

The INPUT PAD VALUE DEFINITIONS consist of the keyword "INPUT" followed by the name of an existing input, 
a time at which the specified input's value will change, and the value that the input will change to.

An example vector file is shown below:

	VECTOR SimpleCircuit
	INPUT A  0  0
	INPUT B  0  0
	INPUT A  4  1
	INPUT B  5  1
