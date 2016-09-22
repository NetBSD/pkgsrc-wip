$NetBSD$

--- dba/create-database.sh.orig	2015-11-12 14:35:57.000000000 +0000
+++ dba/create-database.sh
@@ -12,7 +12,8 @@ INSTALL_NOTE_FN="`mktemp -t tmp.XXXXXXXX
 
 
 # Candidate locations of the AWL directory
-awldirs="${DBADIR}/../../awl
+awldirs="@LIBAWLPATH@
+${DBADIR}/../../awl
 /usr/share/awl
 /usr/share/php/awl
 /usr/local/share/awl"
@@ -182,7 +183,7 @@ rm "${INSTALL_NOTE_FN}"
 cat <<FRIENDLY
 *  The password for the 'admin' user has been set to '${ADMINPW}'
 
-Thanks for trying DAViCal!  Check in /usr/share/doc/davical/examples/ for
+Thanks for trying DAViCal!  Check in @EGDIRCONFIG@/ for
 some configuration examples.  For help, visit #davical on irc.oftc.net.
 
 FRIENDLY
