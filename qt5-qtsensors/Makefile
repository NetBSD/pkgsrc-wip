# $NetBSD$

DISTNAME=	qtsensors-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtsensors-${QTVERSION}
COMMENT=	Qt5 module for Sensors

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Sensors.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../wip/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
