$NetBSD$

--- posix.mak.orig	2020-08-15 09:49:13.000000000 +0000
+++ posix.mak
@@ -57,9 +57,9 @@ install:
 else
 install: all
 	$(MAKE) INSTALL_DIR=$(INSTALL_DIR) -C src -f posix.mak install
-	cp -r samples $(INSTALL_DIR)
-	mkdir -p $(INSTALL_DIR)/man
-	cp -r docs/man/* $(INSTALL_DIR)/man/
+	#cp -r samples $(INSTALL_DIR)
+	mkdir -p $(INSTALL_DIR)/share/man
+	cp -r docs/man/* $(INSTALL_DIR)/share/man/
 endif
 
 # Checks that all files have been committed and no temporary, untracked files exist.
