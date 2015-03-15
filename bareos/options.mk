PKG_OPTIONS_VAR=                PKG_OPTIONS.bareos
PKG_SUPPORTED_OPTIONS=          ssl lzo
PKG_OPTIONS_REQUIRED_GROUPS=    database
PKG_OPTIONS_GROUP.database=     catalog-sqlite3 catalog-pgsql catalog-mysql
PKG_SUGGESTED_OPTIONS=          ssl catalog-sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcatalog-sqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=        --with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
BAREOS_DB=              sqlite3
.elif !empty(PKG_OPTIONS:Mcatalog-pgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=        --with-postgresql=${PGSQL_PREFIX}
BAREOS_DB=              postgresql
.elif !empty(PKG_OPTIONS:Mcatalog-mysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=        --with-mysql=${PREFIX}
BAREOS_DB=              mysql
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=        --with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=        --without-openssl
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.  include "../../archivers/lzo/buildlink3.mk"
.endif
