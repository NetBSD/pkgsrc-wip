# $NetBSD: options.mk,v 1.2 2010/04/10 23:59:04 helgoman Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.eric4
PKG_SUPPORTED_OPTIONS=	sqlite mysql pgsql enchant pylint cxfreeze rope all
PKG_SUGGESTED_OPTIONS=	sqlite


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=				qt4-sqlite3>=4.6.2:../../x11/qt4-sqlite3
.endif

#Enable support for mysql & postgresql | build Qt4-drivers
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=				qt4-mysql>=4.6.2:../../x11/qt4-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=				qt4-pgsql>=4.6.2:../../x11/qt4-pgsql
.endif

#Enable spell-checking
.if !empty(PKG_OPTIONS:Menchant)
DEPENDS+=				py26-enchant>=1.4.2:../../textproc/py-enchant
.endif

#Enable source code analyzer for python
.if !empty(PKG_OPTIONS:Mpylint)
.include "../../wip/pylint/buildlink3.mk"
.endif

#Enable support for freezing Python scripts
.if !empty(PKG_OPTIONS:Mcxfreeze)
.include "../../wip/cxfreeze/buildlink3.mk"
.endif

#Enable support for code refactoring
.if !empty(PKG_OPTIONS:Mrope)
.include "../../wip/rope/buildlink3.mk"
.endif

#Enable support for all given options
.if !empty(PKG_OPTIONS:Mall)
DEPENDS+=				qt4-mysql>=4.6.2:../../x11/qt4-mysql
DEPENDS+=				qt4-pgsql>=4.6.2:../../x11/qt4-pgsql
DEPENDS+=				py26-enchant>=1.4.2:../../textproc/py-enchant
.include "../../wip/pylint/buildlink3.mk"
.include "../../wip/cxfreeze/buildlink3.mk"
.include "../../wip/rope/buildlink3.mk"
.endif
