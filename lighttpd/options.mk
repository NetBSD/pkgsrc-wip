# $NetBSD: options.mk,v 1.1 2005/09/15 13:24:07 elvstone Exp $

PKG_OPTIONS_VAR	=		PKG_OPTIONS.lighttpd
PKG_SUPPORTED_OPTIONS=		inet6 mysql ssl gdbm memcache fam ldap lua webdav
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gdbm
.endif

.if !empty(PKG_OPTIONS:Mmemcache)
.include "../../wip/libmemcache/buildlink3.mk"
CONFIGURE_ARGS+=	--with-memcache
.endif

.if !empty(PKG_OPTIONS:Mfam)
.include "../../mk/fam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-fam
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.include "../../wip/libmemcache/buildlink3.mk"
CONFIGURE_ARGS+=	--with-lua --with-memcache
.endif

.if !empty(PKG_OPTIONS:Mwebdav)
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-webdav-props
.endif
