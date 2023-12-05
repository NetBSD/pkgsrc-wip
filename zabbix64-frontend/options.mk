# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix64-frontend
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS+=		pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../mk/mysql.buildlink3.mk"
ZABBIX_DB_TYPE=		mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql
.include "../../mk/pgsql.buildlink3.mk"
ZABBIX_DB_TYPE=		postgresql
.endif
