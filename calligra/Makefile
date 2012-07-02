# $NetBSD: Makefile,v 1.1 2012/07/02 13:34:33 thomasklausner Exp $
#

DISTNAME=	calligra-2.4.3
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=calligra-2.4.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.calligra-suite.org/
COMMENT=	Calligra, the KDE4 Office suite
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_INTERPRETER+=	kross
REPLACE.kross.old=	.*kross
REPLACE.kross.new=	${PREFIX}/bin/kross
REPLACE_FILES.kross= \
	plan/plugins/scripting/scripts/*.py \
	sheets/plugins/scripting/scripts/*.py

CMAKE_ARG_PATH= ..
CONFIGURE_DIRS= _KDE_build

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

# Optionally, add support for:
#.include "../../databases/freetds/buildlink3.mk"
#.include "../../databases/mysql51-client/buildlink3.mk"
#.include "../../mk/pgsql.buildlink3.mk"

# Package and enable:
# OpenCTL (0.9.10 or higher)  <http://www.opengtl.org>
# OpenShiva  <http://www.opengtl.org>
# QtShiva  <http://www.opengtl.org>
# Spnav  <http://spacenav.sourceforge.net/>

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../textproc/soprano/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
#.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
#.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
#.include "../../lang/ruby/replace.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../print/okular/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
