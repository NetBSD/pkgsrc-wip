# $NetBSD$

DISTNAME=	qttools-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qttools-${QTVERSION}
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase/Makefile.common"

QTPKGCONFIGPC=		Qt5CLucene.pc Qt5DesignerComponents.pc Qt5UiTools.pc \
			Qt5Designer.pc Qt5Help.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../wip/qt5-qtxmlpatterns/buildlink3.mk"
#.include "../../wip/qt5-qtwebkit/buildlink3.mk"
#instead:
.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../wip/qt5-qtlocation/buildlink3.mk"
.include "../../wip/qt5-qtmultimedia/buildlink3.mk"
.include "../../wip/qt5-qtsensors/buildlink3.mk"
.include "../../wip/qt5-qtwebchannel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
