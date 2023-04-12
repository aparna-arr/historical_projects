#!/usr/bin/env perl
use warnings;
use strict;
use Curses;
use Term::ReadKey;
use Time::HiRes qw(sleep);

initscr();

my @termsize = GetTerminalSize;
my $maxx = $termsize[0] - 1;
my $maxy = $termsize[1];
my $key;

addstr(0,0, "Press q to quit");

my %rat;

$rat{speed} = 0.5;
$rat{health} = 1;
$rat{pos}[0] = 5;
$rat{pos}[1] = 5;

#symmetrical square
#addstr(1,0, "#"x18);
#addstr(11,0, "#"x18);
#for (my $i = 2; $i < 11; $i++) {
#  addstr($i, 0, "#");
#  addstr($i, 17, "#");
#}

#good sized symmetrical square
addstr(1,0, "#"x35);
addstr(20,0, "#"x35);
for (my $i = 2; $i < 20; $i++) {
  addstr($i, 0, "#");
  addstr($i, 34, "#");
}
addstr($rat{pos}[0], $rat{pos}[1], "@"); #adding the rat
refresh;

my %box; #defines movable boundaries
$box{y}[0] = 2;
$box{y}[1] = 19;
$box{x}[0] = 2;
$box{x}[1] = 33; 

while(1) {
  while (!defined($key = ReadKey(-1))) {
    move_rat();
    refresh;
  }

  if ($key eq "q") {
    last;
  }

}

endwin();

sub move_rat {
  sleep($rat{speed});
  addstr($rat{pos}[0], $rat{pos}[1], " ");
  my $rand = rand(1);
  
  if ($rand < 0.5) {
    # x direction movement
    if ($rand < 0.25) {
      $rat{pos}[1]++;
    } 
    else {
      $rat{pos}[1]--;
    }
  }
  else {
    # y direction movement
    if ($rand > 0.75) {
      $rat{pos}[0]++;
    } 
    else {
      $rat{pos}[0]--;
    }
  }  

  if ($rat{pos}[0] <= $box{y}[0]) {
    $rat{pos}[0]+=2;
  }
  elsif ($rat{pos}[0] >= $box{y}[1]) {
    $rat{pos}[0]-=2;
  }

  if ($rat{pos}[1] <= $box{x}[0]) {
    $rat{pos}[1]+=2;
  }
  elsif ($rat{pos}[1] >= $box{x}[1]) {
    $rat{pos}[1]-=2;
  }

  addstr($rat{pos}[0], $rat{pos}[1], "@");
}
