# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.synapse
PKG_SUPPORTED_OPTIONS=	email ldap pgsql sqlite
PKG_SUGGESTED_OPTIONS=	email sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Memail)
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-bleach-[0-9]*:../../www/py-bleach
.endif

.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif
