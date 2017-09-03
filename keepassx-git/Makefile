# $NetBSD: Makefile,v 1.2 2015/09/14 12:52:50 thomasklausner Exp $

DISTNAME=	keepassx-2.0.3
CATEGORIES=	x11
MASTER_SITES=	https://github.com/keepassx/keepassx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/keepassx/keepassx/
COMMENT=	Password generator and manager (git version)
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	keepassx
GIT_REPO.keepassx=	git://github.com/keepassx/keepassx.git
WRKSRC=			${WRKDIR}/keepassx

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	build

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
