#!/usr/bin/env perl
use warnings;
use strict;

my ($input) = @ARGV;

my @matrix = split(/,/, $input);

for (my $i = 0; $i < @matrix; $i++) {
	# in a string of roman numerals
	# how many valid sets of 3 can we extract from it?
	# network flows? 
	#
	my (@nums) = $matrix[$i] =~ /(I{0,1}[IVX]{0,1}I{0-3}){3}/g;	
}
