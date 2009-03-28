# $NetBSD: Makefile,v 1.1.1.1 2009/03/28 10:49:28 jihbed Exp $
#

DISTNAME=	ta-lib-0.4.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ta-lib/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.ta-lib.org/
COMMENT=	Unix POSIX Library for Technical Analysis

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ta-lib
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
