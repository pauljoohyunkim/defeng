# defeng

defeng is a wordlist generator that generates words that "looks like English words".

```
Usage: defeng -c [consonant_cluster file] -v [vowel_cluster file] [other options]
Other options:
        -o file         Output to file
        -m length       Set minimum number of spaces. (Default: 2)
        -M length       Set minimum number of spaces. (Default: 3)
```

## How it works
defeng works by generating words of the following syntax
```
(v)cv(c)cv(c)...
```
where `c` refers to a "consonant cluster", `v` refers to a vowel or a diphthong, and (?) refers to optional space.

By default, consonant clusters include, but not limited to
* a, b, c, ...
* ch, sh, sch, ...
* bl, sl, sk, ...

## Note
Note that you do not have to set the length to be more than 5 is most cases!
For example, the word `strength` will require only four spaces with this generator. (str-e-ng-th)


