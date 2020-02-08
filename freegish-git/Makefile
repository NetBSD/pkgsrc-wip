# $NetBSD$

DISTNAME=	freegish-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=freegish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freegish/freegish/
COMMENT=	Free version of the game Gish
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
CMAKE_ARGS+=	-DINSTALL_FHS:BOOL=ON
CMAKE_ARGS+=	-DMAN_DIR:PATH=${PREFIX}/${PKGMANDIR}/man6

GIT_REPOSITORIES=	freegish
GIT_REPO.freegish=	git://github.com/freegish/freegish.git
WRKSRC=			${WRKDIR}/freegish

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
