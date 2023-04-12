#!/usr/bin/env perl
use warnings;
use strict;

# The StackMice interpreter # 

# Hands #
my %LeftHand = (
	pos => -1, # at tmp
       	prev_pos => -1,
	haveMouse => false,	
);

my %RightHand = (
	pos => -1, # at tmp
       	prev_pos => -1,
	haveMouse => false,	
);

# ... this should be OO. It looks like C++

# Cages #
my @CageStack; # Array of hash of array, maintain second level of arrays as sorted.
my $StackLen = 1; # start with 1 cage
my %TmpCage; # Hash of array for tmp cage.

my $cycles = 0; # No cycles yet
my $LIFESPAN = 20; # a normal mouse lives for 20 cycles

my @Mice ; # master mouse array: for use of keeping track of lifespans

# Init # 

for (my $i = 0; $i < 4; $i++)
{
	$CageStack[0]{mice}[$i]{value} = -1; # empty cells
	$CageStack[0]{isEmpty} = true;
}

# Start with 2 mice, both of value 1
$TmpCage{isEmpty} = false;
$TmpCage{mice}[0]{value} = 1;
$TmpCage{mice}[0]{mouseIndex} = 0;

$Mice[0] = 20;

$TmpCage{mice}[1]{value} = 1;
$TmpCage{mice}[1]{mouseIndex} = 1;

$Mice[1] = 20;

$TmpCage{mice}[2]{value} = -1;
$TmpCage{mice}[3]{value} = -1;


