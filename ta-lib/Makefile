# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:20 asau Exp $
#

DISTNAME=	ta-lib-0.4.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ta-lib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.ta-lib.org/
COMMENT=	Unix POSIX Library for Technical Analysis

WRKSRC=		${WRKDIR}/ta-lib
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
