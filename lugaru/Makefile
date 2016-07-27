# $NetBSD$

DISTNAME=	lugaru-rev${PKGVERSION_NOREV}-src
PKGNAME=	lugaru-${VERSION}
VERSION=	269
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/osslugaru/lugaru/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Open source release of the game from Wolfire
HOMEPAGE=	https://bitbucket.org/osslugaru/lugaru/
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DLUGARU_INSTALL_PREFIX:PATH=${PREFIX} 

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
