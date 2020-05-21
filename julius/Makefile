# $NetBSD$

SUBDIR+=	julius
GITHUB_PROJECT=	julius
DISTNAME=	julius-1.4.0-source
PKGNAME=	julius-1.4.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bvschaik/}
GITHUB_RELEASE=	v1.4.0

MAINTAINER=	astr0b4by@gmail.com
HOMEPAGE=	https://github.com/bvschaik/julius/
COMMENT=	Open source re-implementation of Caesar III
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/julius-1.4.0
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
LDFLAGS.NetBSD+=	-lexecinfo

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
