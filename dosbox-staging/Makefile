# $NetBSD$

GITHUB_PROJECT=	dosbox-staging
GITHUB_TAG=	v0.77.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=dosbox-staging/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dosbox-staging.github.io/
COMMENT=	DOS/x86 emulator focusing on ease of use
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_TOOLS=	pkg-config

NOT_PAX_MPROTECT_SAFE=	bin/dosbox-staging

pre-configure:
	${MV} ${WRKSRC}/docs/dosbox.1 ${WRKSRC}/docs/dosbox-staging.1

# devel/googletest
MESON_ARGS+=	-Dunit_tests=disabled
MESON_ARGS+=	-Duse_fluidsynth=true
MESON_ARGS+=	-Duse_mt32emu=false
MESON_ARGS+=	-Duse_png=true
MESON_ARGS+=	-Duse_sdl2_net=true

.include "../../devel/meson/build.mk"

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
