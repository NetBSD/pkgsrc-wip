$NetBSD: patch-testtools_CustomTarget_uno_test.mk,v 1.1 2012/07/28 13:00:30 ftigeot Exp $

Add a LD_LIBRARY_PATH statement along the line of CustomTarget_bridgetest.mk
Without it, the test failed with the uno binary unable to find needed shared
libraries such as libuno_cppu.so.3 .

--- testtools/CustomTarget_uno_test.mk.orig	2012-07-17 12:02:12.000000000 +0000
+++ testtools/CustomTarget_uno_test.mk
@@ -34,11 +34,12 @@ $(call gb_CustomTarget_get_target,testto
 		$(call gb_Executable_get_target_for_build,uno) \
 		$(call gb_InternalUnoApi_get_target,bridgetest)
 	$(call gb_Helper_abbreviate_dirs,\
-		$(call gb_Executable_get_target_for_build,uno) \
-		-ro $(OUTDIR)/xml/uno_services.rdb \
-		-ro $(OUTDIR)/bin/udkapi.rdb \
-		-ro $(WORKDIR)/UnoApiTarget/bridgetest.rdb \
-		-s com.sun.star.test.bridge.BridgeTest \
-		-- com.sun.star.test.bridge.CppTestObject)
+		echo "LD_LIBRARY_PATH=$(OUTDIR)/lib" \
+		"$(call gb_Executable_get_target_for_build,uno)" \
+		"-ro $(OUTDIR)/xml/uno_services.rdb" \
+		"-ro $(OUTDIR)/bin/udkapi.rdb" \
+		"-ro $(WORKDIR)/UnoApiTarget/bridgetest.rdb" \
+		"-s com.sun.star.test.bridge.BridgeTest" \
+		"-- com.sun.star.test.bridge.CppTestObject")
 
 # vim:set shiftwidth=4 tabstop=4 noexpandtab:
