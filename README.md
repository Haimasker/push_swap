<h1 align="center">
	push_swap
</h1>

<p align="center">
	This project was made in accordance with the project of School 21 (Ecole 42).
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/haimasker/push_swap?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/haimasker/push_swap?color=blue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/haimasker/push_swap?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/haimasker/push_swap?color=blue" />
</p>

<h3 align="center">
	<a href="#preamble">Preamble</a>
	<span> · </span>
  <a href="#description">Description</a>
	<span> · </span>
	<a href="#installation">Installation and usage</a>
	<span> · </span>
	<a href="#testing">Testing</a>
</h3>

---

<a name="preamble"></a>
## Preamble

The purpose of this project is to code algorithm for sorting list of integers using two stacks. <br>

``push_swap`` should sort in ascending order numbers into stack and display a sequence <br>
of instructions that can sort given stack.

You can see the subject here: [push_swap](en.subject.pdf).

Main requirements, rules and code style: [Norm](en_norm.pdf).

---

<a name="description"></a>
## Description

### Mandatory part

* At start of the programm there are two stacks named ``a`` and ``b``. <br>

* The stack ``a`` contains a random amount of integers which cannot be duplicated. <br>

* The stack ``b`` is empty.

Allowed operations with stacks are:

1. ``sa`` : swap a - swap the first 2 elements at the top of stack a. <br>
Do nothing if there is only one or no elements.

2. ``sb`` : swap b - swap the first 2 elements at the top of stack b. <br>
Do nothing if there is only one or no elements.

3. ``ss`` : ``sa`` and ``sb`` at the same time.

4. ``pa`` : push a - take the first element at the top of b and put it at the top of a. <br>
Do nothing if b is empty.

5. ``pb`` : push b - take the first element at the top of a and put it at the top of b. <br>
Do nothing if a is empty.

6. ``ra`` : rotate a - shift up all elements of stack a by 1. <br>
The first element becomes the last one.

7. ``rb`` : rotate b - shift up all elements of stack b by 1. <br>
The first element becomes the last one.

8. ``rr`` : ``ra`` and ``rb`` at the same time.

9. ``rra`` : reverse rotate a - shift down all elements of stack a by 1. <br>
The last element becomes the first one.

10. ``rrb`` : reverse rotate b - shift down all elements of stack b by 1. <br> 
The last element becomes the first one.

11. ``rrr`` : ``rra`` and ``rrb`` at the same time.

* At evaluation final grade depends on amount of instructions to sort the stack.

### Bonus part

* In this section we should code a ``checker`` for ``push_swap``.

* ``checker`` receives as arguments given stack ``a``. <br>
It will then wait and read instructions on the standard input.
If after executing those instructions, stack ``a`` is actually sorted <br>
and ``b`` is empty, then checker must display "OK\n" on the standard output. <br>
In every other case, checker must display "KO\n" on the standard output.

---

<a name="installation"></a>
## Installation and usage

Makefile compiles given functions into ``push_swap`` or ``checker`` executable file.

Compiler: `gcc`

Flags: `-Wall` `-Werror` `-Wextra`

<br>

* Go to the project folder:

```shell
$ cd 'path_to_push_swap'
```
* Then typo one of these command:

| Command         | Description                            |
| --------------- | -------------------------------------- |
| ``make``        | compiling mandatory part               |
| ``make bonus``  | compiling bonus part                   |
| ``make clean``  | clearing all .o files                  |
| ``make fclean`` | clearing all .o files and executables  |

* Example of executing ``push_swap`` :

```shell
./push_swap 3 5 2 7 9
```

* Example of executing ``checker`` with instructions received from ``push_swap`` :

```shell
ARG="3 5 2 7 9"; ./push_swap $ARG | ./checker $ARG
```
---

<a name="testing"></a>
## Testing

* You can check code norm due to [norminette](https://github.com/42School/norminette).

* Following checkers should be executed in way like ``checker`` in this project:
  * [Linux checker](checker_linux)
  * [MacOS checker](checker_Mac)

* [push_swap_tester](https://github.com/SimonCROS/push_swap_tester)
