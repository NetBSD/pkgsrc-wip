# $NetBSD$

DISTNAME=	qtile-0.36.0
CATEGORIES=	wm python
MASTER_SITES=	${MASTER_SITE_GITHUB:=qtile/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://qtile.org/
COMMENT=	Fully-featured, pure-Python tiling window manager
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cairocffi>=1.7.0:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-xcffib>=1.4.0:../../wip/py-xcffib

USE_LANGUAGES=	# none

# setuptools_scm can't find version, because .git is missing
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION_FOR_qtile=${PKGVERSION_NOREV}

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
