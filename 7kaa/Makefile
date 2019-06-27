# $NetBSD$

DISTNAME=	7kaa-2.15.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=the3dfxdude/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://7kfans.com/
COMMENT=	Seven Kingdoms: Ancient Adversaries
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++11
GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	pkg-config

# C++11
GCC_REQD+=	4.6

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
