$NetBSD$

Gracefully handle subtleties of util_expand() of `~' and `~user'.

When `~' is expanded to an home directory without any user, g_get_home_dir()
function is used that on Unix systems first try to honor HOME and fall back to
the passwd file if not set.

On the other hand, `~user' is expanded always by checking the passwd
file, adjust test_expand_tilde_user() accordingly.

Patch shared upstream via:

 <https://github.com/fanglingsu/vimb/pull/524>

--- tests/test-util.c.orig	2018-09-25 22:49:33.000000000 +0000
+++ tests/test-util.c
@@ -17,6 +17,7 @@
  * along with this program. If not, see http://www.gnu.org/licenses/.
  */
 
+#include <pwd.h>
 #include <gtk/gtk.h>
 #include <src/util.h>
 
@@ -88,9 +89,15 @@ static void test_expand_tilde_home(void)
 static void test_expand_tilde_user(void)
 {
     State state = {0};
-    const char *home = g_get_home_dir();
     const char *user = g_get_user_name();
+    const char *home;
     char *in, *out;
+    struct passwd *pwd;
+
+    /* initialize home */
+    pwd = getpwnam(user);
+    g_assert_nonnull(pwd);
+    home = pwd->pw_dir;
 
     /* don't expand within words */
     in = g_strdup_printf("foo~%s/bar", user);
