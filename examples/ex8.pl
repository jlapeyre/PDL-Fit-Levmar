#!/usr/bin/perl
use PDL;
use PDL::Fit::Levmar;

# Specify compiler invocation.

$n = 100;
$t = 10 * (sequence($n)/$n -1/2);
$x = 3 * exp(-$t*$t * .3  );
$p = pdl [ 1, 1 ]; # initial  parameter guesses

$h = levmar($p,$x,$t, FVERBOSE => 1,  MKOBJ => "cc -c -O3 -fPIC -o %o %c ",
                 CTOP => '#include <strings.h>',
                 FUNC => 
                '   function
                     x = p0 * exp( -t*t * p1);
           ');

print levmar_report($h);

print $h->{FUNC}->{MKOBJ} , "\n";
print $h->{FUNC}->{MKSO} , "\n";
