# $NetBSD$

DISTNAME=	sioyek-2.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=ahrm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahrm/sioyek/
COMMENT=	PDF viewer with a focus on textbooks and research papers
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

pre-configure:
	${LN} -fs ${PREFIX}/qt5/bin/qmake ${BUILDLINK_DIR}/bin

do-build:
	cd ${WRKSRC} && ${SH} build_linux.sh

.include "../../fonts/harfbuzz/buildlink3.mk"
#.include "../../x11/qt5-qt3d/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
