#!/usr/bin/env perl
use warnings;
use strict;
use TERM::ReadKey;

my $key = '';
while (1) {
	$key = ReadKey(-1);
	if ($key) {
		if ($key == "q") {
			break;
		}
		print $key;	
	}

}
