# $NetBSD: Makefile,v 1.1.1.1 2008/03/16 19:59:46 hoka_adam Exp $

VERSION=		20061207
DICTNAME=		sv_SE
PKGNAME=		hunspell-${DICTNAME}-${VERSION}
DISTNAME=		${DICTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://hem.bredband.net/dsso1/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=		Swedish dictionary for hunspell

EXTRACT_OPTS_ZIP=	-aqo # We don't want -L
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}
PLIST_SUBST+=		DICTNAME=${DICTNAME}
MAKE_DIRS=		share/hunspell
WRKSRC=			${WRKDIR}

do-build:	# nothing

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README_${DICTNAME}.txt \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
