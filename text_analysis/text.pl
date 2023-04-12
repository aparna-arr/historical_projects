#!/usr/bin/env perl
use warnings;
use strict;

# Input: file with plaintext
# Output: LaTeX file w/ highlighting, statistics in tsv file

main();

sub main {
	my ($input) = @ARGV;
	die "usage: <input text file>\n" unless @ARGV == 1;

	my @rawtext = %{readInput($input)};	
	
}

sub readInput {
	my $file = $_[0];
	my @text;

	open (IN, "<", $file) or die "could not open $file\n";

	while(<IN>) {
		my $line = $_;
		chomp $line;

		my @sentances = split(/\./, $line);
		my $size = @sentances;

		foreach my $sentance (@sentances) {
			my @words_ar = split(/\s+/, $sentance);
			foreach my $word (@words_ar) {

			}
		}
	}


}
