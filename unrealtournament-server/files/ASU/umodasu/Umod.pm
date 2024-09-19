package umodasu::Umod;

use POSIX;
use umodasu::Ini;
use strict;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK);

require Exporter;
require AutoLoader;

@ISA = qw(Exporter AutoLoader);
# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.
@EXPORT = qw(
	
);
$VERSION = '0.50';


# Preloaded methods go here.

# Autoload methods go after =cut, and are processed by the autosplit program.

=head1 NAME

Umod - Perl module for Unreal mod file manipulation

=head1 SYNOPSIS

    use umodasu::Umod;
    $umod = new umodasu::Umod( -file => "$umodFileName" );

=head1 DESCRIPTION

The package is an abstraction of an Unreal mod file.

=head1 METHODS

=over 4

=cut

# ----------------------------------------------------------------

=item B<new( [-file => filename] )>

Constructor for the umod object.  The umod filename can optionally be
supplied.

=cut

sub new {

    my( $type ) = shift;
    my( %params ) = @_;
    my( $file ) = shift;
    my( $self ) = {};

    bless( $self );

    if( exists( $params{ -file } ) ) {
	$self->{file} = $params{ -file };
    } elsif( $file !~ m/^-/ ) {
	$self->{file} = $file;
    }

    if( exists( $self->{file} ) ) {
	$self->open or return( undef );
    }

    return( $self );

}

# ----------------------------------------------------------------

=item B<file( self[, filename] )>

Set/retrieve the umod filename.

=cut

sub file {

    my( $self ) = shift;
    my( $file ) = shift;

    $self->{file} = $file
      if( $file );

    return( $self->{file} );

}

# ----------------------------------------------------------------

=item B<baseDir( self[, dir] )>

Set/retrieve the base directory for file extraction.

=cut

sub baseDir {

    my( $self ) = shift;
    my( $basedir ) = shift;

    $self->{basedir} = $basedir
      if( $basedir );

    return( $self->{basedir} );

}

# ----------------------------------------------------------------

=item B<product( self[, product] )>

Set/retrieve the product name.

=cut

sub product {

    my( $self ) = shift;
    my( $product ) = shift;

    $self->{product} = $product
      if( $product );

    return( $self->{product} );

}

# ----------------------------------------------------------------

=item B<version( self[, version] )>

Set/retrieve the version number.

=cut

sub version {

    my( $self ) = shift;
    my( $version ) = shift;

    $self->{version} = $version
      if( $version );

    return( $self->{version} );

}

# ----------------------------------------------------------------

=item B<archive( self[, archive] )>

Set/retrieve the archive name.

=cut

sub archive {

    my( $self ) = shift;
    my( $archive ) = shift;

    $self->{archive} = $archive
      if( $archive );

    return( $self->{archive} );

}

# ----------------------------------------------------------------

=item B<requirements( self[, requirements] )>

Retrieve the requirment information.

=cut

sub requirements {

    my( $self ) = shift;

    return( @{ $self->{requirements} } );

}

# ----------------------------------------------------------------

=item B<localproduct( self[, product] )>

Set/retrieve the localized umod product name.

=cut

sub localproduct {

    my( $self ) = shift;
    my( $localproduct ) = shift;

    $self->{localproduct} = $localproduct
      if( defined( $localproduct ) );

    return( $self->{localproduct} );

}

# ----------------------------------------------------------------

=item B<producturl( self[, producturl] )>

Set/retrieve the product URL.

=cut

sub producturl {

    my( $self ) = shift;
    my( $producturl ) = shift;

    $self->{producturl} = $producturl
      if( defined( $producturl ) );

    return( $self->{producturl} );

}

# ----------------------------------------------------------------

=item B<versionurl( self[, versionurl] )>

Set/retrieve the version URL.

=cut

sub versionurl {

    my( $self ) = shift;
    my( $versionurl ) = shift;

    $self->{versionurl} = $versionurl
      if( defined( $versionurl ) );

    return( $self->{versionurl} );

}

# ----------------------------------------------------------------

=item B<developer( self[, developer] )>

Set/retrieve the localized developer name.

=cut

sub developer {

    my( $self ) = shift;
    my( $developer ) = shift;

    $self->{developer} = $developer
      if( defined( $developer ) );

    return( $self->{developer} );

}

# ----------------------------------------------------------------

=item B<developerurl( self[, developerurl] )>

Set/retrieve the developer URL.

=cut

sub developerurl {

    my( $self ) = shift;
    my( $developerurl ) = shift;

    $self->{developerurl} = $developerurl
      if( defined( $developerurl ) );

    return( $self->{developerurl} );

}

# ----------------------------------------------------------------

=item B<readmefile( self[, filename] )>

Set/retrieve the filename of the ReadMe file.

=cut

sub readmefile {

    my( $self ) = shift;
    my( $readme ) = shift;

    $self->{readmefile} = $readme
      if( defined( $readme ) );

    return( $self->{readmefile} );

}

# ----------------------------------------------------------------

=item B<packingList( self )>

Return the packing list.  

At this point, this read-only.  This could change if I add the
ability to pack a umod file.

Each element in the returned list is a ref to a hash derived from
the Src lines in the packed ini files.

=cut

sub packingList {

    my( $self ) = shift;

    return( @{ $self->{packingList} } );

}

# ----------------------------------------------------------------

=item B<iniChanges( self )>

Return the ini change list.  

Each element in the returned list is a ref to a hash derived from
the Ini lines in the packed ini files.

=cut

sub iniChanges {

    my( $self ) = shift;

    return( @{ $self->{iniChanges} } );

}

# ----------------------------------------------------------------

sub endOfManifestInt {

    my( $self ) = shift;

    return( $self->{endOfManifestInt} );

}

# ----------------------------------------------------------------

=item B<open( self[, file] )>

Open the umod file and parse it.

Yup, here's the big one, forx.

=cut

sub open {

    my( $self ) = shift;
    my( $file ) = shift;
    my( $ini );
    my( @requirements, @groups, @packingList, @iniChanges );
    my( $offset ) = 0;

    # Juggle $file passed to us, if any, with what we've already got.
    if( $file ) {
	$self->file( $file );
    } else {
	$file = $self->file;
    }

    # Call upon umodasu::Ini to do the actual parsing of the preamble.
    $ini = new umodasu::Ini( $file, -umod => 1 );

    return( undef ) if( !$ini->exists( ['Setup'] ) );
	# end_of_manifest_int may not be accurate.so dont use
    # $offset = $ini->{end_of_manifest_int};

    # Set values in $self.
    $self->product( $ini->get( ['Setup', 'Product'], -mapping => 'single' ) );
    $self->version( $ini->get( ['Setup', 'Version'], -mapping => 'single' ) );
    $self->archive( $ini->get( ['Setup', 'Archive'], -mapping => 'single' ) );

    # Loop through the requirements.
    if( $ini->exists( ['Setup', 'Requires'] ) ) {
	foreach my $requirement ( $ini->get( ['Setup', 'Requires'],
	    -mapping => 'multiple' ) ) {
	    my( %hash );
	    %hash->{product}      = $ini->get( [$requirement, 'Product'],
		-mapping => 'single' );
	    %hash->{version}      = $ini->get( [$requirement, 'Version'],
		-mapping => 'single' );
	    %hash->{localproduct} = $ini->get( [$requirement, 'LocalProduct'],
		-mapping => 'single' );
	    %hash->{producturl}   = $ini->get( [$requirement, 'ProductURL'],
		-mapping => 'single' );
	    %hash->{versionurl}   = $ini->get( [$requirement, 'VersionURL'],
		-mapping => 'single' );
	    %hash->{developer}    = $ini->get( [$requirement, 'Developer'],
		-mapping => 'single' );
	    %hash->{developerurl} = $ini->get( [$requirement, 'DeveloperURL'],
		-mapping => 'single' );
	    push( @requirements, \%hash );
	}
    }

    # Loop through the setup groups.
    @groups = $ini->get( ['Setup', 'Group'], -mapping => 'multiple' );

    foreach my $group ( @groups ) {

	if( $group eq "SetupGroup" ) {

	} else {

	    if( $ini->exists( [$group, 'Ini'] ) ) {
		foreach my $line ( $ini->get( [$group, 'Ini'],
		    -mapping => 'multiple' ) ) {
		    my( @hash ) = parseIniLine( $line );
		    push( @iniChanges, @hash );
		}
	    }

	    # AddIni is different from Ini by
	    # 1. a new key=value line is added
	    # 2. files are assumed to be in System/, hence the System/
	    #    prefix is omitted
	    if( $ini->exists( [$group, 'AddIni'] ) ) {
		foreach my $line ( $ini->get( [$group, 'AddIni'],
		    -mapping => 'multiple' ) ) {
		    my( @hash ) = parseIniLine( $line, -add => 'true' );
		    push( @iniChanges, @hash );
		}
	    }

	    # Fix for compatibility with UMOD Tool
	    # which uses addini not AddIni
	    if( $ini->exists( [$group, 'addini'] ) ) {
		foreach my $line ( $ini->get( [$group, 'addini'],
		    -mapping => 'multiple' ) ) {
		    my( @hash ) = parseIniLine( $line, -add => 'true' );
		    push( @iniChanges, @hash );
		}
	    }


	    # Umod-defined groups.
	    if( $ini->exists( [$group, 'File'] ) ) {
		foreach my $line ( $ini->get( [$group, 'File'],
		    -mapping => 'multiple' ) ) {
		    my( $hash ) = parseSrcLine( $line );
			# These values are unreliable as end_of_manifest_int
			# may not be accurate.
			# $hash->{start} is now back calculated below
		    #$hash->{start} = $offset;
		    #$offset += $hash->{size};
		    push( @packingList, $hash );
		}
	    }
    	}
    }

	# The trailing packing info is as follows:
	# 2 byte header ( seems like it can be more )
	# 19 byte trailer
	# 14 byte file trailer
	# 	1 byte seperator
	#   4 bytes start ( little endium )
	#   4 bytes size ( little endium )
	#	9 bytes unknown
	# N.B. dont forget the missing manifest files
	# System/Manifest.ini & System/Manifest.int and their headers
	my ($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size) = stat($file);
	my $files_size = 0;
	my $trailer_size = 2 + 19 + ( 2 * ( 19 + 14 ) ); # header + trailer + manifest files
	my @filenames = ( 'System\\Manifest.ini', 'System\\Manifest.int' );

    foreach my $srcFile ( @packingList ) {
		push @filenames, $srcFile->{'src'};
		$files_size += $srcFile->{'size'};
		$trailer_size += length( $srcFile->{'src'} ) + 14;
	}

	# Check the layout of the file matches our predictions
	if( !CORE::open( UMOD, "<$file" ) ) {
		warn( "Umod: cannot open $file for reading: $!\n" );
		return( undef );
	}

	binmode( UMOD );

	if( !seek( UMOD, -$trailer_size, SEEK_END ) ) {
		warn( "Umod: cannot seek EOF - $trailer_size bytes: $!\n" );
	}

	my $trailer;

	if( !read( UMOD, $trailer, $trailer_size ) ) {
		warn( "Umod: cannot read $trailer_size bytes: $!\n" );
		return( undef );
	}

	if ( length( $trailer ) != $trailer_size ) {
		warn( "Umod: trailer is invalid ( short )\n" );
		return( undef );
	}

	# 2 + ( filenames + 14 ) + 19
	my $pattern = '^..' . ( join '(.{14})',
		map{
			s/([\\\.\[\]\(\)\?\*])/\\$1/g; # escape bad pattern chars
			$_
		} @filenames ) . '(.{14}).{19}$';

	if ( $trailer !~ /$pattern/s ) {
		warn( "Umod: trailer is invalid ( pattern )\n" );
		return( undef );
	}
	close UMOD;

	# If the 14 bytes after the filenames in the trailer
	# are CRC's we should store them for here and check
	# them on extraction.

	# umod has passed the checks.
	# update the start positions of all the files using
	# the information we now have from the trailer
	$offset = $size - $files_size - $trailer_size;

	# Remove the manifest files and their information
	substr( $trailer, 0, 2 + ( 2 * ( 19 + 14 ) ) ) = '';

	foreach my $srcFile ( @packingList ) {
		# Remove the filename and the seperator byte?
		substr( $trailer, 0, length( $srcFile->{'src'} ) + 1 ) = '';

		# The next 4 bytes are the start position in little endium
		my $start_le = substr( $trailer, 0, 4 );

		# The next 4 bytes are the size in little endium
		my $size_le = substr( $trailer, 4, 4 );

		# Remove the remaining detail about this file
		substr( $trailer, 0, 13 ) = '';

		# Decode the start and size
		my $start = unpack( "V", $start_le );
		my $size = unpack( "V", $size_le );

		# Set the start point for this file
		$srcFile->{'start'} = $start;

		if ( $srcFile->{'size'} != $size ) {
			warn( "Overriding manifest size for '$srcFile->{'src'}" );
			$srcFile->{'size'} = $size;
		}
	}

    # Set variables in $self.
    $self->{requirements} = \@requirements;
    $self->{packingList} = \@packingList;
    $self->{iniChanges} = \@iniChanges;
    $self->{endOfManifestInt} = $size - $files_size - $trailer_size;

    # Set variables based on the Manifest.int Setup section.
    $self->localproduct( $ini->get( ['Setup', 'LocalProduct'],
	-mapping => 'single' ) );
    $self->producturl  ( $ini->get( ['Setup', 'ProductURL'],
	-mapping => 'single' ) );
    # Version string is not localized, use $self->version.
    $self->versionurl  ( $ini->get( ['Setup', 'VersionURL'],
	-mapping => 'single' ) );
    $self->developer   ( $ini->get( ['Setup', 'Developer'],
	-mapping => 'single' ) );
    $self->developerurl( $ini->get( ['Setup', 'DeveloperURL'],
	-mapping => 'single' ) );
    $self->readmefile  ( $ini->get( ['Setup', 'ReadMe'],
	-mapping => 'single' ) );

    return( 1 );

}
  
# ----------------------------------------------------------------

=item B<parseSrcLine( line )>

Parse a given 'Src' line.

These lines exist in the ini sections of the umod and contain 
information on files packed into the umod.  We do some simple
processing to return a hash ref atomically.

=cut

sub parseSrcLine {

    my( $line ) = shift;
    my( %hash );

    $line =~ s/^\((.+)\)$/$1/;
    %hash = map {
	my( $key, $value ) = split( /\s*=\s*/, $_, 2 );
	( lc( $key ), $value )
    } split( /,\s*/, $line );

    $hash{src} =~ s/"(.*)"/$1/;
#    $hash{src} =~ s/\\/\//g;
    $hash{size} = 0
      if( !exists( $hash{size} ) );

    return( \%hash );

}

# ----------------------------------------------------------------

=item B<parseIniLine( line[, -add => bool] )>

Parse a given 'Ini' line or 'AddIni' line.

These lines exist in the umodINIGroup sections of the umod and
contain information on changes or additions to the ini files. As a
special case, changes to the ServerPackages of the Engine.GameEngine
section of System\UnrealTournament.ini or System\Unreal.ini is always
interpreted as an addition.

=cut

sub parseIniLine {

    my( $line, %args ) = @_;
    my( @allhashes, %hash );

    my( $tmp );
    ( $hash{file}, $line ) = ( split( /,/, $line, 2 ) );
    # The decision to use the period as the delimiter and at the same time allow
    # section header to contain periods is a very bad one.
    ( $tmp, $hash{value}, $line ) = ( $line =~ m/([^=]*)=([^,]*),?(.*)/ );
    ( $hash{section}, $hash{key} ) = ( $tmp =~ m/(.*)\.(.*)/ );
    #                                            ^^^^greedy, can contain '.'

    if( $args{-add} ) {
	# Ensure its in the format we expect
	# i.e. without the System\ prefix
	# This maintains compatibility with UMOD Tool
	$hash{file} =~ s/^System\\//;
	$hash{file} = "System\\$hash{file}";
	$hash{add} = 1;
    }

    # Special case.
    if( $hash{file} =~ m/System\\Unreal(Tournament)?.ini/i
	and $hash{section} eq 'Engine.GameEngine'
	and $hash{key} eq 'ServerPackages' ) {
	$hash{add} = 1;
    }

    push( @allhashes, \%hash );

    while( $line ) {
	my( %newhash );

	$newhash{file} = $hash{file};
	$newhash{section} = $hash{section};

	($newhash{key}, $newhash{value}, $line) =
	    ($line =~ m/([^=]*)=([^,]*),?(.*)/);

	$newhash{add} = 1 if( $args{-add}
	    or ( $newhash{file} eq 'System\\UnrealTournament.ini'
		 and $newhash{section} eq 'Engine.GameEngine'
		 and $newhash{key} eq 'ServerPackages' ) );

	push( @allhashes, \%newhash );
    }

    return( @allhashes );

}

# ----------------------------------------------------------------

=item B<extract( self, force, files )>

Extract the listed files.

Files are expected to come in hash refs as returned from
parseSrcLine above.  These hashes contain filenames, sizes, etc.

=cut

sub extract {

    my( $self      ) = shift;
    my( $flagForce ) = shift;
    my( @srcFiles  ) = @_;
    my( $umodfile  ) = $self->file;

    foreach my $srcFile ( @srcFiles ) {

	my( $file ) = $srcFile->{src};
	my( $depth ) = 0;
	my( $contents );

	# Make preceeding directories.
	my( $workDir ) = $self->baseDir."/";
	$file =~s-\\-/-g;

	while( $file =~ m-^([^/]*)/- ) {
	    my( $dir ) = umodasu::Ini::adjustfilecase( $1, $workDir );
	    $file = $';
	    if( !-d "${workDir}$dir"
		and !mkdir( "${workDir}$dir", 0755 ) ) {
		warn( "Umod: error making dir ${workDir}$dir: $!\n" );
		return( undef );
	    }
	    # Add this to our 'working dir', as used above and below.
	    $workDir .= "$dir/";
	}

	if ( "$file" eq "" ) {
	    next;
	}

	# Don't overwrite existing file unless force option is requested.
	if( -e "${workDir}$file" && !$flagForce ) {
	    warn( "Umod: ${workDir}$file already exists, skipping\n" );
	    next;
	}

	if( !CORE::open( OUTFILE, ">${workDir}$file" ) ) {
	    warn( "Umod: cannot open ${workDir}$file for writing: $!\n" );
	    return( undef );
	}

	if( $srcFile->{size} > 0 ) {

	    if( !CORE::open( UMOD, "<$umodfile" ) ) {
		warn( "Umod: cannot open $umodfile for reading: $!\n" );
		return( undef );
	    }
	    binmode( UMOD );

	    if( !seek( UMOD, $srcFile->{start}, SEEK_SET ) ) {
		warn( "Umod: cannot seek $srcFile->{start} bytes: $!\n" );
		return( undef );
	    }

	    if( !read( UMOD, $contents, $srcFile->{size} ) ) {
		warn( "Umod: cannot read $srcFile->{size} bytes: $!\n" );
		return( undef );
	    }

	    close( UMOD );

	    print( OUTFILE $contents );

	} else {
	    warn( "Umod: $srcFile->{src} is empty\n" );
	}

	if( !close( OUTFILE ) ) {
	    warn( "Umod: cannot close ${workDir}$file: $!\n" );
	    return( undef );
	}

    }

    return( 1 );

}

# ----------------------------------------------------------------

=item B<dump( self, files )>

Dump the listed files.

Files are expected to come in hash refs as returned from
parseSrcLine above.  These hashes contain filenames, sizes, etc.

=cut

sub dump {

    my( $self      ) = shift;
    my( $srcFile   ) = @_;
    my( $umodfile  ) = $self->file;
    my( $contents );

    return( undef ) if( $srcFile->{size} == 0 );

    if( !CORE::open( UMOD, "<$umodfile" ) ) {
	warn( "Umod: cannot open $umodfile for reading: $!\n" );
	return( undef );
    }
    binmode( UMOD );

    if( !seek( UMOD, $srcFile->{start}, SEEK_SET ) ) {
	warn( "Umod: cannot seek $srcFile->{start} bytes: $!\n" );
	return( undef );
    }

    if( !read( UMOD, $contents, $srcFile->{size} ) ) {
	warn( "Umod: cannot read $srcFile->{size} bytes: $!\n" );
	return( undef );
    }

    close( UMOD );

    return( $contents );
}

# ----------------------------------------------------------------

=item B<readme( self )>

Return the contents of the readme file, if it exists and if found.

=cut

sub readme {

    my( $self ) = shift;
    my( $umodfile  ) = $self->file;
    my( $readmeSrc, $contents );

    # Make sure there is a readme file as listed in Setup group.
    return( undef ) if( !defined( $self->readmefile ) );

    ( $readmeSrc ) = grep( $_->{src} eq $self->readmefile, $self->packingList );

    return( undef ) if( $readmeSrc->{size} == 0 );

    if( !CORE::open( UMOD, "<$umodfile" ) ) {
	warn( "Umod: cannot open $umodfile for reading: $!\n" );
	return( undef );
    }
    binmode( UMOD );

    if( !seek( UMOD, $readmeSrc->{start}, SEEK_SET ) ) {
	warn( "Umod: cannot seek $readmeSrc->{start} bytes: $!\n" );
	return( undef );
    }

    if( !read( UMOD, $contents, $readmeSrc->{size} ) ) {
	warn( "Umod: cannot read $readmeSrc->{size} bytes: $!\n" );
	return( undef );
    }

    close( UMOD );

    return( $contents );

}

# ----------------------------------------------------------------

1;
__END__

=back

=head1 AUTHOR

Mishka Gorodnitzky <F<misaka@pobox.com>> and Avatar <F<avatar@deva.net>>.

=head1 SEE ALSO

umod(1), xumod(1).

=cut
