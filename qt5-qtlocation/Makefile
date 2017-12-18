# $NetBSD: Makefile,v 1.19 2017/04/22 21:03:21 adam Exp $

DISTNAME=	qtlocation-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtlocation-${QTVERSION}
COMMENT=	Qt5 module for qtlocation

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Positioning.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
