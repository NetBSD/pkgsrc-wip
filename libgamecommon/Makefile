# $NetBSD$

DISTNAME=	libgamecommon-1.2
CATEGORIES=	devel games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Malvineous/libgamecommon/releases/download/v1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shikadi.net/camoto/
COMMENT=	Utility functions for working with binary files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libgamecommon.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
