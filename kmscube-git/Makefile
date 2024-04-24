# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	kmscube-0.0.1
CATEGORIES=	x11
GIT_REPO=	https://gitlab.freedesktop.org/mesa/kmscube.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/mesa/kmscube/
COMMENT=	Example KMS/GBM/EGL application
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

USE_CC_FEATURES=	c99

.include "../../devel/meson/build.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
