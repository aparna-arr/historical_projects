#!/usr/bin/env perl
use warnings;
use strict;
use Curses;
use Term::ReadKey;
use Time::HiRes qw(sleep); # best method of controlling automatic moving

initscr();
my @termsize = GetTerminalSize;
my $maxx = $termsize[0]-1;
my $maxy = $termsize[1];
my $key;
addstr(0,0, "Press q to quit\n");

my @pos;
$pos[0] = 5;
$pos[1] = 5;
addstr($pos[0], $pos[1], "@"); 
refresh;

while(1) {
  while (!defined($key = ReadKey(-1))) {
  sleep (0.5) ; # sleep for half a second = framerate
    move_char();
  }
  addstr(1,0, $key);
  refresh;
  if ($key eq "q") {
    last;
  }
}
endwin();

sub move_char {
  addstr($pos[0], $pos[1], " "); 
  if ($pos[1] + 1 < $maxx) {
    $pos[1]++;
  }
  else {
    $pos[1]--;
  }
  if ($pos[0] + 2 < $maxy ) {
    $pos[0]+=2;
  }
  else {
    $pos[0]-=2;
  }
  addstr($pos[0], $pos[1], "@"); 
  refresh;   
}
