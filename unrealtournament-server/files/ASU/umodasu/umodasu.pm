package umodasu::umodasu;

# umod - all-purpose Unreal mod tool
#
# Copyright (C) 2000 Mishka Gorodnitzky <misaka@pobox.com>
#   and Avatar <avatar@deva.net>
#
# You may distribute this file under the terms of the Artistic License,
# as distributed with Perl.  A copy is available here:
# http://language.perl.com/misc/Artistic.html
#
# $Id: umodasu.pm,v 1.2 2004/12/01 09:53:20 thomasklausner Exp $

use umodasu::Umod;
use umodasu::Ini;
#use Archive::Zip qw(:ERROR_CODES);
use FileHandle;
use File::Find;
use Getopt::Long;
use POSIX qw(tmpnam SEEK_END);
use strict;

=pod

=head1 NAME

umod - all-purpose Unreal mod tool

=head1 SYNOPSIS

B<umod> S<[ B<-i> ]>
S<[ B<-x>I<pattern> ]>
S<[ B<-d>I<file> ]>
S<[ B<-r> ]>
S<[ B<-l> >
S<[ B<-f> ]> S<[ B<-b>I<dir> ]>
S<[ B<-v> ]>
S<[ B<-hV> ]> umod_file

B<umod>
S<[ B<-l> >
S<[ B<-c> >
S<[ B<-b>I<dir> ]>
S<[ B<-v> ]>
S<[ B<-hV> ]> product_name

=head1 DESCRIPTION

=head2 Unpack mode

B<umod> will run in unpack mode if the specified non-option argument
is an existing file.  This file will be treated as an umod file to which
unpack mode operations will be applied.

=over 4

=item B<-l> B<--list>

List contents of the umod file.  Show the product name, optionally the
localized product name in double quotes if it is different from the
generic product name, and the version number.  If the B<-v> option is
specified, show also the packed files and changes to ini files the umod
will instate when installed.

=item B<-i> B<--install>

Install the umod file into the base directory specified via the B<-b>
option or if it is not specified on the command line the base directory
setting in I<~/.umodrc> (\Windows\umod.ini for Windows users).

=item B<-x>I<pattern> S<B<--extract> I<pattern>>

Extract the files matching the specified pattern from the umod file.
Extracted files are put inside the base directory as specified via the
B<-b> option.  If the base directory is not specified, I<~/.umodrc>
(\Windows\umod.ini for Windows users) will be consulted for the
B<extractdir> setting, and if it is not found the current directory will
be used.  Multiple packed files can be specified for extraction by using
the ? and * construct in the pattern, which represents any single
character and any sequence of characters respectively.  No other glob or
regex magic character is recognized.

As a special case, if no pattern is specifed such that the umod file
follows immediately the B<-x> flag, and no further argument exists on
the command line, all the files in the specified umod file will be
dumped.

=item B<-d>I<filename> S<B<--dump> I<filename>>

Take the specified file from the umod file and dump it to the standard
output.  The filename specification is taken literally.  No glob or
regex pattern is recognized.

=item B<-r> B<--readme>

Display the readme file if such is included in the umod file.

=item B<-f> B<--force>

Overwrite existing files when doing extraction or installation.

=item B<-b>I<dir> S<B<--base> I<dir>>

Set the base directory for extraction and installation.  In the latter
case this should be set to where an Unreal game resides.

=back

=head2 Maintenance mode

B<umod> is in maintenance mode if no non-option argument is specified
on the command line or if the non-option argument does not end in
".umod", in which case said argument is taken as the name of an
installed product.

=over 4

=item B<-l> B<--list>

List all the installed products along with their version numbers and
optionally the localized product names in double quotes if they are
different from the generic names.  Use the B<-v> option to show also the
file lists, and changes made to ini files (only available for umods
installed with this installer).  If a specific product name is given on
the command line only that product is listed.  Lists also files not
belonged to any product group under the `Others' group if two B<-v>
options are given.

=item B<-c> B<--check>

Check all the installed product for integrity, or just one product if a
specific product name is given on the command line.

=item B<-b>I<dir> S<B<--base> I<dir>>

Set the base directory of the Unreal game on which the maintenance
operation is to be applied.

=back

=head2 Common options

=over 4

=item B<-v> B<--verbose>

Show more information in the output.  More than one B<-v> option can be
specified for increased verbosity.

=item B<-h> B<--help>

Display a summary of command line options.

=item B<-V> B<--version>

Display the version string of this umod program.

=back

=cut

# ----------------------------------------------------------------

my( %pref );
my( $systemDir );
my( $manifestFileName, $manifestFile );
my( @installedUmod );
my( @tmpfiles );

END {
    foreach my $tmpfile ( @tmpfiles ) {
	unlink( $tmpfile );
    }
}

sub cleanUp {
    exit( 1 );
}

$SIG{INT} = \&cleanUp;

my( $rcfile ) = "./ASU/umodasu/rc.umod";
if ($^O eq "MSWin32") { $rcfile = "$ENV{windir}/umod.ini"; }

my( $versionText ) = <<EOT;
Umod 0.5-beta16

Copyright (C) 2000 Mishka <misaka\@pobox.com> and Avatar <avatar\@deva.net>

This is free software; see the source for copying conditions. There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
EOT

my( $helpText ) = <<EOT;
Usage: $0 [OPTION]... [UMOD]

Unpack mode (UMOD specified and is an existing file) operations:
  -l, --list                list the content of the UMOD file
  -r, --readme              display the readme file, if any, in the UMOD file
  -i, --install             install the UMOD file
  -x, --extract PATTERN     extract files matching the specified PATTERM
  -d, --dump FILE           dump the specified FILE in the UMOD file

Maintenance mode (UMOD not specified or is a product name) operations:
  -l, --list                list all installed products
  -l, --list UMOD           list information about the installed product UMOD
  -c, --check               check the integrity of all installed products
  -c, --check UMOD          check the integrity of the installed product UMOD
  -u, --uninstall UMOD      uninstall the product UMOD

Output control:
  -f, --force               overwrite existing files
  -b, --base DIR            set target directory for unpack

Informative output control:
  -v, --verbose             display more information
  -V, --version             print version information and exit
  -h, --help                display this help and exit

Use `perldoc $0' for more information.
EOT

# --------------------------------
# Process options and command line args.

# Read options from the rc file.
if( open(RCFILE, "<$rcfile") ) {
    while( <RCFILE> ) {
	chomp;
	s/#.*//;
	s/^\s+//;
	s/\s+$//;
	next unless length;
	my ($var, $value) = split(/\s*=\s*/, $_, 2);
	$pref{$var} = $value
	  unless( $value eq 'no' or $value eq 'false' );

	# For backward compatibility.
	if( !defined( $value ) ) {
	    $pref{basedir} = $var;
	}
    }
    close( RCFILE );
}

my( $flagInstall, $argExtract, $argDump, $flagShowReadme,
    $flagUninstall, $flagCheck,
    $flagList,
    $argBaseDir,
    $flagVersion, $flagHelp );
my( $mode );

#Getopt::Long::Configure("no_ignore_case");
GetOptions( "install"           => \$flagInstall,
	    "uninstall"         => \$flagUninstall,
	    "check"             => \$flagCheck,
	    "extract|x=s"       => \$argExtract,
	    "dump=s"            => \$argDump,
	    "readme"            => \$flagShowReadme,
	    "list|l"            => \$flagList,
	    "force!"            => \$pref{force},
	    "base=s"            => \$argBaseDir,
	    "verbose|v+"        => \$pref{verbose},
	    "modversion"        => \$pref{modvers},
	    "version|V"         => \$flagVersion,
	    "help"              => \$flagHelp );

# Base dir specified on command line overrides that in rc file.
$pref{basedir} = $argBaseDir if( defined( $argBaseDir ) );

# Check if help was requested.
if( $flagHelp ) {
    print( $helpText );
    exit( 0 );
}

# Check if version info was requested.
if( $flagVersion ) {
    print( $versionText );
    exit( 0 );
}

# Sanity check.
if(   $flagList
    + $flagCheck
    + $flagShowReadme
    + $argDump
    + $argExtract
    + $flagInstall
    + $flagUninstall > 1 ) {
    print( STDERR "$0: option combination does not make sense\n" );
    print( STDERR $helpText );
    exit( 1 );
}

# --------------------------------
# Main logic.

# No argument given.
if( $#ARGV < 0 ) {
    my( $mode ) = "maint";

    if( $flagCheck ) {

	scanSystem();

	my( $erred );
	++$pref{verbose};
	foreach my $umodName ( @installedUmod ) {
	    $erred = 1
	      if( !checkInstalledUmod( $umodName ) );
	}
	print( "all products checked ok\n" )
	  if( !$erred );

    } elsif( $argExtract ) {

	# Command line is like -x foo.umod.
	my( $umodName ) = $argExtract;

	# Initialize the umod file object.
	my( $umodFile ) = getUmodFromFile( $umodName );
	
	# Use the base directory if given on the command line.  If
	# it is not given, uses the extractdir option in the rc file.
	# Last a last resort, extact to the current directory.
	# Do not use the saved option $pref{basedir} because extracting
	# into the real UT directory is generally not desirable for
	# extraction.
	$argBaseDir = $argBaseDir || $pref{extractdir} || '.';
	if( !-d $argBaseDir and !mkdir( $argBaseDir, 0755 ) ) {
		die( "$0: cannot make directory $argBaseDir: $!\n" );
	}

	if (defined $umodFile) {
	    $umodFile->baseDir($argBaseDir);
	    extractUmodFile($umodFile, '*');
#	} elsif ($umodName =~ /\.zip$/i) {
#	    extractPlainZipFile($umodName, '*', $argBaseDir);
	} else {
	    die "$0: cannot open or parse $umodName\n";
	}

    } elsif( $argDump ) {

	# Command line is like -d foo.umod, interpreted as "list verbosely".
	my( $umodName ) = $argDump;

	# Initialize the umod file object.
	my( $umodFile ) = getUmodFromFile( $umodName );
	
	++$pref{verbose};
	if (defined $umodFile) {
	    listUmodFile($umodFile);
#	} elsif ($umodName =~ /\.zip$/i) {
#	    listPlainZipFile($umodName);
	} else {
	    die "$0: cannot open or parse $umodName\n";
	}

    } elsif( $flagUninstall ) {

	print( STDERR
	    "$0: a product name must be supplied for uninstallation.\n" );
	print( STDERR $helpText );
	exit( 1 );

    } else { # list

	scanSystem();

	listAllInstalledUmod();
	listUnreferencedFiles() if( $pref{verbose} > 1 );

    }

}

# Loop throughs the arguments.
foreach my $umodName ( @ARGV ) {

    # Set mode depending on the nature of the current argument.
    if( -e $umodName ) {
	$mode = 'unpack';
    } elsif( $umodName =~ /\.umod$/i ) {
	print( STDERR "$0: cannot open $umodName: No such file or directory\n" );
	exit( 1 );
    } else {
	$mode = 'maint';
    }

    if( $mode eq "maint" ) {

	scanSystem();

	if( $flagCheck ) {

	    $pref{verbose} += 2;
	    checkInstalledUmod( $umodName );
	    $pref{verbose} -= 2;

	} elsif( $flagUninstall ) {

	    uninstallUmod( $umodName );

	} elsif( $flagInstall ) {

	    print( STDERR "$0: cannot install $umodName: file not found\n" );
	    exit( 1 );

	} else { # list

	    listInstalledUmod( $umodName );

	}

    } elsif( $mode eq "unpack" ) {

	# Initialize the umod file object.
	my( $umodFile ) = getUmodFromFile( $umodName );

	# Set the base directory for extracted files.
	$umodFile->baseDir( $pref{basedir} )
	  unless( !defined( $umodFile ) );

	if( $flagShowReadme ) {

	    die( "$0: cannot open or parse $umodName\n" )
	      if( !defined( $umodFile ) );
	    
	    showUmodFileReadme( $umodFile );

	} elsif( $argDump ) {

	    if (defined $umodFile) {
		dumpUmodFile($umodFile, $argDump);
#	    } elsif ($umodName =~ /\.zip$/i) {
#		dumpPlainZipFile($umodName, $argDump);
	    } else {
		die "$0: cannot open or parse $umodName\n";
	    }

	} elsif( $argExtract ) {

	    # Use the base directory if given on the command line.  If
	    # it is not given, uses the extractdir option in the rc file.
	    # Last a last resort, extact to the current directory.
	    # Do not use the saved option $pref{basedir} because extracting
	    # into the real UT directory is generally not desirable for
	    # extraction.
	    $argBaseDir = $argBaseDir || $pref{extractdir} || '.';
	    if (!-d $argBaseDir and !mkdir $argBaseDir, 0755) {
		    die "$0: cannot make directory $argBaseDir: $!\n";
	    }

	    if (defined $umodFile) {
		$umodFile->baseDir($argBaseDir);
		extractUmodFile($umodFile, $argExtract);
#	    } elsif ($umodName =~ /\.zip$/i) {
#		extractPlainZipFile($umodName, $argExtract, $argBaseDir);
	    } else {
		die "$0: cannot open or parse $umodName\n";
	    }

	} elsif( $flagInstall ) {

	    scanSystem();

	    if(defined $umodFile) {
		installUmodFile($umodFile);
#	    } elsif ($umodName =~ /\.zip$/i) {
#		installPlainZipFile($umodName);
	    } else {
		die "$0: cannot open or parse $umodName\n";
	    }

	} elsif( $flagCheck ) {

	    die( "$0: cannot open or parse $umodName\n" )
	      if( !defined( $umodFile ) );
	    
	    checkUmodFile( $umodFile );

	} elsif( $flagUninstall ) {

	    # Uninstall product defined by the umod file.
	    scanSystem();

	    if(defined $umodFile) {
		uninstallUmod($umodFile->product);
#	    } elsif ($umodName =~ /\.zip$/i) {
#		uninstallPlainZip($umodName);
	    } else {
		die "$0: cannot open or parse $umodName\n";
	    }

	} else {

	    if (defined $umodFile) {
		listUmodFile($umodFile);
#	    } elsif ($umodName =~ /\.zip$/i) {
#		listPlainZipFile($umodName);
	    } else {
		die "$0: cannot open or parse $umodName\n";
	    }

	}
    }

}

# --------------------------------
# Unpack mode functions.

# Return an Umod from the give file.  Will obtain file from zip archive
# if necessary.
sub getUmodFromFile {

    my( $filename ) = @_;

#    if( $filename =~ /\.zip$/i ) {
#
#	my( $tmpFile, $fh );
#	do { $tmpFile = tmpnam(); } until $fh = new FileHandle( $tmpFile, 'w' );
#
#	my( $zipFile ) = new Archive::#Zip;
#	if( $zipFile->read( $filename ) != AZ_OK ) {
#	    die( "$0: cannot open $filename as a zip file\n" );
#	}
#
#	my( @umodFiles ) = $zipFile->membersMatching( '.*\.umod$' );
#	return( undef ) if( !defined $umodFiles[0] );
#
#	$umodFiles[0]->extractToFileHandle( $fh );
#
#	# Make sure the tmp file gets unlinked.
#	push( @tmpfiles, $tmpFile );
#
#	$filename = $tmpFile;
#
#    }

    return( new umodasu::Umod( -file => $filename ) );

}

# Display information about the umod file.
sub listUmodFile {

    my( $umodFile ) = @_;

    my( @requirements ) = $umodFile->requirements;
    my( @packingList ) = $umodFile->packingList;
    my( @iniChanges ) = $umodFile->iniChanges;

    if( $pref{verbose} ) {
	print( "  Product: ", $umodFile->product );
	print( " \"", $umodFile->localproduct, "\"" )
	  if( $umodFile->localproduct ne $umodFile->product );
	print( " (", $umodFile->producturl, ")" )
	  if( defined( $umodFile->producturl ) );
	print( "\n" );
	print( "  Version: ", $umodFile->version );
	print( " (", $umodFile->versionurl, ")" )
	  if( defined( $umodFile->versionurl ) );
	print( "\n" );
	print( "Developer: ", $umodFile->developer );
	print( " (", $umodFile->developerurl, ")" )
	  if( defined( $umodFile->developerurl ) );
	print( "\n" );

	print( map( "  Require: $_->{product} $_->{version}\n",
		    @requirements ) )
	  if( $umodFile->requirements );

	print( "\n",
	       map( '  '.($_->{src} eq $umodFile->readmefile ?  "R" : " ")
	            ." $_->{src}"
	            .( $pref{verbose} > 1 ? " (offset $_->{start})" : '')
	            ." ($_->{size} bytes)\n",
		    @packingList ) );

	my( $prevfile, $prevsection, $prevadd );
	foreach my $change ( $umodFile->iniChanges ) {
	    if( $change->{file} ne $prevfile or $change->{add} ne $prevadd) {
		undef $prevsection;
		print( "\n" ) unless( !defined $prevfile );
		print( ($change->{add} ? '  + ' : '  = ') );
		print( "$change->{file}\n" );
		$prevfile = $change->{file};
		$prevadd = $change->{add};
	    }

	    if( $change->{section} ne $prevsection ) {
		print( "\n        [$change->{section}]\n" );
		$prevsection = $change->{section};
	    }

	    print( "        $change->{key}=$change->{value}\n" );
	}

	print( "\n" );
    } else {
	print( $umodFile->product );
	print( " \"", $umodFile->localproduct, "\"" )
	  if( $umodFile->localproduct ne $umodFile->product );
	print( " ", $umodFile->version, "\n" );
    }

}

#sub listPlainZipFile {
#    my ($zipname) = @_;
#
#    my $zipfile = new Archive::Zip;
#    $zipfile->read($zipname) == AZ_OK
#	or die "$0: cannot open $zipname as a zip file\n";
#
#    # Determine product name.
#    my $product = determineProductNameFromZipFile($zipfile, $zipname);
#
#    if ($pref{verbose}) {
#	print "  Product: $product\n\n";
#	foreach ($zipfile->memberNames()) {
##	    my $file = mungeFilename($_, $product);
#	    my $file = $_;
#	    next if (!(length $file) or ($file =~ /\/$/));
#	    print "    $file\n";
#	}
#	print "\n";
#    } else {
#	print "$product\n";
#    }
#
#    return 1;
#}
#
## Determines product name.
#sub determineProductNameFromZipFile {
#    my ($zipfile, $filename) = @_;
#
#    my $product;
#    foreach ($zipfile->memberNames()) {
#	$_ =~ s-.*[\\/]--;
#	next if (!length $_);
#
#	# Some maps come with .u files, in that case .unr takes precedence.
#	SWITCH: for ($_) {
#	    /\.unr$/i && do { $product = $`; last; };
#	    /\.u$/i && do { $product = $` if (!defined $product); last; };
#	    /\.utx$/i && do { $product = $` if (!defined $product); last; };
#	}
#    }
#    ($product) = ($filename =~ m-(.*[\\/])?(.*)\.zip-i)[1] if (!$product);
#
#    # Munge it further.
#    $product =~ s/^(DM|CTF|DOM|AS|DK)/\U$1\E/i;
#    $product =~ s/\]I\[/-3/g;
#    $product =~ s/\]\[/-2/g;
#    $product =~ s/\]//g;
#    $product =~ s/\[//g;
#    $product =~ s-/-_-g;
#    $product =~ s-\\-_-g;
#
#    return $product;
#}

# Determines the right place for a file from its extension.
sub mungeFilename {
    my ($file, $product) = @_;

    $file =~ s-.*[\\/]--;
    return undef if (!length $file);

    my ($fileEsc) = $file;
    $fileEsc =~ s/\]/\\\]/g;
    $fileEsc =~ s/\[/\\\[/g;
    SWITCH: for ($fileEsc) {
	/\.(unr)$/i && do {
	    $file =~ "$`".lc($&);
	    $file =~ s/^(DM|CTF|DOM|AS|DK)/\U$1\E/i;
	    $file = "Maps\\$file"; last; };
	/\.(utx)$/i && do { $file = "Textures\\$`".lc($&); last; };
	/\.(umx)$/i && do { $file = "Music\\$`".lc($&); last; };
	/\.(uax)$/i && do { $file = "Sounds\\$`".lc($&); last; };
	/\.(u|int|ini)$/i && do { $file = "System\\$`".lc($&); last; };
	/\.(txt|html?|rtf|doc)$/i && do {
	    $file =~ s/^readme/$product-readme/i;

	    $file = "Help\\$file";
	    last; };
	/\.(bmp|gif|jpe?g|png|xmp)$/i && do { $file = "Help\\$file"; last; };
	{
	};
    }

    return $file;
}

sub showUmodFileReadme {

    my( $umodFile ) = shift;

    # Display the umod's readme file.
    #
    # The umod's readme file is listed in Setup group.  The umod object
    # grabs that and return that, if it's found.
    my( $readme ) = $umodFile->readme;

    if( defined( $readme ) ) {
	print( $umodFile->readme, "\n\n" );
    } else {
	print( STDERR "$0: umod readme file not defined.\n" );
    }

}

# Dump a file inside the umod file.
sub dumpUmodFile {
    my ($umodfile, $pattern) = @_;

    my ($patternEsc) = $pattern;
    # Allow /.
    $patternEsc =~ s-/-\\-g;
    my ($file) = grep { $_->{src} eq $patternEsc } $umodfile->packingList;

    die "$0: $pattern not found for dumping: $!\n" if (!defined $file);

    print $umodfile->dump($file);
}

#sub dumpPlainZipFile {
#    my ($zipname, $pattern) = @_;
#
#    # Prepare to-be-dumped file pattern.
#    my ($patternEsc) = $pattern;
#    # Allow /.
#    $patternEsc =~ s-/-\\-g;
#
#    # Open the zip file.
#    my $zipfile = new Archive::Zip;
#    $zipfile->read($zipname) == AZ_OK
#	or die "$0: cannot open $zipname as a zip file\n";
#
#    die( "$0: $pattern not found for dumping\n" )
#      if( !grep { $_ =~ /$patternEsc/ } $zipfile->memberNames() );
#
#    # Determine product name.
#    my $product = determineProductNameFromZipFile($zipfile, $zipname);
#
#    # Dump matching file.
#    foreach ($zipfile->memberNames()) {
##	my $file = mungeFilename($_, $product);
#	my $file = $_;
#	next if (!$file);
#
#	if ($file eq $patternEsc) {
#	    print $zipfile->contents($_);
#	}
#    }
#}

# Extract a file from the umod file.
sub extractUmodFile {

    my( $umodFile ) = shift;
    my( $file ) = shift;

    my( @packingList ) = $umodFile->packingList;
    my( $fileEsc ) = quotemeta $file;
    # Allow ? and *.
    $fileEsc =~ s/\\\*/.*/g;
    $fileEsc =~ s/\\\?/./g;
    # Allow /.
    $fileEsc =~ s-/-\\-g;
    my( @packedFile ) = grep { $_->{src} =~ /^$fileEsc$/i } @packingList;

    die( "$0: $file not found for extraction: $!\n" )
      if( !defined( $packedFile[0] ) );

    print( map( "extracting $_->{src}\n", @packedFile ) ) if( $pref{verbose} );

    $umodFile->extract( $pref{force}, @packedFile )
      or die( "$0: error extracting $file: $!\n" );

}

#sub extractPlainZipFile {
#    my ($zipname, $pattern, $basedir) = @_;
#
#    # Prepare to-be-extracted file pattern.
#    my ($patternEsc) = quotemeta $pattern;
#    # Allow ? and *.
#    $patternEsc =~ s/\\\*/.*/g;
#    $patternEsc =~ s/\\\?/./g;
#    # Allow /.
#    $patternEsc =~ s-\\\\-/-g;
#
#    # Open the zip file.
#    my $zipfile = new Archive::Zip;
#    $zipfile->read($zipname) == AZ_OK
#	or die "$0: cannot open $zipname as a zip file\n";
#
#    die( "$0: $pattern not found for extraction\n" )
#      if( !grep { $_ =~ /$patternEsc/ } $zipfile->memberNames() );
#
#    # Determine product name.
#    my $product = determineProductNameFromZipFile($zipfile, $zipname);
#
#    # Extract matching files.
#    foreach ($zipfile->memberNames()) {
##	my $file = mungeFilename($_, $product);
#	my $file = $_;
#	next if (!$file);
#
#	if ($file =~ m/$patternEsc/) {
#	    my $rightplace = umodasu::Ini::adjustpathcase("$basedir/"
#		.mungeFilename($_, $product));
#
#	    if (!$pref{force} and -e $rightplace) {
#		warn "$0: $rightplace already exists, skipping\n";
#		next;
#	    }
#
#	    print "extracting file: $file\n" if ($pref{verbose});
#	    $zipfile->extractMember($_, $rightplace);
#	}
#    }
#}

# Install the umod file.
sub installUmodFile {

    my( $umodFile ) = shift;

    my( $product ) = $umodFile->product;
    my( @requirements ) = $umodFile->requirements;
    my( @packingList ) = $umodFile->packingList;
    my( @iniChanges ) = $umodFile->iniChanges;

    foreach my $requirement ( @requirements ) {
		my( $requiredProduct ) = $requirement->{product};
		my( $requiredVersion ) = $requirement->{version};

		if ($requirement->{product} eq "UnrealTournament" || $requirement->{product} eq "Unreal Tournament" ) {
			$requirement->{product} = "Setup";
			$requiredProduct = "UnrealTournament";
		}
		if( !grep { $_ eq $requiredProduct } @installedUmod ) {

			warn( "$0: $requiredProduct version $requiredVersion required\n");

		} else {
			my( $installedVersion ) = $manifestFile->get(
				[$requirement->{product}, 'Version'], -mapping => 'single' );

			if( $installedVersion < $requirement->{version} ) {
				warn( "$0: $requiredProduct $requiredVersion required, installed version is $installedVersion\n");
			}
		}
    }

    my $alreadyinstalled;
    if (grep { $_ eq $product } @installedUmod) {
	if (!$pref{force}) {
	    my $installedVersion = $manifestFile->get( [$product, 'Version'],
		-mapping => 'single' );
	    if ($umodFile->version < $installedVersion) {
		die  "$0: installed $product is of a newer version, skipping\nUse the -f option to install this older version anyway.\n";
	    } elsif ($umodFile->version == $installedVersion) {
		if (checkInstalledUmod($product)) {
		    die "$0: $product already installed, skipping\nUse the -f option to install anyway.\n";
		} else {
		    warn "$0: some files are missing from a previous installation of $product, proceeding to reinstallation\n";
		}
	    } else {
		die "$0: an older version of $product is installed, skipping\nUninstall it first, or use the -f option to install new version on top.\n";
	    }
	}

	$alreadyinstalled = 1;
    }

    foreach (@packingList) {
	print "extracting file: $_->{src}\n" if ($pref{verbose});
	$umodFile->extract($pref{force}, $_)
	  or die "$0: error extracting files: $!\n";
    }

    my( %alreadyBackedUp );
    foreach my $change ( @iniChanges ) {

	my( $iniFileName ) =
	    umodasu::Ini::adjustpathcase( "$pref{basedir}/$change->{file}" );

	if( !exists( $alreadyBackedUp{ $iniFileName } ) ) {
	    backUp( $iniFileName );
	    $alreadyBackedUp{ $iniFileName } = 1;
	}

	print( "modifying $iniFileName\n" ) if( $pref{verbose} );

	if( !$pref{force} and
	    $iniFileName =~ m-System\\UnrealTournament\.ini-i ) {
	    die "$0: System\\UnrealTournament.ini did not exists, skipping\nRun UnrealTournament once to create it, or use the -f option to install anyway (if you use -f the game will still not be playable afterwards).\n";
	}

	# Actually change the .ini file.
	my( $iniFile ) = new umodasu::Ini( $iniFileName );

	$change->{oldvalue} = $iniFile->put(
	    [$change->{section}, $change->{key}, $change->{value}],
	    -add => $change->{add} );

	$iniFile->save;

    }

    backUp( $manifestFileName );

    # Actually change the Manifest.ini file.
    $manifestFile->put( ['Setup', 'Group', $product], -add => 1 );
    $manifestFile->put( [$product, 'Caption', $umodFile->localproduct] );
    $manifestFile->put( [$product, 'Version', $umodFile->version] );

    foreach (@packingList) {
	$manifestFile->put( [$product, 'File', $_->{ src }], -add => 1 );

	if (!$alreadyinstalled) {
	    # Increase reference count.
	    # TODO: casing may not match existing file
	    my $refcount = $manifestFile->get(['RefCounts', "File:$_->{src}"]);
	    if (defined $refcount) {
		$manifestFile->put(['RefCounts', "File:$_->{src}",
		    $refcount + 1]);
	    } else {
		$manifestFile->put(['RefCounts', "File:$_->{ src}", 1]);
	    }
	}
    }

    foreach my $requirement ( @requirements ) {

	$manifestFile->put( [$product, 'Requires', $requirement->{ product }],
	    -add => 1 );

    }

    # Recording file changes.
    foreach my $change ( @iniChanges ) {

	if( $change->{add} ) {
	    # Undo our path canonicalization to mimic AddIni= line.
	    $change->{file} =~ s/^System\\//;

	    $manifestFile->put( [$product, 'AddIni',
		$change->{file}.','.$change->{section}.'.'.$change->{key}
		    .'='.$change->{value}],
		-add => 1 );
	} else {
	    $manifestFile->put( [$product, 'Ini',
		$change->{file}.','.$change->{section}.'.'.$change->{key}
		    .'='.$change->{value}.'='.$change->{oldvalue}],
		-add => 1 );
	}

    }

    $manifestFile->save;

}

#sub installPlainZipFile {
#    my ($filename) = @_;
#
#    my $zipfile = new Archive::Zip;
#    $zipfile->read($filename) == AZ_OK
#	or die "$0: cannot open $filename as a zip file\n";
#
#    # Determine product name.
#    my $product = determineProductNameFromZipFile($zipfile, $filename);
#
#    # Check if product is already installed.
#    my $alreadyinstalled;
#    if (grep { $_ eq $product } @installedUmod) {
#	if (!$pref{force}) {
#	    die "$0: $product is already installed, skipping\nUse the -f option to install it anyway.\n";
#	}
#
#	$alreadyinstalled = 1;
#    }
#
#    # Move the files into the right place.
#    my @files;
#    foreach ($zipfile->memberNames()) {
#	my ($file, $rightplace);
#
#	$file = mungeFilename($_, $product);
#	next if (!defined $file);
#
#	if (!grep /\\/, $file) {
#	    warn "$0: cannot figure out where $file belongs, a copy will be placed in the current directory for you to install it manually\n";
#	    $rightplace = $file;
#	} else {
#	    $rightplace = umodasu::Ini::adjustpathcase("$pref{basedir}/$file");
#	    push @files, $file;
#	}
#
#	if (!$pref{force} and -e $rightplace) {
#	    warn "$0: $rightplace already exists, skipping\n";
#	    next;
#	}
#
#	print "extracting file: $file\n" if ($pref{verbose});
#	$zipfile->extractMember($_, $rightplace);
#    }
#
#    # Update Manifest.ini.
#    backUp($manifestFileName);
#
#    $manifestFile->put(['Setup', 'Group', $product], -add => 1);
#    $manifestFile->put([$product, 'Caption', $product]);
#    $manifestFile->put([$product, 'Version', 'unknown']);
#
#    foreach (@files) {
#	$manifestFile->put([$product, 'File', $_], -add => 1);
#
#	if (!$alreadyinstalled) {
#	    # Increase reference count.
#	    # TODO: casing may not match existing file
#	    my $refcount = $manifestFile->get(['RefCounts', "File:$_"]);
#	    if (defined $refcount) {
#		$manifestFile->put(['RefCounts', "File:$_", $refcount + 1]);
#	    } else {
#		$manifestFile->put(['RefCounts', "File:$_", 1]);
#	    }
#	}
#    }
#
#    $manifestFile->save;
#
#    return 1;
#}

# Check the consistency of the umod file.
sub checkUmodFile {

    print( "$0: umod file checking is not yet implemented\n" );
    return 1;

    my( $umodFile ) = shift;

    open( UMOD, $umodFile->file )
      or die( "$0: cannot open $umodFile->file for reading: $!\n" );
    binmode( UMOD );

    seek( UMOD, 0, SEEK_END )
      or die( "$0: cannot seek to end of file: $!\n" );

    my $filesize = tell UMOD;
    my $calcfilesize = $umodFile->endOfManifestInt;
    foreach ( $umodFile->packingList ) {
	$calcfilesize += $_->{ size };
    }

    close( UMOD );
}

# --------------------------------
# Maint mode functions.

# Display information about installed umods.
sub listInstalledUmod {

    my( $umodName ) = shift;

    if( !grep { $_ eq $umodName } @installedUmod ) {
	print( STDERR "$0: cannot list $umodName: product not installed\nInstalled products are:\n" );
	$pref{verbose} = 0;
	listAllInstalledUmod();
	exit( 1 );
    }

    my( $installedCaption ) = $manifestFile->get( [$umodName, 'Caption'],
	-mapping => 'single' );
    return if( !defined( $installedCaption ) );
    my( $installedVersion ) = $manifestFile->get( [$umodName, 'Version'],
	-mapping => 'single' );
    return if( !defined( $installedVersion ) );

    if( $pref{verbose} ) {
	print( $umodName );
	print( " \"$installedCaption\"" )
	  if( $installedCaption and $installedCaption ne $umodName );
	print( " $installedVersion\n" );

	my( @packingList ) = $manifestFile->get( [$umodName, 'File'],
	    -mapping => 'multiple' );
	foreach my $file ( @packingList ) {
	    print( "    $file\n" );
	}

	my( @iniChanges ) = $manifestFile->get( [$umodName, 'Ini'],
	    -mapping => 'multiple' );
	if( defined $iniChanges[0] ) {
	    my( $prevfile, $prevsection );

	    foreach my $change ( @iniChanges ) {

		# These lines are written by us.  We don't put multiple
		# changes on a single line.
		my( $file, $section, $key, $value ) =
		    ( $change =~ m/([^,]*),(.*)\.([^=]*)=([^=]*)/ );
		#                          ^^^^can        ^^^^don't
		#                              contain '.'    show old value

		if( $file ne $prevfile ) {
		    undef $prevsection;
		    print( "\n" ) unless( !defined $prevfile );
		    print( "  C $file\n" );
		    $prevfile = $file;
		}

		if( $section ne $prevsection ) {
		    print( "\n        [$section]\n" );
		    $prevsection = $section;
		}

		print( "        $key=$value\n" );
	    }
	    print( "\n" );
	}

	my( @iniAdditions ) = $manifestFile->get( [$umodName, 'AddIni'],
	    -mapping => 'multiple' );
	if( defined $iniAdditions[0] ) {
	    my( $prevfile, $prevsection );

	    foreach my $addition ( @iniAdditions ) {

		# These lines are written by us.  We don't put multiple
		# changes on a single line.
		my( $file, $section, $key, $value ) =
		    ( $addition =~ m/([^,]*),(.*)\.([^=]*)=(.*)/ );
		#                            ^^^^can contain '.'

		if( $file ne $prevfile ) {
		    undef $prevsection;
		    print( "\n" ) unless( !defined $prevfile );
		    print( "  + System\\$file\n" );
		    $prevfile = $file;
		}

		if( $section ne $prevsection ) {
		    print( "\n        [$section]\n" );
		    $prevsection = $section;
		}

		print( "        $key=$value\n" );
	    }
	    print( "\n" );
	}

	print( "\n" )
	    if( !defined $iniChanges[0] and !defined $iniAdditions[0] );

## next three lines added by abf to suppress version from name
    } elsif( ! $pref{modvers} ) {
	print( $umodName );
   print "\n";
## end of lines added

    } else {
	print( $umodName );
	print( " \"$installedCaption\"" )
	  if( $installedCaption and $installedCaption ne $umodName );
	print( " $installedVersion\n" );
    }

}

sub listAllInstalledUmod {
    # Loop through the umods sorted by their Caption and Version.
    foreach my $umodName (
	map  { $_->[0] }
	sort { $a->[1] cmp $b->[1] or $a->[2] <=> $b->[2] }
	map  { [$_,
	    $manifestFile->get( [$_, 'Caption'], -mapping => 'single' ),
	    $manifestFile->get( [$_, 'Version'], -mapping => 'single' )] }
	@installedUmod ) {
	listInstalledUmod( $umodName );
    }
}

sub listUnreferencedFiles {
    my (%allfiles);
    find({ wanted => sub {
        my $file = $File::Find::name;
        return 0 if (-d $file);

        $file =~ s-$pref{basedir}/--;
        $file =~ s-/-\\-g;

        $allfiles{ lc( $file ) } = $file; }, follow => 1 },
        $pref{basedir});

    foreach ( @installedUmod ) {
	foreach ( $manifestFile->get( [$_, 'File'], -mapping => 'multiple') ) {
	    delete( $allfiles{ lc( $_ ) } )
	      if( exists( $allfiles{ lc( $_) } ) );
	}
    }

    print "Others\n";
    foreach ( sort values %allfiles ) {
	print "    $_\n";
    }
    print "\n";
}

# Check the integrity of installed umods.
sub checkInstalledUmod {

    my( $umodName ) = shift;

    if( !grep { $_ eq $umodName } @installedUmod ) {
	print( STDERR "$0: cannot check $umodName: product not installed\nInstalled products are:\n" );
	$pref{verbose} = 0;
	listAllInstalledUmod();
	return( 0 );
    }

    my( $installedCaption, $installedVersion );

    my( @errors );
    if( $manifestFile->exists( [$umodName] ) ) {
	if( $manifestFile->exists( [$umodName, 'Caption'] ) ) {
	    $installedCaption = $manifestFile->get( [$umodName, 'Caption'],
		-mapping => 'single' );
	} else {
	    push( @errors, "caption not defined" );
	}
	if( $manifestFile->exists( [$umodName, 'Version'] ) ) {
	    $installedVersion = $manifestFile->get( [$umodName, 'Version'],
		-mapping => 'single' );
	} else {
	    push( @errors, "version not defined" );
	}

	# Check for existence of all files.
	my( @packingList ) = $manifestFile->get( [$umodName, 'File'],
	    -mapping => 'multiple' );
	foreach my $file ( @packingList ) {
	    $file = umodasu::Ini::adjustpathcase( "$pref{basedir}/$file" );

	    if( !-e $file ) {
		push( @errors, "$file does not exist" );
	    }
	}

    } else {
	push( @errors, "dangling group declaration in Setup group" );
    }

    if( @errors ) {
	if( $pref{verbose} ) {
	    print( "checking $umodName" );
	    print( " \"$installedCaption\"" )
	      if( $installedCaption and $installedCaption ne $umodName );
	    print( " $installedVersion" )
	      if( $installedVersion );
	    print( "... error detected:\n" );

	    foreach my $error ( @errors ) {
		print( "    $error\n" );
	    }
	}

	return( 0 );
    } elsif( $pref{verbose} > 1 ) {
	print( "checking $umodName" );
	print( " \"$installedCaption\"" )
	  if( $installedCaption ne $umodName );
	print( " $installedVersion... ok\n" );
    }

    return( 1 );

}

sub uninstallUmod {
    my( $umodName ) = shift;

    if( !grep { $_ eq $umodName } @installedUmod ) {
	print( STDERR "$0: cannot uninstall $umodName: product not installed\nInstalled products are:\n" );
	$pref{verbose} = 0;
	listAllInstalledUmod();
	exit( 1 );
    }

    # Delete the files.
    foreach ($manifestFile->get([$umodName, 'File'], -mapping => 'multiple')) {
	# Decrease reference count.
	# TODO: casing may not match existing file
	my $refcount = $manifestFile->get(['RefCounts', "File:$_"]);
	if (defined $refcount) {
	    if (--$refcount > 0) {
		$manifestFile->put(['RefCounts', "File:$_", $refcount]);
	    } else {
		$manifestFile->delete(['RefCounts', "File:$_"]);
	    }
	} else {
	    # No reference count.
	    # TODO: scanning
	}

	if (!$refcount) {
	    # Really delete it.
	    $_ = umodasu::Ini::adjustpathcase("$pref{basedir}/$_");
	    unlink $_ or warn "$0: cannot remove $_: $!\n";
	    print "deleting $_\n"  if ($pref{verbose});
	} else {
	    print "not deleting $_\n"  if ($pref{verbose});
	}
    }

    # Undo AddIni additions.
    my( %alreadyBackedUp );
    foreach my $addition ( $manifestFile->get( [$umodName, 'AddIni'],
	-mapping => 'multiple' ) ) {
	last if( !$addition );

	my ($file, $section, $key, $value) =
	    ($addition =~ m/([^,]*),(.*)\.([^=]*)=(.*)/);

	my( $iniFileName ) =
	    umodasu::Ini::adjustpathcase( "$systemDir/$file" );

	print( "modifying $iniFileName\n" ) if( $pref{verbose} );

	if( !exists( $alreadyBackedUp{ $iniFileName } ) ) {
	    backUp( $iniFileName );
	    $alreadyBackedUp{ $iniFileName } = 1;
	}

	# Actually change the .ini file.
	my( $iniFile ) = new umodasu::Ini( $iniFileName );

	$iniFile->delete( [$section, $key, $value] );

	$iniFile->save;
    }

    # Undoing Ini changes is not terribly useful.
    foreach my $change ( $manifestFile->get( [$umodName, 'Ini'],
	-mapping => 'multiple' ) ) {
	last if( !$change );

	my ($file, $section, $key, $value, $oldvalue) =
	    ($change =~ m/([^,]*),(.*)\.([^=]*)=([^=]*)=(.*)/);

	my( $iniFileName ) =
	    umodasu::Ini::adjustpathcase( "$pref{basedir}/$file" );

	print( "modifying $iniFileName\n" ) if( $pref{verbose} );

	if( !exists( $alreadyBackedUp{ $iniFileName } ) ) {
	    backUp( $iniFileName );
	    $alreadyBackedUp{ $iniFileName } = 1;
	}

	# Actually change the .ini file.
	my( $iniFile ) = new umodasu::Ini( $iniFileName );

	$iniFile->put( [$section, $key, $oldvalue] );

	$iniFile->save;
    }

    backUp( $manifestFileName );

    # Delete the groups registration and the group itself.
    $manifestFile->delete( ['Setup', 'Group', $umodName] );
    $manifestFile->delete( [$umodName] );
    $manifestFile->save();

    return 1;
}

#sub uninstallPlainZip {
#    my ($filename) = @_;
#
#    my $zipfile = new Archive::Zip;
#    $zipfile->read($filename) == AZ_OK
#	or die "$0: cannot open $filename as a zip file\n";
#
#    # Determine product name.
#    my $product = determineProductNameFromZipFile($zipfile, $filename);
#
#    return uninstallUmod($product);
#}

# --------------------------------
# Initialization functions.

# Scan the system for the current config.
sub scanSystem {

    # Determine base directory.
    if( !defined( $pref{basedir} ) ) {

	# Autodetect Unreal installation.
	foreach my $dir ( '/usr/local/games/ut', '/usr/games/ut',
	    '/usr/local/games/UnrealTournament', '/usr/games/UnrealTournament',
	    'C:/UnrealTournament', '.' ) {
	    my $sysDir;
	    if( $sysDir = $pref{basedir}.'/'
		    .umodasu::Ini::adjustfilecase( 'System', $pref{basedir} ),
		-e $sysDir.'/'
		    .umodasu::Ini::adjustfilecase( 'Core.u', $sysDir ) ) {
		$pref{basedir} = $dir;
		last;
	    }
	}

	if( !defined( $pref{basedir} ) ) {
	    die( "$0: no Unreal game found\nUse the -b option to specify a valid base directory.\n" );
	}

    }

    # Determine System directory.
    $systemDir = $pref{basedir}."/"
	.umodasu::Ini::adjustfilecase( "System", $pref{basedir} );

    # Unless doing extraction, bail out if base directory is invalid.
    if( !$argExtract
	and !-e $systemDir."/"
	    .umodasu::Ini::adjustfilecase( "Core.u", $systemDir )
	and !$pref{force} ) {
	die( "$0: no Unreal game found in $pref{basedir}\nUse the -b option to specify a valid base directory, or the -f option to use it anyway.\n" );
    }

    # Force flag is given, try to make the base directory if it does not exist.
    if( !-d $pref{basedir} and !mkdir( $pref{basedir}, 0755 ) ) {
	die( "$0: cannot make directory $pref{basedir}: $!\n" );
    }

    # Save base directory  to the rc file if it does not already exist.
    # Don't save if base directory is "." because it's too transient.
    if( !-e $rcfile and $pref{basedir} ne "." ) {
	if( open( RCFILE, ">$rcfile" ) ) {
	    print( RCFILE "basedir = $pref{basedir}\n" );
	    close( RCFILE );
	}
    }

    # Determine Manifest.ini path.
    $manifestFileName = $systemDir."/"
	.umodasu::Ini::adjustfilecase( "Manifest.ini", $systemDir );

    # Make an initial Manifest.ini if not installed.
    if ( !-e $manifestFileName ) {
	warn( "$0: $manifestFileName does not exist, creating it\n" );
	makeInitialManifest($manifestFileName);
    }

    # Read list of installed mods from Manifest.ini.
    $manifestFile = new umodasu::Ini( $manifestFileName );
    @installedUmod = $manifestFile->get( ['Setup', 'Group'],
	-mapping => 'multiple' );

    push (@installedUmod, "UnrealTournament");

}

sub makeInitialManifest {

    my( $manifestFileName ) = shift;

    # This initial Manifest.ini is for UNIX.
    my( $content ) = <<EOT;
[Setup]
Group=UnrealTournament
MasterProduct=UnrealTournament

[UnrealTournament]
File=Help\\Heat.ico
File=Help\\Logo.bmp
File=Help\\MPlayer.ico
File=Help\\ReadMe.htm
File=Help\\Unreal.ico
File=Help\\UnrealEd.ico
File=Help\\UnrealTournamentLogo.bmp
File=Help\\UnrealTournamentSetupLogo.bmp
File=Help\\UT-Linux.Xpm
File=Help\\UT.Xpm
File=Help\\UT-Small.Xpm
File=Logs\\delete_me.txt
File=Maps\\AS-Frigate.unr
File=Maps\\AS-Guardia.unr
File=Maps\\AS-HiSpeed.unr
File=Maps\\AS-Mazon.unr
File=Maps\\AS-OceanFloor.unr
File=Maps\\AS-Overlord.unr
File=Maps\\AS-Rook.unr
File=Maps\\AS-Tutorial.unr
File=Maps\\CTF-Command.unr
File=Maps\\CTF-Coret.unr
File=Maps\\CTF-Dreary.unr
File=Maps\\CTF-EternalCave.unr
File=Maps\\CTF-Face.unr
File=Maps\\CTF-Gauntlet.unr
File=Maps\\CTF-LavaGiant.unr
File=Maps\\CTF-Niven.unr
File=Maps\\CTF-November.unr
File=Maps\\CTF-Tutorial.unr
File=Maps\\CityIntro.unr
File=Maps\\DM-Barricade.unr
File=Maps\\DM-Codex.unr
File=Maps\\DM-Conveyor.unr
File=Maps\\DM-Curse][.unr
File=Maps\\DM-Deck16][.unr
File=Maps\\DM-Fetid.unr
File=Maps\\DM-Fractal.unr
File=Maps\\DM-Gothic.unr
File=Maps\\DM-Grinder.unr
File=Maps\\DM-HyperBlast.unr
File=Maps\\DM-KGalleon.unr
File=Maps\\DM-Liandri.unr
File=Maps\\DM-Morbias][.unr
File=Maps\\DM-Morpheus.unr
File=Maps\\DM-Oblivion.unr
File=Maps\\DM-Peak.unr
File=Maps\\DM-Phobos.unr
File=Maps\\DM-Pressure.unr
File=Maps\\DM-Pyramid.unr
File=Maps\\DM-Stalwart.unr
File=Maps\\DM-StalwartXL.unr
File=Maps\\DM-Tempest.unr
File=Maps\\DM-Turbine.unr
File=Maps\\DM-Tutorial.unr
File=Maps\\DM-Zeto.unr
File=Maps\\DOM-Cinder.unr
File=Maps\\DOM-Condemned.unr
File=Maps\\DOM-Cryptic.unr
File=Maps\\DOM-Gearbolt.unr
File=Maps\\DOM-Ghardhen.unr
File=Maps\\DOM-Lament.unr
File=Maps\\DOM-Leadworks.unr
File=Maps\\DOM-MetalDream.unr
File=Maps\\DOM-Olden.unr
File=Maps\\DOM-Sesmar.unr
File=Maps\\DOM-Tutorial.unr
File=Maps\\EOL_Assault.unr
File=Maps\\EOL_CTF.unr
File=Maps\\EOL_Challenge.unr
File=Maps\\EOL_Deathmatch.unr
File=Maps\\EOL_Domination.unr
File=Maps\\EOL_Statues.unr
File=Maps\\Entry.unr
File=Maps\\UT-Logo-Map.unr
File=Maps\\UTCredits.unr
File=Music\\Botmca9.umx
File=Music\\Botpck10.umx
File=Music\\Cannon.umx
File=Music\\Colossus.umx
File=Music\\Course.umx
File=Music\\Credits.umx
File=Music\\Ending.umx
File=Music\\Enigma.umx
File=Music\\Foregone.umx
File=Music\\Godown.umx
File=Music\\Lock.umx
File=Music\\Mech8.umx
File=Music\\Mission.umx
File=Music\\Nether.umx
File=Music\\Organic.umx
File=Music\\Phantom.umx
File=Music\\Razor-ub.umx
File=Music\\Run.umx
File=Music\\SaveMe.umx
File=Music\\Savemeg.umx
File=Music\\Seeker.umx
File=Music\\Seeker2.umx
File=Music\\Skyward.umx
File=Music\\Strider.umx
File=Music\\Suprfist.umx
File=Music\\UnWorld2.umx
File=Music\\Uttitle.umx
File=Music\\Wheels.umx
File=Music\\firebr.umx
File=Music\\utmenu23.umx
File=NetGamesUSA.com\\ngStats\\ngusa.jar
File=NetGamesUSA.com\\ngStats\\history.txt
File=NetGamesUSA.com\\ngStats\\ngStatsUT.cfg
File=NetGamesUSA.com\\ngStats\\Backup of default ngStatsUT.cfg
File=NetGamesUSA.com\\ngStats\\html\\Help_Using_ngStats.html
File=NetGamesUSA.com\\ngStats\\html\\ngStats_Main.html
File=NetGamesUSA.com\\ngStats\\html\\About_NetGames_USA.html
File=NetGamesUSA.com\\ngStats\\html\\About_ngWorldStats.html
File=NetGamesUSA.com\\ngStats\\html\\Legal_Terms.html
File=NetGamesUSA.com\\ngStats\\html\\About_ngTCS.html
File=NetGamesUSA.com\\ngStats\\html\\About_Epic_Games.html
File=NetGamesUSA.com\\ngStats\\html\\processing.html
File=NetGamesUSA.com\\ngStats\\html\\skins\\skin.css
File=NetGamesUSA.com\\ngStats\\html\\skins\\Default NetGamesUSA Skin\\skin.css
File=NetGamesUSA.com\\ngStats\\html\\skins\\Default NetGamesUSA Skin\\README.txt
File=NetGamesUSA.com\\ngStats\\html\\skins\\Default NetGamesUSA Skin\\custom_graphics\\skin_credit_88x31.gif
File=NetGamesUSA.com\\ngStats\\html\\skins\\Default NetGamesUSA Skin\\custom_graphics\\background.gif
File=NetGamesUSA.com\\ngStats\\html\\skins\\Default NetGamesUSA Skin\\custom_graphics\\sidebar_120x90.gif
File=NetGamesUSA.com\\ngStats\\html\\skins\\custom_graphics\\skin_credit_88x31.gif
File=NetGamesUSA.com\\ngStats\\html\\skins\\custom_graphics\\background.gif
File=NetGamesUSA.com\\ngStats\\html\\skins\\custom_graphics\\sidebar_120x90.gif
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\Total_Index.html
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\Player_Index.html
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\All_Totals.html
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\Human_Totals.html
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\Bot_Totals.html
File=NetGamesUSA.com\\ngStats\\html\\Total_Game_Stats\\Rankings.html
File=NetGamesUSA.com\\ngStats\\html\\Individual_Game_Stats\\Recent_Index.html
File=NetGamesUSA.com\\ngStats\\html\\Individual_Game_Stats\\Highest_Score\\index.html
File=NetGamesUSA.com\\ngStats\\html\\Individual_Game_Stats\\Last_Game\\index.html
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngStats.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngStats_106_Wide.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngUSA_Logo_106_wide.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\unreallogo.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngUSA_Logo.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\UT_Logo_Large_Button.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\UT_Logo_Small_Button.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\white.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\flags_279.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngStats_Processing.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats_ENABLED_240x70.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngTCS_129x114.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngTCS_Lite_129x114.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngTCS_Pro_129x114.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\View_ngWorldStats.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats_Password.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\blue_white.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\View_ngStats.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats_ENABLED_88x31.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g11.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g_no.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g10.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g_legend.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g12.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g13.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g14.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g15.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g16.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g1.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g2.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g19.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g17.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g20.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g21.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g22.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g23.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g24.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g25.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g26.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g27.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g28.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g29.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g3.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g30.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g31.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g32.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g4.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g5.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g6.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g7.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g8.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g9.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\graph_back_ngStats.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\graph_back_ngStats_big.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\g18.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\Change_ngWorldStats_Password.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats_Enabled_234x46.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\ngWorldStats_500x83.gif
File=NetGamesUSA.com\\ngStats\\html\\graphics\\Confirm_Password.gif
File=NetGamesUSA.com\\ngStats\\data\\db.ver
File=NetGamesUSA.com\\ngStats\\README.linux
File=NetGamesUSA.com\\ngStats\\Readme-Help_Using_ngStats.html
File=NetGamesUSA.com\\ngStats\\ngStats End User License Agreement (EULA).txt
File=NetGamesUSA.com\\ngStats\\spawnBrowser.exe
File=NetGamesUSA.com\\ngStats\\processedLogs\\_tmp
File=NetGamesUSA.com\\ngStats\\ngStatsUT
File=NetGamesUSA.com\\ngWorldStats\\logs\\New_Install.log
File=NetGamesUSA.com\\ngWorldStats\\bin\\ngWorldStats
File=NetGamesUSA.com\\ngWorldStats\\bin\\ngWS.ver
File=NetGamesUSA.com\\ngWorldStats\\bin\\ngWorldStats End User License Agreement (EULA).txt
File=NetGamesUSA.com\\About_NetGames_USA.html
File=Sounds\\Activates.uax
File=Sounds\\Addon1.uax
File=Sounds\\AmbAncient.uax
File=Sounds\\AmbCity.uax
File=Sounds\\AmbModern.uax
File=Sounds\\AmbOutside.uax
File=Sounds\\Announcer.uax
File=Sounds\\BossVoice.uax
File=Sounds\\DDay.uax
File=Sounds\\DMatch.uax
File=Sounds\\DoorsAnc.uax
File=Sounds\\DoorsMod.uax
File=Sounds\\Extro.uax
File=Sounds\\Female1Voice.uax
File=Sounds\\Female2Voice.uax
File=Sounds\\FemaleSounds.uax
File=Sounds\\LadderSounds.uax
File=Sounds\\Male1Voice.uax
File=Sounds\\Male2Voice.uax
File=Sounds\\MaleSounds.uax
File=Sounds\\Pan1.uax
File=Sounds\\TutVoiceAS.uax
File=Sounds\\TutVoiceCTF.uax
File=Sounds\\TutVoiceDM.uax
File=Sounds\\TutVoiceDOM.uax
File=Sounds\\VRikers.uax
File=Sounds\\noxxsnd.uax
File=Sounds\\openingwave.uax
File=Sounds\\rain.uax
File=System\\BotPack.u
File=System\\Core.u
File=System\\Editor.u
File=System\\Engine.u
File=System\\Fire.u
File=System\\IpDrv.u
File=System\\IpServer.u
File=System\\UBrowser.u
File=System\\UMenu.u
File=System\\UTBrowser.u
File=System\\UTMenu.u
File=System\\UTServerAdmin.u
File=System\\UWeb.u
File=System\\UWindow.u
File=System\\UnrealI.u
File=System\\UnrealShare.u
File=System\\Botpack.int
File=System\\CommandoSkins.int
File=System\\Core.int
File=System\\D3DDrv.int
File=System\\Editor.int
File=System\\Engine.int
File=System\\FCommandoSkins.int
File=System\\Galaxy.int
File=System\\GlideDrv.int
File=System\\IpDrv.int
File=System\\IpServer.int
File=System\\Manifest.int
File=System\\MeTaLDrv.int
File=System\\OpenGlDrv.int
File=System\\SGLDrv.int
File=System\\SGirlSkins.int
File=System\\Setup.int
File=System\\SoftDrv.int
File=System\\SoldierSkins.int
File=System\\Startup.int
File=System\\UBrowser.int
File=System\\UMenu.int
File=System\\UTMenu.int
File=System\\UTServerAdmin.int
File=System\\UWeb.int
File=System\\UnrealI.int
File=System\\UnrealShare.int
File=System\\UnrealTournament.int
File=System\\WinDrv.int
File=System\\Window.int
File=System\\license.int
File=System\\DefUser.ini
File=System\\Audio.so
File=System\\Core.so
File=System\\Engine.so
File=System\\Fire.so
File=System\\Galaxy.so
File=System\\GalaxyLib.so
File=System\\GlideDrv.so
File=System\\IpDrv.so
File=System\\NullRender.so
File=System\\Render.so
File=System\\UWeb.so
File=System\\XDrv.so
File=System\\XMesaGLDrv.so
File=System\\UnrealTournament
File=System\\ucc
File=System\\XDrv.int
File=System\\Default.ini
File=Textures\\AlfaFX.utx
File=Textures\\Ancient.utx
File=Textures\\ArenaTex.utx
File=Textures\\Belt_fx.utx
File=Textures\\BluffFX.utx
File=Textures\\BossSkins.utx
File=Textures\\CTF.utx
File=Textures\\ChizraEFX.utx
File=Textures\\Coret_FX.utx
File=Textures\\Creative.utx
File=Textures\\Crypt.utx
File=Textures\\Crypt2.utx
File=Textures\\Crypt_FX.utx
File=Textures\\DDayFX.utx
File=Textures\\DMeffects.utx
File=Textures\\DacomaFem.utx
File=Textures\\DacomaSkins.utx
File=Textures\\DecayedS.utx
File=Textures\\Detail.utx
File=Textures\\Egypt.utx
File=Textures\\EgyptPan.utx
File=Textures\\FCommandoSkins.utx
File=Textures\\Faces.utx
File=Textures\\Female1Skins.utx
File=Textures\\Female2Skins.utx
File=Textures\\FireEng.utx
File=Textures\\FlareFX.utx
File=Textures\\FractalFX.utx
File=Textures\\GenEarth.utx
File=Textures\\GenFX.utx
File=Textures\\GenFluid.utx
File=Textures\\GenIn.utx
File=Textures\\GenTerra.utx
File=Textures\\GenWarp.utx
File=Textures\\GothFem.utx
File=Textures\\GothSkins.utx
File=Textures\\GreatFire.utx
File=Textures\\GreatFire2.utx
File=Textures\\HubEffects.utx
File=Textures\\ISVFX.utx
File=Textures\\Indus1.utx
File=Textures\\Indus2.utx
File=Textures\\Indus3.utx
File=Textures\\Indus4.utx
File=Textures\\Indus5.utx
File=Textures\\Indus6.utx
File=Textures\\Indus7.utx
File=Textures\\JWSky.utx
File=Textures\\LadderFonts.utx
File=Textures\\LadrArrow.utx
File=Textures\\LadrStatic.utx
File=Textures\\LavaFX.utx
File=Textures\\Lian-X.utx
File=Textures\\Liquids.utx
File=Textures\\Logo.utx
File=Textures\\Male1Skins.utx
File=Textures\\Male2Skins.utx
File=Textures\\Male3Skins.utx
File=Textures\\MenuGr.utx
File=Textures\\Metalmys.utx
File=Textures\\Mine.utx
File=Textures\\NaliCast.utx
File=Textures\\NaliFX.utx
File=Textures\\NivenFX.utx
File=Textures\\Old_FX.utx
File=Textures\\Palettes.utx
File=Textures\\PhraelFx.utx
File=Textures\\PlayrShp.utx
File=Textures\\Queen.utx
File=Textures\\RainFX.utx
File=Textures\\Render.utx
File=Textures\\RotatingU.utx
File=Textures\\SGirlSkins.utx
File=Textures\\Scripted.utx
File=Textures\\ShaneChurch.utx
File=Textures\\ShaneDay.utx
File=Textures\\ShaneSky.utx
File=Textures\\SkTrooperSkins.utx
File=Textures\\Skaarj.utx
File=Textures\\SkyBox.utx
File=Textures\\SkyCity.utx
File=Textures\\Slums.utx
File=Textures\\Soldierskins.utx
File=Textures\\SpaceFX.utx
File=Textures\\Starship.utx
File=Textures\\TCrystal.utx
File=Textures\\Terranius.utx
File=Textures\\TrenchesFX.utx
File=Textures\\UT.utx
File=Textures\\UT_ArtFX.utx
File=Textures\\UTbase1.utx
File=Textures\\UTcrypt.utx
File=Textures\\UTtech1.utx
File=Textures\\UTtech2.utx
File=Textures\\UTtech3.utx
File=Textures\\UWindowFonts.utx
File=Textures\\XFX.utx
File=Textures\\XbpFX.utx
File=Textures\\Xtortion.utx
File=Textures\\castle1.utx
File=Textures\\city.utx
File=Textures\\commandoskins.utx
File=Textures\\credits.utx
File=Textures\\eol.utx
File=Textures\\of1.utx
File=Web\\current.uhtm
File=Web\\current_console.uhtm
File=Web\\current_console_log.uhtm
File=Web\\current_console_send.uhtm
File=Web\\current_game.uhtm
File=Web\\current_menu.uhtm
File=Web\\current_mutators.uhtm
File=Web\\current_players.uhtm
File=Web\\defaults.uhtm
File=Web\\defaults_bots.uhtm
File=Web\\defaults_ippolicy-d.uhtm
File=Web\\defaults_ippolicy-f.uhtm
File=Web\\defaults_ippolicy-h.uhtm
File=Web\\defaults_maps.uhtm
File=Web\\defaults_menu.uhtm
File=Web\\defaults_rules.uhtm
File=Web\\defaults_server.uhtm
File=Web\\defaults_settings.uhtm
File=Web\\images\\1-1.gif
File=Web\\images\\1-2.gif
File=Web\\images\\1.gif
File=Web\\images\\2-1.gif
File=Web\\images\\2-2.gif
File=Web\\images\\3-1.gif
File=Web\\images\\3-2.gif
File=Web\\images\\4-1.gif
File=Web\\images\\4-2.gif
File=Web\\images\\5-1.gif
File=Web\\images\\5-2.gif
File=Web\\images\\6-1.gif
File=Web\\images\\6-2.gif
File=Web\\images\\7-1.gif
File=Web\\images\\7-2.gif
File=Web\\images\\7-3.gif
File=Web\\images\\image.gif
File=Web\\images\\logo.gif
File=Web\\images\\m1-1.gif
File=Web\\images\\m1-2.gif
File=Web\\images\\m3-1.gif
File=Web\\images\\m3-2.gif
File=Web\\images\\right.gif
File=Web\\menu.uhtm
File=Web\\message.uhtm
File=Web\\plaintext\\current.uhtm
File=Web\\plaintext\\current_console.uhtm
File=Web\\plaintext\\current_console_log.uhtm
File=Web\\plaintext\\current_console_send.uhtm
File=Web\\plaintext\\current_game.uhtm
File=Web\\plaintext\\current_menu.uhtm
File=Web\\plaintext\\current_mutators.uhtm
File=Web\\plaintext\\current_players.uhtm
File=Web\\plaintext\\defaults.uhtm
File=Web\\plaintext\\defaults_bots.uhtm
File=Web\\plaintext\\defaults_ippolicy-d.uhtm
File=Web\\plaintext\\defaults_ippolicy-f.uhtm
File=Web\\plaintext\\defaults_ippolicy-h.uhtm
File=Web\\plaintext\\defaults_maps.uhtm
File=Web\\plaintext\\defaults_menu.uhtm
File=Web\\plaintext\\defaults_rules.uhtm
File=Web\\plaintext\\defaults_server.uhtm
File=Web\\plaintext\\defaults_settings.uhtm
File=Web\\plaintext\\menu.uhtm
File=Web\\plaintext\\message.uhtm
File=Web\\plaintext\\root.uhtm
File=Web\\root.uhtm
File=uninstall
Caption=Unreal Tournament
Version=400

EOT

    # Make preceeding directories.
    my( $path ) = $manifestFileName;
    my( $prefix );
    while( $path =~ m-^([^/]*)/- ) {
	$prefix .= $1."/";
	if ( !-d $prefix and !mkdir( $prefix, 0755 ) ) {
	    die( "$0: cannot make directory $prefix: $!\n" );
	}
	$path = $';
    }

    open( MANIFEST, ">$manifestFileName" )
      or die( "$0: cannot open $manifestFileName for writing: $!\n" );

    print( MANIFEST $content );

    close( MANIFEST );

}

# --------------------------------
# Utility functions.

sub backUp {

    my( $filename ) = shift;

    if( -e $filename ) {
	open( INI, "<$filename" )
	  or die( "$0: cannot open $filename for reading: $!\n" );

	undef $/;
	my( $content ) = <INI>;
	$/ = "\n";

	close( INI );

#	if( exists "$filename.bak" ) {
#	    my $i = 1;
#	    do { $i++; } until( !exists $umod{"$filename.bak.$i"} );
#	    $filename .= ".bak.$i";
#	}

	open( INI, ">$filename.bak" )
	  or die( "$0: cannot open $filename.bak for writing: $!\n" );

	print( INI $content );

	close( INI );
    }

}

1;
__END__

=head1 EXAMPLES

=over 4

=item Indentify an umod file

umod -l DE.umod

=item List the contents of an umod file

umod -v -l DE.umod

=item Install an umod file inside /usr/local/UT

umod -b /usr/local/UT -i DE.umod

=item Extract all the files in DE.umod into /tmp/de

umod -b /tmp/de -x DE.umod

=item Examine the content of de.int in DE.umod

umod -d System/de.int DE.umod

Forward slashes can be used in place of backslashes.

=item List all the installed products

umod -l

=item List all the installed products, files belong to them and changes made to files

umod -v -l

=item List all the installed products, files belong to them, changes made to files.  List also files not belonged to any product group under the group `Others'

umod -v -v -l

=item List the files belonging to an installed product and the changes
made to files by this product

umod -v -l "DE Mutators"

=item Check for integrity of installed products

umod -c

=back

=head1 AUTHOR

Mishka Gorodnitzky <F<misaka@pobox.com>> and  Avatar <F<avatar@deva.net>>.

=cut
