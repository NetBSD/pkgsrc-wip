# $NetBSD: options.mk,v 1.1 2013/09/11 10:01:56 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	dbi diag file gnutls gssapi guardtime libgcrypt \
			mail mysql pgsql snmp uuid
PKG_SUGGESTED_OPTIONS+=	libgcrypt uuid

.if ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	solaris
.else
PKG_SUGGESTED_OPTIONS+=	klog
.endif

PKG_OPTIONS_REQUIRED_GROUPS=	sysmod
PKG_OPTIONS_GROUP.sysmod=	klog solaris

PLIST_VARS+=		dbi diag file gnutls gssapi guardtime klog libgcrypt \
			mail mysql pgsql snmp solaris

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

.if !empty(PKG_OPTIONS:Mdbi)
CONFIGURE_ARGS+=		--enable-libdbi
PLIST.dbi=			yes
.include "../../databases/libdbi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdiag)
CONFIGURE_ARGS+=		--enable-imdiag
PLIST.diag=			yes
.endif

.if !empty(PKG_OPTIONS:Mguardtime)
CONFIGURE_ARGS+=		--enable-guardtime
CONFIGURE_ENV+=			GUARDTIME_CFLAGS=-I/opt/local/include
CONFIGURE_ENV+=			GUARDTIME_LIBS='-L${BUILDLINK_PREFIX.libguardtime}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libguardtime}/lib -lgthttp -lgtbase -lcurl -lcrypto -lrt'
PLIST.guardtime=		yes
.include "../../security/libguardtime/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
CONFIGURE_ARGS+=		--enable-libgcrypt
PLIST.libgcrypt=		yes
.include "../../security/libgcrypt/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--disable-libgcrypt
.endif

.if !empty(PKG_OPTIONS:Muuid)
CONFIGURE_ARGS+=		--enable-uuid
.include "../../devel/libuuid/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--disable-uuid
.endif
