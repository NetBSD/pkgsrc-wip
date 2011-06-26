# $NetBSD: Makefile,v 1.4 2011/06/26 11:47:20 ryo-on Exp $
#

DISTNAME=	hanazono-20110516
PKGNAME=	${DISTNAME:S/-/-ttf-/}
CATEGORIES=	fonts
MASTER_SITES=	http://www.fonts.jp/hanazono/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.fonts.jp/hanazono/
COMMENT=	Hanazono font (HanaMin) contains all UCS CJK glyphs
LICENSE=	mplusfont OR open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	HanaMinA.ttf \
		HanaMinB.ttf
INSTALL_DOCS=	LICENSE.txt \
		README.txt \
		THANKS.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKDIR}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKDIR}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
