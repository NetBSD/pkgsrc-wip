# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.kea
PKG_SUPPORTED_OPTIONS=		mysql pgsql tests
PKG_SUGGESTED_OPTIONS=		mysql pgsql
PLIST_VARS+=			mysql pgsql

.include "../../mk/bsd.options.mk"

###
### database support
###

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=--with-mysql=${PREFIX}/bin/mysql_config
PLIST.mysql=yes
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=--with-pgsql=${PGSQL_PREFIX}/bin/pg_config
PLIST.pgsql=yes
.endif

.if !empty(PKG_OPTIONS:Mtests)
.  include "../../devel/googletest/buildlink3.mk"
CONFIGURE_ARGS+=--with-gtest=${BUILDLINK_PREFIX.googletest}
.endif
