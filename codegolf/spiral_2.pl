#!/usr/bin/env perl
use warnings;
use strict;

my ($n) = @ARGV;
die "usage: <n>\n" unless @ARGV;

my %hash = (
	"|" => 0,
	"/" => 0,
	"\\" => 0,
	"_" => 0
); 

my @set = ("/", "\\", "/", "\\");
my $dec = $n;
my @str = ("","");
my $spirals = 1;
my $string = "";
my $switch = 0;
my $cen = 1; # marks place of | | | 
my $pos = $cen;
while($n > 0) {
	for (my $i = 0; $i < @set; $i++) {
		print "$n\n";
		if ($switch == 0) {
			$str[$cen] = "| $str[$cen]";
			$n--;
			while($pos >= 0) {
				$str[$pos] = "$set[$i] $str[$pos]";
				$pos--;
				$n--;
			}
			unshift (@str, "_"x(2*$spirals-1));
			$n-=(1+2*$spirals);
			$switch++;
			$cen++;
			$pos=1;
		}
		elsif ($switch == 1) {
			$str[$cen] = "$str[$cen] |";
			$n--;
			while($pos < @str) {
				$str[$pos] = "$str[$pos] $set[$i]";	
				$pos++;
				$n--;
			}
			push(@str, "\\" . "_"x(1+2*$spirals) . "/");
			$n-=(2+1+2*$spirals);
			$switch--;
			$pos = $cen - 1;
		}
	}
}

$string = join("\n", @str);
print $string;
