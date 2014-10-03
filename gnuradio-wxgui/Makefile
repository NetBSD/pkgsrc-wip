# $NetBSD: Makefile,v 1.5 2014/10/03 13:50:41 makoto Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
COMMENT=	WxGTK Toolkit module of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CONF_FILES+=	${EGDIR}/gr-wxgui.conf	${PKG_SYSCONFDIR}/gr-wxgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WXGUI=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True

.include	"../../devel/orc/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
