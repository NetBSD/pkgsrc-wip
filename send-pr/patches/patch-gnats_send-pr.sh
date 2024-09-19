$NetBSD$

'sysconfdir' is a macro to be replaced during build, not a shell variable

Use build mechanism to provide full path to install-sid (in case base
has one, too)

Add placeholders to be substituted in mail template

--- gnats/send-pr.sh.orig	2015-02-26 04:26:41.000000000 +0000
+++ gnats/send-pr.sh
@@ -76,7 +76,7 @@ MAILADDR="bugs"
 # Configuration file to be read.  It must be a shell script that can redefine
 # the variables above to fit a local configuration.  It reads the system config
 # file first, then the personal config file.
-CONFIGFILES="${sysconfdir}/gnats/send-pr.conf ${HOME}/.send-pr.conf"
+CONFIGFILES="@sysconfdir@/gnats/send-pr.conf ${HOME}/.send-pr.conf"
 for CONFIGFILE in ${CONFIGFILES}; do
   if [ -r ${CONFIGFILE} ]; then
     . ${CONFIGFILE}
@@ -276,12 +276,12 @@ if [ "x$SUBMITTER" = "xunknown" -a -z "$
 It seems that send-pr is not installed with your unique submitter-id,
 or that "unknown" has been specified.  You need to run:
 
-          install-sid YOUR-SID
+          @bindir@/install-sid YOUR-SID
 
 where YOUR-SID is the identification code you received with `send-pr'.
 `send-pr' will automatically insert this value into the template field
 `>Submitter-Id'.  If you've downloaded `send-pr' from the Net, use `net'
-for this value.  If you do not know your id, run `send-pr --request-id'
+for this value.  If you do not know your id, run `@bindir@/send-pr --request-id'
 to get one from your support site.
 __EOF__
   exit 1
@@ -322,7 +322,7 @@ else
   fi
 
   if [ -n "$TEMPLATE" -a -z "$PRINT_INTERN" ]; then
-    sed "s/<FROM>/$FROM/;s/<REPLYTO>/$REPLYTO/;s/<DEFAULT_ORIGINATOR>/$DEFAULT_ORIGINATOR/;s/<SUBMITTER>/$DEFAULT_SUBMITTERID/" < $TEMPLATE > $TEMP ||
+    sed "s/<MAILADDR>/$MAILADDR/;s/<FROM>/$FROM/;s/<REPLYTO>/$REPLYTO/;s/<VERSION>/$VERSION/;s/<DEFAULT_ORIGINATOR>/$DEFAULT_ORIGINATOR/;s/<SUBMITTER>/$DEFAULT_SUBMITTERID/;s/<DEFAULT_ORGANIZATION>/$DEFAULT_ORGANIZATION/;s/<DEFAULT_RELEASE>/$DEFAULT_RELEASE/;s/<SYSTEM>/$SYSTEM/;s/<ARCH>/$ARCH/;s/<MACHINE>/$MACHINE/" < $TEMPLATE > $TEMP ||
       { echo >&2 "$COMMAND: could not copy $TEMPLATE" ; xs=1; exit; }
     if [ -z "${SENDPR_CLEANUP+set}" ]; then
       # build a cleanup sed script to schedule the removal of comments
