use strict;
use warnings;

use PDL::Core::Dev;
use ExtUtils::MakeMaker;
use Carp;
PDL::Core::Dev->import();

#our $VERSION = "0.0094"; # Func/Makefile.PL relies on this!

my $levmarsrc = "./levmar-2.5";
my $lmpackage = ["levmar.pd", 'Levmar', 'PDL::Fit::Levmar'];

my %hash = pdlpp_stdargs($lmpackage);

#$hash{VERSION}  = $VERSION;
$hash{VERSION_FROM} = 'levmar.pd';
$hash{INC} .= " -I$levmarsrc";

# I spent a few hours trying to figure out how to automatically
# determine how to link lapack and blas. But I had no luck.

$hash{DEFINE} = " -DHAVE_LAPACK ";

$hash{LIBS}  = $^O =~ /MSWin32/i ? 
    [ ' -L.. -lm  -llapack -lrefblas -LC:/strawberry/c/lib/gcc/x86_64-w64-mingw32/4.6.3/ -lgfortran ']  :
    [ ' -L/usr/lib/lapack -lm  -llapack -lblas '];

# These are some other possibilities, eg if f2c (f77) was used to compile lapack
#' -lm  -llapack -lblas -lf2c ',
#	       ' -lm  -llapack -lblas -lF77 ', ' -lm  -llapack -lblas -lI77 ',
#	       ' -llapack -lcblas -lf77blas -latlas -lf2c ',
#               ' -llapack -lblas -latlas -lg2c  ' ];

$hash{DIR} = [ 'Func' ];

foreach my $f (qw( lm Axb misc lmlec lmbc lmblec lmbleic ) ){
    $hash{OBJECT} .= " $levmarsrc/$f\$(OBJ_EXT) ";
}

$hash{clean} = {FILES => $hash{clean}->{FILES} . " " . $hash{OBJECT} .
		" *.o *.so  Levmar.html tempcode/* " };

$hash{OPTIMIZE} = " -O3 --unroll-loops ";  # from levmar src Makefile
#$hash{OPTIMIZE} = " -O2  ";

$hash{PREREQ_PM} = { 
    'PDL' => 0,
};

$hash{CONFIGURE_REQUIRES} = { 'PDL' => 0 , 'ExtUtils::MakeMaker' => 0 };

$hash{BUILD_REQUIRES} = {
        'PDL'            => 0,
        'ExtUtils::MakeMaker' => 0
};

{
# This should be done more elegantly
    my $s =  $levmarsrc;

sub MY::postamble {
"

$s/lm\$(OBJ_EXT): $s/lm.c $s/lm_core.c $s/levmar.h $s/misc.h
$s/Axb\$(OBJ_EXT): $s/Axb.c $s/Axb_core.c $s/levmar.h $s/misc.h
$s/misc\$(OBJ_EXT): $s/misc.c $s/misc_core.c $s/levmar.h $s/misc.h
$s/lmlec\$(OBJ_EXT): $s/lmlec.c $s/lmlec_core.c $s/levmar.h $s/misc.h
$s/lmblec\$(OBJ_EXT): $s/lmblec.c $s/lmblec_core.c $s/levmar.h $s/misc.h
$s/lmbleic\$(OBJ_EXT): $s/lmbleic.c $s/lmbleic_core.c $s/levmar.h $s/misc.h
$s/lmbc\$(OBJ_EXT): $s/lmbc.c $s/lmbc_core.c $s/levmar.h $s/misc.h


Levmar.xs: pdlperlfunc\$(OBJ_EXT)

".
    pdlpp_postamble($lmpackage)
}

}

$hash{AUTHOR} = 'John Lapeyre <jlapeyre cpan.org>';
$hash{ABSTRACT} = 'Nonlinear fit and optimization routines for pdl';

WriteMakefile( %hash );

# makemaker does not use -o flag when making object
# files. So if I have a target ./dir/file.o, it
# does ./dir/file.c --> ./file.o, which is not what
# I want. This routine fixes it.
# I wonder if it will break build on another platform
package MY; # so that "SUPER" works right
sub c_o {
    my $inherited = shift->SUPER::c_o(@_);
    $inherited =~ s/\$\(DEFINE\)/\$\(DEFINE\) -o \$\*\$\(OBJ_EXT\)/g;
    $inherited;
}



