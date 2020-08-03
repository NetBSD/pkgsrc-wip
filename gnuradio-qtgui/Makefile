# $NetBSD: Makefile,v 1.23 2019/08/22 12:23:23 ryoon Exp $

PKGNAME=	gnuradio-qtgui-${VERSION}
COMMENT=	Qt GUI module of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

#ONF_FILES+=	${EGDIR}/gr-qtgui.conf	${PKG_SYSCONFDIR}/gr-qtgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_QTGUI=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../x11/py-qt5/buildlink3.mk"
.include	"../../x11/qwt6-qt5/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
