# $NetBSD$

DISTNAME=	stagit-0.8
CATEGORIES=	www
MASTER_SITES=	https://dl.2f30.org/releases/

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://git.2f30.org/stagit/
COMMENT=	Static git page generator
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	GITINC=${PREFIX}/include
MAKE_FLAGS+=	GITLIB=${PREFIX}/lib

.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
