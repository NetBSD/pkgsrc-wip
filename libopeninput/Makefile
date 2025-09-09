# $NetBSD$

DISTNAME=	libopeninput-1.26.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sizeofvoid/}
GITHUB_TAG=	cf9699e76e41bf1b824c3820d06d36a2b0fbb8c1

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/sizeofvoid/libopeninput/tree/build-on-openbsd/
COMMENT=	Wscons(4) and kqueue(2) based port of libinput
LICENSE=	mit

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dlibwacom=false
MESON_ARGS+=	-Ddocumentation=false
MESON_ARGS+=	-Dtests=false

CFLAGS+=	-O0 -g
LDFLAGS+=	-levdev

.include "../../devel/meson/build.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../wip/input-headers/buildlink3.mk"
.include "../../wip/libevdev-chunk/buildlink3.mk"
.include "../../wip/libudev-bsd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
