# $NetBSD$

DISTNAME=	libgamemusic-1.2
CATEGORIES=	devel games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Malvineous/libgamemusic/releases/download/v1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shikadi.net/camoto/
COMMENT=	Library for playing and converting music used in DOS games
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILD_DEPENDS=	xmlto-[0-9]*:../../textproc/xmlto

PKGCONFIG_OVERRIDE+=	libgamemusic.pc.in

.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/libgamecommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
