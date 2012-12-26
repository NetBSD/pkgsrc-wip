# $NetBSD: Makefile,v 1.12 2012/12/26 23:01:50 othyro Exp $
#

DISTNAME=	InfoNES097JRC1_SDL
PKGNAME=	InfoNES-0.97rc1
CATEGORIES=	emulators
MASTER_SITES=	http://www.sourcefiles.org/Emulators/Videogames/ \
		http://patpend.net/ftp/emulators/nes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.co.jp/SiliconValley/5604/infones.html
COMMENT=	Portable NES emulator
LICENSE=	gnu-gpl-v2

.include "options.mk"

BUILD_DIRS=		src/${SRC_SUBDIR}
INSTALLATION_DIRS+=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${SRC_SUBDIR}/InfoNES ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/keys.txt ${DESTDIR}${PREFIX}/share/doc/InfoNES

.include "../../mk/bsd.pkg.mk"
