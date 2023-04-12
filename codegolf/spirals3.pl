#!/usr/bin/env perl
use warnings;
use strict;

# start at midline. Add first |
# go up until hit top, adding / 's. Add top.
# go down until hit midline, adding \ 's. Add last |
# go down until hit end, adding / 's. Add bottom.
# go up until hit midline, adding / 's
#
# # of slashes per side = # spirals
# # _ on top = 2 * spirals - 1
# # _ on bottom = 2 * spirals + 1
# stop when N runs out

# add spaces at end: make sure every line is the same length

my ($n) = @ARGV;
die "usage: <n>\n" unless @ARGV;

my $switch = 1; # go up
my $cen = 1;
my @string = ("", "");
my $pos = 1;
my $spiral = 0;

while ($n > 0) {
#	print "pos is $pos n is $n\n";
	if ($pos == $cen) {
#		print "pos == cen\n";
		if ($switch == 1) {
			$string[$pos] = "| " . $string[$pos];
			$pos--;
			$spiral++;
		}
		else {
			$string[$pos] .= "| ";
			$pos++;
		}	
		$n--;
	}
	elsif ($pos < 0) {
#		print "pos == 0\n";
		if ($n >= $spiral*2-1) {
			unshift(@string, "_"x(2*$spiral-1) . " ");
			$n -= 2*$spiral-1;
			$cen++;
		}	
		else {
			unshift(@string, "_"x$n);
			$n = 0;		
		}
		$pos = 1;
		$switch = 0;
	}
	elsif ($pos == @string) {
#		print "pos == string\n";
		if ($n >= $spiral*2+1+2) {
			push(@string, "\\" . "_"x(2*$spiral+1) . "/ ");
			$n -= 2*$spiral + 1 + 2;
		}	
		else {
			push(@string, "_"x($n-1) . "/ ");
			$n = 0;
		}
		$pos--;
		$switch = 1;
	}
	elsif ($switch == 1) {
#		print "switch == 1\n";
		if ($pos != @string-2 || $pos == 0) {
#			print "\tpos != string - 2\n";
			$string[$pos] = "/ " . $string[$pos];	
		}
		else {
#			print "\tpos == string - 2\n";
			$string[$pos] = "\\ " . $string[$pos];
		}
		$pos--;
		$n--;

		if($pos == -1) {
			$switch = 0;
		}
	}
	elsif ($switch == 0) {
#		print "switch == 0\n";
#		if ($pos != 1) {
		if ($pos > $cen) {
			$string[$pos] .= "/ ";
		}
		else {
			$string[$pos] .= "\\ ";
		}
		$pos++;
		$n--;

		if ($pos == @string) {
			$switch = 1;
		}
	}	
}

my $max = 0;
for (my $j = 0; $j < @string; $j++) {
	my $tmp = $string[$j];
	($tmp) =~ s/ //g;
	if (length($tmp) > $max) {
		$max = length($tmp);
	}
}

my $diff = $spiral+1;
	for (my $i = 0; $i < @string; $i++) {
#		if ($i < $cen) {
#			$string[$i] = " "x$diff . $string[$i];
#			$diff--;
#		}
#		elsif ($i >= $cen && length($string[$i]) != $max) {
#			$string[$i] = " "x$diff . $string[$i];
#			$diff++;
#		}

	my $tmp = $string[$i];
	($tmp) =~ s/ //g;
		if (length($tmp) < $max-2) {
			$string[$i] = " "x$diff . $string[$i];
			if ($i > $spiral) {
				$diff++;
			}
			else {
				$diff--;
			}
		}
		elsif(length($tmp) != $max) {
			$string[$i] = " "x($max - length($string[$i])) . $string[$i];
			if ($i > $spiral) {
				$diff++;
			}
			else {
				$diff--;
			}
		}

	}

my $final = join("\n", @string);
print "$final\n";
