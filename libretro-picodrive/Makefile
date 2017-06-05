# $NetBSD: Makefile,v 1.2 2015/02/05 16:57:53 wiz Exp $

PKGNAME=	libretro-picodrive-20170418
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.libretro.com/index.php?title=PicoDrive
COMMENT=	Fast MegaDrive/MegaCD/32X emulator
LICENSE=	picodrive-license

PICODRIVE_TAG=	cbc93b68dca1d72882d07b54bbe1ef25b980558a
CYCLONE_TAG=	355815ebb5b1c60916f66d043a43f3af7839589f

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

.if !empty(MACHINE_ARCH:M*armv6*) || !empty(MACHINE_ARCH:M*armv7*)
# This is just a way to get the right flags, it doesn't use anything
# Raspberry Pi specific.
BUILD_MAKE_FLAGS+=	platform=raspberrypi

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
