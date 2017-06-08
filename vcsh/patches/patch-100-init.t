$NetBSD$

Remove failing test for missing hook sample.

--- t/100-init.t.orig	2015-12-29 19:24:22.000000000 +0000
+++ t/100-init.t
@@ -39,7 +39,6 @@ ok -f 'hooks/commit-msg.sample';
 ok -f 'hooks/post-update.sample';
 ok -f 'hooks/pre-applypatch.sample';
 ok -f 'hooks/pre-commit.sample';
-ok -f 'hooks/pre-push.sample';
 ok -f 'hooks/pre-rebase.sample';
 ok -f 'hooks/prepare-commit-msg.sample';
 ok -f 'hooks/update.sample';
