# $NetBSD: Makefile,v 1.1.1.1 2009/08/09 23:07:33 jihbed Exp $
#

DISTNAME=	hunspell-ar_20080110
DICTNAME=	ar
PKGNAME=	hunspell-${DICTNAME}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ayaspell/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ayaspell.sourceforge.net/
COMMENT=	Arabic dictionary for hunspell
#LICENSE=	gnu-gpl-v2 And gnu-lgpl-v2.1 And mpl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	20080110
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-${DICTNAME}
PLIST_SUBST+=		DICTNAME=${DICTNAME}
MAKE_DIRS=		share/hunspell

do-build:	# nothing

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.aff \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.aff
	${INSTALL_DATA} ${WRKSRC}/${DICTNAME}.dic \
		${DESTDIR}${PREFIX}/share/hunspell/${DICTNAME}.dic
	${INSTALL_DATA} ${WRKSRC}/README-* \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}
	${INSTALL_DATA} ${WRKSRC}/install-* \
		${DESTDIR}${PREFIX}/share/doc/hunspell-${DICTNAME}


.include "../../mk/bsd.pkg.mk"
