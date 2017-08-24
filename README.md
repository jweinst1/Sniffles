# Sniffles

A Reactive C++ String Object

Sniffles is a small C++ string class that implements a string via a nodular interface rather than an underlying array of chars.

## Usage

Included in src are one `cpp` file and two `.h` header files.

### Advantages

Using a nodular string class allows the string to change size and insert or remove elements much faster than array based strings. You cna also change individual chars much faster.

### Building

run `make all` to build the object file in the `/lib` dir.