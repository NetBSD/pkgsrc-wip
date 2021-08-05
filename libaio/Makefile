# $NetBSD$

DISTNAME=	libaio-0.3.112
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/libaio/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://pagure.io/libaio
COMMENT=	Linux-native asynchronous I/O access library
LICENSE=	gnu-lgpl-v2.1

# Linux-specific library
ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=	gmake

MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
