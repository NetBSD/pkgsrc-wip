# $NetBSD: options.mk,v 1.4 2014/05/09 07:38:46 thomasklausner Exp $

PKG_OPTIONS_VAR =	PKG_OPTIONS.chiantipy
PKG_SUPPORTED_OPTIONS=	wx qt
PKG_SUGGESTED_OPTIONS=	wx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mqt)
.  include "../../x11/py-qt4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwx)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets
.  include "../../x11/py-wxWidgets/buildlink3.mk"
.endif
