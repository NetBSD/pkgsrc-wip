# $NetBSD: options.mk,v 1.1 2014/08/09 17:59:17 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.texmaker
PKG_SUPPORTED_OPTIONS=	build-using-qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbuild-using-qt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.else
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.endif
