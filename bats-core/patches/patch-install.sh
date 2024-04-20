$NetBSD$

Change manpages installation directory.

--- install.sh.orig	2024-03-24 15:01:17.000000000 +0000
+++ install.sh
@@ -14,13 +14,13 @@ if [[ -z "$PREFIX" ]]; then
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
 
 read -rd '' BATS_EXE_CONTENTS <"$PREFIX/bin/bats" || true
 BATS_EXE_CONTENTS=${BATS_EXE_CONTENTS/"BATS_BASE_LIBDIR=lib"/"BATS_BASE_LIBDIR=${LIBDIR}"}
