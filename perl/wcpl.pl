#!/usr/bin/perl -Wall

$line_count = 0;
$word_count = 0;
open(INPUT, $ARGV[0]) || die "Could not open input file ", $ARGV[0];
while ($record = <INPUT>) {
    $line_count++;
    @words = split(" ", $record);
    $word_count += scalar(@words);
}
close (INPUT);

print "Line Count:  ", $line_count;
print "Word Count:  ", $word_count;
