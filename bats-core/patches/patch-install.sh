$NetBSD$

Change manpages installation directory.

--- install.sh.orig	2020-12-05 05:08:52.331014166 +0000
+++ install.sh
@@ -12,11 +12,11 @@ if [[ -z "$PREFIX" ]]; then
   exit 1
 fi
 
-install -d -m 755 "$PREFIX"/{bin,libexec/bats-core,lib/bats-core,share/man/man{1,7}}
+install -d -m 755 "$PREFIX"/{bin,libexec/bats-core,lib/bats-core,$PKGMANDIR/man{1,7}}
 install -m 755 "$BATS_ROOT/bin"/* "$PREFIX/bin"
 install -m 755 "$BATS_ROOT/libexec/bats-core"/* "$PREFIX/libexec/bats-core"
 install -m 755 "$BATS_ROOT/lib/bats-core"/* "$PREFIX/lib/bats-core"
-install -m 644 "$BATS_ROOT/man/bats.1" "$PREFIX/share/man/man1"
-install -m 644 "$BATS_ROOT/man/bats.7" "$PREFIX/share/man/man7"
+install -m 644 "$BATS_ROOT/man/bats.1" "$PREFIX/$PKGMANDIR/man1"
+install -m 644 "$BATS_ROOT/man/bats.7" "$PREFIX/$PKGMANDIR/man7"
 
 echo "Installed Bats to $PREFIX/bin/bats"
