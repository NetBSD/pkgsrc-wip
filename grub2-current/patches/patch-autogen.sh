$NetBSD: patch-autogen.sh,v 1.1 2013/08/12 15:02:24 gregoire Exp $

Use find(1)'s portable option -path instead of -ipath.  The latter is even
deprecated in GNU find.

--- autogen.sh.orig	2013-08-12 13:02:29.000000000 +0000
+++ autogen.sh
@@ -6,7 +6,7 @@ export LC_CTYPE=C
 export LC_COLLATE=C
 unset LC_ALL
 
-find . -iname '*.[ch]' ! -ipath './grub-core/lib/libgcrypt-grub/*' ! -ipath './build-aux/*' ! -ipath './grub-core/lib/libgcrypt/src/misc.c' ! -ipath './grub-core/lib/libgcrypt/src/global.c' ! -ipath './grub-core/lib/libgcrypt/src/secmem.c' |sort > po/POTFILES.in
+find . -iname '*.[ch]' ! -path './grub-core/lib/libgcrypt-grub/*' ! -path './build-aux/*' ! -path './grub-core/lib/libgcrypt/src/misc.c' ! -path './grub-core/lib/libgcrypt/src/global.c' ! -path './grub-core/lib/libgcrypt/src/secmem.c' |sort > po/POTFILES.in
 find util -iname '*.in' ! -name Makefile.in  |sort > po/POTFILES-shell.in
 
 autogen --version >/dev/null || exit 1
