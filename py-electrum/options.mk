# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-electrum
PKG_SUPPORTED_OPTIONS=		x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	${PYPKGPREFIX}-qt6>=6.9.0:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-qdarkstyle>=3.2:../../wip/py-qdarkstyle
.endif
