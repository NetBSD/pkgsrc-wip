$NetBSD$

	Simplify UF_NODUMP test

--- core/src/findlib/find_one.cc.orig	2019-01-19 23:50:10.325582240 +0000
+++ core/src/findlib/find_one.cc
@@ -209,7 +209,7 @@ static bool VolumeHasAttrlist(const char
  */
 static inline bool no_dump(JobControlRecord *jcr, FindFilesPacket *ff_pkt)
 {
-#if defined(HAVE_CHFLAGS) && defined(UF_NODUMP)
+#if defined(UF_NODUMP)
    if (BitIsSet(FO_HONOR_NODUMP, ff_pkt->flags) &&
        (ff_pkt->statp.st_flags & UF_NODUMP) ) {
       Jmsg(jcr, M_INFO, 1, _("     NODUMP flag set - will not process %s\n"),
