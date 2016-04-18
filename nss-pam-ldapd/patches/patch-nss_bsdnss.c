$NetBSD$

NetBSD does not have __nss_compat_xxx functions in its C library.
It also need non-_r variants.

--- nss/bsdnss.c.orig	2012-05-18 15:34:22.000000000 +0200
+++ nss/bsdnss.c	2013-12-03 17:18:50.000000000 +0100
@@ -40,108 +40,106 @@
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
 
 static ns_mtab methods[]={
   { NSDB_GROUP, "getgrnam_r", __nss_compat_getgrnam_r, _nss_ldap_getgrnam_r },
   { NSDB_GROUP, "getgrgid_r", __nss_compat_getgrgid_r, _nss_ldap_getgrgid_r },
   { NSDB_GROUP, "getgrent_r", __nss_compat_getgrent_r, _nss_ldap_getgrent_r },
+  { NSDB_GROUP, "getgrent",   __nss_compat_getgrent,   _nss_ldap_getgrent_r },
   { NSDB_GROUP, "setgrent",   __nss_compat_setgrent,   _nss_ldap_setgrent },
   { NSDB_GROUP, "endgrent",   __nss_compat_endgrent,   _nss_ldap_endgrent },
-  { NSDB_GROUP, "getgroupmembership", __freebsd_getgroupmembership, NULL },
+  { NSDB_GROUP, "getgrnam", __nss_compat_getgrnam, _nss_ldap_getgrnam_r },
+  { NSDB_GROUP, "getgrgid", __nss_compat_getgrgid, _nss_ldap_getgrgid_r },
+  { NSDB_GROUP, "getgroupmembership", __netbsd_getgroupmembership, NULL },
 
   { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, _nss_ldap_getpwnam_r },
   { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, _nss_ldap_getpwuid_r },
   { NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, _nss_ldap_getpwent_r },
+  { NSDB_PASSWD, "getpwent",   __nss_compat_getpwent,   _nss_ldap_getpwent_r },
   { NSDB_PASSWD, "setpwent",   __nss_compat_setpwent,   _nss_ldap_setpwent },
   { NSDB_PASSWD, "endpwent",   __nss_compat_endpwent,   _nss_ldap_endpwent },
+  { NSDB_PASSWD, "getpwnam", __nss_compat_getpwnam, _nss_ldap_getpwnam_r },
+  { NSDB_PASSWD, "getpwuid", __nss_compat_getpwuid, _nss_ldap_getpwuid_r },
 
   { NSDB_HOSTS, "gethostbyname", __nss_compat_gethostbyname, _nss_ldap_gethostbyname_r },
   { NSDB_HOSTS, "gethostbyaddr", __nss_compat_gethostbyaddr, _nss_ldap_gethostbyaddr_r },
-  { NSDB_HOSTS, "gethostbyname2", __nss_compat_gethostbyname2, _nss_ldap_gethostbyname2_r },
 
   { NSDB_GROUP_COMPAT, "getgrnam_r", __nss_compat_getgrnam_r, _nss_ldap_getgrnam_r },
   { NSDB_GROUP_COMPAT, "getgrgid_r", __nss_compat_getgrgid_r, _nss_ldap_getgrgid_r },
   { NSDB_GROUP_COMPAT, "getgrent_r", __nss_compat_getgrent_r, _nss_ldap_getgrent_r },
+  { NSDB_GROUP_COMPAT, "getgrent",   __nss_compat_getgrent,   _nss_ldap_getgrent_r },
   { NSDB_GROUP_COMPAT, "setgrent",   __nss_compat_setgrent,   _nss_ldap_setgrent },
   { NSDB_GROUP_COMPAT, "endgrent",   __nss_compat_endgrent,   _nss_ldap_endgrent },
+  { NSDB_GROUP_COMPAT, "getgrnam", __nss_compat_getgrnam, _nss_ldap_getgrnam_r },
+  { NSDB_GROUP_COMPAT, "getgrgid", __nss_compat_getgrgid, _nss_ldap_getgrgid_r },
 
   { NSDB_PASSWD_COMPAT, "getpwnam_r", __nss_compat_getpwnam_r, _nss_ldap_getpwnam_r },
   { NSDB_PASSWD_COMPAT, "getpwuid_r", __nss_compat_getpwuid_r, _nss_ldap_getpwuid_r },
   { NSDB_PASSWD_COMPAT, "getpwent_r", __nss_compat_getpwent_r, _nss_ldap_getpwent_r },
+  { NSDB_PASSWD_COMPAT, "getpwent",   __nss_compat_getpwent,   _nss_ldap_getpwent_r },
   { NSDB_PASSWD_COMPAT, "setpwent",   __nss_compat_setpwent,   _nss_ldap_setpwent },
   { NSDB_PASSWD_COMPAT, "endpwent",   __nss_compat_endpwent,   _nss_ldap_endpwent },
+  { NSDB_PASSWD_COMPAT, "getpwnam", __nss_compat_getpwnam, _nss_ldap_getpwnam_r },
+  { NSDB_PASSWD_COMPAT, "getpwuid", __nss_compat_getpwuid, _nss_ldap_getpwuid_r },
 };
 
-int __nss_compat_gethostbyname(void *retval,void *mdata,va_list ap)
-{
-  nss_status_t (*fn)(const char *,struct hostent *,char *,size_t,int *,int *);
-  const char *name;
-  struct hostent *result;
-  char buffer[BUFFER_SIZE];
-  int errnop;
-  int h_errnop;
-  int af;
-  nss_status_t status;
-  fn=mdata;
-  name=va_arg(ap,const char*);
-  af=va_arg(ap,int);
-  result=va_arg(ap,struct hostent *);
-  status=fn(name,result,buffer,sizeof(buffer),&errnop,&h_errnop);
-  status=__nss_compat_result(status,errnop);
-  h_errno=h_errnop;
-  return (status);
-}
+#ifdef __NetBSD__
+#include <compat/nss_compat.c>
+#endif
 
-int __nss_compat_gethostbyname2(void *retval,void *mdata,va_list ap)
+int __nss_compat_gethostbyname(void *cbrv,void *cbdata,va_list ap)
 {
   nss_status_t (*fn)(const char *,struct hostent *,char *,size_t,int *,int *);
   const char *name;
-  struct hostent *result;
+  int namelen;
   char buffer[BUFFER_SIZE];
   int errnop;
   int h_errnop;
   int af;
   nss_status_t status;
-  fn=mdata;
+  fn=cbdata;
   name=va_arg(ap,const char*);
+  namelen=va_arg(ap,int);
   af=va_arg(ap,int);
-  result=va_arg(ap,struct hostent *);
-  status=fn(name,result,buffer,sizeof(buffer),&errnop,&h_errnop);
+  status=fn(name,(struct hostent *)cbrv,buffer,sizeof(buffer),&errnop,&h_errnop);
   status=__nss_compat_result(status,errnop);
   h_errno=h_errnop;
   return (status);
 }
 
-int __nss_compat_gethostbyaddr(void *retval,void *mdata,va_list ap)
+int __nss_compat_gethostbyaddr(void *cbrv,void *cbdata,va_list ap)
 {
   struct in_addr *addr;
-  int len;
-  int type;
-  struct hostent *result;
+  int addrlen;
+  int af;
   char buffer[BUFFER_SIZE];
   int errnop;
   int h_errnop;
   nss_status_t (*fn)(struct in_addr *,int,int,struct hostent *,char *,size_t,int *,int *);
   nss_status_t status;
-  fn=mdata;
+  fn=cbdata;
   addr=va_arg(ap,struct in_addr*);
-  len=va_arg(ap,int);
-  type=va_arg(ap,int);
-  result=va_arg(ap,struct hostent*);
-  status=fn(addr,len,type,result,buffer,sizeof(buffer),&errnop,&h_errnop);
+  addrlen=va_arg(ap,int);
+  af=va_arg(ap,int);
+  status=fn(addr,addrlen,af,(struct hostent *)cbrv,buffer,sizeof(buffer),&errnop,&h_errnop);
   status=__nss_compat_result(status,errnop);
   h_errno=h_errnop;
   return (status);
@@ -165,22 +163,26 @@
   return ret;
 }
 
-int __freebsd_getgroupmembership(void *retval,void *mdata,va_list ap)
+int __netbsd_getgroupmembership(void *cbrv,void *cbdata,va_list ap)
 {
   int err;
   nss_status_t s;
   gid_t group;
   gid_t *tmpgroups;
+  int *retval;
   const char *user;
   gid_t *groups;
   int maxgrp,*grpcnt;
   int i;
   long int lstart,lsize;
+  (void)cbdata;
+  retval=va_arg(ap,int *);
   user=va_arg(ap,const char *);
   group=va_arg(ap,gid_t);
   groups=va_arg(ap,gid_t *);
   maxgrp=va_arg(ap,int);
   grpcnt=va_arg(ap,int *);
+  (void)retval;
   tmpgroups=malloc(maxgrp*sizeof(gid_t));
   if (tmpgroups==NULL)
     return NSS_STATUS_UNAVAIL;
