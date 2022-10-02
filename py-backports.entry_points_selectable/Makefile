# $NetBSD$

DISTNAME=	backports.entry_points_selectable-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.entry_points_selectable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.entry_points_selectable
COMMENT=	Compatibility shim providing selectable entry points
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
