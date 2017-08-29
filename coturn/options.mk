PKG_OPTIONS_VAR=		PKG_OPTIONS.coturn
PKG_SUPPORTED_OPTIONS=		hiredis mysql pgsql sqlite redis

PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhiredis)
.include "../../databases/hiredis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql55-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql94-client/buildlink3.mk"
DBLIBS+=	${BUILDLINK_PREFIX.postgresql-lib}
CONFIGURE_ENV+=	POSTCFLAGS="-I${PREFIX}/include/postgresql"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=       redis-[0-9]*:../../databases/redis
.endif
