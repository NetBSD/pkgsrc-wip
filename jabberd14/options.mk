# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jabberd
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql

.include "../../mk/bsd.options.mk"

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=		--with-mysql=${BUILDLINK_INCDIRS.mysql}
. include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=		--with-mysql=no
.endif

###
### PostgresSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=		--with-postgresql=${BUILDLINK_INCDIRS.pgsql}
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=		--with-postgresql=no
.endif
