# $NetBSD: Makefile,v 1.1.1.1 2010/11/04 11:08:49 ryo-on Exp $
#

DISTNAME=	ubuntu-font-family-sources_0.69+ufl.orig
PKGNAME=	${DISTNAME:S/family-sources_/ttf-/:S/+ufl.orig//}
CATEGORIES=	fonts
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/u/ubuntu-font-family-sources/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://archive.ubuntu.com/ubuntu/pool/main/u/ubuntu-font-family-sources/
COMMENT=	Ubuntu font family
#LICENSE=	UBUNTU FONT LICENCE Version 1.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ubuntu-font-family-sources-0.69+ufl
USE_LANGUAGES=	# none

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Ubuntu-B.ttf \
		Ubuntu-BI.ttf \
		Ubuntu-I.ttf \
		Ubuntu-R.ttf

INSTALL_DOCS=	CONTRIBUTING.txt \
		FONTLOG.txt \
		LICENCE-FAQ.txt \
		LICENCE.txt \
		README.txt \
		RELEASENOTES.txt \
		TRADEMARKS.txt \
		copyright.txt

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor


.include "../../mk/bsd.pkg.mk"
