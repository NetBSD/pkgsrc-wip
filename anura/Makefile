# $NetBSD$

DISTNAME=	anura
PKGNAME=	anura-0
CATEGORIES=	games
GITHUB_TAG=	6185d6d5f0774610375f4277d0e39d4f6f239202
MASTER_SITES=	${MASTER_SITE_GITHUB:=anura-engine/}
LICENSE=	modified-bsd AND mit

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Fully-featured game engine

USE_LANGUAGES=	c c++
GCC_REQD=	4.8
EXTRACT_USING=	gtar
USE_TOOLS+=	pkg-config gmake
WRKSRC=		${WRKDIR}/anura-${GITHUB_TAG}
AUTO_MKDIRS=	yes

CFLAGS+=	-Wno-sign-compare
LDFLAGS+=	-lexecinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anura ${DESTDIR}${PREFIX}/bin/anura

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
