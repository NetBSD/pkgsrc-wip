# Introduction

This is a local pkgsrc README for the zoneminder package.  It attempts
not to duplicate the upstream documentation.  (Arguably, some of this
should be pushed upstream.)

# pkgsrc-specific notes

## Choice of jpeg implementation

ZoneMinder claims to benefit dramatically from using libjpeg-turbo.
Consider setting that as default in mk.conf
`JPEG_DEFAULT=libjpeg-turbo` and then *everything*.

## User and Group

zoneminder uses APACHE_USER and APACHE_GROUP.  These are www by
default, but people set them to fpm for use with nginx and php_fpm.
It is important that apache, zoneminder, and any existing directories
all agree.

# MySQL configuration and initial database creation

(It seems that zoneminder only works with MySQL.)

Condider adding `bind-address=127.0.0.1` to `etc/my.conf`, if you are
using mysql only for zoneminder and do not want it accessible from the
network.

See upstream instructions at
https://zoneminder.readthedocs.io/en/1.32.3/installationguide/ubuntu.html
which are for Ubuntu, but seem mostly generic.

Specifically, see "Step 5: Configure the ZoneMinder Database".

The default password is "zmpass".  You may (probably should) change
this to something else, and update ZM_DB_PASS in
${PKG_SYSCONFDIR}/zm.conf.

# Other setup

See "Step 6: Set permissions", and use APACHE_GROUP.

See "Step 9: Edit Timezone in PHP".  Otherwise, access to streams will
fail.  See https://github.com/ZoneMinder/ZoneMinder/issues/1552 for
more information.
 
# Web setup

See "Step 7: Configure Apache correctly", but edit the apache config
file instead of using the not-in-pkgsrc a2enmod command.

mod_cgid is a hard requirement.  zm appears to work without rewrite
and expire.  headers is default on.  Enabling a zoneminder apache
module does not make sense.

Perhaps, one needs to use prefork instead of event. \todo Validate.

Zoneminder installs
${PREFIX}/share/examples/zoneminder/apache/zoneminder.conf, which does
two things:
  - aliases /zm to the zm main dir and /zm/cgi-bin/ to the zm cgi directory
  - allows those paths to 127.0.0.1
Either `Include` this, copy/modify and `Include`, or insert into
httpd.conf.  (You will need to adjust the IP acl if you want
off-machine access; this should be addressed upstream but does not
seem to be.)

# Upgrading from previous versions

Upgrade a database from an older version of ZoneMinder via:

  zmupdate.pl -u root [-p <password>]

NB: Before doing this ensure that $prefix/etc/conf.d exists.
Zoneminder 1.32 will attempt to remove config from the database and
place it in e.g. `/usr/pkg/etc/conf.d/zmcustom.conf`.

# Shared memory

Zoneminder tries to use a shm filesystem to store files that are then
mmap'd.  (1.28 used SysV shm but that is no longer relevant.)

On NetBSD, the compiled default might be /dev/shm but the right place
is /var/shm.  This can be changed in Options in the web interface.

(One might need a lot of space, or to turn the buffer down to fewer
frames; this is not about pkgsrc.)

Somtimes, the shm file can get into a bad state and be zero length.
This might be a bad error path during camera timeouts; it seems to
happen more with bad wifi connections.  Turning up the timeouts in the
config (e.g. wait 10s or 30s before giving up instead of 2s) probably
also helps.
