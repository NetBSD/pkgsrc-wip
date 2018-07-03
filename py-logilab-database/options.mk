# $NetBSD: options.mk,v 1.3 2014/05/09 07:38:48 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-logilab-database
PKG_SUPPORTED_OPTIONS=	mysql sqlite pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mysqldb
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sqlite2
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
.endif
