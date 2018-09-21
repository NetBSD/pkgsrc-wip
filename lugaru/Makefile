# $NetBSD$

DISTNAME=	lugaru-${VERSION}
VERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/osslugaru/lugaru/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Open source release of the game from Wolfire
HOMEPAGE=	https://bitbucket.org/osslugaru/lugaru/
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
