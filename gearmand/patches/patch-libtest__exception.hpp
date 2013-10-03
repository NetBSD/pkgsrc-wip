$NetBSD: patch-libtest__exception.hpp,v 1.1 2013/10/03 00:37:54 genolopolis Exp $

--- libtest/exception.hpp-orig	2013-10-02 23:53:23.000000000 +0000
+++ libtest/exception.hpp
@@ -33,7 +33,7 @@
  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  */
-
+#include <cstdarg>
 #pragma once
 
 namespace libtest {
