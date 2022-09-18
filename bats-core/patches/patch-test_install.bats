$NetBSD$

Use $PKGMANDIR to check installation of man files.

--- test/install.bats.orig	2022-09-14 23:35:50.000000000 +0000
+++ test/install.bats
@@ -29,8 +29,8 @@ setup() {
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-format-junit" ]
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-format-pretty" ]
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-preprocess" ]
-  [ -f "$INSTALL_DIR/share/man/man1/bats.1" ]
-  [ -f "$INSTALL_DIR/share/man/man7/bats.7" ]
+  [ -f "$INSTALL_DIR/$PKGMANDIR/man1/bats.1" ]
+  [ -f "$INSTALL_DIR/$PKGMANDIR/man7/bats.7" ]
 
   reentrant_run "$INSTALL_DIR/bin/bats" -v
   [ "$status" -eq 0 ]
@@ -52,8 +52,8 @@ setup() {
   [ ! -x "$INSTALL_DIR/libexec/bats-core/bats-format-pretty" ]
   [ ! -x "$INSTALL_DIR/libexec/bats-core/bats-preprocess" ]
   [ ! -x "$INSTALL_DIR/libexec/bats-core" ]
-  [ ! -x "$INSTALL_DIR/share/man/man1/bats.1" ]
-  [ ! -x "$INSTALL_DIR/share/man/man7/bats.7" ]
+  [ ! -x "$INSTALL_DIR/$PKGMANDIR/man1/bats.1" ]
+  [ ! -x "$INSTALL_DIR/$PKGMANDIR/man7/bats.7" ]
 }
 
 @test "install.sh creates a multilib valid installation, and uninstall.sh undos it" {
@@ -75,8 +75,8 @@ setup() {
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-format-junit" ]
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-format-pretty" ]
   [ -x "$INSTALL_DIR/libexec/bats-core/bats-preprocess" ]
-  [ -f "$INSTALL_DIR/share/man/man1/bats.1" ]
-  [ -f "$INSTALL_DIR/share/man/man7/bats.7" ]
+  [ -f "$INSTALL_DIR/$PKGMANDIR/man1/bats.1" ]
+  [ -f "$INSTALL_DIR/$PKGMANDIR/man7/bats.7" ]
 
   reentrant_run "$INSTALL_DIR/bin/bats" -v
   [ "$status" -eq 0 ]
@@ -98,8 +98,8 @@ setup() {
   [ ! -x "$INSTALL_DIR/libexec/bats-core/bats-format-pretty" ]
   [ ! -x "$INSTALL_DIR/libexec/bats-core/bats-preprocess" ]
   [ ! -x "$INSTALL_DIR/libexec/bats-core" ]
-  [ ! -x "$INSTALL_DIR/share/man/man1/bats.1" ]
-  [ ! -x "$INSTALL_DIR/share/man/man7/bats.7" ]
+  [ ! -x "$INSTALL_DIR/$PKGMANDIR/man1/bats.1" ]
+  [ ! -x "$INSTALL_DIR/$PKGMANDIR/man7/bats.7" ]
 }
 
 @test "uninstall.sh works even if nothing is installed" {
