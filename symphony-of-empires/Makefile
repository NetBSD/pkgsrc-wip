# $NetBSD$

DISTNAME=	symphony-of-empires-0.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=symphony-of-empires/}
GITHUB_TAG=	6b57ac88856f9a1a0633be081d0cad8ce4c1fd97

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://symphony-of-empires.com/
COMMENT=	Real-time strategy and map game
LICENSE=	gnu-gpl-v2

# C++20
GCC_REQD+=	10.3

USE_LANGUAGES+=	c c++

USE_TOOLS+=	pax
USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DE3D_BACKEND_D3D9=OFF
CMAKE_CONFIGURE_ARGS+=	-DE3D_BACKEND_GLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DE3D_BACKEND_OPENGL=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ENGINE=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GAME=ON

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	libexec

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/SymphonyOfEmpires.template > ${WRKDIR}/SymphonyOfEmpires

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/SymphonyOfEmpires ${DESTDIR}${PREFIX}/bin/SymphonyOfEmpires
	${INSTALL_PROGRAM} ${WRKSRC}/SymphonyOfEmpires ${DESTDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKSRC}/eng3d/libeng3d.so ${DESTDIR}${PREFIX}/lib
	(cd ${WRKSRC}/mods && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/SymphonyOfEmpires/mods)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../multimedia/assimp/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
