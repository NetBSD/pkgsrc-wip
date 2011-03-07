# $NetBSD: Makefile,v 1.4 2011/03/07 07:36:57 ryo-on Exp $
#

DISTNAME=	Konatu_ver_26
PKGNAME=	${DISTNAME:tl:S/_ver_/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.masuseki.com/be/konatu/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.masuseki.com/?u=be/konatu.htm
COMMENT=	Japanese TrueType gothic (sans-serif) fonts, Konatu fonts
# LICENSE=	Creative Commons Attribution-Share Alike 3.0 Unported

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

INSTALL_FONTS=	Konatu.ttf \
		KonatuTohaba.ttf

INSTALL_DOCS=	README.txt \
		README_Japanese.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
