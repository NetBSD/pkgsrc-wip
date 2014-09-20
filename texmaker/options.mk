# $NetBSD: options.mk,v 1.2 2014/09/20 07:46:23 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.texmaker
PKG_SUPPORTED_OPTIONS=	build-using-qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbuild-using-qt5)
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.else
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.endif
