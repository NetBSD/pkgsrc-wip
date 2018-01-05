# $NetBSD: Makefile,v 1.2 2015/02/05 16:57:53 wiz Exp $

PKGNAME=	libretro-picodrive-20171021
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/picodrive/
COMMENT=	Libretro core for emulating Sega 8/16-bit consoles & 32X
LICENSE=	picodrive-license

PICODRIVE_TAG=	084a4f24258cce81fb248739494ebee7339b7761
CYCLONE_TAG=	b889883d36b2d247488c82d79d1eaab4dd41d236

DISTFILES+=	${PICODRIVE_TAG}.tar.gz
SITES.${PICODRIVE_TAG}.tar.gz= \
	${MASTER_SITE_GITHUB:=libretro/picodrive/archive/}

DISTFILES+=	${CYCLONE_TAG}.tar.gz
SITES.${CYCLONE_TAG}.tar.gz= \
	${MASTER_SITE_GITHUB:=notaz/cyclone68000/archive/}

WRKSRC=		${WRKDIR}/picodrive-${PICODRIVE_TAG}
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

.include "../../mk/bsd.fast.prefs.mk"

NOT_FOR_PLATFORM=	${BIGENDIANPLATFORMS}

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.if !empty(MACHINE_ARCH:M*armv7*)
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
BUILD_MAKE_FLAGS+=	ARM_ASM=1
BUILD_MAKE_FLAGS+=	use_cyclone=0
BUILD_MAKE_FLAGS+=	use_fame=1
BUILD_MAKE_FLAGS+=	use_drz80=0
BUILD_MAKE_FLAGS+=	use_cz80=1
BUILD_MAKE_FLAGS+=	use_sh2drc=1
BUILD_MAKE_FLAGS+=	use_svpdrc=1
.elif !empty(MACHINE_ARCH:M*armv6*)
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
BUILD_MAKE_FLAGS+=	ARM_ASM=1
BUILD_MAKE_FLAGS+=	asm_memory=1
BUILD_MAKE_FLAGS+=	asm_render=1
BUILD_MAKE_FLAGS+=	asm_ym2612=1
BUILD_MAKE_FLAGS+=	asm_misc=1
BUILD_MAKE_FLAGS+=	asm_cdpico=1
BUILD_MAKE_FLAGS+=	asm_cdmemory=1
BUILD_MAKE_FLAGS+=	asm_mix=1
BUILD_MAKE_FLAGS+=	use_cyclone=1
BUILD_MAKE_FLAGS+=	use_fame=0
BUILD_MAKE_FLAGS+=	use_drz80=1
BUILD_MAKE_FLAGS+=	use_cz80=0
BUILD_MAKE_FLAGS+=	use_sh2drc=1
BUILD_MAKE_FLAGS+=	use_svpdrc=1

USE_TOOLS+=		gzcat

# Cyclone.s is pre-generated because the default build process needs to
# build a generation program, and the toolchain might not be set up to
# properly build programs for the host machine. To regenerate
# ${FILESDIR}/Cyclone.s.gz, go to ${WRKSRC}/cpu/cyclone, then do this:
# `gmake CONFIG_FILE=../cyclone_config.h && gzip Cyclone.s`
post-extract:
	${MV} ${WRKDIR}/cyclone68000-${CYCLONE_TAG}/* ${WRKSRC}/cpu/cyclone
	${GZCAT} ${FILESDIR}/Cyclone.s.gz >${WRKSRC}/cpu/cyclone/Cyclone.s
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/picodrive_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/picodrive_libretro.so

.include "../../mk/bsd.pkg.mk"
