# $NetBSD: Makefile,v 1.3 2012/10/07 16:22:54 asau Exp $
#

DISTNAME=	scantailor-0.9.9.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scantailor/0.9.9.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/scantailor/
COMMENT=	Interactive post-processing tool for scanned pages
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

BUILD_MAKE_FLAGS+=	VERBOSE=1

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		paths
SUBST_SED.paths+=	-e 's,/usr/local,${BUILDLINK_DIR},'
SUBST_SED.paths+=	-e 's,libpng.lib,png15,'
SUBST_FILES.paths=	CMakeLists.txt
SUBST_MESSAGE.paths=	Fixing path and png library name in configure check.
SUBST_STAGE.paths=	pre-configure

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
