# diaper-bag-dash
A text-based adventure game where the protagonist endures the struggles of parents with young children trying to get out of the house on time. 

## Synopsis
You are the loving, caring parent to two wonderful children under the age of 3. 

What a fun age! There’s story time,
playing make believe, cuddles, and giggles! Those balance out with potty training, cleaning spit-up, and changing diapers, but it’s totally worth it.


BUT! Today you have just realized you forgot about Teddy Bear Club AND your sitter called and is sick!


It’s 7:45 a.m. and you need to get out of the door ASAP! But your limit isn’t time … it’s *patience*.

## Objectives

You need to quickly move from room to room in your home to collect the following items before patience runs out:

* Baby clothes
* Diapers
* Rash Cream
* Lunch
* Shakey Elephant

Some items require actions before they can be collected, and your patience level will naturally slowly tick down with
each move to a new room. Look out though .. sometimes random events can occur that may add or subtract from your
patience level making the morning more or less challenging.

## Program Build
### Pre-requisites
System with GNU C/C++ compiler. Preferred method utilizes [make](https://cplusplus.com/articles/jTbCpfjN/) for build and cleanup.

### Build Steps
Via a terminal in the parent directory of the repository:
```
make 
```

_Example output_
```
g++ -std=gnu++11 -pedantic-errors -g -c main.cpp
g++ -std=gnu++11 -pedantic-errors -g -c game.cpp
g++ -std=gnu++11 -pedantic-errors -g -c space.cpp
g++ -std=gnu++11 -pedantic-errors -g -c patio.cpp
g++ -std=gnu++11 -pedantic-errors -g -c mainfloor.cpp
g++ -std=gnu++11 -pedantic-errors -g -c parentsroom.cpp
g++ -std=gnu++11 -pedantic-errors -g -c kitchen.cpp
g++ -std=gnu++11 -pedantic-errors -g -c kidsroom.cpp
g++ -std=gnu++11 -pedantic-errors -g -c finaltesting.cpp
g++ -std=gnu++11 -pedantic-errors -g -c livingroom.cpp
g++ -std=gnu++11 -pedantic-errors -g -c bathroom.cpp
g++ -std=gnu++11 -pedantic-errors -g -c helpers.cpp
g++ -std=gnu++11 -pedantic-errors -g -c player.cpp
g++ -std=gnu++11 -pedantic-errors -g -c item.cpp
g++ -std=gnu++11 -pedantic-errors -g main.o game.o space.o patio.o mainfloor.o parentsroom.o kitchen.o kidsroom.o finaltesting.o livingroom.o bathroom.o helpers.o player.o item.o -o diaperbagdash
```

### Run Steps
```
./diaperbagdash
```

If built successfully, you should see the opening screen for the game.

```
    WELCOME TO

   ######                                   ######
   #     # #   ##   #####  ###### #####     #     #   ##    ####
   #     # #  #  #  #    # #      #    #    #     #  #  #  #    #
   #     # # #    # #    # #####  #    #    ######  #    # #
   #     # # ###### #####  #      #####     #     # ###### #  ###
   #     # # #    # #      #      #   #     #     # #    # #    #
   ######  # #    # #      ###### #    #    ######  #    #  ####

                    ######
                    #     #   ##    ####  #    #
                    #     #  #  #  #      #    #
                    #     # #    #  ####  ######
                    #     # ######      # #    #
                    #     # #    # #    # #    #
                    ######  #    #  ####  #    #





[BACKGROUND]
          You are the loving, caring parent to two wonderful children under the age of 3.
          What a fun age!
Press enter...
```


### Cleanup Steps
Removes all generated *.o files and program executable.
```
make clean
```

