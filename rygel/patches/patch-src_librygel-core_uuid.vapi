$NetBSD: patch-src_librygel-core_uuid.vapi,v 1.1 2012/12/03 20:51:43 thomasklausner Exp $

Use BSD uuid functions instead of Linux ones.

--- src/librygel-core/uuid.vapi.orig	2012-11-13 13:28:32.000000000 +0000
+++ src/librygel-core/uuid.vapi
@@ -1,4 +1,4 @@
-[CCode (cheader_filename = "uuid/uuid.h")]
+[CCode (cheader_filename = "uuid.h")]
 namespace UUID {
     public static void generate ([CCode (array_length = false)] uchar[] uuid);
     public static void unparse ([CCode (array_length = false)] uchar[] uuid,
