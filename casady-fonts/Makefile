# $NetBSD: Makefile,v 1.1 2014/02/03 22:05:51 christtrekker Exp $

DISTNAME=	casady-fonts-201402
CATEGORIES=	fonts
MASTER_SITES=	http://www.moorstation.org/typoasis/designers/casady_greene/ \
	http://www.moorstation.org/typoasis/designers/casady_greene/d_h/ \
	http://www.moorstation.org/typoasis/designers/casady_greene/j_p/
EXTRACT_SUFX=	.zip
DISTFILES=	Collegiate${EXTRACT_SUFX}
DISTFILES+=	Dorovar${EXTRACT_SUFX} Gazelle${EXTRACT_SUFX} Gregorian${EXTRACT_SUFX}
DISTFILES+=	Jott${EXTRACT_SUFX} Kells${EXTRACT_SUFX} Meath${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moorstation.org/typoasis/designers/casady_greene/
COMMENT=	TrueType fonts by Robin Casady
LICENSE=	public-domain

WRKSRC=			${WRKDIR}
TTFPATH=		lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH:Q}
INSTALLATION_DIRS=	${TTFPATH:Q}
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf:Q}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf:Q}
# install doco too!

#DEPENDS+=	the Chicago package too

.include "../../mk/bsd.pkg.mk"
