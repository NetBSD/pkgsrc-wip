$NetBSD$

Take the usual pkgsrc LDFLAGS into account.

--- rules.mk.orig	2026-09-23 18:19:45.433257025 +0000
+++ rules.mk
@@ -7,12 +7,12 @@
 $(rastertoqpdl_TARGET): $(rastertoqpdl_OBJ)
 	$(call printCmd, $(cmd_link))
 	$(Q)g++ -o $@ $^ $(rastertoqpdl_CXXFLAGS) $(rastertoqpdl_LDFLAGS) \
-		$(rastertoqpdl_LIBS)
+		$(rastertoqpdl_LIBS) $(LDFLAGS)
 
 $(pstoqpdl_TARGET): $(pstoqpdl_OBJ)
 	$(call printCmd, $(cmd_link))
 	$(Q)g++ -o $@ $^ $(pstoqpdl_CXXFLAGS) $(pstoqpdl_LDFLAGS) \
-		$(pstoqpdl_LIBS)
+		$(pstoqpdl_LIBS) $(LDFLAGS)
 
 .PHONY: install installcms
 cmd_install_raster	= INSTALL           $(rastertoqpdl_TARGET)
