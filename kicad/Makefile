# $NetBSD: Makefile,v 1.4 2012/10/01 21:57:38 asau Exp $
#

V=		2012-01-19
S=		BZR3256-stable
DISTNAME=	kicad_sources-${V}-${S}
PKGNAME=	kicad-${V:S/-//g}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://iut-tice.ujf-grenoble.fr/cao/
EXTRACT_SUFX=	.zip

MAINTAINER=	jonathan.gabris@gmail.com
HOMEPAGE=	http://iut-tice.ujf-grenoble.fr/kicad/
COMMENT=	Schematic and PCB CAD software
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/KiCad_sources
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CMAKE=		yes

CMAKE_ARGS+=		-DKICAD_STABLE_VERSION=ON
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release

SUBST_CLASSES+=		macosx
SUBST_STAGE.macosx=	pre-configure
SUBST_MESSAGE.macosx=	Eliminating Mac OS X build specific for ${PKGNAME}
SUBST_FILES.macosx=	bitmap2component/CMakeLists.txt			\
			eeschema/CMakeLists.txt				\
			cvpcb/CMakeLists.txt				\
			gerbview/CMakeLists.txt				\
			kicad/CMakeLists.txt				\
			pcb_calculator/CMakeLists.txt			\
			pcbnew/CMakeLists.txt
SUBST_SED.macosx=	-e 's/[[:<:]]MACOSX_BUNDLE[[:>:]]//'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
