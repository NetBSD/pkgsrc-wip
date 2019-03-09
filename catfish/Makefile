# $NetBSD$

DISTNAME=	catfish-1.4.7
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/catfish/1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://docs.xfce.org/apps/catfish/start
COMMENT=	Versatile file search utility for the Xfce desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS=	intltool

BUILD_DEPENDS+=	${PYPKGPREFIX}-distutils-extra-[0-9]*:../../wip/py-distutils-extra
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	bin/catfish
REPLACE_PYTHON+=	setup.py

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
