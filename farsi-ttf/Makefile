# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=	farsifonts-0.4
PKGNAME=	farsi-ttf-0.4
CATEGORIES=	fonts
MASTER_SITES=	http://www.farsiweb.ir/font/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.farsiweb.ir/wiki/Products/PersianFonts
COMMENT=	Mothanna is a sans-serif like Arabic OpenType font
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	share/doc/farsi-ttf ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS		 	\
		 ${DESTDIR}${PREFIX}/share/doc/farsi-ttf
	${INSTALL_DATA} ${WRKSRC}/elham.ttf		\
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/homa.ttf		\
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/koodak.ttf 		\
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/nazli.ttf 			\
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/nazlib.ttf		\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/roya.ttf			\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/royab.ttf		\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/terafik.ttf		\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/terafikb.ttf		\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/titr.ttf			\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}



.include "../../mk/bsd.pkg.mk"
