# $NetBSD: Makefile,v 1.1 2013/08/20 19:38:30 airhead Exp $
#

DISTNAME=	58d69ab3cdb242d7fe4e29e85dbae9183e25d821
PKGNAME=	openxcom-0.9
WRKSRC=		${WRKDIR}/OpenXcom-${DISTNAME}
# This is really just slightly newer than 0.9, so let's call it 0.9nb1.
# We don't use the official 0.9 release because it depends on yaml-cpp 0.3,
# which is deprecated.  This uses yaml-cpp 0.5 (which has a different API).
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	https://github.com/SupSuper/OpenXcom/archive/
FETCH_USING=	curl

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://www.openxcom.org/
COMMENT=	Open-source clone of UFO: Enemy Unknown/X-Com: UFO Defense
LICENSE=	gnu-gpl-v3

DEPENDS+=	timidity-[0-9]*:../../audio/timidity
# Docs say this is needed, but it builds fine without
#BUILD_DEPENDS+=	docbook2X-[0-9]*:../../wip/docbook2X

OPENXCOM_BASE=		${PREFIX}/share/games/${PKGBASE}
OPENXCOM_DATA=		${OPENXCOM_BASE}/data
OWN_DIRS=		${OPENXCOM_DATA}
MESSAGE_SUBST+=		OPENXCOM_DATA=${OPENXCOM_DATA}

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_CMAKE=	yes
# Yes, this is slightly confusing (the data gets appended by OpenXcom)
CMAKE_ARGS+=	-DDATADIR=${OPENXCOM_BASE}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../wip/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
