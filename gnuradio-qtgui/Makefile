# $NetBSD: Makefile,v 1.5 2015/09/17 13:48:06 makoto Exp $

PKGNAME=	gnuradio-qtgui-${VERSION}
COMMENT=	Qt GUI module of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

#ONF_FILES+=	${EGDIR}/gr-qtgui.conf	${PKG_SYSCONFDIR}/gr-qtgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_QTGUI=ON

.include	"../../x11/qt4-libs/buildlink3.mk"
.include	"../../x11/qwt-qt4/buildlink3.mk"
.include	"../../x11/py-qt4/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
