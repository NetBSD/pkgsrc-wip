$NetBSD$

Workaround conflicts with system headers.

--- perl/uuid.xs.orig	2007-01-01 18:13:21.000000000 +0000
+++ perl/uuid.xs
@@ -27,12 +27,19 @@
 **  uuid.xs: Perl Binding (Perl/XS part)
 */
 
-#include "uuid.h"
+#define uuid_t		__vendor_uuid_t
+#define uuid_st		__vendor_uuid_st
+#define uuid_compare	__vendor_uuid_compare
 
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
 
+#undef uuid_t
+#undef uuid_st
+#undef uuid_compare
+#include "uuid.h"
+
 MODULE = OSSP::uuid PACKAGE = OSSP::uuid
 
 void
