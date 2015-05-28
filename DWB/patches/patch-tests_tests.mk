$NetBSD: patch-tests_tests.mk,v 1.1 2015/05/28 11:00:49 n-t-roff Exp $

Propagate make error

--- tests/tests.mk.orig	2015-05-18 16:21:17.000000000 +0200
+++ tests/tests.mk	2015-05-18 16:21:28.000000000 +0200
@@ -44,7 +44,7 @@
 	if [ -d $@ -a -f $@/$@.mk ]; then \
 	    cd $@; \
 	    echo "---- Making $(ACTION) in directory $(CURRENTDIR)/$@ ----"; \
-	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION); \
+	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION) && \
 	    echo; \
 	fi
 
