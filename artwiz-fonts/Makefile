# $NetBSD: Makefile,v 1.1.1.1 2003/07/02 11:05:18 xtraeme Exp $
#

DISTNAME=	artwiz-fonts
PKGNAME=        artwiz-fonts-1.0
WRKSRC=         ${WRKDIR}/fluxbox-${DISTNAME}
CATEGORIES=	fonts
MASTER_SITES=	http://www.xs4all.nl/~hanb/software/fluxbox/ \
		http://www.cus.org.uk/~dom/distfiles/artwiz-fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.vastwaters.com/
COMMENT=	Set of free fonts for X11 desktops

USE_BUILDLINK2=		yes
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes
USE_PKGINSTALL=		yes

FONTS= 			${PREFIX}/lib/X11/fonts/artwiz
FONTS_X11_DIRS=		${FONTS}
OWN_DIRS=		${FONTS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.gz ${FONTS_X11_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
