#!/usr/bin/env perl
use warnings;
use strict;
use Curses;
use Term::ReadKey;

initscr();
my @termsize = GetTerminalSize;
my $maxx = $termsize[0]-1;
my $maxy = $termsize[1];
my $key;

addstr(0,0, "The basics of controlling a screen interactively!\n");
addstr(1,0, "Type any letter, q to quit\n");
refresh();
# refresh flushes all previous addstr()'s that have not already been flushed to the screen
while (1) {
  while(!defined($key = ReadKey(-1))) {
# waiting for input  
  }
  for (my $i = 2; $i < $maxy-1; $i++) {
    addstr($i, 0, $key x $maxx);
#    refresh;
  }
  refresh;
  if ($key eq "q") {
    last;
  }
}
endwin();
