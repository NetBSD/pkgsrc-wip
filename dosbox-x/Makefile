# $NetBSD$

GITHUB_PROJECT=	dosbox-x
PKGNAME=	dosbox-x-0.82.9
DISTNAME=	${GITHUB_TAG}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=joncampbell123/}
GITHUB_TAG=	dosbox-x-windows-v0.82.9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dosbox-x.com/
COMMENT=	DOSBox with accurate emulation and wide testing
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/dosbox-x-${GITHUB_TAG}
GNU_CONFIGURE=		yes
# dosbox-x uses a modified SDL1 or system SDL2
CONFIGURE_ARGS+=	--enable-sdl2
USE_TOOLS+=		autoconf automake pkg-config
USE_LANGUAGES=		c c++
LIBS.NetBSD+=		-lcompat

PKGCONFIG_OVERRIDE+=	vs2015/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdl/sdl.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdl2/sdl2.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdlnet/SDL_net.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/zlib/zlib.pc.in

CHECK_PORTABILITY_SKIP+=	vs2015/sdl2/build-scripts/androidbuildlibs.sh
CHECK_PORTABILITY_SKIP+=	vs2015/sdl2/build-scripts/iosbuild.sh

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
#.include "../../net/SDL2_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
