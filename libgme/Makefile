# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=	game-music-emu-0.5.5
PKGNAME=	${DISTNAME:S/game-music-emu/libgme/}
CATEGORIES=	audio
MASTER_SITES=	http://game-music-emu.googlecode.com/files/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://code.google.com/p/game-music-emu/
COMMENT=	Video game music file emulation/playback library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	lib/pkgconfig
BUILD_DIRS=		gme
MAKE_ENV+=		MKDIR="${MKDIR}"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/gme/
	${CP} ${FILESDIR}/gme_types.h ${WRKSRC}/gme/
	${SED}	-e "s,@PREFIX@,${PREFIX}," \
                -e 's,@VERSION@,${PKGVERSION},g' \
		${FILESDIR}/libgme.pc > ${WRKSRC}/libgme.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgme.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
