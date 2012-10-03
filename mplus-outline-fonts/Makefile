# $NetBSD: Makefile,v 1.24 2012/10/03 15:09:58 asau Exp $
#

DISTNAME=	mplus-TESTFLIGHT-050
PKGNAME=	${DISTNAME:S/-TESTFLIGHT-/-outline-fonts-0pre/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mplus-fonts/6650/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mplus-fonts.sourceforge.jp/mplus-outline-fonts/index-en.html
COMMENT=	M+ outline fonts
LICENSE=	mplusfont

USE_LANGUAGES=	# empty

NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	${RUN} cd ${WRKSRC}; 					\
	for f in *.ttf; do					\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${FONTDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
