/***************************************************************************
 * The PERPETRATOR hereby grants you (the VICTIM) explicit permission to use
 * this bomb (the BOMB).  This is a time limited license, which expires on the
 * death of the VICTIM.  The PERPETRATOR takes no responsibility for damage,
 * frustration, insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or
 * other harm to the VICTIM.  Unless the PERPETRATOR wants to take credit, that
 * is.  The VICTIM may not distribute this bomb source code to any enemies of
 * the PERPETRATOR.  No VICTIM may debug, reverse-engineer, run "strings" on,
 * decompile, decrypt, or use any other technique to gain knowledge of and
 * defuse the BOMB.  BOMB proof clothing may not be worn when handling this
 * program.  The PERPETRATOR will not apologize for the PERPETRATOR's poor
 * sense of humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will all blow up in a
 * spectaculary fiendish explosion.  ***giggles*** 
 */


FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Note to self: remember to port this bomb to Windows and put a 
     * fantastic GUI on it. */

    /* When run with no arguments, the bomb reads its input lines 
     * from standard input. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* When run with one argument <file>, the bomb reads from <file> 
     * until EOF, and then switches to standard input. Thus, as you 
     * defuse each phase, you can add its defusing string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* You can't call the bomb with more than 1 command line argument. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
    initialize_bomb();

    welcome_message(argc);

    /* Hpmh, some students ... I bet they can be stopped with a single letter */
    input = read_line();             /* Get input                   */
    phase_1(input);                  /* Run the phase               */
    phase_defused();                 /* Drat!  They figured it out!
				      * Let me know how they did it. */
    printf("Phase 1 defused. And they said you'd never amount to anything. \n");

    /* Looks like we got a smart one.  
     * In that *case*, time to *switch* it up a little! */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Why so serious?\n");

    /* Looks like we'll need to test them on some more complex sequences */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Now that was beautiful! Halfway there!\n");

    /* Round and 'round in memory we go, where we stop, the bomb blows! */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("Four stages complete? And they said I was the mad one!\n");

    /* Oh yeah?  I bet they couldn't even pass middle-school algebra...  */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Alright good work, you'll like this last one!\n");

    /* Ha knowledge doesn't grow on trees.  I've put landmines everywhere to
     * blow them up for good. */
    input = read_line();
    phase_6(input);
    phase_defused();

    printf("Now that, was beautiful!\n");
    /* Hehe, they think they solved it... no one will find my s3crets!
     * they want hints? like i'm going to make a /bomblab-secrets/ webpage... */

    return 0;
}