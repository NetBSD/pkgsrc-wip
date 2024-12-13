# $NetBSD$

DISTNAME=	libwacom-2.14.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxwacom/libwacom/releases/download/libwacom-2.14.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/linuxwacom/libwacom/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

MESON_ARGS+=	-Dtests=disabled

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing Python script interpreters
SUBST_FILES.python=	tools/show-stylus.py tools/libwacom-update-db.py
SUBST_SED.python=	-e 's|/usr/bin/env python3|${PYTHONBIN}|'

.include "../../lang/python/application.mk"
.include "../../devel/meson/build.mk"
.include "../../wip/libgudev/buildlink3.mk"
.include "../../wip/libevdev/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
