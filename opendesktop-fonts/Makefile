# $NetBSD: Makefile,v 1.4 2013/01/10 12:23:36 obache Exp $
#

DISTNAME=	opendesktop-fonts-1.4.2
CATEGORIES=	fonts chinese japanese
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/ODOFonts/OpenFonts/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.opendesktop.org.tw/
COMMENT=	Simplified and Traditional Chinese and Japanese Ming and Kai Face
LICENSE=	arphic-public-license
LICENSE_FILE=	arphic-public-license

NO_BUILD=	yes
USE_LANGUAGES=	# empty

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/odokai-ExtB.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/odokai.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/odosung-ExtB.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/odosung.ttc ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
