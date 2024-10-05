# $NetBSD$

GITHUB_PROJECT=	grass
DISTNAME=	grass-8.4.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=OSGeo/}
GITHUB_RELEASE=	8.4.0

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/OSGeo/grass/
COMMENT=	Geographic Information System
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/grass
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE+=	grass.pc.in



do-build:
	cd ${WRKSRC}/lib/pngdriver && ${GMAKE}

.include "../../lang/python/application.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/pdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
