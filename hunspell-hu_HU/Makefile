# $NetBSD: Makefile,v 1.2 2007/11/17 19:50:23 hoka_adam Exp $
#

VERSION=	1.2.2
DICTNAME=	hu_HU
PKGNAME=	hunspell-${DISTNAME}
DISTNAME=	${DICTNAME}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=magyarispell/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=	Hungarian dictionaries for hunspell

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_u8_gen_alias.aff ${PREFIX}/share/hunspell/${DICTNAME}-utf8.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_u8_gen_alias.dic ${PREFIX}/share/hunspell/${DICTNAME}-utf8.dic
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_gen_alias.aff ${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_gen_alias.dic ${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README_${DICTNAME}.txt \
		${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
