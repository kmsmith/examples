#!/usr/bin/perl

for (1..100) {
    my $fizz = ($_ % 3) ? "" : "Fizz";
    my $buzz = ($_ % 5) ? "" : "Buzz";
    print ((($fizz ne "" or $buzz ne "") ? "$fizz$buzz" : $_) . "\n");
}
