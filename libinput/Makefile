# $NetBSD$

DISTNAME=	libinput-1.15.6
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/libinput/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://wayland.freedesktop.org/libinput/doc/latest/
COMMENT=	Coordinate scaling, relative pointer, acceleration
LICENSE=	mit

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=allno
SUBST_STAGE.allno=pre-configure
SUBST_FILES.allno=*.txt
SUBST_SED.allno=s,true,false,

.include "../../wip/libevdev/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/mtdev/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
