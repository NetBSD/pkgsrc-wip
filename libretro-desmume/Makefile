# $NetBSD$

DISTNAME=	libretro-desmume-20180416
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	desmume
GITHUB_TAG=	9fb1e8c1f4ccd819f15b29e2114a05e45140fec0

HOMEPAGE=	https://docs.libretro.com/library/desmume/
COMMENT=	Libretro core based on the Desmume Nintendo DS emulator
LICENSE=	gnu-gpl-v2

BUILD_DIRS=	desmume/src/frontend/libretro
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
CXXFLAGS+=		-marm
CXXFLAGS+=		-DUSE_POSIX_MEMALIGN -D__RETRO_ARM__
CXXFLAGS+=		-DARM
MAKE_FLAGS+=		DESMUME_JIT=0
MAKE_FLAGS+=		DESMUME_JIT_ARM=1
.elif !empty(MACHINE_ARCH:M*x86_64*) || !empty(MACHINE_ARCH:M*i386*)
MAKE_FLAGS+=		DESMUME_JIT=1
.endif

MAKE_FLAGS+=		GIT_VERSION="-pkgsrc"
INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} \
	    ${WRKSRC}/desmume/src/frontend/libretro/desmume_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/desmume_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
