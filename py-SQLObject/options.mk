# $NetBSD: options.mk,v 1.5 2014/05/09 07:38:44 thomasklausner Exp $

PKG_OPTIONS_VAR =	PKG_OPTIONS.SQLObject
PKG_SUPPORTED_OPTIONS=	mysql psycopg2 sqlite sybase
PKG_SUGGESTED_OPTIONS=	psycopg2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mysqldb
PLIST.mysql=	yes
.endif

.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
PLIST.psycopg2=	yes
.endif

.if !empty(PKG_OPTIONS:Mpsycopg1) || !empty(PKG_OPTIONS:Mpsycopg2)
PLIST.psycopg1=	yes
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sqlite2
PLIST.sqlite=	yes
.endif

.if !empty(PKG_OPTIONS:Msybase)
DEPENDS+=	${PYPKGPREFIX}-sybase>=0.36:../../databases/py-sybase
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sybase
PLIST.sybase=	yes
.endif
