# $NetBSD: options.mk,v 1.1 2014/02/13 03:39:33 makoto Exp $
### Set options
PKG_OPTIONS_VAR=        PKG_OPTIONS.gitlab

PKG_OPTIONS_OPTIONAL_GROUPS+=	database
PKG_OPTIONS_GROUP.database= mysql postgres sqlite3

PKG_OPTIONS_OPTIONAL_GROUPS+=	webserver
PKG_OPTIONS_GROUP.webserver=	apache apache22 apache24 nginx

PKG_OPTIONS_OPTIONAL_GROUPS+= database
PKG_OPTIONS_GROUP.database=  mysql postgres sqlite3
PKG_SUGGESTED_OPTIONS=  sqlite3 nginx
PKG_SUGGESTED_OPTIONS=  sqlite3 apache22

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql56-client/buildlink3.mk"
.include "../../databases/mysql56-server/buildlink3.mk"
OPT_MYSQL=
OPT_POSTGRES=echo
.endif

.if !empty(PKG_OPTIONS:Mpostgres)
DEPENDS+=	postgresql93-[0-9]*:../../databases/postgresql93-server
.include "../../databases/postgresql93-client/buildlink3.mk"
OPT_POSTGRES=
OPT_MYSQL=echo
.endif

.if !empty(PKG_OPTIONS:Mnginx)
DEPENDS+=	nginx-[0-9]*:../../www/nginx
.endif

.if !empty(PKG_OPTIONS:Mapache)
DEPENDS+=	apache-[0-9]*:../../www/apache
.include "../../www/apache/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mapache22)
DEPENDS+=	apache-[0-9]*:../../www/apache22
DEPENDS+=	ap[0-9]*-passenger-[0-9]*:../../wip/ap2-passenger
.include "../../www/apache22/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mapache24)
DEPENDS+=	apache-[0-9]*:../../www/apache24
.include "../../www/apache24/buildlink3.mk"
.endif
