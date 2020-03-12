# $NetBSD$

DISTNAME=	grim-1.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=emersion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wayland.emersion.fr/grim/
COMMENT=	Tool to grab images from a Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config
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
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
