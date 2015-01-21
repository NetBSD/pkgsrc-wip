# $NetBSD: options.mk,v 1.8 2015/01/21 22:56:43 heidnes Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zabbix

PKG_SUPPORTED_OPTIONS+=	curl
PKG_SUPPORTED_OPTIONS+=	ldap
PKG_SUPPORTED_OPTIONS+=	snmp
PKG_SUPPORTED_OPTIONS+=	zabbix-static
PKG_SUPPORTED_OPTIONS+=	jabber
PKG_SUPPORTED_OPTIONS+=	ssh
PKG_SUPPORTED_OPTIONS+=	ipv6
#PKG_SUPPORTED_OPTIONS+=ipmi
#PKG_SUPPORTED_OPTIONS+=odbc

.if !empty(PKG_OPTIONS:Mzabbix-server)
PKG_SUGGESTED_OPTIONS=	curl ldap snmp ssh jabber ipv6
.endif

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjabber)
CONFIGURE_ARGS+=	--with-jabber
.include "../../textproc/iksemel/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssh)
CONFIGURE_ARGS+=	--with-ssh2
.include "../../security/libssh2/buildlink3.mk"
.endif

#.if !empty(PKG_OPTIONS:Mipmi)
# no openipmi (yet)
#.endif

#.if !empty(PKG_OPTIONS:Modbc)
# don't know quite yet
#.endif

.if !empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif


# DB support is mandatory, default to SQLite
#.if empty(PKG_OPTIONS:Mpgsql) && empty(PKG_OPTIONS:Msqlite) && empty(PKG_OPTIONS:Mmysql)
#PKG_OPTIONS+=	sqlite
#.endif

#.if !empty(PKG_OPTIONS:Mpgsql)
#CONFIGURE_ARGS+=	--with-pgsql
#.include "../../mk/pgsql.buildlink3.mk"
##DEPENDS+=		php-pgsql
#.endif
#.if !empty(PKG_OPTIONS:Msqlite)
#CONFIGURE_ARGS+=	--with-sqlite3
#.include "../../databases/sqlite3/buildlink3.mk"
#.endif
#.if !empty(PKG_OPTIONS:Mmysql)
#CONFIGURE_ARGS+=	--with-mysql
#.include "../../mk/mysql.buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--with-libcurl
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-net-snmp
.include "../../net/net-snmp/buildlink3.mk"
.endif
#.if !empty(PKG_OPTIONS:Mucd-snmp)
#CONFIGURE_ARGS+=	--with-ucd-snmp
#.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client:Q}
.endif

.if !empty(PKG_OPTIONS:Mzabbix-static)
CONFIGURE_ARGS+=	--enable-static
.endif
