# $NetBSD: Makefile,v 1.5 2008/02/29 21:06:03 hoka_adam Exp $

VERSION=		1.2.2
DICTNAME=		hu_HU
PKGNAME=		hunspell-${DISTNAME}
DISTNAME=		${DICTNAME}-${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=magyarispell/}

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://magyarispell.sourceforge.net/
COMMENT=		Hungarian dictionary for hunspell

DEPENDS+=		hunspell>=1.1.12.2:../../textproc/hunspell

USE_LANGUAGES=		# none
NO_BUILD=		yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}
PLIST_SUBST+=		DICTNAME=${DICTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_u8_gen_alias.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}-utf8.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_u8_gen_alias.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}-utf8.dic
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_gen_alias.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}_gen_alias.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README_${DICTNAME}.txt \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}

.include "../../mk/bsd.pkg.mk"
