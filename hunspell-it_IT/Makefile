# $NetBSD: Makefile,v 1.1.1.1 2008/03/16 18:24:13 hoka_adam Exp $

VERSION=		2.4
DICTNAME=		it_IT
PKGNAME=		hunspell-${DICTNAME}-${VERSION}
DISTNAME=		italiano_2_4_2007_09_01
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=linguistico/}
EXTRACT_SUFX=		.zip

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://linguistico.sourceforge.net/wiki/doku.php?id=dizionario_italiano
COMMENT=		Italian dictionary for hunspell

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
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_* \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
