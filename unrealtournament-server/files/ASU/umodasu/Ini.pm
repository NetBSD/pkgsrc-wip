package umodasu::Ini;

=head1 NAME

umodasu::Ini - Perl interface to MS-Windows registry files, Windows .ini
    and Unreal style .ini files.

=cut

# Copyright (C) 2000 Avatar <avatar@deva.net>.  All rights reserved.
# This program is free software;  you can redistribute it and/or modify
# it under under the same terms as Perl itself.  There is NO warranty;
# not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

=head1 SYNOPSIS

    use umodasu::Ini;
    $ini = new umodasu::Ini('system.ini');

    # MS-Windows style
    print $ini->get(['system', 'path']);
    $oldpath = $ini->put(['system', 'path', 'C:\\windows']);
    if ($ini->exists(['system', 'path'])) ...
    $ini->delete(['system', 'path']);

    # Unreal style (multi-valued keys)
    $ini = new umodasu::Ini('UnrealTournament.ini');
    print map "$_\n", $ini->get(['Engine.GameEngine', 'ServerPackages']);
    $ini->put(['Engine.GameEngine', 'ServerPackages', 'New Mod'], -add => 1);
    if ($ini->exists(['Engine.GameEngine', 'ServerPackages', 'Old Mod'])) ...
    $ini->delete(['Engine.GameEngine', 'ServerPackages', 'Some Mod']);

    $ini->save;

    # Save it in the registry file format
    $ini->registry(1);
    $ini->save('system.reg');

=head1 DESCRIPTION

This package provides easy access to MS-Windows style .ini files, Unreal
style extended .ini files (where multiple values can be associated with
a single key), as well as registry files with automatic conversion from
native Perl to Windows registry data encoding and vice versa.

For an .ini file to be recognized it must be of the following format:

    [section]
    key=value           ; comments

In our implementation the key must be no longer than 1024 characters,
and contain no high-ASCII nor control character.

On a line, everything after the semicolon (;) is ignored.  Backslash (\)
right before the end of line is treated as line continuation marker and
the contents of the next line will be appended after stripping off
preceeding whitespaces.  Comment delimiter takes precedence over line
continuation marker.  Spaces surrounding the delimiting equation sign
are stripped.  If there are more than one equation sign on a line the
first one is treated as the delimiter, the rest of them are considered
part of the value.

The comment delimiter can be specified during calls to B<new> or
B<open> via the B<-commentdelim> option as a regular expression.  If no
comment stripping is desired supply the empty string ('') as the
argument.

Specifcations of section, key and value are to be supplied to methods
via an array reference containing just a section name, or the section
name plus a key name, or the section name plus a key name with its
associated value.

If the first line of a file starts with "REGEDIT4" it will be treated
as a registry file. See the L<"Registry Format"> section below for more
details.  Invoking the B<save> method on such a file will have it saved
in registry file format.  If this is not desirable the output mode can
be forced by calling the B<registry> method.

=head2 Registry Format

If the module is processing a Windows "registry" style file, or
is placed into registry mode, all values are automatically converted
to and from native Perl/Windows registry formats.  For special situations
you can use the B<decode_reg_value> subroutine for manual decoding.

A registry file follows the same format described above, except that
keys are expected to be enclosed in double quotes.  The first line of a
registry file starts with "REGEDIT4".

=over 4

=item

B<Strings> - A string is stored in the registry as a sequence of alphanumeric
symbols that are enclosed in a pair of double quotation marks (").  When
retrieving a string from a registry file, only the actual data is returned
in the scalar variable.  When writting a string, you need to enclose it
within the double quotations marks.

    $ini->put(['sys', 'mystr', '"hi there"'], -add => 1);
    print $ini->get(['sys', 'mystr']);

This will result in the un-quoted 8 character long "hi there" string being printed.

The registry file contains:

    [sys]
    "mystr"="hi there"

=item

B<32 bit numbers> - The registry format allows for special handling of 32 bit numbers.
When you pass in a scalar that is not enclosed in double quotations, this
library will assume you are tring to store a number.  When retrieving a number
it is returned as a Perl number.

    $ini->put(['sys', 'Number', 100], -add => 1);
    print $ini->get(['sys', 'Number']);

This will result in "100" being printed.

The registry file contains:

    [sys]
    "Number"=dword:00000064

=item

B<Arrays of 8 bit numbers> - If you need to store value that is an array of numbers, you can
pass in an array or list of non-quote enclosed scalars.  When retrieving that key's value this module will
return an array or list of scalars.

    $ini->put(['sys', 'ListOfNumbers', ( 1...9) ], -add => 1);
    @nums = $ini->get(['sys', 'ListOfNumbers']);

This will result in an array containing 10 elements.

The registry file contains:

    [sys]
    "ListOfNumbers"=hex:00,01,02,03,04,05,06,07,08,09

=item

B<Multiple Strings> - Registries can also store a list of strings.  They are stored as a sequence of
null terminated arrays of 8 bit numbers, and there is a final null marking the end of the sequence.
When saving multiple strings, you pass in an array or list of scalars that contains double-quote
delimited strings.  When retrieving one of these values, you will receive an array of strings
(without the enclosing quotation marks).

    $ini->put(['sys', 'ListOfStr', ( '"str1"', '"str2"', '"str3"' ) ], -add => 1);
    @strs = $ini->get(['sys', 'ListOfStr']);

This will result in an array containing 3 elements: "str1", "str2" and "str3".

The registry file contains:

    [sys]
    "ListOfStr"=hex(7):73,74,72,31,00,73,74,72,32,00,73,74,\
    72,33,00,00

Note that this example contains a line continuation marker "\".

=back

=head1 METHODS

=over 4

=cut

use umodasu::IxHash;
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
@EXPORT_OK = qw(
    adjustfilecase
    adjustpathcase
);
$VERSION = '1.06';


# Preloaded methods go here.

# Autoload methods go after =cut, and are processed by the autosplit program.

# ----------------------------------------------------------------

=item B<new([filename])>

Constructor.  If a filename is supplied it will be opened as an .ini
file with its content read as the initial configuration of the object.

=cut

sub new {
    my ($class, $file, %args) = @_;

    my $self = bless {}, $class;

    # Use an indexed hash to preserve the order.
    tie %{ $self->{sections} }, 'umodasu::IxHash';

    if (defined $args{-commentdelim}) {
	$self->{commentdelim} = $args{-commentdelim};
    } else {
	$self->{commentdelim} = ";";
    }

    if (defined $file) {
	$self->{file} = $file;
	$self->open($file, -umod => $args{-umod},
	    -commentdelim => $self->{commentdelim})
	    or return undef;
    }

    return $self;
}

# ----------------------------------------------------------------

=item B<open(self[, filename])>

Open the .ini file and read in all valid entries.  New entries will be
merged with the existing configuration.

=cut

sub open {
    my ($self, $file, %args) = @_;

    if (defined $file) {
	$self->{file} = $file;
    } else {
	$file = $self->{file};
    }

    # No need to do anything if this is a new file.
    return 1 if (!-e $file);

    open INIFILE, "<$file" or return 0;

    $_ = <INIFILE>;			# read in the header line
    if ($_ =~ '^REGEDIT4') {
	$self->{registry} = 1;
    } else {
	# Rewind.
	close INIFILE;
	open INIFILE, "<$file" or return 0;
    }

    $self->{commentdelim} = $args{-commentdelim}
	if (defined $args{-commentdelim});

    $self->{lastpos} = 0;
    my $section;
    my $section_terminated = 1;		# umod mode kluge
    my $setup_seen;			# umod mode kluge
    my $line_continuing = 0;

    my ($key, $value);
    while (<INIFILE>) {
	s/\r*\n$//;

	if (m/^\[([^\]]+)\]\s*$/) {
	    # In umod mode, ignores section headings without preceeding
	    # empty line.
	    if ($args{-umod}) {
		# Fix for UMOD Tool not putting a blank line at the
		# end oF manifest.ini
		if (!$section_terminated && 2 == $setup_seen ) {
		    last;
		} else {
		    undef $section_terminated;
		}
	    }

	    $section = $1;
	    tie %{ $self->{sections}->{$section} }, 'umodasu::IxHash'
		if (!defined $self->{sections}->{$section});

	    if ($args{-umod}) {
		if ( 2 == $setup_seen and !defined $self->{end_of_manifest_int}
		    and !grep { $_ eq $section }
			@{ $self->{sections}->{Setup}->{Group} }
		    and !grep { $_ eq $section }
			@{ $self->{sections}->{Setup}->{Requires} }) {

		    $self->{end_of_manifest_ini} = $self->{lastpos};

		    my ($intsize) = grep /Manifest.int/i,
			@{ $self->{sections}->{SetupGroup}->{Copy} };
		    ($intsize) = ($intsize =~ m/Size=(\d*)/);
		    $self->{end_of_manifest_int} = $self->{lastpos}
			+ $intsize;
		}

		$setup_seen++ if ($section eq 'Setup');
	    }

	    next;
	}

	# Fix for UMOD Tool no setting size for the manifest and
	if ($args{-umod} && 2 == $setup_seen && '' ne $_ && ! /^\w+=/ ) {
	    $self->{end_of_manifest_int} = $self->{lastpos};
	    last;
	}

	next if (!defined $section);

	# In umod mode, an empty line terminates a section.
	if ($args{-umod} and m/^\s*$/) {
	    $section_terminated = 1;
	    $line_continuing = 0;

	    # Update last valid read position.
	    $self->{lastpos} = tell INIFILE if tell INIFILE > $self->{lastpos};

	    next;
	}

	# Strip comments.
	unless ($self->{commentdelim} eq '') {
	    my $delim = $self->{commentdelim};
	    s/\s*$delim.*//;
	}

	if (!length) {
	    undef $line_continuing;
	    next;
	}

	unless ($line_continuing) {
	    # Strip spaces around first equation sign.
	    s/\s*=\s*/=/;

	    # Backslashes are allowed only in value part according to the
	    # MS-Windows API;  but we'll allow them anyway.
	    # Only non-control-character low-ASCII characters are disallowed in
	    # the key part in our implementation.
	    ($key, $value) = (
		m/^([\w !"#$%&'()*+,-.\/:;<>?@\[\]^`{|}~\\]{1,1024})=(.*)$/);

	    last if (!defined $key);

	    if ($self->{registry}) {
		# Strip the enclosing quotes off of registry entries.
		($key) = ($key =~ /"*([^"]*)"*/);
	    }
	} else {			# we must be continuing, so
	    s/\s*(\S*)/$1/;		# strip leading spaces
	    $value .= $_;		# and append the continuation line
					# onto the value
	    undef $line_continuing;
	}
	if ($value =~ /(.*)\\$/) {
	    $line_continuing = 1;
	    $value = $1;		# remember the new, stripped,
					# concatenated value
	    next;
	}

	# To allow for multi-valued keys, values are pushed into an array.
	push @{ $self->{sections}->{$section}->{$key} }, $value;

	# Update last valid read position.
	$self->{lastpos} = tell INIFILE if tell INIFILE > $self->{lastpos};
    }

    close INIFILE;

    return 1;
}

# ----------------------------------------------------------------

=item B<save(self[, filename])>

Save the current configuration into file in the .ini format.  Both
the section order and the order of key=value pairs within a section
are preserved.  If a filename is given the file will be used as the save
target, otherwise the configuration will be save to the last used (via
B<new>, B<open> or B<save>) file.  The original content of the file will
be clobbered.  Be careful not to inadvertently merge two .ini files into
one by opening them in turn and then saving.

True will be returned if the save is successful, false otherwise.

=cut

sub save {
    my ($self, $file) = @_;

    if (defined $file) {
	$self->{file} = $file;
    } else {
	$file = $self->{file};
    }

    CORE::open INIFILE, ">$file" or return 0;

    print INIFILE "REGEDIT4\n\n" if ($self->{registry});
    foreach my $section (keys %{ $self->{sections} }) {
	print INIFILE "[$section]\n";
	my %hash = %{ $self->{sections}->{$section} };
	foreach my $key (keys %{ $self->{sections}->{$section} }) {
	    my ($quote) = '"' if ($self->{registry});
	    print INIFILE map "$quote$key$quote=$_\n", @{ $hash{$key} };
	}
	print INIFILE "\n";
    }

    close INIFILE or return 0;

    return 1;
}

# ----------------------------------------------------------------

=item B<file(self[, filename] )>

Set or retrieve the filename that was last used.  B<new>, B<open> and
B<save> will all update the last used filename if a filename was
supplied to them.

=cut

sub file {
    my ($self, $file) = shift;

    if (defined $file) {
	$self->{file} = $file;
    }

    return $self->{file};
}

# ----------------------------------------------------------------

=item B<lastpos(self)>

Set or retrieve the byte offset into the file immediately after the last
line that conforms to the .ini format.

=cut

sub lastpos {
    my ($self, $lastpos) = @_;

    if (defined $lastpos) {
	$self->{lastpos} = $lastpos;
    }

    return $self->{lastpos};
}

# ----------------------------------------------------------------

=item B<registry(self)>

Set or retrieve the registry flag which determines whether the file is
to be treated as a registry file or .ini file.  If this flag is true
all subsequent file operations will work in registry file mode,
otherwise the .ini mode is used.  Normally this flag need not be altered
manually because it is automatically set to a value matching the format
of the most recently read file.

=cut

sub registry {
    my ($self, $registry) = @_;

    if (defined $registry) {
	$self->{registry} = $registry;
    }

    return $self->{registry};
}

# ----------------------------------------------------------------

=item B<commentdelim(self)>

Set or retrieve the comment delimiter.

=cut

sub commentdelim {
    my ($self, $commentdelim) = @_;

    if (defined $commentdelim) {
	$self->{commentdelim} = $commentdelim;
    }

    return $self->{commentdelim};
}

# ----------------------------------------------------------------

=item B<exists(self, [ section[, key[, value]] ])>

Return true if the specified section exists, or if the specified key
exists in the specified section.  If a value is specified, return true
if it is any one of the values of the key.

=cut

sub exists {
    my ($self, $path) = @_;

    my ($section, $key, $value) = @$path;

    # Invalid section.
    return 0 if (!defined $section or $section eq '');

    # Only section given.
    return exists $self->{sections}->{$section}
	if (!defined $key or $key eq '');

    # Only section and key given.
    return exists $self->{sections}->{$section}->{$key}
	if (!defined $value or $value eq '');

    # Section, key and value all given.  Any matching value will do.
    return grep { $_ eq $value } @{ $self->{sections}->{$section}->{$key} };
}

# ----------------------------------------------------------------

=item B<get(self, [ section[, key[, value]] ][, -mapping => ('single'|'multiple'))>

Depending on how many elements are specified in the array reference,
retrieve the entire specified section or the values of the specified
key.

If nothing is specified the entire file is returned as a hash
reference.

If only a section name is specified the matching section is returned in
its entirety as a hash reference.

If both a section name and a key name are specified, the associated
values are returned.  If the key has multiple values the returned
result is an array reference containing all the values, otherwise if the
key has only one value that single value is returned as a scalar.

The decision of whether to return a single or multiple values can be
forced via the B<-mapping> argument.  If the multiple mapping option is
applied to a single value result an array of one element that is the
single value will be returned.  If on the other hand the single mapping
option is forced upon a mutli-valued result only the first value will
be returned.

In general, don't specify any mapping when dealing with standard
MS-Windows style .ini files and use the multiple mapping when dealing
with multivalued keys in an Unreal style .ini files.

=cut

sub get {
    my ($self, $path, %args) = @_;

    return $self->{sections} if (!defined $path);

    if ($self->exists($path)) {
	my ($section, $key, $value) = @$path;

	# It doesn't make sense to call get if the value is already
	# available, but we'll try to do something meaningful.
	return $self->exists($path) if (defined $value);

	# Return the entire section if that is the only thing
	# specified.
	return $self->{sections}->{$section} if (!defined $key);

	# Return the associated value/values.
	my @value = @{ $self->{sections}->{$section}->{$key} };

	if ($args{-mapping} eq 'single'
	    or ($#value == 0 and $args{-mapping} ne 'multiple')) {
	    # The key is singly-valued, return the only value.
	    if ($self->{'registry'}) { return decode_reg_value($value[0]); }
	    return $value[0];
	} else {
	    # The key is multi-valued, return all of them in an array.
	    return @value;
	}
    } else {
	return undef;
    }
}

# ----------------------------------------------------------------

=item B<put(self, [ section[, key[, value]] ][, -add => boolean])>

Set the value for the specified key in the specified section and return
the old value.  If the optional B<-add> argument is true a new value
will be added to the key if that value does not already exist.

=cut

sub put {
    my ($self, $path, %args) = @_;

    my ($section, $key, @value_list) = @$path;
	my $value;

    tie %{ $self->{sections}->{$section} }, 'umodasu::IxHash'
	if (!defined $self->{sections}->{$section});

	if ($self->{'registry'}) {
	    $value = encode_reg_value(@value_list);
	} else {
	    $value = $value_list[0];
	}
    if ($args{-add}) {
	push @{ $self->{sections}->{$section}->{$key} }, $value
	    if (!$self->exists($path));
    } else {
	$value = splice @{ $self->{sections}->{$section}->{$key} },
	    0, 1, $value;
	if ($self->{'registry'}) { $value = decode_reg_value($value); }
	return $value;
    }
}

# ----------------------------------------------------------------

=item B<decode_reg_value(value)>

Returns a decoded value or list of values from a registry key.
See the section above on L<"Registry Format">. This routine accepts
the raw value field from a registry entry, and return a Perl
specific data structure that natively represents the data.

This routine is called automatically when either B<get> or B<set>
methods are called specifying a particular key.  If you used
B<get> to retrieve a whole section, the values of the registry keys
will be in their native file format.  You must use this method
call to convert them from registry to Perl format.

=cut

sub decode_reg_value {
    $_ = shift;
    my ($i, $char, @reslist, $res);

    if		(/^\"(.*)\"/) {		# its a string
	return $1;
    } elsif	(/^dword:(.*)/) {	# its a dword
	hex($1);
    } elsif	(/^hex:(.*)/) {		# its a string of hex
	my @list = split /,/, $1;
	for ($i = 0; $i < scalar(@list); $i++) {
	    $list[$i] = hex($list[$i]);
	}
	@list;
    } elsif	(/^hex\(7\):(.*)/s) {	# its a list of null terminated strings
					# and accept embedded new lines
	my ($v) = $1;
	$v =~ s/[\\\s\n\r]//sg;								# remove any continuation marks, <CR>, <LF>, and extra spaces
	my @list = split /,00/, $v;
	foreach $_ (@list) {
	    my @string = split /,/, $_;
	    $res = '';
	    foreach $char (@string) {
		$res .= chr(hex($char)) if ($char);
	    }
	    push @reslist, $res;
	}
	@reslist;
    }
}

# ----------------------------------------------------------------

# This is an internal routine used to encode values from native Perl
# format to their Windows registry file format.

sub encode_reg_value {
    my ($res, $i);

    if (scalar(@_) == 1) {		# if only one value was given
					# its either a number or a string
	if ($_[0] =~ /\".*\"/) {	# If it was a string use it as is
	    $res = $_[0];
	} else {			# it must have been a number
					# so convert it to a dword
	    $res = sprintf ("dword:%08x", $_[0]);
	}
    } else {				# a list was given
	if ($_[0] =~ /\".*\"/) {	# if the first entry was a string
					# assume they are all strings
	    $res = 'hex(7):';
	    foreach (@_) {
		for ($i = 1; $i < length($_) - 1;) {
		    $res .= sprintf("%02x,", ord(substr($_, $i, 1)));
		    $i++;
		    if ((($i % 19) == 0) && $i != length($_)){ $res .= "\\\n"; }
		}
		$res .= '00,';		# null terminate each string
	    }
	    $res .= '00';		# null terminate the sequence
	} else {			# must be a list of numbers
	    $res = 'hex:';
	    for ($i = 0; $i < scalar(@_); ) {
		$res .= sprintf("%02x,", $_[$i]);
		$i++;
		if ((($i % 19) == 0) && $i != scalar(@_)){ $res .= "\\\n"; }
	    }
	    chop $res;
	}
    }
    return $res;
}

# ----------------------------------------------------------------

=item B<delete(self, [ section[, key[, value]] ][, -keep => boolean])>

If section, key and value are all given the corresponding key=value pair
will be deleted from the specified section.  If a specific value is not
given the entire key including all its values will be deleted.  If the
path only specifies a section the entire section will be deleted.

If the optional B<-keep> argument evaluates to true, when performing
section deletion all the keys along with their values are deleted but
the now empty section will still exist to mimic the bahavior of the
Unreal uninstaller.

=cut

sub delete {
    my ($self, $path, %args) = @_;

    return 0 if (!$self->exists($path));

    my ($section, $key, $value) = @$path;

    # Only section given.  Delete whole section.
    if (!defined $key) {
	if ($args{-keep}) {
	    $self->{sections}->{$section} = {};
	} else {
	    delete $self->{sections}->{$section};
	}
	return 1;
    }

    # Only section and key given.  Delete whole key.
    if (!defined $value) {
	delete  $self->{sections}->{$section}->{$key};
	return 1;
    }

    # Section, key and value all given.  Delete matching key=value pair.
    my @newkey =
	grep { $_ ne $value } @{ $self->{sections}->{$section}->{$key} };
    @{ $self->{sections}->{$section}->{$key} } = @newkey;
}

# ----------------------------------------------------------------

=item B<adjustfilecase(filename[, dirname])>

Return the properly cased filename by performing a case-insensitive
match of the specified file within the specified parent directory.  If
there is no match the filename passed in is return as-is.  If the
dirname argument is not given the current directory will be used.

=cut

sub adjustfilecase {
    my ($file) = shift;
    my ($dir) = shift || '.';

    # Win32 is too dumb to handle case-sensitive filenames anyway.
    return $file if ($^O eq 'MSWin32');

    opendir DIR, $dir or return $file;

    my $fileEscaped = $file;
    $fileEscaped =~ s#\[#\\\[#g;
    $fileEscaped =~ s#\]#\\\]#g;
    my @matches = grep { /^$fileEscaped$/i } readdir DIR;
    closedir DIR;

    # Return first match.
    return $matches[0] if ($matches[0]);

    # No match, just return the original filename.
    return $file;
}

# ----------------------------------------------------------------

=item B<adjustpathcase(pathname)>

Return the properly cased and slashed pathname, unless running on a
brain-damaged OS that is too dumb to handle pathnames in a modern,
case-sensitive manner.  Each path components are inspected from left to
right to see if a file or directory of the same name, in any case
combination, already exists.  If any match results the first match is
used, otherwise the original path component is used verbatim.  No
backtracking is performed, so if any path component in the middle fails
to match an existing directory, all subsequent path components are used
as-is.  All backslashes are also changed to forward-slashes.

=cut

sub adjustpathcase {
    my ($path) = @_;

    # Win32 is too dumb to handle case-sensitive pathnames anyway.
    return $path if ($^O eq 'MSWin32');

    $path =~ s#\\#/#g;

    my $dir;
    ($dir, $path) = ($path =~ m#(^/)?(.*)#);
    while ($path =~ m#^([^/]*)/#) {
	$dir .= adjustfilecase($1, $dir).'/';
	$path = $';
    }

    return $dir.adjustfilecase($path, $dir);
}

# ----------------------------------------------------------------

1;
__END__

=back

=head1 AUTHOR

Avatar <F<avatar@deva.net>>, based on a prototype by Mishka Gorodnitzky
<F<misaka@pobox.com>>.  Registry file support by Fulko Hew
<F<fulko@wecan.com>>.

=cut
