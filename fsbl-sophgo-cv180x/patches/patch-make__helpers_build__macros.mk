$NetBSD$

--- make_helpers/build_macros.mk.orig	2026-03-24 12:34:00.253558669 +0000
+++ make_helpers/build_macros.mk
@@ -265,7 +265,7 @@ $(ELF): $(OBJS) $(LINKERFILE) | bl$(1)_d
 
 $(SYM): $(ELF)
 	@echo "  SYM     $$@"
-	$$(Q)$$(READELF) -s $$< | sort -b -r -g -k 3 > $$@
+	$$(Q)$$(READELF) -s $$< | gsort -b -r -g -k 3 > $$@
 
 $(DUMP): $(ELF)
 	@echo "  OD      $$@"
