$NetBSD: patch-Documentation_bup-index.md,v 1.1 2013/11/24 02:35:19 thomasklausner Exp $

Document --exclude-rx-from.

--- Documentation/bup-index.md.orig	2013-11-15 09:46:48.000000000 +0000
+++ Documentation/bup-index.md
@@ -10,7 +10,8 @@ bup-index - print and/or update the bup 
 
 bup index \<-p|-m|-s|-u\> [-H] [-l] [-x] [\--fake-valid] [\--no-check-device]
 [\--fake-invalid] [\--check] [\--clear] [-f *indexfile*] [\--exclude *path*]
-[\--exclude-from *filename*] [\--exclude-rx *pattern*] [-v] \<filenames...\>
+[\--exclude-from *filename*] [\--exclude-rx *pattern*]
+[\--exclude-rx-from *file*] [-v] \<filenames...\>
 
 # DESCRIPTION
 
@@ -168,6 +169,10 @@ does, due to the accommodations describe
       * '/foo/.' - exclude the content of any directory named foo
       * '^/tmp/.' - exclude root-level /tmp's content, but not /tmp itself
 
+\--exclude-rx-from=*filename*
+:   read --exclude-rx paths from *filename*, one pattern per-line (can
+    be used more than once).
+
 \--no-check-device
 :   don't mark a an entry invalid if the device number (stat(2)
     st_dev) changes.  This can be useful when indexing remote,
