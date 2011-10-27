# $NetBSD: options.mk,v 1.2 2011/10/27 10:14:19 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	gnutls gssapi mail mysql pgsql snmp file

.if ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	solaris
.else
PKG_SUGGESTED_OPTIONS+=	klog
.endif

PKG_OPTIONS_REQUIRED_GROUPS=	sysmod
PKG_OPTIONS_GROUP.sysmod=	klog solaris

PLIST_VARS+=		gnutls gssapi mail mysql pgsql snmp klog solaris file

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gnutls
PLIST.gnutls=			yes
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gssapi-krb5
PLIST.gssapi=			yes
.endif

.if !empty(PKG_OPTIONS:Mmail)
CONFIGURE_ARGS+=		--enable-mail
PLIST.mail=			yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-mysql
PLIST.mysql=			yes
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=		--enable-pgsql
PLIST.pgsql=			yes
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-snmp
PLIST.snmp=			yes
.endif

.if !empty(PKG_OPTIONS:Mklog)
CONFIGURE_ARGS+=		--enable-klog
PLIST.klog=			yes
RSYSLOG_SYSMOD=			klog
.else
CONFIGURE_ARGS+=		--disable-klog
.endif

.if !empty(PKG_OPTIONS:Msolaris)
CONFIGURE_ARGS+=		--enable-imsolaris
PLIST.solaris=			yes
RSYSLOG_SYSMOD=			solaris
.endif

.if !empty(PKG_OPTIONS:Mfile)
CONFIGURE_ARGS+=		--enable-imfile
PLIST.file=			yes
.endif
