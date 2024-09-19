$NetBSD$

Avoid a:

 TypeError: user() takes exactly 2 arguments (1 given)

Both github3.GitHub.user() and github3.GitHubEnterprise.user() functions need
the `username' argument.

--- lib/gitspindle/github.py.orig	2017-12-21 19:05:09.000000000 +0000
+++ lib/gitspindle/github.py
@@ -84,7 +84,7 @@ class GitHub(GitSpindle):
             err("No user or token specified")
         self.gh.login(username=user, token=token)
         try:
-            self.me = self.gh.user()
+            self.me = self.gh.user(user)
             self.my_login = self.me.login
         except github3.GitHubError:
             # Token obsolete
