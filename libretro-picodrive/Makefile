# $NetBSD: Makefile,v 1.2 2015/02/05 16:57:53 wiz Exp $

DISTNAME=	libretro-picodrive-20170418
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.libretro.com/index.php?title=PicoDrive
COMMENT=	Fast MegaDrive/MegaCD/32X emulator
LICENSE=	picodrive-license

GITHUB_PROJECT=	picodrive
GITHUB_TAG=	cbc93b68dca1d72882d07b54bbe1ef25b980558a

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
BUILD_MAKE_FLAGS+=	ARCH=arm
BUILD_MAKE_FLAGS+=	asm_memory=1
BUILD_MAKE_FLAGS+=	asm_render=1
BUILD_MAKE_FLAGS+=	asm_ym2612=1
BUILD_MAKE_FLAGS+=	asm_misc=1
BUILD_MAKE_FLAGS+=	asm_cdpico=0
BUILD_MAKE_FLAGS+=	asm_cdmemory=1
BUILD_MAKE_FLAGS+=	asm_mix=1
BUILD_MAKE_FLAGS+=	use_cyclone=0
BUILD_MAKE_FLAGS+=	use_fame=1
BUILD_MAKE_FLAGS+=	use_drz80=1
BUILD_MAKE_FLAGS+=	use_cz80=0
BUILD_MAKE_FLAGS+=	use_sh2drc=1
BUILD_MAKE_FLAGS+=	use_svpdrc=1
.endif

NOT_FOR_PLATFORM+=	${BIGENDIANPLATFORMS}

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/picodrive_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/picodrive_libretro.so

.include "../../mk/bsd.pkg.mk"
