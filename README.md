# defeng

defeng is a wordlist generator that generates words that "looks like English words".

## Installation
As of right now, there is no installer, so you can simply compile it:
```
make
```
and add the generated `bin/defeng` to a directory included in the PATH variable.

## Usage
```
Usage: defeng -c [consonant_former_cluster file] -C [consonant_latter_cluster file] -v [vowel_cluster file] [other options]
Other options:
        -o file         Output to file
        -m length       Set minimum number of spaces. (Default: 2)
        -M length       Set minimum number of spaces. (Default: 3)
```
Here is an example you could try (Note that c_{former,latter}.txt and v.txt are provided in the `data` directory):
```
./bin/defenc -c data/c_former.txt -C data/c_latter.txt -v data/v.txt -m 3 -M 4 -o wordlist.txt
```
(You can find `austria` in this wordlist.txt.)

## How it works
defeng works by generating words of the following syntax
```
* cv(C)cv(C)...
* v(C)cv(C)cv(C)...
```
where `c` refers to a "former consonant cluster", `v` refers to a vowel or a diphthong, and `(C)` refers to optional "latter consonalt cluster".

By default, consonant clusters include, but not limited to
* b, c, ...
* ch, sh, sch, ...
* bl, sl, sk, ...

## Note
Note that you do not have to set the length to be more than 5 is most cases!
For example, the word `strength` will require only four spaces with this generator. (str-e-ng-th)

## Outlook
If I keep developing this, here are a few small things I aim to do in the upcoming future.
* More realistic word generation \[Done!\]
    * It turns out that words like astrsch (3-space word) is not likely a word that people would have invented.
    * I can try to split up consonants and vowels into "former" and "latter".
* Size of the file computation.
    * Not only the number of words, but also the overall size of the file generated.


## Conception
The idea behind this was that, many words have limited number of consonants or vowels in a row.
This fact applies in some languages as well, such as French, Spanish, Korean, etc.

By only outputting words that are more "word-like", one could greatly reduce the search space for penetration testing.

For analysis of this conjecture, one may look more into asymptotic equipartition property (AEP), I guess?

