# $NetBSD: Makefile,v 1.103 2023/11/12 13:20:48 wiz Exp $

VERSION=	2021.01
DISTNAME=	openscad-${VERSION}
PKGREVISION=	27
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=openscad/}
GITHUB_TAG=	openscad-${VERSION}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	https://www.openscad.org/
COMMENT=	OpenSCAD - The Programmers Solid 3D CAD Modeller
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		bison gettext pkg-config itstool
USE_LIBTOOL=		yes

WRKSRC=		${WRKDIR}/${PKGBASE}-${DISTNAME}

CHECK_PORTABILITY_SKIP+=	tests/compare-bitmaps.sh

.include "../../lang/python/application.mk"

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

# CGAL 6.0.x+ needs c++17
BUILDLINK_TRANSFORM+=	opt:-std=c++1y:-std=c++17

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake \
	    PREFIX=${PREFIX} -after QMAKE_YACC=bison QMAKE_LEX=flex

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
# DragonFly requires FlexLexer.h from pkgsrc - base doesn't cut it.
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/opencsg/buildlink3.mk"
.include "../../math/cgal/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
