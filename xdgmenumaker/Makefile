# $NetBSD$

DISTNAME=	xdgmenumaker-2.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gapan/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	dvollen@gmail.com
HOMEPAGE=	https://github.com/gapan/xdgmenumaker/
COMMENT=	Program to generate menus based on XDG .desktop files
LICENSE=	gnu-gpl-v3

BUILD_TARGET=	install

REPLACE_PYTHON=	src/xdgmenumaker

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# empty


.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
