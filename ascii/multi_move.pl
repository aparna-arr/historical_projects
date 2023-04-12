#!/usr/bin/env perl
use warnings ;
use strict;
use Curses;
use Term::ReadKey;
use Time::HiRes qw(sleep);

initscr();

my @termsize = GetTerminalSize;
my $maxx = $termsize[0] - 1;
my $maxy = $termsize[1];
my $key;
addstr(0,0, "Press q to quit"); #first arg is y, 2nd is x

my %pos;

$pos{"@"}[0] = 5;
$pos{"@"}[1] = 5;
 
$pos{"#"}[0] = 10;
$pos{"#"}[1] = 5;

foreach my $char (keys %pos) {
  addstr($pos{$char}[0], $pos{$char}[1], $char);
}
refresh;
while(1) {
  while (!defined($key = ReadKey(-1))) {
    sleep (0.5);
    move_all();
  }
  
  if ($key eq "q") {
    last ;
  }
}
endwin();

sub move_all {
  foreach my $char (keys %pos) {
    addstr($pos{$char}[0], $pos{$char}[1], " ");
    if ($pos{$char}[1] + 1 < $maxx && $pos{$char}[1] > 0) {
      if (rand(1) < 0.5) {
        $pos{$char}[1]++;
      }
      else {
        $pos{$char}[1]--;
      }
    }
    elsif ($pos{$char}[0] < $maxy && $pos{$char}[0] > 0) {
      if (rand(1) < 0.5) {
        $pos{$char}[0]++;
      }
      else {
        $pos{$char}[0]--;
      }
    }
    else {
      if ($pos{$char}[0] <= 0) {
        $pos{$char}[0]+=10;
      }
      elsif ($pos{$char}[1] <= 0) {
        $pos{$char}[1]+=10;
      }
      $pos{$char}[0]-=10;
      $pos{$char}[1]-=10;
    }
    addstr($pos{$char}[0], $pos{$char}[1], $char);
  }
  refresh;
}
