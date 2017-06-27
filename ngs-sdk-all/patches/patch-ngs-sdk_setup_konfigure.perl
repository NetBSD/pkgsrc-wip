$NetBSD$

--- ngs-sdk/setup/konfigure.perl.orig	2015-11-23 18:38:45.000000000 +0000
+++ ngs-sdk/setup/konfigure.perl
@@ -198,14 +198,14 @@ print "checking system type... " unless
 my ($OS, $ARCH, $OSTYPE, $MARCH, @ARCHITECTURES) = OsArch();
 println $OSTYPE unless ($AUTORUN);
 
-unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
+unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win' || $OSTYPE eq 'NetBSD') {
     println "configure: error: unsupported system '$OSTYPE'";
     exit 1;
 }
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i) {
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH =~ /amd64/i) {
     println "configure: error: unsupported architecture '$OSTYPE'";
     exit 1;
 }
@@ -300,6 +300,8 @@ if ($MARCH =~ /x86_64/i) {
     $BITS = '32_64';
 } elsif ($MARCH =~ /i?86/i) {
     $BITS = 32;
+} elsif ($MARCH =~ /amd64/i) {
+    $BITS = 64;
 } else {
     die "unrecognized Architecture '$ARCH'";
 }
@@ -329,6 +331,15 @@ if ($OSTYPE =~ /linux/i) {
     $TOOLS = 'clang' unless ($TOOLS);
 } elsif ($OSTYPE eq 'win') {
     $TOOLS = 'vc++';
+} elsif ($OSTYPE =~ /NetBSD/i) {
+    $LPFX = 'lib';
+    $OBJX = 'o';
+    $LOBX = 'pic.o';
+    $LIBX = 'a';
+    $SHLX = 'so';
+    $EXEX = '';
+    $OSINC = 'unix';
+    $TOOLS = 'gcc' unless ($TOOLS);
 } else {
     die "unrecognized OS '$OSTYPE'";
 }
