# $NetBSD: options.mk,v 1.2 2014/01/25 10:38:16 thomasklausner Exp $

PKG_OPTIONS_VAR =	PKG_OPTIONS.chiantipy
PKG_SUPPORTED_OPTIONS=	wx qt
PKG_SUGGESTED_OPTIONS=	wx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mqt)
.  include "../../x11/py-qt4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwx)
.  include "../../x11/py-wxWidgets/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-wxWidgets
.endif
