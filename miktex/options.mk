# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.tex-miktex

PKG_SUPPORTED_OPTIONS+=		qt5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_ARGS+=	-DWITH_UI_QT=ON
.include "../../print/poppler-qt5/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_UI_QT=OFF
.endif
