$NetBSD: patch-t_test-cat-file.sh,v 1.2 2013/11/02 00:15:37 thomasklausner Exp $

test-cat-file.sh: use -l instead of -b; explain differences.

It turns out that cmp -b doesn't work on at least NetBSD, so use -l
instead, and when there's a problem, diff the "bup meta" output as
well.

Thanks to Thomas Klausner <tk@giga.or.at> for the report.

Signed-off-by: Rob Browning <rlb@defaultvalue.org>

--- t/test-cat-file.sh.orig	2013-11-02 00:00:52.000000000 +0000
+++ t/test-cat-file.sh
@@ -34,6 +34,10 @@ src_hash=$(bup ls -s "src/latest/$(pwd)"
 bupm_hash=$(git ls-tree "$src_hash" | grep -F .bupm | cut -d' ' -f 3)
 bupm_hash=$(echo "$bupm_hash" | cut -d'	' -f 1)
 git cat-file blob "$bupm_hash" > git-cat-bupm
-WVPASS cmp -b git-cat-bupm bup-cat-bupm
+if ! cmp git-cat-bupm bup-cat-bupm; then
+    cmp -l git-cat-bupm bup-cat-bupm
+    diff -uN <(bup meta -tvvf git-cat-bupm) <(bup meta -tvvf bup-cat-bupm)
+    WVPASS cmp git-cat-bupm bup-cat-bupm
+fi
 
 rm -rf "$tmpdir"
