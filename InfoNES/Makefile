# $NetBSD: Makefile,v 1.11 2012/09/24 16:56:27 asau Exp $
#

DISTNAME=		InfoNES097JRC1_SDL
PKGNAME=		InfoNES-0.97rc1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=infones/19061/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.geocities.co.jp/SiliconValley/5604/infones.html
COMMENT=		Portable NES emulator

PKG_DESTDIR_SUPPORT=	none

.include "options.mk"

BUILD_DIRS=		src/${SRC_SUBDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${SRC_SUBDIR}/InfoNES ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/InfoNES
	${INSTALL_DATA} ${FILESDIR}/keys.txt ${PREFIX}/share/doc/InfoNES

.include "../../mk/bsd.pkg.mk"
