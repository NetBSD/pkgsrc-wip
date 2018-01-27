# $NetBSD$

DISTNAME=	musl-1.1.15
CATEGORIES=	devel
MASTER_SITES=	http://www.musl-libc.org/releases/

MAINTAINER=	maya@NetBSD.org
HOMEPAGE=	http://www.musl-libc.org/
COMMENT=	C standard library
LICENSE=	mit

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/musl

.include "../../mk/bsd.pkg.mk"
