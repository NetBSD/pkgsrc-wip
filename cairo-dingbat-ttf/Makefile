# $NetBSD: Makefile,v 1.6 2014/02/27 19:57:29 christtrekker Exp $

DISTNAME=	CairoUnicode
PKGNAME=	cairo-dingbat-ttf-20140211
CATEGORIES=	fonts
MASTER_SITES=	http://christtrekker.users.sourceforge.net/fnt/
EXTRACT_SUFX=	.tgz

OWNER=		christtrekker@users.sourceforge.net
HOMEPAGE=	http://christtrekker.users.sourceforge.net/fnt/cairo.shtml
COMMENT=	Outline version of old Macintosh font
LICENSE=	cc-by-sa-v3.0

WRKSRC=			${WRKDIR}/cairo
TTFPATH=		lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH:Q}
DOCPATH=		share/doc/cairo-dingbat-ttf	# why doesn't ${PKGBASE} work here?
DOCDIR=			${PREFIX}/${DOCPATH}
INSTALLATION_DIRS=	${TTFPATH:Q} ${DOCPATH:Q}
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf:Q}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.ttf ${DESTDIR}${FONTS_DIRS.ttf:Q}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.pdf ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Cairo*.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
