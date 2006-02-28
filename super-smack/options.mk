# $NetBSD: options.mk,v 1.1.1.1 2006/02/28 17:31:00 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.super-smack
PKG_SUPPORTED_OPTIONS=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include		"../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include		"../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
CONFIGURE_ARGS+=	--with-pgsql-include=${PGSQL_PREFIX}/include
CONFIGURE_ARGS+=	--with-pgsql-lib=${PGSQL_PREFIX}/lib
.endif
