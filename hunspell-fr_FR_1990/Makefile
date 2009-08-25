# $NetBSD: Makefile,v 1.3 2009/08/25 11:57:52 thomasklausner Exp $

VERSION=		20080308
DICTNAME=		fr_FR-1990
PKGNAME=		hunspell-${DICTNAME:S/-/_/}-${VERSION}
DISTNAME=		fr_FR-1990_2-2-0
CATEGORIES=		textproc
MASTER_SITES=		http://dico.savant.free.fr/_download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dico.savant.free.fr/index.php
COMMENT=		French (1990 Reform) dictionary for hunspell

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
