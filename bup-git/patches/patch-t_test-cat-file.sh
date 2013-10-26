$NetBSD: patch-t_test-cat-file.sh,v 1.1 2013/10/26 23:21:09 thomasklausner Exp $

NetBSD's cmp does not support -b; use -l instead.

--- t/test-cat-file.sh.orig	2013-10-26 23:10:28.000000000 +0000
+++ t/test-cat-file.sh
@@ -34,6 +34,6 @@ src_hash=$(bup ls -s "src/latest/$(pwd)"
 bupm_hash=$(git ls-tree "$src_hash" | grep -F .bupm | cut -d' ' -f 3)
 bupm_hash=$(echo "$bupm_hash" | cut -d'	' -f 1)
 git cat-file blob "$bupm_hash" > git-cat-bupm
-WVPASS cmp -b git-cat-bupm bup-cat-bupm
+WVPASS cmp -l git-cat-bupm bup-cat-bupm
 
 rm -rf "$tmpdir"
