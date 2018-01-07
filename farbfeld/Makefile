# $NetBSD$

DISTNAME=	farbfeld-3
CATEGORIES=	graphics
MASTER_SITES=	http://dl.suckless.org/farbfeld/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suckless image format with conversion tools
LICENSE=	isc

USE_TOOLS+=	gmake

# Needed for `convert' by 2ff
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

USE_LANGUAGES=	c99

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
