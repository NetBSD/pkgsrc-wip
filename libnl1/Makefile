# $NetBSD$

DISTNAME=	libnl-1.1.4
PKGNAME=	${DISTNAME:S/libnl/libnl1/}
CATEGORIES=	devel
MASTER_SITES=	https://www.infradead.org/~tgr/libnl/files/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.infradead.org/~tgr/libnl/
COMMENT=	APIs to netlink protocol based Linux kernel interfaces
LICENSE=	gnu-lgpl-v2.1

# Linux-specific library
ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
