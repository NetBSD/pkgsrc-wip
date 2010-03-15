# $NetBSD: Makefile,v 1.1.1.1 2010/03/15 23:22:05 ryo-on Exp $
#

DISTNAME=	IPAexfont00101
PKGNAME=	${DISTNAME:S/IPAexfont/ipaexfonts-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=ipafonts/46160/} \
		http://info.openlab.ipa.go.jp/ipafont/fontdata/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://ossipedia.ipa.go.jp/ipafont/
COMMENT=	IPAex fonts (fixed JIS X0213 Kanji, and proportional ASCII)
# LICENSE=	IPA Font License Agreement v1.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	ipaexg.ttf \
		ipaexm.ttf
INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_IPAexfont00101.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
