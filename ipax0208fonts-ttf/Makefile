# $NetBSD: Makefile,v 1.1.1.1 2010/03/15 23:24:11 ryo-on Exp $
#

DISTNAME=	IPAfont00103
PKGNAME=	${DISTNAME:S/IPAfont/ipax0208fonts-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://info.openlab.ipa.go.jp/ipafont/fontdata/old/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://ossipedia.ipa.go.jp/ipafont/
COMMENT=	TrueType IPA fonts based on JIS X0208
# LICENSE=	IPA Public Font End User License

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	ipag0208_for_legacy_compatibility.ttf \
		ipagp0208_for_legacy_compatibility.ttf \
		ipagui0208_for_legacy_compatibility.ttf \
		ipam0208_for_legacy_compatibility.ttf \
		ipamp0208_for_legacy_compatibility.ttf
INSTALL_DOCS=	Readme00103.txt \
		enduser_license.txt

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
