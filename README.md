# Brainfuck Extended

## What is this about?

it has all the usual Brainfuck stuff, and some other stuff that helps the brainfuck program interact with the rest of the system.

if you don't already know what brain fuck is, here are a few resources:

  https://en.wikipedia.org/wiki/Brainfuck
  
  https://esolangs.org/wiki/Brainfuck

if you want to use this as a normal Brainfuck interpreter it will do the job, but there are also a few other neat features.

## terminlology

* data segment - a one dimensional array manipulated by a Brainfuck program
* data pointer - a pointer to the currently in use data segment cell
* stack segment - a deticated array to keep track of loop start addresses
* C string - the standard way to format a string in the C programming language

## Features

currently there are 2 new features, both are added in as keywords/operators

these features take in use the data segment to a large extent.
as they will require you to create a valid C string for the command, and then the data pointer, which will be assumed to be the start of the string, will be passed to the command

### `?` - command line call:

command line call, invokes a command processor to execute a command given in the format of a C string.

the command must be mapped out on the data segment in the format of a C string, meaning the string starts at the string pointer address and ends at the 0 termnation character.
the pointer address for the string will be the same as the data pointer.

### `%` - run shared Brainfuck Extended file:

run shared Brainfuck Extended file, run a Brainfuck Extended file, but both files share the same data segment. to execute a file, a path in the format of a C string must be supplied.

the path similarly command line call has to be mapped out on the data segment first and then the data pointer moved to the start of the string.

## example files:

* the file named `file.txt`

## how to compile?

it's a single C file i think you can figure it out

## how to run it?

like a command line command, `./BrainFuckExt.exe file.txt`

isn't exactly rocket science

please report any issues concerning typos to nobody
