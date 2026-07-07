# $NetBSD$

DISTNAME=	chocolate-quake-2.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Henrique194/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/Henrique194/chocolate-quake/
COMMENT=	Minimalist source port of Quake
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/chocolate-quake-chocolate-quake-2.1.0

.include "../../devel/cmake/build.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
