# $NetBSD$
#

DISTNAME=	openscad-master
CATEGORIES=	wip
MASTER_SITES=	-https://github.com/openscad/openscad/archive/master.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openscad.org/
COMMENT=	OpenSCAD - The Programmers Solid 3D CAD Modeller
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++11
USE_TOOLS+=	bison gettext pkg-config
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:R}

CHECK_PORTABILITY_SKIP+=	tests/compare-bitmaps.sh

REPLACE_PYTHON=	libraries/MCAD/get_submodules.py
.include "../../lang/python/application.mk"

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake \
	    PREFIX=${PREFIX} -after QMAKE_YACC=bison QMAKE_LEX=flex

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
# DragonFly requires FlexLexer.h from pkgsrc - base doesn't cut it.
#.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/opencsg/buildlink3.mk"
.include "../../wip/cgal/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
