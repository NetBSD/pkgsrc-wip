# $NetBSD: Makefile,v 1.2 2009/06/26 23:27:25 jihbed Exp $
#

DISTNAME=	ta-lib-0.4.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ta-lib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.ta-lib.org/
COMMENT=	Unix POSIX Library for Technical Analysis

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ta-lib
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
