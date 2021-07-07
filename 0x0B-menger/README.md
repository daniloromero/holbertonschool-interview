# 0x0B. Menger sponge


Function that draws a 2D Menger Sponge

    Prototype: void menger(int level);
    Where level is the level of the Menger Sponge to draw
    If level is lower than 0, your function must do nothing

see 3D example of [merger sponge](https://youtu.be/d-dI_pu_Z0g "Inside a Menger sponge level 14")

see 3D example of [merger sponge][https://youtu.be/d-dI_pu_Z0g]


Compile
```
 gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

Execute
```
prompt@~/0x0B-menger$ ./0-menger 0
#
prompt@~/0x0B-menger$ ./0-menger 1
###
# #
###
propmt@~/0x0B-menger$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

