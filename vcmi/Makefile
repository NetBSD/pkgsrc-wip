# $NetBSD$

DISTNAME=	vcmi-0.99
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcmi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vcmi.eu/
COMMENT=	Open-source engine for Heroes of Might and Magic 3
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# \todo Not 100% sure, at least pthreads are checked for.
PTHREAD_OPTS=	require native
LDFLAGS+=	-lpthread

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
