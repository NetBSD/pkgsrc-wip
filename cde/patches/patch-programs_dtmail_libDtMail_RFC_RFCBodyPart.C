$NetBSD: patch-programs_dtmail_libDtMail_RFC_RFCBodyPart.C,v 1.1 2012/10/04 04:57:03 jellehermsen Exp $

--- programs/dtmail/libDtMail/RFC/RFCBodyPart.C.orig	2012-09-29 12:06:20.000000000 +0000
+++ programs/dtmail/libDtMail/RFC/RFCBodyPart.C
@@ -1030,7 +1030,7 @@ char *from_cs, char *to_cs)
    DtMailEnv error;
    iconv_t cd;
    size_t ileft = (size_t) bp_len, oleft = (size_t) bp_len, ret = 0;
-#if defined(_aix) || defined(sun) || defined(__FreeBSD__)
+#if defined(_aix) || defined(sun) || defined(CSRG_BASED)
    const char *ip = (const char *) *bp;
 #else
    char *ip = *bp;
