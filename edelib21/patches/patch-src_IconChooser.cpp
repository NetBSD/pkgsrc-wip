$NetBSD$

Add missing header for free().

--- src/IconChooser.cpp.orig	2014-06-21 21:24:07.000000000 +0000
+++ src/IconChooser.cpp
@@ -18,6 +18,8 @@
  * along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <cstdlib>
+
 #include <FL/Fl_Double_Window.H>
 #include <FL/Fl.H>
 #include <FL/Fl_Button.H>
