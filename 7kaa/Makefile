# $NetBSD$

DISTNAME=	7kaa-2.14.6
CATEGORIES=	games
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=the3dfxdude/}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Seven Kingdoms: Ancient Adversaries
HOMEPAGE=	https://7kfans.com/
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf automake

REPLACE_SH+=	autogen.sh

pre-configure:
	cd ${WRKSRC} && sh ./autogen.sh

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
