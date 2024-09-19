# $NetBSD: Makefile,v 1.1 2015/02/02 10:10:25 nros Exp $

DISTNAME=	clearsans-1.00
PKGNAME=	${DISTNAME:S/-/-ttf-/}
CATEGORIES=	fonts
MASTER_SITES=	https://01.org/sites/default/files/downloads/clear-sans/
EXTRACT_SUFX=	.zip
EXTRACT_DIR=	${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://01.org/clear-sans
COMMENT=	Clear Sans TrueType font from Intel
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/clearsans-ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE-2.0.txt ${DESTDIR}${PREFIX}/share/doc/clearsans-ttf/


.include "../../mk/bsd.pkg.mk"
