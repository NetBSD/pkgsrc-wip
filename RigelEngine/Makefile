# $NetBSD$

GITHUB_PROJECT=	RigelEngine
GITHUB_TAG=	v0.7.1-beta
DISTNAME=	${GITHUB_TAG}
PKGNAME=	RigelEngine-0.7.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=lethal-guitar/}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES+=	${GITHUB_TAG}.tar.gz
DISTFILES+=	imgui-1.7.9.tar.gz
SITES.imgui-1.7.9.tar.gz= \
	-${MASTER_SITE_GITHUB:S,^,-,:=ocornut/}imgui/archive/v1.79.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lethal-guitar/RigelEngine/
COMMENT=	Modern re-implementation of the classic DOS game Duke Nukem II
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/RigelEngine-0.7.1-beta
USE_CMAKE=	yes
USE_LANGUAGES=	c c++17

INSTALLATION_DIRS+=	bin

pre-configure:
	cp -R ${WRKDIR}/imgui-1.79/* ${WRKSRC}/3rd_party/imgui/imgui

do-install:
	${INSTALL_GAME} ${WRKSRC}/src/RigelEngine ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../wip/entityx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
