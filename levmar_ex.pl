#!/usr/bin/perl -w

use PDL;
use PDL::Fit::Levmar;
#use PDL::Fit::Levmar::Func;

$p = pdl(-1.2,1);
$x = pdl(0,0);
$t = pdl(0,0);



$st = '

function mros
    double ROSD=105.0;
    loop
    x[i]=((1.0-p[0])*(1.0-p[0]) + ROSD*(p[1]-p[0]*p[0])*(p[1]-p[0]*p[0]));
end function

jacobian jacmros
    double ROSD=105.0;
    loop
    d1=(-2 + 2*p[0]-4*ROSD*(p[1]-p[0]*p[0])*p[0]);
    d2=(2*ROSD*(p[1]-p[0]*p[0]));
end jacobian

';

#$h = levmar($p,$x,$t, FUNC => $st, MAXITS => 10000, NOCLEAN => 1);
$h = levmar($p,$x,$t, CSRC => 'ros.c', MAXITS => 10000);
print $h->{REPORT};

#$h = levmar( GETOPTS => 1);
#print %$h;




