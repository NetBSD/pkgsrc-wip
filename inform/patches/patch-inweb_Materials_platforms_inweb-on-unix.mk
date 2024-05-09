$NetBSD$

Generated file.
https://github.com/ganelson/inweb/pull/45

--- inweb/Materials/platforms/inweb-on-unix.mk.orig	2022-08-20 10:02:58.000000000 +0000
+++ inweb/Materials/platforms/inweb-on-unix.mk
@@ -70,7 +70,7 @@ safe:
 
 define make-me-once-tangled
 	clang -std=c11 -c $(MANYWARNINGS) $(CCOPTS) -g  -o $(ME)/Tangled/$(ME).o $(ME)/Tangled/$(ME).c
-	clang  -lm -lpthread -static -g -o $(ME)/Tangled/$(ME)$(EXEEXTENSION) $(ME)/Tangled/$(ME).o 
+	clang  -static -g -o $(ME)/Tangled/$(ME)$(EXEEXTENSION) $(ME)/Tangled/$(ME).o -lm -lpthread 
 endef
 
 define make-me
