# $NetBSD: Makefile,v 1.26 2017/01/21 20:06:46 ryoon Exp $

DISTNAME=	qttools-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttools-${QTVERSION}
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase58/Makefile.common"

QTPKGCONFIGPC=		Qt5UiTools.pc \
			Qt5Designer.pc Qt5Help.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../wip/qt5-qtxmlpatterns58/buildlink3.mk"
.include "../../wip/qt5-qtwebkit58/buildlink3.mk"
.include "../../wip/qt5-sqlite358/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
