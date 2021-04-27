# $NetBSD$

DISTNAME=	anura-0
CATEGORIES=	devel games
GIT_REPO=	https://github.com/anura-engine/anura.git
GIT_REVISION=	188004394edf268bd9e798d0781ac394b84f5489

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Fully-featured game engine
LICENSE=	modified-bsd AND mit

USE_LANGUAGES=	c c++
GCC_REQD+=	4.8
USE_TOOLS+=	pkg-config gmake
AUTO_MKDIRS=	yes

CFLAGS+=	-Wno-sign-compare
CFLAGS+=	-Wno-deprecated-declarations

.if "${OPSYS}" == "NetBSD"
LDFLAGS+=	-lexecinfo
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anura ${DESTDIR}${PREFIX}/bin/anura

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
