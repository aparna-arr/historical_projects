#!/usr/bin/env perl
use warnings;
use strict;

my ($n) = @ARGV;
die "usage: <n>\n" unless @ARGV;

my $numS = int($n / 10);

my @str = ("","");
my @set = (" ", "|", "/", "_", "\\", "|");

my @result = @{spiral(\@str, $numS+1)};

my $diff = $n - $numS*10; 

##my $sum = 0;
##my @set = ("/", "_", "\\", "|", "_", "/", "_", "\\"); 
##for (my $k = 0; $k <= $diff; $k++) {
##	if ($diff > ($sum = $numS+1)) { # left top diags
##		if ($diff > ($sum += 2*$numS)) { # top _'s
##			if ($diff > ($sum += $numS+1)) { # right top diags
##				if ($diff > ($sum += 2*$numS + 1)) { # right bottom diags
##					if ($diff > ($sum += 2*$numS)) { # bottom _'s
##						# last left bottom diags
##					}
##				}	
##			}
##		}
##	}	
##}



for (my $j = 0; $j < @result; $j++) {
	if ($numS-$j >= 0) {
		print ""x($numS-$j + 2) . $result[$j] . "\n";
	}
	elsif($j == $numS + 1) {
		print " " . "$result[$j]\n";
	}	
	else {
		print ""x($j-$numS-2) . "$result[$j]\n";
	}
}

sub spiral {
	my @str = @{$_[0]};
	my $num = $_[1];
	
	if ($num == 0) {
		return(\@str);
	}

	@str = @{spiral(\@str, $num-1)};

	if ($num == $numS + 1) {
		# find out what to set to " "
#		if ($diff < 2*$num+1 + $num + 1 + $num + 2*$num-1 + $num + 1) {
#my @set = (" ", "|", "/", "_", "\\", "|");

		if ($diff > 1+$num) {
			if ($diff > 1+$num+2*$num-1) {
				
			}
			else {
				$set[]
			}
		}
		else {
			$set[3] = $set[4] = $set[5] = $set[0];
		}	
	}


	for (my $i = 0; $i < @str; $i++) {
		if ($str[$i] ne "") {
			$str[$i] .= $set[0];
		}

		if ($i < ($num)) {
			$str[$i] = "$set[2] " . $str[$i] . "$set[4]";	
		}
		elsif($i == ($num)) {
			$str[$i] = "$set[1] " . $str[$i] . "$set[5]";
		}
		else {
			$str[$i] = "$set[4] " . $str[$i] . "$set[2]";	
		}
	}
	push(@str, "$set[4]" . "_"x(1+2*$num) . "$set[2]");
	unshift(@str, "$set[3]"x(2*$num-1));
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
