$NetBSD$

NetBSD support

--- Makefile.PL.orig	2026-06-23 06:29:57.969257022 +0000
+++ Makefile.PL
@@ -291,6 +291,10 @@ SWITCH: {
         $MakeParams{LIBS} = "-L$FB::LIB -l$client_lib ";
         last SWITCH;
     };
+    $os eq 'netbsd' && do {
+        $MakeParams{LIBS} = "-L$FB::LIB -l$client_lib ";
+        last SWITCH;
+    };
     $os eq 'darwin' && do {
         my $framework_dir = dirname $FB::HOME; #"/Library/Frameworks/Firebird.framework";
         my $framework_name = File::Spec->catfile( $framework_dir, "Firebird");
