$NetBSD$

* illumos can't choose std::pow overload, be explicit 

--- examples/message_passing/fan_out_request.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ examples/message_passing/fan_out_request.cpp
@@ -137,7 +137,7 @@ void caf_main(actor_system& sys) {
   //      4    16    64   256  1024  4096
   for (int row = 0; row < rows; ++row)
     for (int column = 0; column < columns; ++column)
-      f(put_atom_v, row, column, (int) pow(row + 2, column + 1));
+      f(put_atom_v, row, column, (int) pow((float)(row + 2), column + 1));
   // Print out matrix.
   for (int row = 0; row < rows; ++row) {
     for (int column = 0; column < columns; ++column)
