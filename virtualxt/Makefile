# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	virtualxt-0.10.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=andreas-jonsson/}

MAINTAINER=		mail@andreasjonsson.se
HOMEPAGE=		https://virtualxt.org/
COMMENT=		Portable, lightweight Turbo PC/XT emulator written in C
LICENSE=		zlib

USE_LANGUAGES=		c
USE_CC_FEATURES=	c11

DEPENDS+=	xdg-utils-1.1.*:../../misc/xdg-utils
TOOL_DEPENDS+=	premake5-5.0.*:../../devel/premake5
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/virtualxt/bios share/virtualxt/boot
BUILD_TARGET=		sdl2-frontend
WRKSRC=			${WRKDIR}/${DISTNAME}

post-extract:
	${CP} ${FILESDIR}/virtualxt.freedos ${WRKSRC}
	${CP} ${FILESDIR}/virtualxt.elks ${WRKSRC}

pre-build:
	cd ${WRKSRC} && premake5 --static --modules=-network,lua gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/virtualxt ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/virtualxt.freedos ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/virtualxt.elks ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/bios/GLABIOS.ROM ${DESTDIR}${PREFIX}/share/virtualxt/bios
	${INSTALL_DATA} ${WRKSRC}/bios/GLABIOS640.ROM ${DESTDIR}${PREFIX}/share/virtualxt/bios
	${INSTALL_DATA} ${WRKSRC}/bios/GLaTICK_0.8.4_AT.ROM ${DESTDIR}${PREFIX}/share/virtualxt/bios
	${INSTALL_DATA} ${WRKSRC}/bios/pcxtbios.bin ${DESTDIR}${PREFIX}/share/virtualxt/bios
	${INSTALL_DATA} ${WRKSRC}/bios/vxtx.bin ${DESTDIR}${PREFIX}/share/virtualxt/bios

	${INSTALL_DATA} ${WRKSRC}/boot/freedos.img ${DESTDIR}${PREFIX}/share/virtualxt/boot
	${INSTALL_DATA} ${WRKSRC}/boot/freedos_hd.img ${DESTDIR}${PREFIX}/share/virtualxt/boot
	${INSTALL_DATA} ${WRKSRC}/boot/freedos_web_hd.img ${DESTDIR}${PREFIX}/share/virtualxt/boot
	${INSTALL_DATA} ${WRKSRC}/boot/elks.img ${DESTDIR}${PREFIX}/share/virtualxt/boot

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
