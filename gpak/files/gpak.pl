#!/usr/pkg/bin/perl -w
# GPaK - a small package management graphical tool
# v0.0.1
#
# Sorry about long lines
#
# TODO
# * rewrite download functions (maybe using p5-HTTP-Lite)
# * rewrite unzip function (using p5-Archive-Zip)
# * make interface asynchronous
# * implement an option dialog
# * conflict avoidance
# * a lot more ...
#
# If your changes are pertinent please commit them
# without asking. Just don't forget to bump version.
#

use strict;
use warnings;

use POSIX;
use Class::Struct;
use File::Find;
use pkgsrc::Dewey;

use Gtk2 -init;
use Gtk2::GladeXML;

# Package structure
struct Spackage => {
	pkgname => '$',
	depends => '$',
	conflicts => '$',
	pkgpath => '$',
	category => '$',
	description => '$',
	local_version => '$',
	remote_version => '$',
	filename => '$',
	automatic => '$',
	already_checked => '$',
};

our @pkgarray;

# GLOBALS
our $TMP = "/tmp";
our $PKGDB = '/var/db/pkg';


my $gxml = Gtk2::GladeXML->new('gpak.glade');
$gxml->signal_autoconnect_from_package('main');

my $main_window = $gxml->get_widget('main_window');

# Import widgets from glade
our $cat_tree = $gxml->get_widget('cat_tree');
our $pac_tree = $gxml->get_widget('pac_tree');
our $update_tree = $gxml->get_widget('update_tree');
our $info_label = $gxml->get_widget('info_label');
our $search_text = $gxml->get_widget('search_text');

# Set model and column for category treeview
my $cat_store = Gtk2::ListStore->new('Glib::String');
$cat_tree->set_model($cat_store);
&cat_set_columns;

# Same for package treeview
&pac_empty;
&pac_set_columns;
$pac_tree->signal_connect ('cursor-changed' => \&pac_clicked, $pac_tree->get_model);

# Download pkg_summary
&on_refreshbutton_clicked unless (-e "$TMP/pkg_summary");

# Fill categories tree view
print "Getting package categories...\n";
&fill_categories;

# Complete pkgarray with installed packages info
print "Loading installed packages...\n";
&fill_installed_pkgs;

# Complete update list
print "Checking what should be updated...\n";
&update_tree_empty;
&update_tree_set_columns;
&update_tree_fill;

Gtk2->main;

#############################################

# PKG SUBS

sub load_pkg_summary {

	my $pkgname = '';
	my $pkgpath = '';
	my $descr = '';
	my $deps = '';
	my $filename = '';
	my $conflicts = '';
	my @categories;
	my $i = 0;

	delete @pkgarray[0 .. $#pkgarray];
	open (F, "$TMP/pkg_summary") || return;

	my $linef = <F>;

	while (defined($linef)) {
		chop($linef);
		if ($linef eq "") {
			if (($pkgname ne "") && ($pkgpath ne "") && ($pkgname =~ /(.+)-(\d.*)/)) {
				
				my $pname = $1;
				my $pversion = $2;
				# add it to the list
				my $pkg_index = @pkgarray;
				$pkgarray[$pkg_index] = Spackage->new();
				$pkgarray[$pkg_index]->pkgname($pname);
				$pkgarray[$pkg_index]->remote_version($pversion);
				$pkgarray[$pkg_index]->pkgpath($pkgpath);
				$pkgarray[$pkg_index]->depends($deps);
				$pkgarray[$pkg_index]->conflicts($conflicts);
				$pkgarray[$pkg_index]->description($descr);
				$pkgarray[$pkg_index]->filename($filename);
				$pkgarray[$pkg_index]->category('');
				$pkgarray[$pkg_index]->automatic(0);
				$pkgarray[$pkg_index]->local_version('');

				# Category - I probably should use CATEGORY instead of PKGPATH
				if ($pkgpath =~ /(.+)\/.+/ ) {
					my $catname = $1;
					my $cfound = 0;
					my $c;
					$pkgarray[$pkg_index]->category($catname);

					# Check if category is already added in category list
					foreach $c (@categories) {
						if ($c eq $catname) {
							$cfound = 1;
							last;
						}
					}
					if ($cfound == 0) {
						$categories[@categories] = $catname;
					}
				} else {
					print "[WARN] Wrong pkgpath $pkgpath\n";
				}
			} else {	# bad $pkgname
				print ("[WARN] Bad PKGNAME $pkgname\n");
			}

			$pkgname = '';
			$pkgpath = '';
			$descr = '';
			$deps = '';
			$conflicts = '';
			$filename = '';
		} elsif ($linef =~ /(.+?)=(.+)/) {	# Fill in $completename, @deps and $pkgname
			my $prop = $1;
			my $value = $2;
			if ($prop eq "PKGNAME") {
				$pkgname = $value;
			} elsif ($prop eq "DEPENDS") {
				$deps .= $value . " ";
			} elsif ($prop eq "CONFLICTS") {
				$conflicts .= $value . " ";
			} elsif ($prop eq "PKGPATH") {
				$pkgpath = $value;
			} elsif ($prop eq "DESCRIPTION") {
				$descr .= $value . " ";
			} elsif ($prop eq "FILE_NAME") {
				$filename = $value;
			}
		}
		$linef = <F>;
	}

	close F;
	return @categories;
}

sub add_conflict {
	my ($pack, $conf) = @_;

	my $c;
	foreach $c (split(/ /, $pack->conflicts)) {
		return 0 if ($c eq $conf);
	}

	$pack->conflicts($pack->conflicts . $conf . " ");
	return 1;
}

# fill in pkg_array with installed versions
# basically walk every entry in $PKGDB
sub fill_installed_pkgs {
	my @dirarr = ( $PKGDB );
	find(sub { -d && fill_pkg($_) }, @dirarr);
}

# Match installed package in pkg_array and fill local_version
sub fill_pkg {
	my $pkgname = shift;

	return if ($pkgname eq '.');

	if ($pkgname =~ /(.+)-(\d.*)/) {
		my $pname = $1;
		my $pversion = $2;

		my $pfound = 0;

		my $pack;
		foreach $pack (@pkgarray) {
			if ($pack->pkgname eq $pname) {
				# Check if this is really it - by matching PKGPATH
				if (-e "$PKGDB/$pkgname/+BUILD_INFO") {
					open(BIFILE, "$PKGDB/$pkgname/+BUILD_INFO");
					my $row = <BIFILE>;
					my $ppath = 'PKGPATH=' . $pack->pkgpath;
					while (defined($row)) {
						chop($row);
						if ($row eq $ppath) {
							$pfound = 1;
							last;
						}
						$row = <BIFILE>;
					}
					close BIFILE;
					next if ($pfound == 0);
				} else {
					$pfound = 1;
				}

				$pack->local_version($pversion);

				# fill the conflicts
				if (-e "$PKGDB/$pkgname/+CONTENTS") {
					open(CONTENTS, "$PKGDB/$pkgname/+CONTENTS");
					my $row = <CONTENTS>;
					while (defined($row)) {
						if ($row =~ /^\@pkgcfl (.+)/) {
							my $conf = $1;
							add_conflict ($pack, $conf);
						}
						$row = <CONTENTS>;
					}
					close CONTENTS;
				}

				# check if it's a dependency
				if (-e "$PKGDB/$pkgname/+INSTALLED_INFO") {
					open (IINFO, "$PKGDB/$pkgname/+INSTALLED_INFO");
					my $row = <IINFO>;
					while (defined($row)) {
						chop($row);
						if ($row eq 'automatic=yes') {
							$pack->automatic(1);
							last;
						}
						$row = <IINFO>;
					}
					close IINFO;
				}

				last;
			}
		}
		print "[WARN] Can't match installed package $pkgname\n" if ($pfound == 0);
	} else {
		print ("[WARN] $pkgname has no version\n");
	}
}

#
# These functions should be rewritten using perl interfaces
#

# Download a file to $TMP
sub http_file_download {
	my ($location, $fname) = @_;

	my $complete_fname = $location . "/" . $fname;

	system ("ftp -o $TMP/$fname $complete_fname");
}

sub unzip_file {
	my ($fname) = @_;

	system ("gunzip -f $fname");
}

sub fix_os_ver {
	my ($os_ver) = @_;

	if ($os_ver =~ /^(\d+\.99\.)/) {	# 4.99.73 => 4.99.x
		$os_ver = $1 . 'x';
	} elsif ($os_ver =~ /^(\d+\.\d+).+/) {	# 4.0.1_WHATEVER => 4.0
		$os_ver = $1;
	}

	return $os_ver;
}

# already_checked = 0 for all packages
sub reset_checks {
	my $p;
	foreach $p (@pkgarray) {
		$p->already_checked(0);
	}
}

# already_checked = 1 for this package and all dependencies
sub check_all_deps {
	my $p = shift;

	return if ($p->already_checked == 1);

	$p->already_checked(1);

	my $dep;
	foreach $dep (split(/ /, $p->depends)) {
		my $pd;
		my $dep_found = 0;
		foreach $pd (@pkgarray) {
			# XXX: should I check remote_version or local_version or maybe both ?!
			if (regexp_dewey_match($dep, $pd->pkgname . '-' . $pd->remote_version) == 1 ) {	# ||
#			    regexp_dewey_match($dep, $pd->pkgname . '-' . $pd->remote_version)) {
				&check_all_deps($pd);
				$dep_found = 1;
				last;
			}
		}
		print "[WARN] Cannot find dependency $dep\n" if ($dep_found == 0);
	}
}

sub regexp_dewey_match {
	my ($pattern, $pkg) = @_;

	return 1 if (dewey_match($pattern, $pkg) == 1);

	my $rpat = $pattern;	# lvalue

	# XXX: slow. There should be an easier way
	if ($rpat =~ /(.*)\{(.*,.*)\}(.*)/) {
		my $e1 = $1;
		my $e2 = $2;
		my $e3 = $3;
		my $expreg;
		foreach $expreg (split(/,/, $e2)) {
			my $recreg = $e1 . $expreg . $e3;
			return 1 if ($pkg =~ /^$recreg/);
		}
		return 0;
	}

	# don't give up just yet, try to match pcre
	return 1 if ($pkg =~ /^$rpat/);

	# No, no match
	return 0;
}

# Check conflicts and circular dependencies
# reset_checks must be called a priori
sub check_conflicts {
	my $pack = shift;
	my $p;

	return 0 if ($pack->local_version eq $pack->remote_version);

	# Check for circular dependency
	if ($pack->already_checked == 1) {
		print "Circular dependency found for " . $pack->pkgname . "\n";
		return 1;
	}
	return 0 if ($pack->already_checked == 2);

	$pack->already_checked(1);

	my $complete_name = $pack->pkgname . '-' . $pack->remote_version;

	# Check to see if there is a conflict between an installed package and $pack
	foreach $p (@pkgarray) {
		next if ($p->local_version eq '');
		my $cfl;
		foreach $cfl (split(/ /, $p->conflicts)) {
			if (regexp_dewey_match($cfl, $complete_name) == 1) {
			    print "Conflict found between " . $p->pkgname . '-' . $p->local_version .
				" and " . $complete_name . " matched as " . $cfl . "\n";
			    return 1;
			}
		}
	}

	# Check conflicts for dependencies
	my $dep;
	foreach $dep (split(/ /, $pack->depends)) {
		my $p;
		my $dep_found = 0;
		foreach $p (@pkgarray) {
			if (regexp_dewey_match($dep, $p->pkgname . '-' . $p->remote_version) == 1) {
				return 1 if (&check_conflicts($p) == 1);
				$dep_found = 1;
				last;
			}
		}
		if ($dep_found == 0) {
			print "[FATAL]: Cannot find dependency " . $dep . "\n";
			return 1;
		}
	}

	$pack->already_checked(2);
	return 0;	# no conflict
}

# dependency = 0 => wanted package
#              1 => dependency
sub download_and_install {
	my ($pack, $dependency) = @_;

	return 1 if ($pack->local_version ne '' && dewey_cmp($pack->local_version, '>=',
		$pack->remote_version));

	my $dep;
	foreach $dep (split(/ /, $pack->depends)) {
		my $p;
		my $dep_found = 0;
		foreach $p (@pkgarray) {
			if (regexp_dewey_match($dep, $p->pkgname . '-' . $p->remote_version) == 1) {
				return 0 if (download_and_install($p, 1) == 0);
				$dep_found = 1;
				last;
			}
		}
		if ($dep_found == 0) {
			print "Cannot find dependency " . $dep . "\n";
			return 0;
		}
	}

	my $fname = $pack->filename;
	http_file_download (&get_all_ftp, $fname); # unless (-e "$TMP/$fname");

	my $depflag;
	if ($pack->local_version eq '') {
		$depflag = $dependency;		# if not installed, honor $dependency
	} elsif ($dependency == 1) {
		$depflag = $pack->automatic;	# Preserve automatic
	} else {
		$depflag = 0;
	}
	if (install_pkg($pack, $depflag) == 1) {
		$pack->automatic(1) if ($depflag == 1);
		unlink "$TMP/$fname";
		return 1;
	}

	# Failure
	return 0;
}

# Return 1 for success
# $dependency == 1 means it's not a wanted package
sub install_pkg {
	my ($pack, $dependency) = @_;

	my $fname = $pack->filename;
	my $flags = '';

	$flags .= ' -u ' if ($pack->local_version ne '');
	$flags .= ' -A ' if ($dependency == 1);

	if (system("pkg_add $flags $TMP/$fname") != 0) {
		return 0;
	}

	$pack->local_version($pack->remote_version);
	return 1;
}

sub delete_pkg {
	my ($pack, $force) = @_;

	return if ($pack->local_version eq '');

	my $flags = '';
	$flags = ' -f ' if ($force == 1);

	my $complete_name = $pack->pkgname . '-' . $pack->local_version;

	system("pkg_delete $flags $complete_name");

	$pack->local_version('');
	$pack->automatic(0);
}

# GTK SUBS

sub cat_add_item {
	my $text = shift;
	my $model = $cat_tree->get_model;
	$model->set($model->append, 0, $text);
	$cat_tree->set_model($model);
}

sub cat_set_columns {
	my $renderer = Gtk2::CellRendererText->new;

	my $column = Gtk2::TreeViewColumn->new_with_attributes ("Category",
					$renderer, 'text', 0);
	$cat_tree->signal_connect ('cursor-changed' => \&cat_clicked, $cat_tree->get_model);
	# set this column to a fixed sizing (of 50 pixels)
#	$column->set_sizing ('fixed');
#	$column->set_fixed_width (50);

	$cat_tree->append_column ($column);
#	$column = Gtk2::TreeViewColumn->new_with_attributes ("Shit", $renderer, 'text', 0);
#	$cat_tree->append_column ($column);
}

sub pac_add_item {
	my ($inst, $automat, $pkgname, $lver, $rver) = @_;
	my $model = $pac_tree->get_model;
	$model->set($model->append, 0, $inst, 1, $automat, 2, $pkgname, 3, $lver, 4, $rver);
	$pac_tree->set_model($model);
}

sub pac_set_columns {
	my $renderer = Gtk2::CellRendererText->new;
	my @columns = ('Ins', 'Dep', 'Package', 'Local', 'Remote');
	my $i;
	for($i = 0; $i < @columns; $i++) {
		my $column = Gtk2::TreeViewColumn->new_with_attributes($columns[$i],
			$renderer, 'text', $i);
		$pac_tree->append_column($column);
	}
	$pac_tree->set_search_column(2);	# Package
}

sub update_tree_set_columns {
	my $renderer = Gtk2::CellRendererText->new;
	my @columns = ('Package', 'Local', 'Remote');
	my $i;
	for($i = 0; $i < @columns; $i++) {
		my $column = Gtk2::TreeViewColumn->new_with_attributes($columns[$i],
			$renderer, 'text', $i);
		$update_tree->append_column($column);
	}
}

sub update_tree_add_item {
        my ($pkgname, $lver, $rver) = @_;
	my $model = $update_tree->get_model;
	$model->set($model->append, 0, $pkgname, 1, $lver, 2, $rver);
	$update_tree->set_model($model);
}

sub update_tree_refresh {
	&update_tree_empty;
	&update_tree_fill;
}

sub update_tree_fill {
	my $p;

	foreach $p (@pkgarray) {
		if ($p->local_version ne '' &&
		    dewey_cmp($p->local_version, '<',  $p->remote_version)) {
			update_tree_add_item($p->pkgname, $p->local_version,
			    $p->remote_version);
		}
	}
}

# Fill categories treeview
sub fill_categories {
	my @categories = &load_pkg_summary;
	@categories = sort(@categories);
	my $cat;
	foreach $cat (@categories) {
		&cat_add_item($cat);
	}
}

sub fill_pack_list {
	my $cat = shift;
	my $pack;

	&pac_empty;

	foreach $pack (@pkgarray) {
		if ($pack->category eq $cat) {
			my $installed = '';
			$installed = '*' if ($pack->local_version ne '');
			my $autom = '';
			$autom = '*' if ($pack->automatic == 1);
			&pac_add_item($installed, $autom, $pack->pkgname, $pack->local_version,
				$pack->remote_version);
		}
	}
}

# Refresh pkgarray and on-screen info
sub refresh_all_cache {
        &cat_empty;
	&pac_empty;
	&fill_categories;
	&fill_installed_pkgs;

	&update_tree_empty;
	&update_tree_fill;

	$info_label->set_label('');
}

#
# Empty lists
#

sub pac_empty {
	my $pac_store = Gtk2::ListStore->new('Glib::String', 'Glib::String',
		'Glib::String', 'Glib::String', 'Glib::String');
	$pac_tree->set_model($pac_store);
	$pac_tree->set_search_column(1);
}

sub cat_empty {
	my $cat_store = Gtk2::ListStore->new('Glib::String');
	$cat_tree->set_model($cat_store);
}

sub update_tree_empty {
	my $update_tree_store = Gtk2::ListStore->new('Glib::String', 'Glib::String',
		'Glib::String');
	$update_tree->set_model($update_tree_store);
}

###################### Gtk Events

# Category list clicked
sub cat_clicked {
	my $tree = shift;
	my $sel = $tree->get_selection;
	my ($model, $iter) = $sel->get_selected;
	my $selcat = $model->get($iter, 0);	# What text it's actually selected

	fill_pack_list($selcat);
	$info_label->set_label('');
}

# Package list clicked
sub pac_clicked {
	my $tree = shift;
	my $sel = $tree->get_selection;
	my ($model, $iter) = $sel->get_selected;
	return unless (defined($iter));
	my $selpac = $model->get($iter, 2);

	my $pack;
	foreach $pack (@pkgarray) {
		if ($pack->pkgname eq $selpac) {
			my $label_text = "DESCRIPTION:\n" . $pack->description;
			if ($pack->depends ne '') {
				$label_text .= "\n\nDEPENDS on:\n";
				my $dep;
				foreach $dep (split(/ /, $pack->depends)) {
					$label_text .= "$dep\n";
				}
			}

			if ($pack->conflicts ne '') {
				$label_text .= "\nCONFLICTS with:\n";
				my $conf;
				foreach $conf (split(/ /, $pack->conflicts)) {
					$label_text .= "$conf\n";
				}
			}

			$info_label->set_label($label_text);
			last;
		}
	}
}

# Returns URL to packages
sub get_all_ftp {
	my $ftp_site = 'ftp.netbsd.org';
	my $os_name;
	my $arch_name;
	my $os_ver;

	my @unamearr = POSIX::uname();
	$arch_name = $unamearr[4];
	$os_name = $unamearr[0];
	$os_ver = $unamearr[2];

	$os_ver = &fix_os_ver($os_ver);

	my $ALL_FTP = "http://$ftp_site/pub/pkgsrc/packages/$os_name/$arch_name/$os_ver/All";
}

# refresh button clicked
sub on_refreshbutton_clicked {
	unlink("$TMP/pkg_summary.gz");
	unlink("$TMP/pkg_summary");
	&http_file_download(&get_all_ftp, 'pkg_summary.gz');
	&unzip_file("$TMP/pkg_summary.gz");

	&refresh_all_cache;
}

# Update/Install a single package
sub on_install_button_clicked {
	my $sel = $pac_tree->get_selection;
	my ($model, $iter) = $sel->get_selected;
	return unless (defined($iter));	# nothing selected
	my $selpac = $model->get($iter, 2);

	my $pack;
	foreach $pack (@pkgarray) {
		if ($pack->pkgname eq $selpac) {
			print "Checking conflicts, depenedencies and cyclic redundancies...\n";
			&reset_checks;
			return if (&check_conflicts($pack) == 1);
			print "None found, proceding...\n";
			&download_and_install ($pack, 0);
			&refresh_all_cache;
			return;
		}
	}

	if (!defined($pack)) {
		print "!!! Cannot match $selpac !!!\n";
		return;
	}
}

# Update all installed packages
sub on_update_all_button_clicked {
	my $p;
	foreach $p (@pkgarray) {
		if ($p->local_version ne '' &&
		    dewey_cmp($p->local_version, '<',  $p->remote_version)) {
			download_and_install($p, $p->automatic);
		}
	}
	&refresh_all_cache;
}

# Clean Up button pressed - deletes all uneeded automatic packages
sub on_cleanup_button_clicked {
	print "Checking for orphan packages...\n";

	&reset_checks;
	my $p;
	foreach $p (@pkgarray) {
		check_all_deps($p) if ($p->local_version ne '' && $p->automatic == 0);
	}

	foreach $p (@pkgarray) {
		if ($p->local_version ne '' && $p->already_checked == 0) {
			print "Removing " . $p->pkgname . "-" . $p->local_version . "\n";
			delete_pkg($p, 1);
		}
	}
	&reset_checks;
	&refresh_all_cache;
}

# Search Button
sub on_search_button_clicked {
	my $search_string = $search_text->get_text;
	$search_text->set_text('');
	$info_label->set_label('');

	&pac_empty;

	my $pack;
	foreach $pack (@pkgarray) {
		if ($pack->pkgname =~ /\Q$search_string\E/) {
			my $installed = '';
			$installed = '*' if ($pack->local_version ne '');
			my $autom = '';
			$autom = '*' if ($pack->automatic == 1);
			&pac_add_item($installed, $autom, $pack->pkgname, $pack->local_version,
				$pack->remote_version);
		}
	}


}

sub on_search_text_activate {
	&on_search_button_clicked;
}

# Exit button
sub on_exitbutton_clicked {
	Gtk2->main_quit;
}

# Window destroyed
sub on_main_window_destroy_event {
	Gtk2->main_quit;
}
