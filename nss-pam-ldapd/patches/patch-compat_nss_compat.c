$NetBSD$

Adjust FreeBSD's nss_compat.c to NetBSD.

--- compat/nss_compat.c.orig	2013-12-03 17:20:30.000000000 +0100
+++ compat/nss_compat.c	2013-12-03 18:06:25.000000000 +0100
@@ -30,19 +30,21 @@
  * SUCH DAMAGE.
  *
  * Compatibility shims for the GNU C Library-style nsswitch interface.
+ *
+ * Ported to NetBSD by Edgar Fuﬂ, Mathematisches Institut der Uni Bonn,
+ * <ef@math.uni-bonn.de>.
  */
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD$");
 
-#include "namespace.h"
 #include <sys/param.h>
 #include <errno.h>
-#include <nss.h>
 #include <pthread.h>
-#include <pthread_np.h>
-#include "un-namespace.h"
-#include "libc_private.h"
 
+#include <stdarg.h>
+#include <lwp.h>
+extern int __isthreaded;
+#define pthread_main_np() (_lwp_self() == 1)
+#include <compat/nss_compat.h>
 
 struct group;
 struct passwd;
@@ -54,26 +56,26 @@
 static void							\
 _term_create_##x(void)						\
 {								\
-	(void)_pthread_key_create(&_term_key_##x, NULL);	\
+	(void)pthread_key_create(&_term_key_##x, NULL);	\
 }								\
 static void		*_term_main_##x;			\
 static pthread_once_t	 _term_once_##x = PTHREAD_ONCE_INIT
 
 #define SET_TERMINATOR(x, y)						\
 do {									\
-	if (!__isthreaded || _pthread_main_np())			\
+	if (!__isthreaded || pthread_main_np())			\
 		_term_main_##x = (y);					\
 	else {								\
-		(void)_pthread_once(&_term_once_##x, _term_create_##x);	\
-		(void)_pthread_setspecific(_term_key_##x, y);		\
+		(void)pthread_once(&_term_once_##x, _term_create_##x);	\
+		(void)pthread_setspecific(_term_key_##x, y);		\
 	}								\
 } while (0)
 
 #define CHECK_TERMINATOR(x)					\
-(!__isthreaded || _pthread_main_np() ?				\
+(!__isthreaded || pthread_main_np() ?				\
     (_term_main_##x) :						\
-    ((void)_pthread_once(&_term_once_##x, _term_create_##x),	\
-    _pthread_getspecific(_term_key_##x)))
+    ((void)pthread_once(&_term_once_##x, _term_create_##x),	\
+    pthread_getspecific(_term_key_##x)))
 
 
 
@@ -81,98 +83,177 @@
 
 
 int
-__nss_compat_getgrnam_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getgrnam(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(const char *, struct group *, char *, size_t, int *);
+	struct group   **retval;
+	const char	*name;
+	int		 errno;
+	enum nss_status	 status;
+	static struct group grp;
+	static char buffer[BUFFER_SIZE];
+
+	fn = cbdata;
+	retval = va_arg(ap, struct group **);
+	name = va_arg(ap, const char *);
+	status = fn(name, &grp, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &grp;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getgrnam_r(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(const char *, struct group *, char *, size_t, int *);
+	int		*retval;
 	const char	*name;
 	struct group	*grp;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct group   **result;
 	enum nss_status	 status;
 
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	name = va_arg(ap, const char *);
 	grp = va_arg(ap, struct group *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(name, grp, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct group **);
+	status = fn(name, grp, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct group **)retval = grp;
+		*result = grp;
+	else
+		*result = NULL;
 	return (status);
 }
 
 
 int
-__nss_compat_getgrgid_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getgrgid(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(gid_t, struct group *, char *, size_t, int *);
+	struct group   **retval;
+	gid_t		 gid;
+	int		 errno;
+	enum nss_status	 status;
+	static struct group grp;
+	static char buffer[BUFFER_SIZE];
+	
+	fn = cbdata;
+	retval = va_arg(ap, struct group **);
+	gid = va_arg(ap, gid_t);
+	status = fn(gid, &grp, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &grp;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getgrgid_r(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(gid_t, struct group *, char *, size_t, int *);
+	int		*retval;
 	gid_t		 gid;
 	struct group	*grp;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct group   **result;
 	enum nss_status	 status;
 	
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	gid = va_arg(ap, gid_t);
 	grp = va_arg(ap, struct group *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(gid, grp, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct group **);
+	status = fn(gid, grp, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct group **)retval = grp;
+		*result = grp;
+	else
+		*result = NULL;
 	return (status);
 }
 
 
 int
-__nss_compat_getgrent_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getgrent(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(struct group *, char *, size_t, int *);
+	struct group   **retval;
+	int		  errno;
+	enum nss_status	 status;
+	static struct group grp;
+	static char buffer[BUFFER_SIZE];
+
+	fn = cbdata;
+	retval = va_arg(ap, struct group **);
+	status = fn(&grp, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &grp;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getgrent_r(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(struct group *, char *, size_t, int *);
+	int		*retval;
 	struct group	*grp;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct group   **result;
 	enum nss_status	 status;
 
 	if (CHECK_TERMINATOR(group))
 		return (NS_NOTFOUND);
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	grp = va_arg(ap, struct group *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(grp, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct group **);
+	status = fn(grp, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct group **)retval = grp;
-	else if (status != NS_RETURN)
+		*result = grp;
+	else
+		*result = NULL;
+	if (status != NS_RETURN)
 		SET_TERMINATOR(group, &terminator);
 	return (status);
 }
 
 
 int
-__nss_compat_setgrent(void *retval, void *mdata, va_list ap)
+__nss_compat_setgrent(void *cbrv, void *cbdata, va_list ap)
 {
 
 	SET_TERMINATOR(group, NULL);
-	((int (*)(void))mdata)();
+	((int (*)(void))cbdata)();
 	return (NS_UNAVAIL);
 }
 
 
 int
-__nss_compat_endgrent(void *retval, void *mdata, va_list ap)
+__nss_compat_endgrent(void *cbrv, void *cbdata, va_list ap)
 {
 
 	SET_TERMINATOR(group, NULL);
-	((int (*)(void))mdata)();
+	((int (*)(void))cbdata)();
 	return (NS_UNAVAIL);
 }
 
@@ -182,97 +263,178 @@
 
 
 int
-__nss_compat_getpwnam_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getpwnam(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(const char *, struct passwd *, char *, size_t, int *);
+	struct passwd  **retval;
+	const char	*name;
+	int		 errno;
+	enum nss_status	 status;
+	static struct passwd pwd;
+	static char buffer[BUFFER_SIZE];
+
+	fn = cbdata;
+	retval = va_arg(ap, struct passwd **);
+	name = va_arg(ap, const char *);
+	status = fn(name, &pwd, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &pwd;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getpwnam_r(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(const char *, struct passwd *, char *, size_t, int *);
+	int		*retval;
 	const char	*name;
 	struct passwd	*pwd;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct passwd  **result;
+	int		 errno;
 	enum nss_status	 status;
 
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	name = va_arg(ap, const char *);
 	pwd = va_arg(ap, struct passwd *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(name, pwd, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct passwd **);
+	status = fn(name, pwd, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct passwd **)retval = pwd;
+		*result = pwd;
+	else
+		*result = NULL;
 	return (status);
 }
 
 
 int
-__nss_compat_getpwuid_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getpwuid(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(uid_t, struct passwd *, char *, size_t, int *);
+	struct passwd  **retval;
+	uid_t		 uid;
+	int		 errno;
+	enum nss_status	 status;
+	static struct passwd pwd;
+	static char buffer[BUFFER_SIZE];
+	
+	fn = cbdata;
+	retval = va_arg(ap, struct passwd **);
+	uid = va_arg(ap, uid_t);
+	status = fn(uid, &pwd, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &pwd;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getpwuid_r(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(uid_t, struct passwd *, char *, size_t, int *);
+	int		*retval;
 	uid_t		 uid;
 	struct passwd	*pwd;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct passwd   **result;
 	enum nss_status	 status;
 	
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	uid = va_arg(ap, uid_t);
 	pwd = va_arg(ap, struct passwd *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(uid, pwd, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct passwd **);
+	retval = va_arg(ap, int *);
+	status = fn(uid, pwd, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct passwd **)retval = pwd;
+		*result = pwd;
+	else
+		*result = NULL;
 	return (status);
 }
 
 
 int
-__nss_compat_getpwent_r(void *retval, void *mdata, va_list ap)
+__nss_compat_getpwent(void *cbrv, void *cbdata, va_list ap)
+{
+	int (*fn)(struct passwd *, char *, size_t, int *);
+	struct passwd  **retval;
+	int		 errno;
+	enum nss_status	 status;
+	static struct passwd pwd;
+	static char buffer[BUFFER_SIZE];
+
+	fn = cbdata;
+	retval = va_arg(ap, struct passwd **);
+	status = fn(&pwd, buffer, sizeof buffer, &errno);
+	status = __nss_compat_result(status, errno);
+	if (status == NS_SUCCESS)
+		*retval = &pwd;
+	else
+		*retval = NULL;
+	return (status);
+}
+
+int
+__nss_compat_getpwent_r(void *cbrv, void *cbdata, va_list ap)
 {
 	int (*fn)(struct passwd *, char *, size_t, int *);
+	int		*retval;
 	struct passwd	*pwd;
 	char		*buffer;
-	int		*errnop;
 	size_t		 bufsize;
+	struct passwd  **result;
 	enum nss_status	 status;
 
 	if (CHECK_TERMINATOR(passwd))
 		return (NS_NOTFOUND);
-	fn = mdata;
+	fn = cbdata;
+	retval = va_arg(ap, int *);
 	pwd = va_arg(ap, struct passwd *);
 	buffer = va_arg(ap, char *);
 	bufsize = va_arg(ap, size_t);
-	errnop = va_arg(ap, int *);
-	status = fn(pwd, buffer, bufsize, errnop);
-	status = __nss_compat_result(status, *errnop);
+	result = va_arg(ap, struct passwd **);
+	status = fn(pwd, buffer, bufsize, retval);
+	status = __nss_compat_result(status, *retval);
 	if (status == NS_SUCCESS)
-		*(struct passwd **)retval = pwd;
-	else if (status != NS_RETURN)
+		*result = pwd;
+	else
+		*result = NULL;
+	if (status != NS_RETURN)
 		SET_TERMINATOR(passwd, &terminator);
 	return (status);
 }
 
 
 int
-__nss_compat_setpwent(void *retval, void *mdata, va_list ap)
+__nss_compat_setpwent(void *cbrv, void *cbdata, va_list ap)
 {
 
 	SET_TERMINATOR(passwd, NULL);
-	((int (*)(void))mdata)();
+	((int (*)(void))cbdata)();
 	return (NS_UNAVAIL);
 }
 
 
 int
-__nss_compat_endpwent(void *retval, void *mdata, va_list ap)
+__nss_compat_endpwent(void *cbrv, void *cbdata, va_list ap)
 {
 
 	SET_TERMINATOR(passwd, NULL);
-	((int (*)(void))mdata)();
+	((int (*)(void))cbdata)();
 	return (NS_UNAVAIL);
 }
