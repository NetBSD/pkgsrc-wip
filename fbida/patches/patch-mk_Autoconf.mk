$NetBSD$

Fix backslashed character.

--- mk/Autoconf.mk.orig	2021-06-25 20:43:29.271325608 +0000
+++ mk/Autoconf.mk
@@ -56,7 +56,7 @@ ac_uname_arch = $(shell \
 # args: header file
 ac_header = $(shell \
 	$(call ac_init,for $(1));\
-	$(call ac_b_cmd,echo '\#include <$(1)>' |\
+	$(call ac_b_cmd,echo '#include <$(1)>' |\
 		$(CC) $(CFLAGS) -E -);\
 	$(call ac_fini))
 
