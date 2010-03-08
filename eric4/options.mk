# $NetBSD: options.mk,v 1.1 2010/03/08 17:55:37 helgoman Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eric4
PKG_SUPPORTED_OPTIONS=	sqlite mysql pgsql enchant #pylint (package not ready yet)
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=               qt4-sqlite3>=4.6.2:../../x11/qt4-sqlite3
.endif

#Enable support for mysql & postgresql | build Qt4-drivers
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=               qt4-mysql>=4.6.2:../../x11/qt4-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=               qt4-pgsql>=4.6.2:../../x11/qt4-pgsql
.endif

#Enable spell-checking
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=				py26-enchant>=1.4.2:../../textproc/py-enchant
.endif

#Enable source code analyzer for python
#.if !empty(PKG_OPTIONS:Mpylint)
#.include "../../wip/py-lint/buildlink3.mk"
#.endif
