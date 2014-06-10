# dwmstaplus

A small, easily extensible and efficient (as is yet to be proven)
[dwm](dwm.suckless.org) status bar information provider.

# Installation

The usual

````
make
make install
````

should suffice.

## Configuration

Edit `config.h` and adjust the `typedef` `InfoModules` to your
requirements.

Currently there are the following `InfoSource`s:

- `BatteryInfo`
- `LoadInfo`
- `TimeInfo`

# Extending

See the existing `InfoSource`s. Basically, you have to:

1. create an new class/struct, which implements `InfoSource`
2. override the `get()` method to provide the information your
   source is supposed to provid
3. insert it into the `InfoSource` chain in `config.h`

# Authors

Sven Schober <sschober@sssm.de>

# License

````
Copyright (c) 2013, Sven Schober
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
````
