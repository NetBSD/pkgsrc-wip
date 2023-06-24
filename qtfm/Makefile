# $NetBSD$

DISTNAME=	6.2.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rodlie/}
GITHUB_PROJECT=	qtfm
GITHUB_TAG=	6.2.1
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsdprg@tuta.io
HOMEPAGE=	https://github.com/rodlie/qtfm/
COMMENT=	Qt file manager
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	qt5-qttools>5.0:../../x11/qt5-qttools

WRKSRC=		${WRKDIR}/qtfm-${DISTNAME}
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX} MANDIR=${PREFIX}/man qtfm.pro

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
