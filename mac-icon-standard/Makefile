# $NetBSD: Makefile,v 1.1 2014/10/21 17:56:30 christtrekker Exp $

DISTNAME=	mac-icon-standard-201401
CATEGORIES=	fonts

DISTFILES+=	mac-icon-standard.ttf
SITES.mac-icon-standard.ttf=	http://images.apple.com/v/30-years/a/fonts/mac-icons/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://images.apple.com/v/30-years/a/fonts/mac-icons/
COMMENT=	30th anniversary Macintosh icon font
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/mac-icon-standard.ttf
USE_LANGUAGES=		# none
WRKSRC=			${WRKDIR}
TTFPATH=		lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
