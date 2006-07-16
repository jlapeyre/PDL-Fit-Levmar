use Data::Dumper;
use PDL::Core::Dev;
use ExtUtils::MakeMaker;
PDL::Core::Dev->import();

$fpackage = ["func.pd", Func, PDL::Fit::Levmar::Func];
%hash = pdlpp_stdargs($fpackage);

$hash{VERSION_FROM}  = '../Makefile.PL';
$hash{LIBS} = [' -lm  -ldl '];
#$hash{OBJECT} .= '  getsymbol$(OBJ_EXT) pdlperlfunc$(OBJ_EXT) ';
$hash{OBJECT} .= '  getsymbol$(OBJ_EXT)  ';
$hash{clean} = {FILES => $hash{clean}->{FILES} . " " . $hash{OBJECT} .
		" *.o *.so  Func.html " };
#$hash{OPTIMIZE} = " -O2 ";
$hash{PM} = {
                    'Func.pm' => '$(INST_LIBDIR)/Func.pm'
              };	


#print "Func hash \n";
#print Dumper(\%hash);
#print pdlpp_postamble($fpackage);
WriteMakefile( %hash );

sub MY::postamble {
 '
# Func.xs: pdlperlfunc$(OBJ_EXT)

' .
  pdlpp_postamble($fpackage)};
