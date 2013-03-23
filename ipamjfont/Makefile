# $NetBSD: Makefile,v 1.4 2013/03/23 08:37:36 shattered Exp $
#

DISTNAME=	ipamjm00201
PKGNAME=	ipamjfont-00201
CATEGORIES=	fonts
MASTER_SITES=	-http://ossipedia.ipa.go.jp/ipamjfont/ipamjm00201.php
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ossipedia.ipa.go.jp/ipamjfont/
COMMENT=	Font for Japanese names
LICENSE=	ipafont

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

DOCS_DIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCS_DIR}

FONTS_DIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTS_DIR}

INSTALL_FONTS=	ipamjm.ttf
INSTALL_DOCS=	IPA_Font_License_Agreement_v1.0.txt \
		Readme_ipamjm002.01.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_FONTS} \
		${DESTDIR}${FONTS_DIR}
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${DOCS_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
