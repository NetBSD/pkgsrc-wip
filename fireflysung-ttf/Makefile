# $NetBSD: Makefile,v 1.1.1.1 2006/02/26 14:51:13 rxg Exp $
#

DISTNAME=	fireflysung-1.3.0
PKGNAME=	${DISTNAME:S/fireflysung/fireflysung-ttf/}
CATEGORIES=	fonts chinese
MASTER_SITES=	http://www.study-area.org/apt/firefly-font/	\
		ftp://cle.linux.org.tw/pub2/fonts/FireFly/	\
		ftp://ftp.tnc.edu.tw/pub/freefont/FireFly/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.study-area.org/apt/firefly-font/
COMMENT=	AR PL New Sung TrueType fonts by Firefly

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/fireflysung-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/fireflysung.ttf ${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
