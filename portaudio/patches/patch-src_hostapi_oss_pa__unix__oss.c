$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.1 2013/05/08 23:57:17 othyro Exp $

Include audioio.h for NetBSD.

--- src/hostapi/oss/pa_unix_oss.c.orig	2011-05-02 17:07:11.000000000 +0000
+++ src/hostapi/oss/pa_unix_oss.c
@@ -66,6 +66,7 @@
 #ifdef HAVE_SYS_SOUNDCARD_H
 # include <sys/soundcard.h>
 # ifdef __NetBSD__
+#  include <sys/audioio.h>
 #  define DEVICE_NAME_BASE           "/dev/audio"
 # else
 #  define DEVICE_NAME_BASE           "/dev/dsp"
