$NetBSD$

--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/autofill/content/renderer/password_form_conversion_utils.cc
@@ -25,7 +25,11 @@
 #include "third_party/WebKit/public/web/WebFormControlElement.h"
 #include "third_party/WebKit/public/web/WebFrame.h"
 #include "third_party/WebKit/public/web/WebInputElement.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using blink::WebDocument;
 using blink::WebFormControlElement;
