# $NetBSD: Makefile,v 1.1.1.1 2011/02/24 17:20:49 christtrekker Exp $
#

DISTNAME=	urbanrenewal
VERSION=	201102
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	http://www.kreativekorp.com/swdownload/fonts/urban/
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.kreativekorp.com/software/fonts/urbanrenewal.shtml
COMMENT=	Insanely great TT versions of the city-named fonts of Mac OS Classic
LICENSE=	kreativekorp-free-license
LICENSE_FILE=	kreativekorp-free-license

WRKSRC=		${WRKDIR}
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
NO_CONFIGURE=	yes
NO_BUILD=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
