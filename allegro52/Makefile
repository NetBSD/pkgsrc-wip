# $NetBSD$

VERSION=	5.2.1.1
DISTNAME=	allegro-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/allegro/allegro/${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liballeg.org/
COMMENT=	Allegro game programming library
#LICENSE=	# TODO: (see mk/license.mk)

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
