# $NetBSD: Makefile,v 1.3 2003/09/29 14:56:41 jeremy-c-reed Exp $
#

DISTNAME=	tads23-unix
PKGNAME=	tads-3.0.5
WRKSRC=		${WRKDIR}/tads
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/tads2/source/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.ifarchive.org/if-archive/programming/tads2/source/
COMMENT=	TADS compiler and interpreter

USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/tads2 ${WRKSRC}/tads3
MAKEFILE=	makefile

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
