# $NetBSD$

DISTNAME=	innerscope-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/innerscope/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/innerscope/
COMMENT=	Expose the inner scope of functions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
