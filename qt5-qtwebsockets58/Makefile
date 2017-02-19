# $NetBSD: Makefile,v 1.10 2016/12/04 05:17:17 ryoon Exp $

DISTNAME=	qtwebsockets-opensource-src-${QTVERSION}
PKGNAME=	qt5-websockets-${QTVERSION}
COMMENT=	Qt5 module for websockets

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase58/Makefile.common"

post-install:
.for i in Qt5WebSockets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor


.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
