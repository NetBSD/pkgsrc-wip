# $NetBSD: Makefile,v 1.1.1.1 2007/09/14 16:19:44 hoka_adam Exp $
#

VERSION=	20021015
DISTNAME=	ca_ES
PKGNAME=	hunspell-${DISTNAME}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/dictionaries/
EXTRACT_SUFX=	.zip

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=	Catalan dictionary for hunspell

DIST_SUBDIR=	hunspell-dictionaries/${DISTNAME}-${VERSION}
# don't want -L
EXTRACT_OPTS_ZIP=	-aqo

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DISTNAME}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.* ${PREFIX}/share/hunspell
	${INSTALL_DATA} ${WRKSRC}/README_${DISTNAME}.txt \
		${PREFIX}/share/doc/hunspell-${DISTNAME}

.include "../../mk/bsd.pkg.mk"
