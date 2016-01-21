# $NetBSD$

DISTNAME=	pioneer
PKGNAME=	pioneer-${VERSION}
VERSION=	${GITHUB_TAG}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=pioneerspacesim/}
GITHUB_TAG=	20160116

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://pioneerspacesim.net/
COMMENT=	A game of lonely space adventure
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config automake autoconf gmake

CONFIGURE_ENV+=	PIONEER_DATA_DIR=${PREFIX}/share/pioneer/data
   
BUILDLINK_PKGSRCDIR.assimp=	../../wip/assimp

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/assimp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
