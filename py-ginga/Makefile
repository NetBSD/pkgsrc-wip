# $NetBSD$

DISTNAME=	ginga-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ginga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ginga.readthedocs.io/
COMMENT=	Astronomical image viewer and toolkit
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-qtpy>=1.1:../../wip/py-qtpy

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
