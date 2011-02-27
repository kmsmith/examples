#!/usr/bin/perl -Wall

opendir(DIR, $ARGV[0]);
@files = readdir(DIR);
closedir(DIR);
foreach $file (@files) {
    print "$file";
}
