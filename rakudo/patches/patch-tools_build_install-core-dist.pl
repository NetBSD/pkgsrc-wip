$NetBSD$

DESTDIR support.
https://github.com/flussence/rakudo/commit/fb00ed3d71f9407a776c82f03855d1242997878c
--- tools/build/install-core-dist.pl.orig	2015-12-25 19:23:19.000000000 +0000
+++ tools/build/install-core-dist.pl
@@ -9,7 +9,8 @@ my %provides = 
     "experimental"               => "lib/experimental.pm6",
 ;
 
-CompUnit::RepositoryRegistry.repository-for-name('perl').install(
+PROCESS::<$REPO> := CompUnit::RepositoryRegistry.repository-for-spec("inst#@*ARGS[0]");
+$*REPO.install(
     Distribution.new(
         name     => "CORE",
         auth     => "perl",
