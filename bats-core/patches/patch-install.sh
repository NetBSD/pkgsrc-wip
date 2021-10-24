$NetBSD$

Change manpages installation directory.

--- install.sh.orig	2021-10-22 08:06:36.000000000 +0000
+++ install.sh
@@ -13,11 +13,11 @@ if [[ -z "$PREFIX" ]]; then
   exit 1
 fi
 
-install -d -m 755 "$PREFIX"/{bin,libexec/bats-core,"${LIBDIR}"/bats-core,share/man/man{1,7}}
+install -d -m 755 "$PREFIX"/{bin,libexec/bats-core,"${LIBDIR}"/bats-core,"$PKGMANDIR"/man{1,7}}
 install -m 755 "$BATS_ROOT/bin"/* "$PREFIX/bin"
 install -m 755 "$BATS_ROOT/libexec/bats-core"/* "$PREFIX/libexec/bats-core"
 install -m 755 "$BATS_ROOT/lib/bats-core"/* "$PREFIX/${LIBDIR}/bats-core"
-install -m 644 "$BATS_ROOT/man/bats.1" "$PREFIX/share/man/man1"
-install -m 644 "$BATS_ROOT/man/bats.7" "$PREFIX/share/man/man7"
+install -m 644 "$BATS_ROOT/man/bats.1" "$PREFIX/$PKGMANDIR/man1"
+install -m 644 "$BATS_ROOT/man/bats.7" "$PREFIX/$PKGMANDIR/man7"
 
 echo "Installed Bats to $PREFIX/bin/bats"
