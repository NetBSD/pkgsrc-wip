$NetBSD$

--- components/autofill/core/browser/address_rewriter.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/autofill/core/browser/address_rewriter.cc
@@ -10,7 +10,11 @@
 #include "base/i18n/case_conversion.h"
 #include "base/memory/singleton.h"
 #include "base/strings/utf_string_conversions.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace autofill {
 namespace {
