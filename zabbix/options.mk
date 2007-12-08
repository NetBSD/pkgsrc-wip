PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix
PKG_SUPPORTED_OPTIONS+=		zabbix-server zabbix-agent
PKG_SUPPORTED_OPTIONS+=		pgsql sqlite mysql
PKG_SUPPORTED_OPTIONS+=		curl
PKG_SUPPORTED_OPTIONS+=		ldap
PKG_SUPPORTED_OPTIONS+=		snmp
PKG_SUPPORTED_OPTIONS+=		zabbix-static

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Default to both, server and agent.
.if empty(PKG_OPTIONS:Mzabbix-server) && empty(PKG_OPTIONS:Mzabbix-agent)
PKG_OPTIONS+=	zabbix-server zabbix-agent
.endif
.if !empty(PKG_OPTIONS:Mzabbix-server)
CONFIGURE_ARGS+=	--enable-server
.endif
.if !empty(PKG_OPTIONS:Mzabbix-agent)
CONFIGURE_ARGS+=	--enable-agent
.endif

# DB support is mandatory, default to SQLite
.if empty(PKG_OPTIONS:Mpgsql) && empty(PKG_OPTIONS:Msqlite) && empty(PKG_OPTIONS:Mmysql)
PKG_OPTIONS+=	sqlite
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
.include "../../databases/postgresql82-client/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite3
.include "../../databases/sqlite3/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../databases/mysql5-client/buildlink3.mk"
.endif

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
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !empty(PKG_OPTIONS:Mzabbix-static)
CONFIGURE_ARGS+=	--enable-static
.endif
