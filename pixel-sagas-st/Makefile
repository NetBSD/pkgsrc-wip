# $NetBSD: Makefile,v 1.2 2013/12/27 18:31:38 christtrekker Exp $

DISTNAME=	pixels-sagas-st-201312
CATEGORIES=	fonts

MASTER_SITES=	http://www.pixelsagas.com/files/
DISTFILES+=	PS_Font_Fontana.zip
DISTFILES+=	PS_Font_Jefferies.zip
DISTFILES+=	PS_Font_Montalban.zip
DISTFILES+=	PS_Font_Okuda.zip
DISTFILES+=	PS_Font_Probert.zip
DISTFILES+=	PS_Font_Roddenberry.zip
DISTFILES+=	PS_Font_Sternbach.zip
DISTFILES+=	PS_Font_Tellarite.zip
DISTFILES+=	PS_Font_Trek_Arrowcaps.zip
DISTFILES+=	PS_Font_Trek_Arrowheads.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.pixelsagas.com/fonts.php
COMMENT=	Star Trek fonts from Pixel Sagas (Neale Davidson)
LICENSE=	pixel-sagas-shareware-license

WRKSRC=		${WRKDIR}
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
