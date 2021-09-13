# pwC

pwC is a very simple key/password generator written in C.
<br>
The goal? Provide a super fast and lightweight password generator embedded in a linux system.
<br>
How? A prepared set of dictionaries and a bit of randomness.
<br>

## Installation

```bash
git clone https://github.com/synth3sis/pwC
cd pwC
make
cp pwC /usr/local/sbin/
```

<br>

## Examples
Print help:
```bash
user@linux:~/pwC# pwC -h
Usage:
       ./pwC [length] [num of key]

Options:
       --human, -H    produces keys using only letters and numbers
       --help, -h     print this help message and exit
```

<br>

Print a single key, 16 chars long (default):

```bash
user@linux:~/pwC# pwC
etg!tSwc#lG42eaG
```

<br>

Print five keys, 12 chars long:

```bash
user@linux:~/pwC# pwC 12 5
ggXet5$9wC?E
68B$ltESIhu?
K9oAMI.iDg&s
$Fsw7jwa+31A
ptr#AjnkR#TX
```
<br>

Print 3 keys, 22 chars long, human readable (no special chars)

```bash
user@linux:~/pwC# pwC 22 3 -H
jxMvWKlYHmPj7r6revO1Bh
Jv5jWsDdMhY2gyBs5AdKxc
ZAICVT5PsWVE83lBocXL8q
```
