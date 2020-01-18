# $NetBSD$

GITHUB_PROJECT=	grim
DISTNAME=	grim-1.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=emersion/}
GITHUB_RELEASE=	v1.3.0

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://wayland.emersion.fr/grim/
COMMENT=	Tool to grab images from a Wayland compositor
LICENSE=	mit

USE_TOOLS=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DJPEG=ENABELED

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${PREFIX}/bin/meson build && \
	${PREFIX}/bin/ninja -C build


.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
