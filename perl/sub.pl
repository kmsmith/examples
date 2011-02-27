#!/usr/bin/perl -Wall

sub printhello {
    print "Hello";
}

sub printargs {
    print "@_";
}


# subroutines can return lists
sub minmax {
    my $a = shift(@_);
    my $b = shift(@_);
    if ($a < $b) { return ($a, $b);}
    else { return ($b, $a);}
}


#functions are first class objects
sub invoke {
    local $func = shift(@_);
    &$func(@_);
}

printargs("one", "two");

print minmax(2, 1);

invoke(\&printhello);
invoke(\&printargs, "one", "two");
