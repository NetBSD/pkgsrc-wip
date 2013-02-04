# $NetBSD: Makefile,v 1.1 2013/02/04 20:58:04 christtrekker Exp $
#

DISTNAME=	courier-prime
PKGNAME=	${DISTNAME}-1.203
CATEGORIES=	fonts
MASTER_SITES=	http://quoteunquoteapps.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quoteunquoteapps.com/courierprime/
COMMENT=	It's Courier, just better
LICENSE=	open-font-license

WRKSRC=		${WRKDIR}/Courier\ Prime
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS+=	${TTFPATH}
INSTALLATION_DIRS+=	share/doc/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Read\ me.txt ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE/OFL.txt ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/


.include "../../mk/bsd.pkg.mk"
