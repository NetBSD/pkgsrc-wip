# $NetBSD$

DISTNAME=	Torque3D-3.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GarageGames/}

MAINTAINER=	pkgsrc-users@NetBSd.org
HOMEPAGE=	http://torque3d.org/
COMMENT=	Open Source version of Torque 3D from GarageGames
LICENSE=	mit

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DTORQUE_APP_NAME:STRING="TORQUE3D"

PKGCONFIG_OVERRIDE+=	Engine/lib/bullet/bullet.pc.in
PKGCONFIG_OVERRIDE+=	Engine/lib/lpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	Engine/lib/lpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	Engine/lib/sdl/sdl2.pc.in

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
