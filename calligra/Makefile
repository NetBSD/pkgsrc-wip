# $NetBSD: Makefile,v 1.19 2011/04/22 13:44:32 obache Exp $

DISTNAME=		calligra-2.9.9
CATEGORIES=		misc kde
MASTER_SITES=		${MASTER_SITE_KDE:=calligra-2.9.9/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.calligra-suite.org/
COMMENT=		Calligra, the KDE4 Office suite
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=		msgfmt pkg-config perl
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
CMAKE_ARG_PATH=		..
CONFIGURE_DIRS=		_KDE_build

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

DEPENDS+=	oxygen-icons:../../graphics/oxygen-icons

.include "../../databases/libpqxx/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libodfgen/buildlink3.mk"
.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/mysql55-client/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
.include "../../print/okular/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/kactivities/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
