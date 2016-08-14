# $NetBSD$

GIT_REPOSITORIES=	openrw
GIT_REPO.openrw=	git@github.com:rwengine/openrw.git

PKGNAME=	openrw-0
CATEGORIES=	games

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	git@github.com:krytarowski/
COMMENT=	Open Source recreation of Grand Theft Auto III
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/openrw

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

.include "../../wip/mk/git-package.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
