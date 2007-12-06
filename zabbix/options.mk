CONFIGURE_ARGS+=	--enable-server
CONFIGURE_ARGS+=	--enable-agent

#CONFIGURE_ARGS+=

# DB access is mandatory
#CONFIGURE_ARGS+=	--with-sqlite3
#CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--with-pgsql
.include "../../databases/postgresql82-client/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-libcurl
.include "../../www/curl/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-net-snmp
#CONFIGURE_ARGS+=	--with-ucd-snmp

#CONFIGURE_ARGS+=	--with-ldap
#CONFIGURE_ARGS+=	--enable-static
