# $NetBSD: Makefile,v 1.30 2017/04/22 21:03:22 adam Exp $

DISTNAME=	qtquick1-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtquick1-${QTVERSION}
COMMENT=	Qt5 module for Quick1

BUILD_TARGET=		sub-tools
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Declarative.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../wip/qt5-qtscript/buildlink3.mk"
.include "../../wip/qt5-qttools/buildlink3.mk"
.include "../../wip/qt5-qtwebkit/buildlink3.mk"
.include "../../wip/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
