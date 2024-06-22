# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	RigelEngine-${GITHUB_TAG:S/^v//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=lethal-guitar/}
GITHUB_PROJECT=	RigelEngine
GITHUB_TAG=	v0.9.1
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES+=	${GITHUB_TAG}.tar.gz
DISTFILES+=	imgui-1.86.tar.gz
SITES.imgui-1.86.tar.gz= \
	-${MASTER_SITE_GITHUB:=ocornut/}imgui/archive/v1.86.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lethal-guitar/RigelEngine/
COMMENT=	Modern re-implementation of the classic DOS game Duke Nukem II
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

INSTALLATION_DIRS+=	bin

pre-patch:
	${CP} -R ${WRKDIR}/imgui-1.86/* ${WRKSRC}/3rd_party/imgui/imgui

do-install:
	${INSTALL_GAME} ${WRKSRC}/src/RigelEngine ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../wip/entityx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
