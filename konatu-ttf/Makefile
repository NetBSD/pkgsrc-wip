# $NetBSD: Makefile,v 1.5 2011/05/04 20:22:54 ryo-on Exp $
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
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
