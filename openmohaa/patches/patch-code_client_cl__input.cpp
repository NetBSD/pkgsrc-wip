$NetBSD$

The code mixes C++ and C (math.h), ensure that isfinite resolves correctly.

--- code/client/cl_input.cpp.orig	2024-12-27 09:20:15.514136633 +0000
+++ code/client/cl_input.cpp
@@ -47,6 +47,7 @@ at the same time.
 ===============================================================================
 */
 
+using std::isfinite;
 
 kbutton_t	in_left, in_right, in_forward, in_back;
 kbutton_t	in_lookup, in_lookdown, in_moveleft, in_moveright;
