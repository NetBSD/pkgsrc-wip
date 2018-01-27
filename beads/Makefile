# $NetBSD: Makefile,v 1.2 2012/09/24 17:14:27 asau Exp $
#

DISTNAME=	beads-1.1.13
CATEGORIES=	biology
MASTER_SITES=	http://pappso.inra.fr//downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pappso.inra.fr/bioinfo/beads/
COMMENT=	BEADS is a program for spot detection on 2-D gel images

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,${PREFIX}/man/man1,g'
SUBST_SED.paths+=	-e 's,/usr/share/beads,${PREFIX}/share/beads,g'
SUBST_FILES.paths+=	CMakeLists.txt share/beads.applications
SUBST_MESSAGE.paths=	Fixing header search paths.

BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.1.0

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
