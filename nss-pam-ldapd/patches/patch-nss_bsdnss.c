$NetBSD$

NetBSD does not have __nss_compat_xxx functions in its C library.
It also need non-_r variants.

--- nss/bsdnss.c.orig	2018-09-01 09:09:35.000000000 +0000
+++ nss/bsdnss.c
@@ -46,21 +46,27 @@ struct name_list {
 NSS_METHOD_PROTOTYPE(__nss_compat_getgrnam_r);
 NSS_METHOD_PROTOTYPE(__nss_compat_getgrgid_r);
 NSS_METHOD_PROTOTYPE(__nss_compat_getgrent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrent);
 NSS_METHOD_PROTOTYPE(__nss_compat_setgrent);
 NSS_METHOD_PROTOTYPE(__nss_compat_endgrent);
-NSS_METHOD_PROTOTYPE(__freebsd_getgroupmembership);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrnam);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrgid);
+NSS_METHOD_PROTOTYPE(__netbsd_getgroupmembership);
 
 NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam_r);
 NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid_r);
 NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwent);
 NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
 NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid);
 
 NSS_METHOD_PROTOTYPE(__nss_compat_gethostbyname);
-NSS_METHOD_PROTOTYPE(__nss_compat_gethostbyname2);
 NSS_METHOD_PROTOTYPE(__nss_compat_gethostbyaddr);
 
 NSS_METHOD_PROTOTYPE(__nss_compat_getnetgrent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getnetgrent);
 NSS_METHOD_PROTOTYPE(__nss_compat_setnetgrent);
 NSS_METHOD_PROTOTYPE(__nss_compat_endnetgrent);
 
@@ -68,33 +74,45 @@ static ns_mtab methods[] = {
   { NSDB_GROUP, "getgrnam_r", __nss_compat_getgrnam_r, (void *)NSS_NAME(getgrnam_r) },
   { NSDB_GROUP, "getgrgid_r", __nss_compat_getgrgid_r, (void *)NSS_NAME(getgrgid_r) },
   { NSDB_GROUP, "getgrent_r", __nss_compat_getgrent_r, (void *)NSS_NAME(getgrent_r) },
+  { NSDB_GROUP, "getgrent",   __nss_compat_getgrent,   (void *)NSS_NAME(getgrent_r) },
   { NSDB_GROUP, "setgrent",   __nss_compat_setgrent,   (void *)NSS_NAME(setgrent) },
   { NSDB_GROUP, "endgrent",   __nss_compat_endgrent,   (void *)NSS_NAME(endgrent) },
-  { NSDB_GROUP, "getgroupmembership", __freebsd_getgroupmembership, NULL },
+  { NSDB_GROUP, "getgrnam",   __nss_compat_getgrnam,   (void *)NSS_NAME(getgrnam_r) },
+  { NSDB_GROUP, "getgrgid",   __nss_compat_getgrgid,   (void *)NSS_NAME(getgrgid_r) },
+  { NSDB_GROUP, "getgroupmembership", __netbsd_getgroupmembership, NULL },
 
   { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, (void *)NSS_NAME(getpwnam_r) },
   { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, (void *)NSS_NAME(getpwuid_r) },
   { NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, (void *)NSS_NAME(getpwent_r) },
+  { NSDB_PASSWD, "getpwent",   __nss_compat_getpwent,   (void *)NSS_NAME(getpwent_r) },
   { NSDB_PASSWD, "setpwent",   __nss_compat_setpwent,   (void *)NSS_NAME(setpwent) },
   { NSDB_PASSWD, "endpwent",   __nss_compat_endpwent,   (void *)NSS_NAME(endpwent) },
+  { NSDB_PASSWD, "getpwnam",   __nss_compat_getpwnam,   (void *)NSS_NAME(getpwnam_r) },
+  { NSDB_PASSWD, "getpwuid",   __nss_compat_getpwuid,   (void *)NSS_NAME(getpwuid_r) },
 
   { NSDB_HOSTS, "gethostbyname",  __nss_compat_gethostbyname,  (void *)NSS_NAME(gethostbyname_r) },
   { NSDB_HOSTS, "gethostbyaddr",  __nss_compat_gethostbyaddr,  (void *)NSS_NAME(gethostbyaddr_r) },
-  { NSDB_HOSTS, "gethostbyname2", __nss_compat_gethostbyname2, (void *)NSS_NAME(gethostbyname2_r) },
 
   { NSDB_GROUP_COMPAT, "getgrnam_r", __nss_compat_getgrnam_r, (void *)NSS_NAME(getgrnam_r) },
   { NSDB_GROUP_COMPAT, "getgrgid_r", __nss_compat_getgrgid_r, (void *)NSS_NAME(getgrgid_r) },
   { NSDB_GROUP_COMPAT, "getgrent_r", __nss_compat_getgrent_r, (void *)NSS_NAME(getgrent_r) },
+  { NSDB_GROUP_COMPAT, "getgrent",   __nss_compat_getgrent,   (void *)NSS_NAME(getgrent_r) },
   { NSDB_GROUP_COMPAT, "setgrent",   __nss_compat_setgrent,   (void *)NSS_NAME(setgrent) },
   { NSDB_GROUP_COMPAT, "endgrent",   __nss_compat_endgrent,   (void *)NSS_NAME(endgrent) },
+  { NSDB_GROUP_COMPAT, "getgrnam",   __nss_compat_getgrnam,   (void *)NSS_NAME(getgrnam_r) },
+  { NSDB_GROUP_COMPAT, "getgrgid",   __nss_compat_getgrgid,   (void *)NSS_NAME(getgrgid_r) },
 
   { NSDB_PASSWD_COMPAT, "getpwnam_r", __nss_compat_getpwnam_r, (void *)NSS_NAME(getpwnam_r) },
   { NSDB_PASSWD_COMPAT, "getpwuid_r", __nss_compat_getpwuid_r, (void *)NSS_NAME(getpwuid_r) },
   { NSDB_PASSWD_COMPAT, "getpwent_r", __nss_compat_getpwent_r, (void *)NSS_NAME(getpwent_r) },
+  { NSDB_PASSWD_COMPAT, "getpwent",   __nss_compat_getpwent,   (void *)NSS_NAME(getpwent_r) },
   { NSDB_PASSWD_COMPAT, "setpwent",   __nss_compat_setpwent,   (void *)NSS_NAME(setpwent) },
   { NSDB_PASSWD_COMPAT, "endpwent",   __nss_compat_endpwent,   (void *)NSS_NAME(endpwent) },
+  { NSDB_PASSWD_COMPAT, "getpwnam",   __nss_compat_getpwnam,   (void *)NSS_NAME(getpwnam_r) },
+  { NSDB_PASSWD_COMPAT, "getpwuid",   __nss_compat_getpwuid,   (void *)NSS_NAME(getpwuid_r) },
 
   { NSDB_NETGROUP, "getnetgrent_r", __nss_compat_getnetgrent_r, (void *)NSS_NAME(getnetgrent_r) },
+  { NSDB_NETGROUP, "getnetgrent", __nss_compat_getnetgrent_r, (void *)NSS_NAME(getnetgrent_r) },
   { NSDB_NETGROUP, "setnetgrent", __nss_compat_setnetgrent, (void *)NSS_NAME(setnetgrent) },
   { NSDB_NETGROUP, "endnetgrent", __nss_compat_endnetgrent, (void *)NSS_NAME(endnetgrent) },
 };
@@ -102,63 +120,45 @@ static ns_mtab methods[] = {
 typedef nss_status_t (*gethbn_t)(const char *, struct hostent *, char *, size_t, int *, int *);
 typedef nss_status_t (*gethba_t)(struct in_addr *, int, int, struct hostent *, char *, size_t, int *, int *);
 
-int __nss_compat_gethostbyname(void UNUSED(*retval), void *mdata, va_list ap)
-{
-  gethbn_t fn;
-  const char *name;
-  struct hostent *result;
-  char buffer[BUFFER_SIZE];
-  int errnop;
-  int h_errnop;
-  int af;
-  nss_status_t status;
-  fn = (gethbn_t)mdata;
-  name = va_arg(ap, const char *);
-  af = va_arg(ap, int);
-  result = va_arg(ap, struct hostent *);
-  status = fn(name, result, buffer, sizeof(buffer), &errnop, &h_errnop);
-  status = __nss_compat_result(status, errnop);
-  h_errno = h_errnop;
-  return status;
-}
+#ifdef __NetBSD__
+#include <compat/nss_compat.c>
+#endif
 
-int __nss_compat_gethostbyname2(void UNUSED(*retval), void *mdata, va_list ap)
+int __nss_compat_gethostbyname(void UNUSED(*cbrv), void *cbdata, va_list ap)
 {
   gethbn_t fn;
   const char *name;
-  struct hostent *result;
+  int namelen;
   char buffer[BUFFER_SIZE];
   int errnop;
   int h_errnop;
   int af;
   nss_status_t status;
-  fn = (gethbn_t)mdata;
+  fn = (gethbn_t)cbdata;
   name = va_arg(ap, const char *);
+  namelen = va_arg(ap, int);
   af = va_arg(ap, int);
-  result = va_arg(ap, struct hostent *);
-  status = fn(name, result, buffer, sizeof(buffer), &errnop, &h_errnop);
+  status = fn(name, (struct hostent *)cbrv, buffer, sizeof(buffer), &errnop, &h_errnop);
   status = __nss_compat_result(status, errnop);
   h_errno = h_errnop;
   return status;
 }
 
-int __nss_compat_gethostbyaddr(void UNUSED(*retval), void *mdata, va_list ap)
+int __nss_compat_gethostbyaddr(void UNUSED(*cbrv), void *cbdata, va_list ap)
 {
   gethba_t fn;
   struct in_addr *addr;
-  int len;
-  int type;
-  struct hostent *result;
+  int addrlen;
+  int af;
   char buffer[BUFFER_SIZE];
   int errnop;
   int h_errnop;
   nss_status_t status;
-  fn = (gethba_t)mdata;
+  fn = (gethba_t)cbdata;
   addr = va_arg(ap, struct in_addr *);
-  len = va_arg(ap, int);
-  type = va_arg(ap, int);
-  result = va_arg(ap, struct hostent *);
-  status = fn(addr, len, type, result, buffer, sizeof(buffer), &errnop, &h_errnop);
+  addrlen = va_arg(ap, int);
+  af = va_arg(ap, int);
+  status = fn(addr, addrlen, af, (struct hostent *)cbrv, buffer, sizeof(buffer), &errnop, &h_errnop);
   status = __nss_compat_result(status, errnop);
   h_errno = h_errnop;
   return status;
@@ -182,23 +182,27 @@ static int __gr_addgid(gid_t gid, gid_t 
   return ret;
 }
 
-int __freebsd_getgroupmembership(void UNUSED(*retval), void UNUSED(*mdata_),
+int __netbsd_getgroupmembership(void UNUSED(*cbrv), void UNUSED(*cbdata),
                                  va_list ap)
 {
   int err;
   nss_status_t s;
   gid_t group;
   gid_t *tmpgroups;
+  int *retval;
   const char *user;
   gid_t *groups;
   int maxgrp, *grpcnt;
   int i;
   long int lstart, lsize;
+  (void)cbdata;
+  retval = va_arg(ap, int *);
   user = va_arg(ap, const char *);
   group = va_arg(ap, gid_t);
   groups = va_arg(ap, gid_t *);
   maxgrp = va_arg(ap, int);
   grpcnt = va_arg(ap, int *);
+  (void)retval;
   tmpgroups = malloc(maxgrp * sizeof(gid_t));
   if (tmpgroups == NULL)
     return NSS_STATUS_UNAVAIL;
@@ -270,6 +274,7 @@ int __nss_compat_getnetgrent_r(void UNUS
           return (NS_SUCCESS);
         }
         break;
+#ifndef __NetBSD__
       case NS_RETURN:
         netlist = netgr->needed_groups;
         if(netlist != NULL){
@@ -280,6 +285,7 @@ int __nss_compat_getnetgrent_r(void UNUS
           ret = NS_TRYAGAIN;
         }
         break;
+#endif
       default:
         ;
     }
