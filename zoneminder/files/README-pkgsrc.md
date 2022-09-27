# Introduction

This is a local pkgsrc README for the zoneminder package.  It attempts
not to duplicate the upstream documentation.

# jpeg implementation

ZoneMinder benefits dramatically from using libjpeg-turbo.  Consider
setting that as default in mk.conf, and rebuilding *everything*, via
`JPEG_DEFAULT=libjpeg-turbo`.

# Initial database creation

To get ZoneMinder started a MySQL database is required.

First, create a MySQL user "zmuser":

echo "create user 'zmuser'@'localhost' identified by 'zmpass';" | mysql -u root

The default password is "zmpass".  You may change this to something else, and
update ZM_DB_PASS in ${PKG_SYSCONFDIR}/zm.conf.

Create the initial database via:

  mysql -u root < ${PREFIX}/share/zoneminder/db/zm_create.sql

Assign rights to the "zmuser" user via:

  echo "grant all on * to 'zmuser';" | mysql -u root zm

# Upgrading from previous versions

Upgrade a database from an older version of ZoneMinder via:

  zmupdate.pl -u root [-p <password>]

# web setup

To enable the web interface via Apache, add the following line to httpd.conf:

  Include ${PREFIX}/share/examples/zoneminder/apache/zoneminder.conf

PHP may log warnings if the PHP date.timezone configuration is not
set.  Consider assigning a default system time zone to date.timezone
in ${PKG_SYSCONFDIR}/php.ini.  [This paragraph might be old advice.]

# Shared memory

With 1.30, zoneminder tries to use a shm filesystem to store files
that are then mmap'd, instead of system V shm.

On NetBSD, the default might be /dev/shm but the right place is
/var/shm.  This can be changed in Options in the web interface.

One might need a lot of space, or to turn the buffer down to fewer frames.

Somtimes, the shm file can get into a bad state and be zero length.
This might be a bad error path during camera timeouts; it seems to
happen more with bad wifi connections.  Turning up the timeouts in the
config (e.g. wait 10s or 30s before giving up instead of 2s) probably
also helps.
