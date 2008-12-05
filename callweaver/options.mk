# $NetBSD: options.mk,v 1.1.1.1 2008/12/05 15:39:43 x400 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.callweaver
PKG_SUPPORTED_OPTIONS=	mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql5-client/buildlink3.mk"
PLIST_SRC+=		PLIST.mysql
CONF_FILES+=		${PKG_SYSCONFDIR}/cdr_mysql.conf \
			${PKG_SYSCONFDIR}/res_mysql.conf

CONFIGURE_ARGS+=	--enable-mysql --with-app_sql_mysql --with-cdr_mysql --with-res_config_mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql83-client/buildlink3.mk"
PLIST_SRC+=		PLIST.pgsql
CONF_FILES+=		${PKG_SYSCONFDIR}/cdr_pgsql.conf \
			${PKG_SYSCONFDIR}/res_pgsql.conf

CONFIGURE_ARGS+=	--enable-postgresql --with-app_sql_postgres --with-cdr_pgsql --with-res_config_pgsql
.endif
