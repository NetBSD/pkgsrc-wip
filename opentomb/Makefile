# $NetBSD$

OTDATEVER=	2016-07-12
OTVERSUFX=	_alpha

DISTNAME=	OpenTomb-${OTDATEVER:S/-/./g}${OTVERSUFX:S/_/./}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentomb/}
GITHUB_TAG=	win32-${OTDATEVER}${OTVERSUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opentomb/OpenTomb/
COMMENT=	Open-Source Tomb Raider 1-5 engine remake
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
