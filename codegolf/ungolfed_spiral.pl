#!/usr/bin/env perl
use warnings;
use strict;

my ($n) = @ARGV;
die "usage: <n>\n" unless @ARGV;

my $numS = int($n / 10);

my @str = ("","");

#print "numS is $numS\n";

my @result = @{spiral(\@str, $numS)};

for (my $j = 0; $j < @result; $j++) {
	if ($numS-$j >= 0) {
		print "."x($numS-$j + 2) . $result[$j] . "\n";
	}
	elsif($j == $numS + 1) {
		print ".." . "$result[$j]\n";
	}	
	else {
		print "."x($j-$numS-2) . "$result[$j]\n";
	}
}

sub spiral {
	my @str = @{$_[0]};
	my $num = $_[1];
	
	if ($num == 0) {
		return(\@str);
	}

	@str = @{spiral(\@str, $num-1)};

#	print "[$numS], str: " . scalar(@str) . " num is [$num]\n";
	for (my $i = 0; $i < @str; $i++) {
#		print "loop $i\n";
		if ($str[$i] ne "") {
			$str[$i] .= ".";
		}

		if ($i < ($num)) {
			$str[$i] = "/." . $str[$i] . "\\";	
		}
		elsif($i == ($num)) {
			$str[$i] = "|." . $str[$i] . "|";
		}
		else {
			$str[$i] = "\\." . $str[$i] . "/";	
		}
	}
	push(@str, "\\" . "_"x(1+2*$num) . "/");
	unshift(@str, "-"x(2*$num-1));
	return(\@str);

}


#...- 1
#../.\ 2
#..|.| 2 
#\___/ 5
#5+5
#10


#....--- 3 
#.../.-.\ 3
#.././.\.\ 4
#..|.|.|.| 4
#\.\___/./ 7
#.\_____/ 7
#14+14
#28

#.....----- 5
#..../.---.\ 5
#..././.-.\.\ 5
#../././.\.\.\ 6
#..|.|.|.|.|.| 6
#\.\.\___/././ 9
#.\.\_____/./ 9
#..\_______/ 9
#15+27+12
#27+27
#54
