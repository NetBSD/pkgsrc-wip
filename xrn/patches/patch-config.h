$NetBSD$

Insert correct path for sendmail.
Extend list of OS so that system regex functions can be used on NetBSD.

--- config.h.orig	2008-11-28 19:48:24.000000000 +0000
+++ config.h
@@ -33,6 +33,7 @@
 /*
  * config.h: configurable defaults
  */
+#define CONFIG_H_IS_OK
 
 #ifndef CONFIG_H_IS_OK
 #error "You must edit config.h appropriately for your site!"
@@ -442,7 +443,7 @@
 #endif /* ! PRINTCOMMAND */
 
 #ifndef SENDMAIL
-#define SENDMAIL       "/usr/lib/sendmail -oi -t"
+#define SENDMAIL       "/usr/sbin/sendmail -oi -t"
 #endif
 /* The command to use to verify that an E-mail address is valid.  it
    should exit with status 0 if the address is valid.  It shouldn't
@@ -451,7 +452,7 @@
    If you don't want XRN to ever attempt to verify sender addresses in
    postings and messages, don't define this. */
 #ifndef SENDMAIL_VERIFY
-#define SENDMAIL_VERIFY "/usr/lib/sendmail -bv >/dev/null"
+#define SENDMAIL_VERIFY "/usr/sbin/sendmail -bv >/dev/null"
 #endif
 
 #define SAVEMODE       "normal,headers,onedir"
@@ -501,7 +502,7 @@
  */
 
 /* POSIX regex routines */
-#if defined(linux) || defined(hpux) || defined(__hpux) || defined(__osf__) || defined(__CYGWIN__)
+#if defined(linux) || defined(hpux) || defined(__hpux) || defined(__osf__) || defined(__CYGWIN__) || defined(__NetBSD__)
 #define POSIX_REGEX
 #endif
 
