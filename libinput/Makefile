# $NetBSD$

DISTNAME=	libinput-1.17.1
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

REPLACE_INTERPRETER+=	env-python
REPLACE.env-python.old=	/usr/bin/env python3
REPLACE.env-python.new=	${PREFIX}/bin/python${PYVERSSUFFIX}
REPLACE_FILES.env-python=	tools/libinput-*.py

.include "../../lang/python/pyversion.mk"
.include "../../wip/libevdev/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/mtdev/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
