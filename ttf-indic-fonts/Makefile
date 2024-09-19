# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:49 asau Exp $

DISTNAME=	ttf-indic-fonts_0.5.4
PKGNAME=	${DISTNAME:C/_/-/}
CATEGORIES=	fonts
MASTER_SITES=	http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/t/ttf-indic-fonts/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.debian-in.org/
COMMENT=	TTF Indic Fonts from Debian
LICENSE=	gnu-gpl-v2

CONFLICTS+=	lohit-fonts-[0-9]*

USE_TOOLS+=	find xargs

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

NO_BUILD=	yes

TTFLANG_DIRS=	ttf-bengali ttf-devanagari ttf-gujarati ttf-kannada ttf-malayalam ttf-oriya \
		ttf-punjabi ttf-tamil ttf-telugu

WRKSRC=	${WRKDIR}/${DISTNAME:C/_/-/}

pre-patch:
	${FIND} ${WRKSRC} -iname "debian" -print | ${XARGS} rm -fdr

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
.for d in ${TTFLANG_DIRS}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${DESTDIR}${FONTS_DIRS.ttf}
.endfor

.include "../../mk/bsd.pkg.mk"
