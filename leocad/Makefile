# $NetBSD$

DISTNAME=		leocad-21.06
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=leozide/}
GITHUB_PROJECT=		leocad
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://leocad.org/
COMMENT=		Design virtual models you can build with LEGO(R) bricks
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
MAKE_FLAGS+=		INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake \
		INSTALL_PREFIX=${PREFIX} \
		MAN_DIR=${PREFIX}/${PKGMANDIR}/man1 \
		DISABLE_UPDATE_CHECK=1

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
