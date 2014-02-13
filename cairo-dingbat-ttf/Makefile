# $NetBSD: Makefile,v 1.1 2014/02/13 20:54:15 christtrekker Exp $

DISTNAME=	CairoUnicode
PKGNAME=	${DISTNAME}-20140211
CATEGORIES=	fonts
MASTER_SITES=	http://christtrekker.users.sourceforge.net/fnt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://christtrekker.users.sourceforge.net/fnt/cairo.shtml
COMMENT=	Outline version of old Macintosh font
LICENSE=	cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/cairo
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
DOCPATH=	share/doc/${DISTNAME}	# why doesn't ${PKGBASE} work here?
DOCDIR=		${PREFIX}/share/doc/${DISTNAME}
INSTALLATION_DIRS=	${TTFPATH} ${DOCPATH}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.pdf ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.txt ${DESTDIR}${DOCDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
